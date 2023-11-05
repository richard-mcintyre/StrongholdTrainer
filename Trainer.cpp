
#include "stdafx.h"
#include "Trainer.h"
#include "ModuleInstance.h"

extern DWORD gdwPlayerOffset;

//#define GAMEVER_10

#define CRUSADER_OFFSET 0x23c52c

#ifdef STRONGHOLD_CRUSADER	// If we are compiling for crusader

// The table of items
GAME_TABLE gaTable[] = {	(void*)(0xB21BA4+CRUSADER_OFFSET),		// Wood
							(void*)(0xB21BA8+CRUSADER_OFFSET),		// Hops
							(void*)(0xB21BAC+CRUSADER_OFFSET),		// Stone
							(void*)(0xB21BB0+CRUSADER_OFFSET),		// Animal Skins
							(void*)(0xB21BB4+CRUSADER_OFFSET),		// Iron
							(void*)(0xB21BB8+CRUSADER_OFFSET),		// Pitch
							(void*)(0xB21BBC+CRUSADER_OFFSET),		// Unknown
							(void*)(0xB21BC0+CRUSADER_OFFSET),		// Wheat
							(void*)(0xB21BC4+CRUSADER_OFFSET),		// Bread
							(void*)(0xB21BC8+CRUSADER_OFFSET),		// Cheese
							(void*)(0xB21BCC+CRUSADER_OFFSET),		// Meat
							(void*)(0xB21BD0+CRUSADER_OFFSET),		// Fruit
							(void*)(0xB21BD4+CRUSADER_OFFSET),		// Ale
							(void*)(0xB21BD8+CRUSADER_OFFSET),		// Gold
							(void*)(0xB21BDC+CRUSADER_OFFSET),		// Flour
							(void*)(0xB21BE0+CRUSADER_OFFSET),		// Bow
							(void*)(0xB21BE4+CRUSADER_OFFSET),		// Cross Bow
							(void*)(0xB21BE8+CRUSADER_OFFSET),		// Spear
							(void*)(0xB21BEC+CRUSADER_OFFSET),		// Pike
							(void*)(0xB21BF0+CRUSADER_OFFSET),		// Mace
							(void*)(0xB21BF4+CRUSADER_OFFSET),		// Sword
							(void*)(0xB21BF8+CRUSADER_OFFSET),		// Leather Armor
							(void*)(0xB21BFC+CRUSADER_OFFSET),		// Metal Armor
							(void*)(0xB21C3C+CRUSADER_OFFSET)		// Current Gold							          
						}; 
/*
// The table of items
GAME_TABLE gaTable[] = {	(void*)(0xB21BA4+CRUSADER_OFFSET),		// Wood
							(void*)(0xB21BA8+CRUSADER_OFFSET),		// Hops
							(void*)(0xB21BAC+CRUSADER_OFFSET),		// Stone
							(void*)(0xB21BB0+CRUSADER_OFFSET),		// Animal Skins
							(void*)(0xB21BB4+CRUSADER_OFFSET),		// Iron
							(void*)(0xB21BB8+CRUSADER_OFFSET),		// Pitch
							(void*)(0xB21BBC+CRUSADER_OFFSET),		// Unknown
							(void*)(0xB21BC0+CRUSADER_OFFSET),		// Wheat
							(void*)(0xB21BC4+CRUSADER_OFFSET),		// Bread
							(void*)(0xB21BC8+CRUSADER_OFFSET),		// Cheese
							(void*)(0xB21BCC+CRUSADER_OFFSET),		// Meat
							(void*)(0xB21BD0+CRUSADER_OFFSET),		// Fruit
							(void*)(0xB21BD4+CRUSADER_OFFSET),		// Ale
							(void*)(0xB21BD8+CRUSADER_OFFSET),		// Gold
							(void*)(0xB21BDC+CRUSADER_OFFSET),		// Flour
							(void*)(0xB21BE0+CRUSADER_OFFSET),		// Bow
							(void*)(0xB21BE4+CRUSADER_OFFSET),		// Cross Bow
							(void*)(0xB21BE8+CRUSADER_OFFSET),		// Spear
							(void*)(0xB21BEC+CRUSADER_OFFSET),		// Pike
							(void*)(0xB21BF0+CRUSADER_OFFSET),		// Mace
							(void*)(0xB21BF4+CRUSADER_OFFSET),		// Sword
							(void*)(0xB21BF8+CRUSADER_OFFSET),		// Leather Armor
							(void*)(0xB21BFC+CRUSADER_OFFSET),		// Metal Armor
							(void*)(0xB21C3C+CRUSADER_OFFSET)		// Current Gold
						}; */
