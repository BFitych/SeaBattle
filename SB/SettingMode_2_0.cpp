#include "SettingMode_2_0.h"

bool ChooseShip(char chr, std::vector<std::vector<char>>& field_view,
	std::vector<std::pair<SHORT, SHORT>>& coords_safe, const unsigned x, const unsigned y, uint16_t OneXShips, 
	uint16_t TwoXShips, uint16_t ThreeXShips , uint16_t FourXShips)
{
	if (chr == '1')
	{
		if (OneXShips != 0) {
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << field_view[item.second - y][item.first - x];
			}
			coords_safe.clear();
			coords_safe.push_back({ 56,13 });
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << '#';
			}
			return true;
		}
		else {
			SetCursor(37, 21);
			std::cout << "You ships with one deck counter is zero";
		}
	}
	else if (chr == '2') {
		if (TwoXShips != 0) {
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << field_view[item.second - y][item.first - x];
			}
			coords_safe.clear();
			coords_safe.push_back({ 56,12 });
			coords_safe.push_back({ 56,13 });
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << '#';
			}
			return true;
		}
		else {
			SetCursor(36, 21);
			std::cout << "You ships with two decks counter is zero";
		}
	}
	
	
	else if (chr == '3') {
		if (ThreeXShips != 0) {
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << field_view[item.second - y][item.first - x];
			}
			coords_safe.clear();
			coords_safe.push_back({ 56,12 });
			coords_safe.push_back({ 56,13 });
			coords_safe.push_back({ 56,14 });
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << '#';
			}
			return true;
		}
		else {
			SetCursor(36, 21);
			std::cout << "You ships with three decks counter is zero";
		}
	}
	else if (chr == '4') {
		if (FourXShips != 0) {
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << field_view[item.second - y][item.first - x];
			}
			coords_safe.clear();
			coords_safe.push_back({ 56,12 });
			coords_safe.push_back({ 56,13 });
			coords_safe.push_back({ 56,14 });
			coords_safe.push_back({ 56,15 });
			for (auto& item : coords_safe)
			{
				SetCursor(item.first, item.second);
				std::cout << '#';
			}
			return true;
		}
		else {
			SetCursor(36, 21);
			std::cout << "You ships with four decks counter is zero";
		}
	}
	return false;
}

void fit_to_classic_coords(std::vector<std::pair<SHORT, SHORT>>& source, SHORT x, SHORT y)
{
	if (source.size() > 1 && source[1].first - source[0].first == 1)
	{
		source[0].first -= x;
		source[0].second -= y;
		for (uint16_t i = 1; i < source.size(); ++i)
		{
			source[i].first -= (x + 2 + unsigned(source[i].first / 2));
			source[i].second -= (y + 2);
		}
	}
	else
	{
		for (auto& item : source)
		{
			item.first -= (x + 2);
			item.first -= unsigned(item.first / 2);
			item.second -= (y + 1);
		}
	}
}

void PrintFieldView(std::vector<std::vector<char>>& field_view, SHORT x, SHORT y)
{
	for (auto item : field_view) {

		for (auto itm : item)
			std::cout << itm;
		std::cout << '\n';
		++y;
		SetCursor(x, y);
	}
}

void MovingCoreFunc(std::vector<std::pair<SHORT, SHORT>>& coords_safe, SHORT x, SHORT y, std::vector<std::vector<char>>& field_view, char symb)
{
	size_t x_step = 2;
	if (field_view.size() == 11)
	{
		x_step = 1;
	}
	if (GetAsyncKeyState(0x44))
	{
		bool checker = true;
		for (auto& item : coords_safe)
		{
			if (item.first > (x + 20))
			{
				checker = false;
			}
		}
		if (checker)
		{
			for (auto item = coords_safe.rbegin(); item != coords_safe.rend(); ++item) {
				SetCursor(item->first, item->second);
				std::cout << field_view[item->second - y][item->first - x];
				item->first += x_step;
				SetCursor(item->first, item->second);
				std::cout << symb;
			}
		}
	}
	else if (GetAsyncKeyState(0x41))
	{
		bool checker = true;
		for (auto& item : coords_safe)
		{
			if (item.first < x + 4)
			{
				checker = false;
			}
		}
		if (checker) {
			for (auto& item : coords_safe) {
				SetCursor(item.first, item.second);
				std::cout << field_view[item.second - y][item.first - x];
				item.first -= x_step;
				SetCursor(item.first, item.second);
				std::cout << symb;
			}
		}
	}
	else if (GetAsyncKeyState(0x57))
	{
		bool checker = true;
		for (auto& item : coords_safe)
		{
			if (item.second < (y + 3))
			{
				checker = false;
			}
		}
		if (checker) {
			for (auto& item : coords_safe) {
				SetCursor(item.first, item.second);
				std::cout << field_view[item.second - y][item.first - x];
				--item.second;
				SetCursor(item.first, item.second);
				std::cout << symb;
			}
		}
	}
	else if (GetAsyncKeyState(0x53))
	{
		
		bool checker = true;
		for (auto& item : coords_safe)
		{
			if (item.second > (y + 10))
			{
				checker = false;
			}
		}
		if (checker)
		{
			for (auto item = coords_safe.rbegin(); item != coords_safe.rend(); ++item) {
				SetCursor(item->first, item->second);
				std::cout << field_view[item->second - y][item->first - x];
				++item->second;
				SetCursor(item->first, item->second);
				std::cout << symb;
			}
		}


	}
	SetCursor(30, 21);
	std::cout << "                                                                                 ";
}