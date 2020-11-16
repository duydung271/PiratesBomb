#include "DataGamePlay.h"

DataGamePlay::DataGamePlay()
{
	m_NumBatBorn = 0;
	m_NumBatDead = 0;

	m_NumBeeBorn = 0;
	m_NumBeeDead = 0;

	m_NumBlueBirdBorn = 0;
	m_NumBlueBirdDead = 0;

	m_NumSunDragonBorn = 0;
	m_NumSunDragonDead = 0;
}

DataGamePlay::~DataGamePlay()
{
}

void DataGamePlay::CountBatBorn()
{
	m_NumBatBorn++;
}

void DataGamePlay::CountBatDead()
{
	m_NumBatDead++;
}

int DataGamePlay::getNumBatDead()
{
	return m_NumBatDead;
}

int DataGamePlay::getNumBatBorn()
{
	return m_NumBatBorn;
}

bool DataGamePlay::BatBornEqualDead()
{
	return m_NumBatBorn==m_NumBatDead;
}

void DataGamePlay::CountBeeBorn()
{
	m_NumBeeBorn++;
}

void DataGamePlay::CountBeeDead()
{
	m_NumBeeDead++;
}

int DataGamePlay::getNumBeeDead()
{
	return m_NumBeeDead;
}

int DataGamePlay::getNumBeeBorn()
{
	return m_NumBeeBorn;
}

bool DataGamePlay::BeeBornEqualDead()
{
	return m_NumBeeBorn==m_NumBeeDead;
}

void DataGamePlay::CountBlueBirdBorn()
{
	m_NumBlueBirdBorn++;
}

void DataGamePlay::CountBlueBirdDead()
{
	m_NumBlueBirdDead++;
}

int DataGamePlay::getNumBlueBirdDead()
{
	return m_NumBlueBirdDead;
}

int DataGamePlay::getNumBlueBirdBorn()
{
	return m_NumBlueBirdBorn;
}

bool DataGamePlay::BlueBirdBornEqualDead()
{
	return m_NumBlueBirdBorn==m_NumBlueBirdDead;
}

void DataGamePlay::CountSunDragonBorn()
{
	m_NumSunDragonBorn++;
}

void DataGamePlay::CountSunDragonDead()
{
	m_NumSunDragonDead++;
}

int DataGamePlay::getNumSunDragonDead()
{
	return m_NumSunDragonDead;
}

int DataGamePlay::getNumSunDragonBorn()
{
	return m_NumSunDragonBorn;
}

bool DataGamePlay::SunDragonBornEqualDead()
{
	return m_NumSunDragonBorn==m_NumSunDragonDead;
}

void DataGamePlay::Reset()
{
	m_NumBatBorn = 0;
	m_NumBatDead = 0;

	m_NumBeeBorn = 0;
	m_NumBeeDead = 0;

	m_NumBlueBirdBorn = 0;
	m_NumBlueBirdDead = 0;

	m_NumSunDragonBorn = 0;
	m_NumSunDragonDead = 0;
}