#elif defined(GAMEVER_10)
// The table of items
GAME_TABLE gaTable[] = {	(void*)(0xB21BA4+VER10_OFFSET),		// Wood
							(void*)(0xB21BA8+VER10_OFFSET),		// Hops
							(void*)(0xB21BAC+VER10_OFFSET),		// Stone
							(void*)(0xB21BB0+VER10_OFFSET),		// Animal Skins
							(void*)(0xB21BB4+VER10_OFFSET),		// Iron
							(void*)(0xB21BB8+VER10_OFFSET),		// Pitch
							(void*)(0xB21BBC+VER10_OFFSET),		// Unknown
							(void*)(0xB21BC0+VER10_OFFSET),		// Wheat
							(void*)(0xB21BC4+VER10_OFFSET),		// Bread
							(void*)(0xB21BC8+VER10_OFFSET),		// Cheese
							(void*)(0xB21BCC+VER10_OFFSET),		// Meat
							(void*)(0xB21BD0+VER10_OFFSET),		// Fruit
							(void*)(0xB21BD4+VER10_OFFSET),		// Ale
							(void*)(0xB21BD8+VER10_OFFSET),		// Gold
							(void*)(0xB21BDC+VER10_OFFSET),		// Flour
							(void*)(0xB21BE0+VER10_OFFSET),		// Bow
							(void*)(0xB21BE4+VER10_OFFSET),		// Cross Bow
							(void*)(0xB21BE8+VER10_OFFSET),		// Spear
							(void*)(0xB21BEC+VER10_OFFSET),		// Pike
							(void*)(0xB21BF0+VER10_OFFSET),		// Mace
							(void*)(0xB21BF4+VER10_OFFSET),		// Sword
							(void*)(0xB21BF8+VER10_OFFSET),		// Leather Armor
							(void*)(0xB21BFC+VER10_OFFSET),		// Metal Armor
							(void*)(0xB21C3C+VER10_OFFSET)		// Current Gold
						}; 
#else
// The table of items
GAME_TABLE gaTable[] = {	(void*)0xB21BA4,		// Wood
							(void*)0xB21BA8,		// Hops
							(void*)0xB21BAC,		// Stone
							(void*)0xB21BB0,		// Animal Skins
							(void*)0xB21BB4,		// Iron
							(void*)0xB21BB8,		// Pitch
							(void*)0xB21BBC,		// Unknown
							(void*)0xB21BC0,		// Wheat
							(void*)0xB21BC4,		// Bread
							(void*)0xB21BC8,		// Cheese
							(void*)0xB21BCC,		// Meat
							(void*)0xB21BD0,		// Fruit
							(void*)0xB21BD4,		// Ale
							(void*)0xB21BD8,		// Gold
							(void*)0xB21BDC,		// Flour
							(void*)0xB21BE0,		// Bow
							(void*)0xB21BE4,		// Cross Bow
							(void*)0xB21BE8,		// Spear
							(void*)0xB21BEC,		// Pike
							(void*)0xB21BF0,		// Mace
							(void*)0xB21BF4,		// Sword
							(void*)0xB21BF8,		// Leather Armor
							(void*)0xB21BFC,		// Metal Armor
							(void*)0xB21C3C		// Current Gold
						}; 
#endif


