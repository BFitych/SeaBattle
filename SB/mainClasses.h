#pragma once
#include <map>
#include <algorithm>
#include <thread>
#include <functional>
#include <future>

#include "CheckersAndGenerators.h"
#include "Interface.h"
#include "SettingMode_2_0.h"

using coordsafe = std::map<uint16_t, std::vector<std::pair<bool, std::pair<uint16_t, uint16_t>>>>;

class YourBattlefield
{
public:
	YourBattlefield();
	bool SetOneCoords(const uint16_t X, const uint16_t Y, uint16_t& sc);
	bool SetTwoCoords(const uint16_t Xs, const uint16_t Ys, const uint16_t Xf, const uint16_t Yf, uint16_t& sc);
	bool SetThreeCoords(const uint16_t Xs, const uint16_t Ys, const uint16_t Xf, const uint16_t Yf, uint16_t& sc);
	bool SetFourCoords(const uint16_t Xs, const uint16_t Ys, const uint16_t Xf, const uint16_t Yf, uint16_t& sc);

	field GetField();
	coordsafe GetCoordinates();

	bool ComputerShoot();

	bool Shoot();

	void SetShipsCoords();
	void SetShipCoords_2_0();

protected:
	uint16_t OneXShips;
	uint16_t TwoXShips;
	uint16_t ThreeXShips;
	uint16_t FourXShips;
	field Bfield;
	field Gfield;
	coordsafe coords;
	RandomGenerator rang;
	uint16_t destroyed_count;
};

class EnemyBattlefield : public YourBattlefield
{
public:
	EnemyBattlefield();
	void GenRandField(char difficulty);
};