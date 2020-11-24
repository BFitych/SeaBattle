#pragma once
#include <vector>
#include "Interface.h"

void fit_to_classic_coords(std::vector<std::pair<SHORT, SHORT>>& source, SHORT x, SHORT y);

bool ChooseShip(char chr, std::vector<std::vector<char>>& field_view,
	std::vector<std::pair<SHORT, SHORT>>& coords_safe, const unsigned x, const unsigned y, uint16_t OneXShips,
	uint16_t TwoXShips, uint16_t ThreeXShips, uint16_t FourXShips);

void PrintFieldView(std::vector<std::vector<char>>& field_view, SHORT x, SHORT Y);

void MovingCoreFunc(std::vector<std::pair<SHORT, SHORT>>& coords_safe, SHORT x, SHORT y,
	std::vector<std::vector<char>>& field_view, char symb);