CTrainer::CTrainer( )
{
	m_hProcess = NULL;
	m_iWoodVal = 0;
	m_iHopsVal = 0;
	m_iStoneVal = 0;
	m_iAniSkinsVal = 0;
	m_iIronVal = 0;
	m_iPitchVal = 0;
	//m_iUnknownVal = 0;
	m_iWheatVal = 0;
	m_iBreadVal = 0;
	m_iCheeseVal = 0;
	m_iMeatVal = 0;
	m_iFruitVal = 0;
	m_iAleVal = 0;
	//m_iGoldVal = 0;
	m_iFlourVal = 0;
	m_iBowVal = 0;
	m_iCrossBowVal = 0;
	m_iSpearVal = 0;
	m_iPikeVal = 0;
	m_iMaceVal = 0;
	m_iSwordVal = 0;
	m_iLeatherArmorVal = 0;
	m_iMetalArmorVal = 0;
	m_iCurGoldVal = 0;
}

BOOL CTrainer::OpenProcess( )
{
	// If we havent found stronghold yet
	if( m_hProcess == NULL )
	{
		// See if we can get the process id of it
#ifdef STRONGHOLD_CRUSADER
		char pszImageName[] = "Stronghold Crusader";
#else
		char pszImageName[] = "Stronghold";
#endif
		CTaskManager        taskManager;
		CExeModuleInstance  *pProcess;
		int iPID = -1;

		// Retrieves information about processes and modules. 
		// The taskManager dynamically decides whether to use ToolHelp library or PSAPI
		taskManager.Populate();

		// Enumerates all processes
		for (unsigned i = 0; i < taskManager.GetProcessCount(); i++)
		{
			pProcess = taskManager.GetProcessByIndex(i);

			char fname[_MAX_FNAME];
			_splitpath( pProcess->Get_Name(), NULL, NULL, fname, NULL );

			if( stricmp( fname, pszImageName ) == 0 )
			{
				iPID = pProcess->Get_ProcessId(); 
				break;
			}
		}

		// Now try and open the process
		if( iPID != -1 )
		{
			m_hProcess = ::OpenProcess( PROCESS_ALL_ACCESS,	// Access flags
										FALSE,	// Inheritable
										iPID );
		}

		if( m_hProcess == NULL )
			return FALSE;
	}

	return TRUE;
}

void CTrainer::GetValues( )
{
	m_iWoodVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_WOOD].pAddr + gdwPlayerOffset) );
	m_iHopsVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_HOPS].pAddr + gdwPlayerOffset) );
	m_iStoneVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_STONE].pAddr + gdwPlayerOffset) );	
	m_iAniSkinsVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_ANI_SKINS].pAddr + gdwPlayerOffset) );	
	m_iIronVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_IRON].pAddr + gdwPlayerOffset) );
	m_iPitchVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_PITCH].pAddr + gdwPlayerOffset) );
	//m_iUnknownVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_UNKNOWN].pAddr + gdwPlayerOffset) );
	m_iWheatVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_WHEAT].pAddr + gdwPlayerOffset) );
	m_iBreadVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_BREAD].pAddr + gdwPlayerOffset) );
	m_iCheeseVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_CHEESE].pAddr + gdwPlayerOffset) );
	m_iMeatVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_MEAT].pAddr + gdwPlayerOffset) );
	m_iFruitVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_FRUIT].pAddr + gdwPlayerOffset) );
	m_iAleVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_ALE].pAddr + gdwPlayerOffset) );
	//m_iGoldVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_GOLD].pAddr + gdwPlayerOffset) );
	m_iFlourVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_FLOUR].pAddr + gdwPlayerOffset) );
	m_iBowVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_BOW].pAddr + gdwPlayerOffset) );
	m_iCrossBowVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_CROSS_BOW].pAddr + gdwPlayerOffset) );
	m_iSpearVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_SPEAR].pAddr + gdwPlayerOffset) );
	m_iPikeVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_PIKE].pAddr + gdwPlayerOffset) );
	m_iMaceVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_MACE].pAddr + gdwPlayerOffset) );
	m_iSwordVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_SWORD].pAddr + gdwPlayerOffset) );
	m_iLeatherArmorVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_LEATHER_ARMOR].pAddr + gdwPlayerOffset) );
	m_iMetalArmorVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_METAL_ARMOR].pAddr + gdwPlayerOffset) );
	m_iCurGoldVal = GetAddrValue( (void*)((DWORD)gaTable[IDX_GOLD_CURRENT].pAddr + gdwPlayerOffset) );
}

