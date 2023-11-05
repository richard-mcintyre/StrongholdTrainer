; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInfoPage
LastTemplate=CPropertySheet
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StrongholdTrainer.h"

ClassCount=10
Class1=CTrainerApp
Class2=CTrainerDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_GRANARY_PAGE
Resource2=IDR_MAINFRAME
Resource3=IDD_ARMORY_PAGE
Class4=CStockpilePage
Resource4=IDD_MONEY_PAGE
Class5=CRawMaterialsPage
Resource5=IDD_RAWMATERIALS_PAGE
Class6=CGranaryPage
Resource6=IDD_STRONGHOLDTRAINER_DIALOG
Class7=CArmoryPage
Resource7=IDD_ABOUTBOX
Class8=CMoneyPage
Resource8=IDD_STOCKPILE_PAGE
Class9=CInfoPage
Class10=CTrainerSheet
Resource9=IDD_INFO_PAGE

[CLS:CTrainerApp]
Type=0
HeaderFile=StrongholdTrainer.h
ImplementationFile=StrongholdTrainer.cpp
Filter=N
LastObject=CTrainerApp

[CLS:CTrainerDlg]
Type=0
HeaderFile=TrainerDlg.h
ImplementationFile=TrainerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTrainerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TrainerDlg.h
ImplementationFile=TrainerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STRONGHOLDTRAINER_DIALOG]
Type=1
Class=CTrainerDlg
ControlCount=118
Control1=IDC_STATIC,button,1342177287
Control2=IDC_ICONWOOD,static,1350569987
Control3=IDC_WOOD_VAL,edit,1350568064
Control4=IDC_INCWOOD10,button,1342242816
Control5=IDC_INCWOOD100,button,1342242816
Control6=IDC_STATIC,static,1350569987
Control7=IDC_STONE_VAL,edit,1350568064
Control8=IDC_SETWOODZERO,button,1342242816
Control9=IDC_INCSTONE10,button,1342242816
Control10=IDC_INCSTONE100,button,1342242816
Control11=IDC_SETSTONEZERO,button,1342242816
Control12=IDC_STATIC,static,1350569987
Control13=IDC_IRON_VAL,edit,1350568064
Control14=IDC_INCIRON10,button,1342242816
Control15=IDC_INCIRON100,button,1342242816
Control16=IDC_SETIRONZERO,button,1342242816
Control17=IDC_STATIC,static,1350569987
Control18=IDC_PITCH_VAL,edit,1350568064
Control19=IDC_INCPITCH10,button,1342242816
Control20=IDC_INCPITCH100,button,1342242816
Control21=IDC_SETPITCHZERO,button,1342242816
Control22=IDC_STATIC,static,1350569987
Control23=IDC_ALE_VAL,edit,1350568064
Control24=IDC_INCALE10,button,1342242816
Control25=IDC_INCALE100,button,1342242816
Control26=IDC_SETALEZERO,button,1342242816
Control27=IDC_STATIC,button,1342177287
Control28=IDC_STATIC,static,1350569987
Control29=IDC_FLOUR_VAL,edit,1350568064
Control30=IDC_INCFLOUR10,button,1342242816
Control31=IDC_INCFLOUR100,button,1342242816
Control32=IDC_STATIC,static,1350569987
Control33=IDC_WHEAT_VAL,edit,1350568064
Control34=IDC_SETFLOURZERO,button,1342242816
Control35=IDC_INCWHEAT10,button,1342242816
Control36=IDC_INCWHEAT100,button,1342242816
Control37=IDC_SETWHEATZERO,button,1342242816
Control38=IDC_STATIC,static,1350569987
Control39=IDC_HOPS_VAL,edit,1350568064
Control40=IDC_INCHOPS10,button,1342242816
Control41=IDC_INCHOPS100,button,1342242816
Control42=IDC_SETHOPSZERO,button,1342242816
Control43=IDC_STATIC,static,1350569987
Control44=IDC_ANISKINS_VAL,edit,1350568064
Control45=IDC_INCANISKINS10,button,1342242816
Control46=IDC_INCANISKINS100,button,1342242816
Control47=IDC_SETANISKINSZERO,button,1342242816
Control48=IDC_STATIC,button,1342177287
Control49=IDC_STATIC,static,1350569987
Control50=IDC_MEAT_VAL,edit,1350568064
Control51=IDC_INCMEAT10,button,1342242816
Control52=IDC_INCMEAT100,button,1342242816
Control53=IDC_STATIC,static,1350569987
Control54=IDC_FRUIT_VAL,edit,1350568064
Control55=IDC_SETMEATZERO,button,1342242816
Control56=IDC_INCFRUIT10,button,1342242816
Control57=IDC_INCFRUIT100,button,1342242816
Control58=IDC_SETFRUITZERO,button,1342242816
Control59=IDC_STATIC,static,1350569987
Control60=IDC_BREAD_VAL,edit,1350568064
Control61=IDC_INCBREAD10,button,1342242816
Control62=IDC_INCBREAD100,button,1342242816
Control63=IDC_SETBREADZERO,button,1342242816
Control64=IDC_STATIC,static,1350569987
Control65=IDC_CHEESE_VAL,edit,1350568064
Control66=IDC_INCCHEESE10,button,1342242816
Control67=IDC_INCCHEESE100,button,1342242816
Control68=IDC_SETCHEESEZERO,button,1342242816
Control69=IDC_STATIC,button,1342177287
Control70=IDC_STATIC,static,1350569987
Control71=IDC_SWORD_VAL,edit,1350568064
Control72=IDC_INCSWORD10,button,1342242816
Control73=IDC_INCSWORD100,button,1342242816
Control74=IDC_STATIC,static,1350569987
Control75=IDC_CROSSBOW_VAL,edit,1350568064
Control76=IDC_SETSWORDZERO,button,1342242816
Control77=IDC_INCCROSSBOW10,button,1342242816
Control78=IDC_INCCROSSBOW100,button,1342242816
Control79=IDC_SETCROSSBOWZERO,button,1342242816
Control80=IDC_STATIC,static,1350569987
Control81=IDC_SPEAR_VAL,edit,1350568064
Control82=IDC_INCSPEAR10,button,1342242816
Control83=IDC_INCSPEAR100,button,1342242816
Control84=IDC_SETSPEARZERO,button,1342242816
Control85=IDC_STATIC,static,1350569987
Control86=IDC_BOW_VAL,edit,1350568064
Control87=IDC_INCBOW10,button,1342242816
Control88=IDC_INCBOW100,button,1342242816
Control89=IDC_SETBOWZERO,button,1342242816
Control90=IDC_STATIC,static,1350569987
Control91=IDC_PIKE_VAL,edit,1350568064
Control92=IDC_INCPIKE10,button,1342242816
Control93=IDC_INCPIKE100,button,1342242816
Control94=IDC_STATIC,static,1350569987
Control95=IDC_MACE_VAL,edit,1350568064
Control96=IDC_SETPIKEZERO,button,1342242816
Control97=IDC_INCMACE10,button,1342242816
Control98=IDC_INCMACE100,button,1342242816
Control99=IDC_SETMACEZERO,button,1342242816
Control100=IDC_STATIC,static,1350569987
Control101=IDC_LEATHERARM_VAL,edit,1350568064
Control102=IDC_INCLEATHERARM10,button,1342242816
Control103=IDC_INCLEATHERARM100,button,1342242816
Control104=IDC_SETLEATHERARMZERO,button,1342242816
Control105=IDC_STATIC,static,1350569987
Control106=IDC_METALARM_VAL,edit,1350568064
Control107=IDC_INCMETALARM10,button,1342242816
Control108=IDC_INCMETALARM100,button,1342242816
Control109=IDC_SETMETALARMZERO,button,1342242816
Control110=IDC_STATIC,button,1342177287
Control111=IDC_STATIC,static,1350569987
Control112=IDC_GOLD_VAL,edit,1350568064
Control113=IDC_INCGOLD10,button,1342242816
Control114=IDC_INCGOLD100,button,1342242816
Control115=IDC_SETGOLDZERO,button,1342242816
Control116=IDC_CHK_FREEZE_MONEY,button,1342242819
Control117=IDC_LOAD_GRANARY,button,1342242827
Control118=IDC_LOAD_ARMORY,button,1342242827

