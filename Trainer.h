
#ifndef TRAINER_H
#define TRAINER_H

typedef struct
{
	void*	pAddr;		// Address of item
} GAME_TABLE;


#define VER10_OFFSET	(-0x2840)

#define IDX_WOOD		0
#define IDX_HOPS		1
#define IDX_STONE		2
#define IDX_ANI_SKINS	3
#define IDX_IRON		4
#define IDX_PITCH		5
#define IDX_UNKNOWN		6
#define IDX_WHEAT		7
#define IDX_BREAD		8
#define IDX_CHEESE		9
#define IDX_MEAT		10
#define IDX_FRUIT		11
#define IDX_ALE			12
#define IDX_GOLD		13
#define IDX_FLOUR		14
#define IDX_BOW			15
#define IDX_CROSS_BOW	16
#define IDX_SPEAR		17
#define IDX_PIKE		18
#define IDX_MACE		19
#define IDX_SWORD		20
#define IDX_LEATHER_ARMOR	21
#define IDX_METAL_ARMOR		22
#define IDX_GOLD_CURRENT	23

#define IDX_LAST_INDEX	23


class CTrainer
{
public:
	CTrainer( );

public:
	HANDLE	m_hProcess;
	int m_iWoodVal;
	int m_iHopsVal;
	int m_iStoneVal;
	int m_iAniSkinsVal;
	int m_iIronVal;
	int m_iPitchVal;
	//int m_iUnknownVal;
	int m_iWheatVal;
	int m_iBreadVal;
	int m_iCheeseVal;
	int m_iMeatVal;
	int m_iFruitVal;
	int m_iAleVal;
	//int m_iGoldVal;
	int m_iFlourVal;
	int m_iBowVal;
	int m_iCrossBowVal;
	int m_iSpearVal;
	int m_iPikeVal;
	int m_iMaceVal;
	int m_iSwordVal;
	int m_iLeatherArmorVal;
	int m_iMetalArmorVal;
	int m_iCurGoldVal;

public:
	BOOL	OpenProcess( );
	void	GetValues( );
	void	SetValues();
	int		GetAddrValue(void *pAddr);
	void	SetAddrValue(void *pAddr, int iValue);

	void SetWoodValue( int iValue );
	void SetStoneValue( int iValue );
	void SetIronValue( int iValue );
	void SetPitchValue( int iValue );
	void SetAleValue( int iValue );
	void SetFlourValue( int iValue );
	void SetWheatValue( int iValue );
	void SetHopsValue( int iValue );
	void SetAniSkinsValue( int iValue );
	void SetMeatValue( int iValue );
	void SetFruitValue( int iValue );
	void SetBreadValue( int iValue );
	void SetCheeseValue( int iValue );
	void SetSwordValue( int iValue );
	void SetBowValue( int iValue );
	void SetCrossBowValue( int iValue );
	void SetSpearValue( int iValue );
	void SetPikeValue( int iValue );
	void SetMaceValue( int iValue );
	void SetLeatherArmorValue( int iValue );
	void SetMetalArmorValue( int iValue );
	void SetCurGoldValue( int iValue );

	void OnLoadArmory();
	void OnLoadGranary(); 

};

#endif	// TRAINER_H