void CTrainer::SetValues()
{
	SetAddrValue( (void*)((DWORD)gaTable[IDX_WOOD].pAddr + gdwPlayerOffset), m_iWoodVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_HOPS].pAddr + gdwPlayerOffset), m_iHopsVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_STONE].pAddr + gdwPlayerOffset), m_iStoneVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_ANI_SKINS].pAddr + gdwPlayerOffset), m_iAniSkinsVal );	
	SetAddrValue( (void*)((DWORD)gaTable[IDX_IRON].pAddr + gdwPlayerOffset), m_iIronVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_PITCH].pAddr + gdwPlayerOffset), m_iPitchVal );
	//SetAddrValue( (void*)((DWORD)gaTable[IDX_UNKNOWN].pAddr + gdwPlayerOffset), m_iUnknownVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_WHEAT].pAddr + gdwPlayerOffset), m_iWheatVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_BREAD].pAddr + gdwPlayerOffset), m_iBreadVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_CHEESE].pAddr + gdwPlayerOffset), m_iCheeseVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_MEAT].pAddr + gdwPlayerOffset), m_iMeatVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_FRUIT].pAddr + gdwPlayerOffset), m_iFruitVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_ALE].pAddr + gdwPlayerOffset), m_iAleVal );
	//SetAddrValue( (void*)((DWORD)gaTable[IDX_GOLD].pAddr + gdwPlayerOffset), m_iGoldVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_FLOUR].pAddr + gdwPlayerOffset), m_iFlourVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_BOW].pAddr + gdwPlayerOffset), m_iBowVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_CROSS_BOW].pAddr + gdwPlayerOffset), m_iCrossBowVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_SPEAR].pAddr + gdwPlayerOffset), m_iSpearVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_PIKE].pAddr + gdwPlayerOffset), m_iPikeVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_MACE].pAddr + gdwPlayerOffset), m_iMaceVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_SWORD].pAddr + gdwPlayerOffset), m_iSwordVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_LEATHER_ARMOR].pAddr + gdwPlayerOffset), m_iLeatherArmorVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_METAL_ARMOR].pAddr + gdwPlayerOffset), m_iMetalArmorVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_GOLD_CURRENT].pAddr + gdwPlayerOffset), m_iCurGoldVal );
}

int CTrainer::GetAddrValue(void *pAddr)
{
	int iValue;
	DWORD dwBytesRead;

	if( m_hProcess == NULL )
		return 0;

	BOOL bResult = ReadProcessMemory( m_hProcess, pAddr, &iValue, sizeof(int), &dwBytesRead );

	if( bResult == FALSE )
		iValue = 0;

	return iValue;
}

void CTrainer::SetAddrValue(void *pAddr, int iValue)
{
	DWORD dwBytesWritten;

	if( m_hProcess == NULL )
		return;

	BOOL bResult = WriteProcessMemory( m_hProcess, pAddr, &iValue, sizeof(int), &dwBytesWritten );
}