[DLG:IDD_STOCKPILE_PAGE]
Type=1
Class=CStockpilePage
ControlCount=25
Control1=IDC_ICONWOOD,static,1350569987
Control2=IDC_WOOD_VAL,edit,1350568064
Control3=IDC_INCWOOD10,button,1342242816
Control4=IDC_INCWOOD100,button,1342242816
Control5=IDC_STATIC,static,1350569987
Control6=IDC_STONE_VAL,edit,1350568064
Control7=IDC_SETWOODZERO,button,1342242816
Control8=IDC_INCSTONE10,button,1342242816
Control9=IDC_INCSTONE100,button,1342242816
Control10=IDC_SETSTONEZERO,button,1342242816
Control11=IDC_STATIC,static,1350569987
Control12=IDC_IRON_VAL,edit,1350568064
Control13=IDC_INCIRON10,button,1342242816
Control14=IDC_INCIRON100,button,1342242816
Control15=IDC_SETIRONZERO,button,1342242816
Control16=IDC_STATIC,static,1350569987
Control17=IDC_PITCH_VAL,edit,1350568064
Control18=IDC_INCPITCH10,button,1342242816
Control19=IDC_INCPITCH100,button,1342242816
Control20=IDC_SETPITCHZERO,button,1342242816
Control21=IDC_STATIC,static,1350569987
Control22=IDC_ALE_VAL,edit,1350568064
Control23=IDC_INCALE10,button,1342242816
Control24=IDC_INCALE100,button,1342242816
Control25=IDC_SETALEZERO,button,1342242816

