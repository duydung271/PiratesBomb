#pragma once
#include "../GameManager/ResourceManager.h"
class DataGamePlay:public CSingleton<DataGamePlay>
{
public:
	DataGamePlay();
	~DataGamePlay();
	void CountBatBorn();
	void CountBatDead();
	int getNumBatDead();
	int getNumBatBorn();
	bool BatBornEqualDead();

	void CountBeeBorn();
	void CountBeeDead();
	int getNumBeeDead();
	int getNumBeeBorn();
	bool BeeBornEqualDead();

	void CountBlueBirdBorn();
	void CountBlueBirdDead();
	int getNumBlueBirdDead();
	int getNumBlueBirdBorn();
	bool BlueBirdBornEqualDead();

	void CountSunDragonBorn();
	void CountSunDragonDead();
	int getNumSunDragonDead();
	int getNumSunDragonBorn();
	bool SunDragonBornEqualDead();

	void Reset();


private:
	int m_NumBatBorn;
	int m_NumBatDead;

	int m_NumBeeBorn;
	int m_NumBeeDead;

	int m_NumBlueBirdBorn;
	int m_NumBlueBirdDead;

	int m_NumSunDragonBorn;
	int m_NumSunDragonDead;
};