void CTrainer::SetWoodValue( int iValue )
{	m_iWoodVal = iValue;		SetValues( );	}
void CTrainer::SetStoneValue( int iValue )
{	m_iStoneVal = iValue;		SetValues( );	}
void CTrainer::SetIronValue( int iValue )
{	m_iIronVal = iValue;		SetValues( );	}
void CTrainer::SetPitchValue( int iValue )
{	m_iPitchVal = iValue;		SetValues( );	}
void CTrainer::SetAleValue( int iValue )
{	m_iAleVal = iValue;		SetValues( );	}
void CTrainer::SetFlourValue( int iValue )
{	m_iFlourVal = iValue;		SetValues( );	}
void CTrainer::SetWheatValue( int iValue )
{	m_iWheatVal = iValue;		SetValues( );	}
void CTrainer::SetHopsValue( int iValue )
{	m_iHopsVal = iValue;		SetValues( );	}
void CTrainer::SetAniSkinsValue( int iValue )
{	m_iAniSkinsVal = iValue;		SetValues( );	}
void CTrainer::SetMeatValue( int iValue )
{	m_iMeatVal = iValue;		SetValues( );	}
void CTrainer::SetFruitValue( int iValue )
{	m_iFruitVal = iValue;		SetValues( );	}
void CTrainer::SetBreadValue( int iValue )
{	m_iBreadVal = iValue;		SetValues( );	}
void CTrainer::SetCheeseValue( int iValue )
{	m_iCheeseVal = iValue;		SetValues( );	}
void CTrainer::SetSwordValue( int iValue )
{	m_iSwordVal = iValue;		SetValues( );	}
void CTrainer::SetBowValue( int iValue )
{	m_iBowVal = iValue;		SetValues( );	}
void CTrainer::SetCrossBowValue( int iValue )
{	m_iCrossBowVal = iValue;		SetValues( );	}
void CTrainer::SetSpearValue( int iValue )
{	m_iSpearVal = iValue;		SetValues( );	}
void CTrainer::SetPikeValue( int iValue )
{	m_iPikeVal = iValue;		SetValues( );	}
void CTrainer::SetMaceValue( int iValue )
{	m_iMaceVal = iValue;		SetValues( );	}
void CTrainer::SetLeatherArmorValue( int iValue )
{	m_iLeatherArmorVal = iValue;		SetValues( );	}
void CTrainer::SetMetalArmorValue( int iValue )
{	m_iMetalArmorVal = iValue;		SetValues( );	}
void CTrainer::SetCurGoldValue( int iValue )
{	m_iCurGoldVal = iValue;		SetValues( );	}

void CTrainer::OnLoadGranary() 
{
	if( m_hProcess == NULL )
		return;

	m_iMeatVal += 62;
	m_iFruitVal += 62;
	m_iBreadVal += 63;
	m_iCheeseVal += 63;

	SetAddrValue( (void*)((DWORD)gaTable[IDX_MEAT].pAddr + gdwPlayerOffset), m_iMeatVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_FRUIT].pAddr + gdwPlayerOffset), m_iFruitVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_BREAD].pAddr + gdwPlayerOffset), m_iBreadVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_CHEESE].pAddr + gdwPlayerOffset), m_iCheeseVal );

	GetValues( );
}

void CTrainer::OnLoadArmory() 
{
	if( m_hProcess == NULL )
		return;
	
	m_iSwordVal += 6;
	m_iBowVal += 6;
	m_iCrossBowVal += 6;
	m_iSpearVal += 6;
	m_iPikeVal += 6;
	m_iMaceVal += 6;
	m_iLeatherArmorVal += 7;
	m_iMetalArmorVal += 7;
	
	SetAddrValue( (void*)((DWORD)gaTable[IDX_SWORD].pAddr + gdwPlayerOffset), m_iSwordVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_BOW].pAddr + gdwPlayerOffset), m_iBowVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_CROSS_BOW].pAddr + gdwPlayerOffset), m_iCrossBowVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_SPEAR].pAddr + gdwPlayerOffset), m_iSpearVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_PIKE].pAddr + gdwPlayerOffset), m_iPikeVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_MACE].pAddr + gdwPlayerOffset), m_iMaceVal );	
	SetAddrValue( (void*)((DWORD)gaTable[IDX_LEATHER_ARMOR].pAddr + gdwPlayerOffset), m_iLeatherArmorVal );
	SetAddrValue( (void*)((DWORD)gaTable[IDX_METAL_ARMOR].pAddr + gdwPlayerOffset), m_iMetalArmorVal );

	GetValues( );
}