[CLS:CStockpilePage]
Type=0
HeaderFile=StockpilePage.h
ImplementationFile=StockpilePage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CStockpilePage
VirtualFilter=idWC

[DLG:IDD_RAWMATERIALS_PAGE]
Type=1
Class=CRawMaterialsPage
ControlCount=20
Control1=IDC_STATIC,static,1350569987
Control2=IDC_FLOUR_VAL,edit,1350568064
Control3=IDC_INCFLOUR10,button,1342242816
Control4=IDC_INCFLOUR100,button,1342242816
Control5=IDC_STATIC,static,1350569987
Control6=IDC_WHEAT_VAL,edit,1350568064
Control7=IDC_SETFLOURZERO,button,1342242816
Control8=IDC_INCWHEAT10,button,1342242816
Control9=IDC_INCWHEAT100,button,1342242816
Control10=IDC_SETWHEATZERO,button,1342242816
Control11=IDC_STATIC,static,1350569987
Control12=IDC_HOPS_VAL,edit,1350568064
Control13=IDC_INCHOPS10,button,1342242816
Control14=IDC_INCHOPS100,button,1342242816
Control15=IDC_SETHOPSZERO,button,1342242816
Control16=IDC_STATIC,static,1350569987
Control17=IDC_ANISKINS_VAL,edit,1350568064
Control18=IDC_INCANISKINS10,button,1342242816
Control19=IDC_INCANISKINS100,button,1342242816
Control20=IDC_SETANISKINSZERO,button,1342242816

[CLS:CRawMaterialsPage]
Type=0
HeaderFile=RawMaterialsPage.h
ImplementationFile=RawMaterialsPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CRawMaterialsPage
VirtualFilter=idWC

[DLG:IDD_GRANARY_PAGE]
Type=1
Class=CGranaryPage
ControlCount=20
Control1=IDC_STATIC,static,1350569987
Control2=IDC_MEAT_VAL,edit,1350568064
Control3=IDC_INCMEAT10,button,1342242816
Control4=IDC_INCMEAT100,button,1342242816
Control5=IDC_STATIC,static,1350569987
Control6=IDC_FRUIT_VAL,edit,1350568064
Control7=IDC_SETMEATZERO,button,1342242816
Control8=IDC_INCFRUIT10,button,1342242816
Control9=IDC_INCFRUIT100,button,1342242816
Control10=IDC_SETFRUITZERO,button,1342242816
Control11=IDC_STATIC,static,1350569987
Control12=IDC_BREAD_VAL,edit,1350568064
Control13=IDC_INCBREAD10,button,1342242816
Control14=IDC_INCBREAD100,button,1342242816
Control15=IDC_SETBREADZERO,button,1342242816
Control16=IDC_STATIC,static,1350569987
Control17=IDC_CHEESE_VAL,edit,1350568064
Control18=IDC_INCCHEESE10,button,1342242816
Control19=IDC_INCCHEESE100,button,1342242816
Control20=IDC_SETCHEESEZERO,button,1342242816

[CLS:CGranaryPage]
Type=0
HeaderFile=GranaryPage.h
ImplementationFile=GranaryPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CGranaryPage
VirtualFilter=idWC

