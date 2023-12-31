//---------------------------------------------------------------------------
// ModuleInstance.cpp
//
// Ivo Ivanov
// ver 1.02
// 05 September 2001
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "ModuleInstance.h"

//---------------------------------------------------------------------------
// IsToolHelpSupported
//
// Checks whether Tool Help library is supported by the current platform
//---------------------------------------------------------------------------
static BOOL IsToolHelpSupported()
{
	BOOL    bResult(FALSE);
	HMODULE hModToolHelp;
	PROC    pfnCreateToolhelp32Snapshot;

	hModToolHelp = ::LoadLibrary("KERNEL32.DLL");
	if (NULL != hModToolHelp)
	{
		pfnCreateToolhelp32Snapshot = ::GetProcAddress(
			hModToolHelp, "CreateToolhelp32Snapshot");
		bResult = (NULL != pfnCreateToolhelp32Snapshot);
		::FreeLibrary(hModToolHelp);
	}
	return bResult;
}

//---------------------------------------------------------------------------
// IsPsapiSupported
//
// Checks whether PSAPI dll has been installed
//---------------------------------------------------------------------------
static BOOL IsPsapiSupported()
{
	BOOL bResult = FALSE;
	HMODULE hModPSAPI = NULL;

	hModPSAPI = ::LoadLibrary("PSAPI.DLL");
	bResult = (NULL != hModPSAPI);
	if (NULL != hModPSAPI)
		::FreeLibrary(hModPSAPI);

	return bResult;
}

//---------------------------------------------------------------------------
//
// class CElements
//
//---------------------------------------------------------------------------
CElements::CElements():
	CModuleList()
{
	
}

CElements::~CElements()
{
	
}
//---------------------------------------------------------------------------
//
// class CLibHandler
//
//---------------------------------------------------------------------------
CLibHandler::CLibHandler(CRunningProcesses* pProcesses):
	m_pProcesses(pProcesses)
{

}

CLibHandler::~CLibHandler()
{

}


//---------------------------------------------------------------------------
//
// class CTaskManager
//
//---------------------------------------------------------------------------
CTaskManager::CTaskManager():
	m_pLibHandler(NULL)
{
	m_pProcesses = new CRunningProcesses();

	if (IsPsapiSupported())
		m_pLibHandler = new CPsapiHandler(m_pProcesses);
	else
	if (IsToolHelpSupported())
		m_pLibHandler = new CToolhelpHandler(m_pProcesses);
}

CTaskManager::~CTaskManager()
{
	delete m_pLibHandler;
	delete m_pProcesses;
}

//---------------------------------------------------------------------------
// Populate
//
// Populate the module list using PSAPI or ToolHlp32
//---------------------------------------------------------------------------
BOOL CTaskManager::Populate()
{
	m_pProcesses->ReleaseAll();
	return m_pLibHandler->PopulateProcesses(); 
}

//---------------------------------------------------------------------------
// GetProcessCount
//
// Returns a number of currently loaded processes
//---------------------------------------------------------------------------
DWORD CTaskManager::GetProcessCount() const
{
	return m_pProcesses->GetCount();
}


//---------------------------------------------------------------------------
// GetProcessByIndex
//
// Returns a process from the its container
//---------------------------------------------------------------------------
CExeModuleInstance* CTaskManager::GetProcessByIndex(DWORD dwIndex)
{
	return static_cast<CExeModuleInstance*>(m_pProcesses->GetModule(dwIndex));
}

//---------------------------------------------------------------------------
//
// class CLoadedModules
//
//---------------------------------------------------------------------------
CLoadedModules::CLoadedModules(DWORD dwProcessId):
	CElements(),
	m_dwProcessId(dwProcessId)
{
	
}

CLoadedModules::~CLoadedModules()
{
	
}

//---------------------------------------------------------------------------
//
// class CRunningProcesses
//
//---------------------------------------------------------------------------
CRunningProcesses::CRunningProcesses():
	CElements()
{

}

CRunningProcesses::~CRunningProcesses()
{

}