[DLG:IDD_ARMORY_PAGE]
Type=1
Class=CArmoryPage
ControlCount=40
Control1=IDC_STATIC,static,1350569987
Control2=IDC_SWORD_VAL,edit,1350568064
Control3=IDC_INCSWORD10,button,1342242816
Control4=IDC_INCSWORD100,button,1342242816
Control5=IDC_STATIC,static,1350569987
Control6=IDC_CROSSBOW_VAL,edit,1350568064
Control7=IDC_SETSWORDZERO,button,1342242816
Control8=IDC_INCCROSSBOW10,button,1342242816
Control9=IDC_INCCROSSBOW100,button,1342242816
Control10=IDC_SETCROSSBOWZERO,button,1342242816
Control11=IDC_STATIC,static,1350569987
Control12=IDC_SPEAR_VAL,edit,1350568064
Control13=IDC_INCSPEAR10,button,1342242816
Control14=IDC_INCSPEAR100,button,1342242816
Control15=IDC_SETSPEARZERO,button,1342242816
Control16=IDC_STATIC,static,1350569987
Control17=IDC_BOW_VAL,edit,1350568064
Control18=IDC_INCBOW10,button,1342242816
Control19=IDC_INCBOW100,button,1342242816
Control20=IDC_SETBOWZERO,button,1342242816
Control21=IDC_STATIC,static,1350569987
Control22=IDC_PIKE_VAL,edit,1350568064
Control23=IDC_INCPIKE10,button,1342242816
Control24=IDC_INCPIKE100,button,1342242816
Control25=IDC_STATIC,static,1350569987
Control26=IDC_MACE_VAL,edit,1350568064
Control27=IDC_SETPIKEZERO,button,1342242816
Control28=IDC_INCMACE10,button,1342242816
Control29=IDC_INCMACE100,button,1342242816
Control30=IDC_SETMACEZERO,button,1342242816
Control31=IDC_STATIC,static,1350569987
Control32=IDC_LEATHERARM_VAL,edit,1350568064
Control33=IDC_INCLEATHERARM10,button,1342242816
Control34=IDC_INCLEATHERARM100,button,1342242816
Control35=IDC_SETLEATHERARMZERO,button,1342242816
Control36=IDC_STATIC,static,1350569987
Control37=IDC_METALARM_VAL,edit,1350568064
Control38=IDC_INCMETALARM10,button,1342242816
Control39=IDC_INCMETALARM100,button,1342242816
Control40=IDC_SETMETALARMZERO,button,1342242816

[CLS:CArmoryPage]
Type=0
HeaderFile=ArmoryPage.h
ImplementationFile=ArmoryPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CArmoryPage
VirtualFilter=idWC

[DLG:IDD_MONEY_PAGE]
Type=1
Class=CMoneyPage
ControlCount=8
Control1=IDC_STATIC,static,1350569987
Control2=IDC_GOLD_VAL,edit,1350568064
Control3=IDC_INCGOLD10,button,1342242816
Control4=IDC_INCGOLD100,button,1342242816
Control5=IDC_SETGOLDZERO,button,1342242816
Control6=IDC_CHK_FREEZE_MONEY,button,1342242819
Control7=IDC_INCGOLD1000,button,1342242816
Control8=IDC_INCGOLD10000,button,1342242816

[CLS:CMoneyPage]
Type=0
HeaderFile=MoneyPage.h
ImplementationFile=MoneyPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CMoneyPage
VirtualFilter=idWC

[DLG:IDD_INFO_PAGE]
Type=1
Class=CInfoPage
ControlCount=10
Control1=IDC_STATIC,static,1342181390
Control2=IDC_LOAD_GRANARY,button,1342242827
Control3=IDC_LOAD_ARMORY,button,1342242827
Control4=IDC_STATIC,static,1342308353
Control5=IDC_STATIC,static,1342308353
Control6=IDC_GAME_STATUS,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_URL,static,1342308352
Control9=IDC_EMAIL,static,1342308352
Control10=IDC_PLAYER,combobox,1344340227

[CLS:CInfoPage]
Type=0
HeaderFile=InfoPage.h
ImplementationFile=InfoPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=IDC_PLAYER
VirtualFilter=idWC

[CLS:CTrainerSheet]
Type=0
HeaderFile=TrainerSheet.h
ImplementationFile=TrainerSheet.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CTrainerSheet
VirtualFilter=hWC