//---------------------------------------------------------------------------
//
// class CPsapiHandler
//
//---------------------------------------------------------------------------
CPsapiHandler::CPsapiHandler(CRunningProcesses* pProcesses):
	CLibHandler(pProcesses),
	m_hModPSAPI(NULL),
    m_pfnEnumProcesses(NULL),
    m_pfnEnumProcessModules(NULL),
    m_pfnGetModuleFileNameExA(NULL)
{
	
}

CPsapiHandler::~CPsapiHandler()
{
	Finalize();
}

//---------------------------------------------------------------------------
// Initialize
//
//---------------------------------------------------------------------------
BOOL CPsapiHandler::Initialize()
{
	BOOL bResult = FALSE;
    //
    // Get to the 3 functions in PSAPI.DLL dynamically.  We can't
    // be sure that PSAPI.DLL has been installed
    //
    if (NULL == m_hModPSAPI)
        m_hModPSAPI = ::LoadLibrary("PSAPI.DLL");

    if (NULL != m_hModPSAPI)
	{
		m_pfnEnumProcesses = (PFNENUMPROCESSES)
			::GetProcAddress(m_hModPSAPI,"EnumProcesses");

		m_pfnEnumProcessModules = (PFNENUMPROCESSMODULES)
			::GetProcAddress(m_hModPSAPI, "EnumProcessModules");

		m_pfnGetModuleFileNameExA = (PFNGETMODULEFILENAMEEXA)
			::GetProcAddress(m_hModPSAPI, "GetModuleFileNameExA");

	}
	bResult = 
		m_pfnEnumProcesses
		&&  m_pfnEnumProcessModules
		&&  m_pfnGetModuleFileNameExA;

	return bResult;
}

//---------------------------------------------------------------------------
// Finalize
//
//---------------------------------------------------------------------------
void CPsapiHandler::Finalize()
{
	if (NULL != m_hModPSAPI)
		::FreeLibrary(m_hModPSAPI);
}

//---------------------------------------------------------------------------
// PopulateModules
//
// Populate the module list using PSAPI
//---------------------------------------------------------------------------
BOOL CPsapiHandler::PopulateModules(CModuleInstance* pProcess)
{
	BOOL   bResult = TRUE;
	CModuleInstance  *pDllModuleInstance = NULL;

    if (TRUE == Initialize())
	{
		DWORD pidArray[1024];
		DWORD cbNeeded;
		DWORD nProcesses;
		// EnumProcesses returns an array with process IDs
		if (m_pfnEnumProcesses(pidArray, sizeof(pidArray), &cbNeeded))
		{
			// Determine number of processes
			nProcesses = cbNeeded / sizeof(DWORD);  
			// Release the container
			pProcess->ReleaseModules();

			for (DWORD i = 0; i < nProcesses; i++)
			{
				HMODULE hModuleArray[1024];
				HANDLE  hProcess;
				DWORD   pid = pidArray[i];
				DWORD   nModules;
				// Let's open the process
				hProcess = ::OpenProcess(
					PROCESS_QUERY_INFORMATION |	PROCESS_VM_READ,
					FALSE, pid);

				if (!hProcess)
					continue;

				if (static_cast<CExeModuleInstance*>(pProcess)->Get_ProcessId() != pid)
				{
					::CloseHandle(hProcess);
					continue;
				}

				// EnumProcessModules function retrieves a handle for 
				// each module in the specified process. 
				if (!m_pfnEnumProcessModules(
						hProcess, hModuleArray,
						sizeof(hModuleArray), &cbNeeded))
				{
					::CloseHandle(hProcess);
					continue;
				}

				// Calculate number of modules in the process                                   
				nModules = cbNeeded / sizeof(hModuleArray[0]);
				for (DWORD j = 0; j < nModules; j++)
				{
					HMODULE hModule = hModuleArray[j];
					char szModuleName[MAX_PATH];
					m_pfnGetModuleFileNameExA(hProcess, hModule,
											szModuleName, sizeof(szModuleName));

					if (0 == j)   // First module is the EXE.  
					{
						// Do nothing.
					} // if
					else    // Not the first module.  It's a DLL
					{
						pDllModuleInstance = new CModuleInstance(
							szModuleName, hModule);
						pProcess->AddModule(pDllModuleInstance);
					} // else
				} // for
				::CloseHandle(hProcess);    // We're done with this process handle
			} // for
			bResult = TRUE;
		} // if
		else
		{
			bResult = FALSE;
		}
	} // if 
	else
	{
		bResult = FALSE;
	}
    return bResult;
}


//---------------------------------------------------------------------------
// PopulateProcesses
//
// Populate the process list using PSAPI
//---------------------------------------------------------------------------

BOOL CPsapiHandler::PopulateProcesses()
{
	BOOL   bResult = TRUE;
	CExeModuleInstance* pProcessInfo;
    
    if (TRUE == Initialize())
	{
		DWORD pidArray[1024];
		DWORD cbNeeded;
		DWORD nProcesses;
      
		if (m_pfnEnumProcesses(pidArray, sizeof(pidArray), &cbNeeded))
		{
			// Determine number of processes
			nProcesses = cbNeeded / sizeof(DWORD);  
			m_pProcesses->ReleaseAll();
			for (DWORD i = 0; i < nProcesses; i++)
			{
				HMODULE hModuleArray[1024];
				HANDLE hProcess;
				DWORD pid = pidArray[i];
				DWORD nModules;
				hProcess = OpenProcess(
					PROCESS_QUERY_INFORMATION |	PROCESS_VM_READ,
					FALSE, pid);
				if (!hProcess)
					continue;
				if (!m_pfnEnumProcessModules(hProcess, hModuleArray,
											sizeof(hModuleArray), &cbNeeded))
				{
					::CloseHandle(hProcess);
					continue;
				}
				// Calculate number of modules in the process                                   
				nModules = cbNeeded / sizeof(hModuleArray[0]);

				for (DWORD j = 0; j < nModules; j++)
				{
					HMODULE hModule = hModuleArray[j];
					char szModuleName[MAX_PATH];

					m_pfnGetModuleFileNameExA(hProcess, hModule,
											szModuleName, sizeof(szModuleName));

					if (0 == j)   // First module is the EXE.  Just add it to the map
					{
						pProcessInfo = new CExeModuleInstance(
							szModuleName, hModule, pid);
						m_pProcesses->Add(*pProcessInfo);
						pProcessInfo->PopulateModules(this);
						break;
					} // if
				} // for
				::CloseHandle(hProcess);    
			} // for
   
			bResult = TRUE;
		} // if
		else
		{
			bResult = FALSE;
		}
	} // if 
	else
	{
		bResult = FALSE;
	}
   
    return bResult;
}	


//---------------------------------------------------------------------------
//
// class CToolhelpHandler
//
//---------------------------------------------------------------------------
CToolhelpHandler::CToolhelpHandler(CRunningProcesses* pProcesses):
	CLibHandler(pProcesses)
{
	
}

CToolhelpHandler::~CToolhelpHandler()
{
	
}


//---------------------------------------------------------------------------
// Initialize
//
//---------------------------------------------------------------------------
BOOL CToolhelpHandler::Initialize()
{
	BOOL           bResult = FALSE;
	HINSTANCE      hInstLib;

	hInstLib = ::LoadLibraryA("Kernel32.DLL");
	if (NULL != hInstLib)
	{
		//
		// We must link to these functions of Kernel32.DLL explicitly. Otherwise 
		// a module using this code would fail to load under Windows NT, which does not 
		// have the Toolhelp32 functions in the Kernel32.
		//
		m_pfnCreateToolhelp32Snapshot = (PFNCREATETOOLHELP32SNAPSHOT) 
			::GetProcAddress(hInstLib, "CreateToolhelp32Snapshot");
		m_pfnProcess32First = (PFNPROCESS32FIRST)
			::GetProcAddress(hInstLib, "Process32First");
		m_pfnProcess32Next = (PFNPROCESS32NEXT)
			::GetProcAddress(hInstLib, "Process32Next");
		m_pfnModule32First = (PFNMODULE32FIRST)
			::GetProcAddress(hInstLib, "Module32First");
		m_pfnModule32Next = (PFNMODULE32NEXT)
			::GetProcAddress(hInstLib, "Module32Next");

		::FreeLibrary( hInstLib );

		bResult = m_pfnCreateToolhelp32Snapshot &&
			      m_pfnProcess32First &&
				  m_pfnProcess32Next &&
				  m_pfnModule32First &&
				  m_pfnModule32Next;
	} // if


	return bResult;
}

//---------------------------------------------------------------------------
// PopulateModules
//
// Populate the module list using ToolHelp32
//---------------------------------------------------------------------------
BOOL CToolhelpHandler::PopulateModules(CModuleInstance* pProcess)
{
	BOOL   bResult = TRUE;
	CModuleInstance  *pDllModuleInstance = NULL;
	HANDLE hSnapshot = INVALID_HANDLE_VALUE;

	hSnapshot = m_pfnCreateToolhelp32Snapshot(
		TH32CS_SNAPMODULE, 
		static_cast<CExeModuleInstance*>(pProcess)->Get_ProcessId());

	MODULEENTRY32 me = { sizeof(me) };

	for (BOOL fOk = ModuleFirst(hSnapshot, &me); fOk; fOk = ModuleNext(hSnapshot, &me)) 
	{	
		// We don't need to add to the list the process itself.
		// The module list should keep references to DLLs only
		if (0 != stricmp(pProcess->GetBaseName(), me.szModule))  
		{
			pDllModuleInstance = new CModuleInstance(me.szExePath, me.hModule);
			pProcess->AddModule(pDllModuleInstance);
		}
	} // for

	if (hSnapshot != INVALID_HANDLE_VALUE)
		::CloseHandle(hSnapshot);

	return bResult;
}

BOOL CToolhelpHandler::ModuleFirst(HANDLE hSnapshot, PMODULEENTRY32 pme) const
{
	return m_pfnModule32First(hSnapshot, pme);
}

BOOL CToolhelpHandler::ModuleNext(HANDLE hSnapshot, PMODULEENTRY32 pme) const
{
	return m_pfnModule32Next(hSnapshot, pme);
}


BOOL CToolhelpHandler::ProcessFirst(HANDLE hSnapshot, PROCESSENTRY32* pe32) const
{
	return m_pfnProcess32First(hSnapshot, pe32);
}

BOOL CToolhelpHandler::ProcessNext(HANDLE hSnapshot, PROCESSENTRY32* pe32) const
{
	return m_pfnProcess32Next(hSnapshot, pe32);
}

//---------------------------------------------------------------------------
// PopulateProcesses
//
// Populate the process list using Toolhelp
//---------------------------------------------------------------------------

BOOL CToolhelpHandler::PopulateProcesses()
{
	BOOL   bResult    = FALSE;
	CExeModuleInstance* pProcessInfo;
	HANDLE hSnapshot  = INVALID_HANDLE_VALUE;

	if (TRUE == Initialize())
	{
		hSnapshot = m_pfnCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		PROCESSENTRY32 pe32 = { sizeof(pe32) };

		for (BOOL fOk = ProcessFirst(hSnapshot, &pe32); fOk; fOk = ProcessNext(hSnapshot, &pe32)) 
		{
			pProcessInfo = new CExeModuleInstance(
				pe32.szExeFile, (HINSTANCE)pe32.th32ModuleID, pe32.th32ProcessID);
			m_pProcesses->Add(*pProcessInfo);
			pProcessInfo->PopulateModules(this);
		} // for

		if (hSnapshot != INVALID_HANDLE_VALUE)
			::CloseHandle(hSnapshot);

		bResult = TRUE;
	}

	return bResult;
}	

//---------------------------------------------------------------------------
//
// class CModuleList
//
//---------------------------------------------------------------------------

CModuleList::CModuleList()
{

}

CModuleList::~CModuleList()
{
	ReleaseAll();
}

//---------------------------------------------------------------------------
// Add
//
// Add new object to the container
//---------------------------------------------------------------------------
void CModuleList::Add(CModuleInstance &moduleInstance)
{
	push_back(&moduleInstance);
}

//---------------------------------------------------------------------------
// ReleaseAll
//
// Release all objects and clear the list
//---------------------------------------------------------------------------
void CModuleList::ReleaseAll()
{
	CModuleList::iterator itr;
	CModuleInstance *pModuleInstance;

	for (itr = begin(); itr != end(); ++itr)
	{
		pModuleInstance = *itr;
		delete pModuleInstance;
	} // for
	clear();
}

//---------------------------------------------------------------------------
// GetModule
//
// Return a module object by its index (Pascal-like style)
//---------------------------------------------------------------------------
CModuleInstance* CModuleList::GetModule(DWORD dwIndex) const
{
	return at(dwIndex);	
}

//---------------------------------------------------------------------------
// GetCount
//
// Return number of items in the container
//---------------------------------------------------------------------------
DWORD CModuleList::GetCount() const
{
	return size();
}

//---------------------------------------------------------------------------
//
// class CModuleInstance
//
//---------------------------------------------------------------------------
CModuleInstance::CModuleInstance(char *pszName, HMODULE hModule):
	m_pszName(NULL),
    m_hModule(NULL),
	m_pInternalList(NULL)
{
	Set_Name(pszName);
	Set_Module(hModule);
	
}

CModuleInstance::~CModuleInstance()
{
	delete m_pInternalList;

	if (NULL != m_pszName)
		delete [] m_pszName;	
}


void CModuleInstance::AddModule(CModuleInstance* pModuleInstance)
{
	if (NULL == m_pInternalList)
		m_pInternalList = new CModuleList();
	m_pInternalList->Add(*pModuleInstance);
}

void CModuleInstance::ReleaseModules()
{
	if (NULL != m_pInternalList)
		m_pInternalList->ReleaseAll();
}

char* CModuleInstance::Get_Name() const
{
	return m_pszName;
}

char* CModuleInstance::GetBaseName() const
{
	char *pdest;
	int  ch = '\\';
	// Search backward 
	pdest = strrchr(m_pszName, ch);
	if(pdest != NULL)
		return &pdest[1];
	else
		return m_pszName;
}

void CModuleInstance::Set_Name(char *pszName)
{
	if (NULL != m_pszName)
		delete [] m_pszName;	
	if ((NULL != pszName) && (strlen(pszName)))
	{
		m_pszName = new char[strlen(pszName) + 1];
		strcpy(m_pszName, pszName);
	}
	else
	{
		m_pszName = new char[strlen("\0") + 1];
		strcpy(m_pszName, "\0");
	}

}

HMODULE CModuleInstance::Get_Module() const
{
	return m_hModule;
}

void CModuleInstance::Set_Module(HMODULE module)
{
	m_hModule = module;
}


//---------------------------------------------------------------------------
//
// class CExeModuleInstance
//
//---------------------------------------------------------------------------

CExeModuleInstance::CExeModuleInstance(
	char *pszName, 
	HMODULE hModule,
	DWORD dwProcessId
	):
	CModuleInstance(pszName, hModule),
	m_dwProcessId(dwProcessId)
{
	
}

CExeModuleInstance::~CExeModuleInstance()
{
	
}

DWORD CExeModuleInstance::Get_ProcessId() const
{
	return m_dwProcessId;
}


BOOL CExeModuleInstance::PopulateModules(CLibHandler* pLibHandler)
{
	return pLibHandler->PopulateModules(this);
}


DWORD CExeModuleInstance::GetModuleCount() const
{
	
	return m_pInternalList ? m_pInternalList->GetCount() : 0;
}

CModuleInstance* CExeModuleInstance::GetModuleByIndex(DWORD dwIndex)
{
	return m_pInternalList ? m_pInternalList->GetModule(dwIndex) : NULL;
}