#include "mainClasses.h"

 YourBattlefield:: YourBattlefield()
	{
		Bfield = GenField(11);
		Gfield = GenField(12);
		OneXShips = 4;
		TwoXShips = 3;
		ThreeXShips = 2;
		FourXShips = 1;
		destroyed_count = 0;

	}
	bool YourBattlefield::SetOneCoords(const uint16_t X, const uint16_t Y, uint16_t& sc)
	{
		bool ret = true;
		if (X >= 1 && X <= 10 && Y >= 1 && X <= 10) {
			bool chkr = CheckNerbyCoord(Bfield, X - 1, Y - 1);
			if (chkr == false) { Bfield[Y][X] = '#'; --OneXShips; coords[sc].push_back(std::make_pair(0, std::make_pair(X, Y))); ++sc; }
			else { ret = false; }
		}
		else { ret = false; }
		return ret;
	}
	bool YourBattlefield::SetTwoCoords(const uint16_t Xs, const uint16_t Ys, const uint16_t Xf, const uint16_t Yf, uint16_t& sc)
	{
		bool ret = true;
		if (Xs == Xf && Yf - Ys == 1)
		{
			bool checker = CheckNerbyCoord(Bfield, Xs - 1, Ys - 1) || CheckNerbyCoord(Bfield, Xf - 1, Yf - 1);
			if (checker) { ret = false; }
			else {
				Bfield[Ys][Xs] = '#', Bfield[Yf][Xf] = '#'; --TwoXShips;
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xf, Yf)));
				sc++;
			}
		}
		else if (Ys == Yf && Xf - Xs == 1)
		{
			bool checker = CheckNerbyCoord(Bfield, Xs - 1, Ys - 1) || CheckNerbyCoord(Bfield, Xf - 1, Yf - 1);
			if (checker) { ret = false; }
			else {
				Bfield[Ys][Xs] = '#', Bfield[Yf][Xf] = '#'; --TwoXShips;
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xf, Yf)));
				sc++;
			}
		}
		else { ret = false; }
		return ret;
	}
	bool YourBattlefield::SetThreeCoords(const uint16_t Xs, const uint16_t Ys, const uint16_t Xf, const uint16_t Yf, uint16_t& sc)
	{
		bool ret = true;
		if (Xs == Xf && Yf - Ys == 2)
		{
			bool checker = CheckNerbyCoord(Bfield, Xs - 1, Ys - 1) || CheckNerbyCoord(Bfield, Xs - 1, Ys) || CheckNerbyCoord(Bfield, Xf - 1, Yf - 1);
			if (checker) { ret = false; }
			else {
				Bfield[Ys][Xs] = '#', Bfield[Ys + 1][Xs] = '#', Bfield[Yf][Xf] = '#'; --ThreeXShips;
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys + 1)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xf, Yf)));
				sc++;
			}
		}
		else if (Ys == Yf && Xf - Xs == 2)
		{
			bool checker = CheckNerbyCoord(Bfield, Xs - 1, Ys - 1) || CheckNerbyCoord(Bfield, Xs, Ys - 1) || CheckNerbyCoord(Bfield, Xf - 1, Yf - 1);
			if (checker) { ret = false; }
			else {
				Bfield[Ys][Xs] = '#', Bfield[Ys][Xs + 1] = '#', Bfield[Yf][Xf] = '#'; --ThreeXShips;
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs + 1, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xf, Yf)));
				sc++;
			}
		}
		else { ret = false; }
		return ret;
	}
	bool YourBattlefield::SetFourCoords(const uint16_t Xs, const uint16_t Ys, const uint16_t Xf, const uint16_t Yf, uint16_t& sc)
	{
		bool ret = true;
		if (Xs == Xf && Yf - Ys == 3)
		{
			bool checker = CheckNerbyCoord(Bfield, Xs - 1, Ys - 1) || CheckNerbyCoord(Bfield, Xs - 1, Ys) || CheckNerbyCoord(Bfield, Xs - 1, Ys + 1) || CheckNerbyCoord(Bfield, Xs - 1, Yf - 1);
			if (checker) { ret = false; }
			else {
				Bfield[Ys][Xs] = '#', Bfield[Ys + 1][Xs] = '#', Bfield[Ys + 2][Xs] = '#', Bfield[Yf][Xf] = '#'; --FourXShips;
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys + 1)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys + 2)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xf, Yf)));
				sc++;
			}
		}
		else if (Ys == Yf && Xf - Xs == 3)
		{
			bool checker = CheckNerbyCoord(Bfield, Xs - 1, Ys - 1) || CheckNerbyCoord(Bfield, Xs, Ys - 1) || CheckNerbyCoord(Bfield, Xs + 1, Ys - 1) || CheckNerbyCoord(Bfield, Xf - 1, Yf - 1);
			if (checker) { ret = false; }
			else {
				Bfield[Ys][Xs] = '#', Bfield[Ys][Xs + 1] = '#', Bfield[Ys][Xs + 2] = '#', Bfield[Yf][Xf] = '#'; --FourXShips;
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs + 1, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xs + 2, Ys)));
				coords[sc].push_back(std::make_pair(0, std::make_pair(Xf, Yf)));
				sc++;
			}
		}
		else { ret = false; }
		return ret;
	}

	field YourBattlefield::GetField() { return Gfield; };
	coordsafe YourBattlefield::GetCoordinates() { return coords; } // возвращает массив с координатами

	bool YourBattlefield::ComputerShoot()
	{
		static std::map<uint16_t, std::pair<uint16_t, uint16_t>> coordsafe;
		static uint16_t tries;
		static std::pair<uint16_t, uint16_t> currentpoint;
		static int const_coord; //X-2, Y-1
		bool chckr = false;
		bool ret = false;
		if (destroyed_count == 20) { throw std::exception("YOU LOSE"); }
		while (!chckr)
		{
			if (coordsafe.size() == 0 && tries == 0)
			{
				auto coordp = rang.GetRandCoords();
				currentpoint = coordp;
				if (Bfield.at(coordp.second).at(coordp.first) == '#' && Gfield.at(coordp.second).at(coordp.first) != '@')
				{
					Gfield[coordp.second][coordp.first] = '@';
					bool destchecker = 1;
					uint16_t number = 12;
					for (auto& item : coords)
					{
						for (auto& itm : item.second)
						{
							if (itm.second.first == coordp.first && itm.second.second == coordp.second)
							{
								itm.first = true;
								number = item.first;
								break;
							}

						}
						if (number != 12)
						{
							break;
						}
					}
					for (const auto& itm : coords[number])
					{
						destchecker &= itm.first;
					}
					if (destchecker) {
						for (const auto& itm : coords[number])
						{
							SetNerbyCoords(Bfield, Gfield, itm.second.first, itm.second.second, '@', '+');
						}
						coordsafe.clear();
						tries = 0;
					}
					else {
						coordsafe[0] = std::make_pair(coordp.first + 1, coordp.second);
						coordsafe[1] = std::make_pair(coordp.first - 1, coordp.second);
						coordsafe[2] = std::make_pair(coordp.first, coordp.second + 1);
						coordsafe[3] = std::make_pair(coordp.first, coordp.second - 1);
						tries = 5;
						const_coord = 0;
					}
					chckr = true;
					++destroyed_count;
					ret = true;
				}
				else if (Bfield[coordp.second][coordp.first] == '.' && Gfield[coordp.second][coordp.first] != '+') { Gfield[coordp.second][coordp.first] = '+'; chckr = true; }
			}

			else if (coordsafe.size() != 0)
			{
				if (coordsafe[0].first > 10 || coordsafe[0].second > 10 || coordsafe[0].first < 1 || coordsafe[0].second < 1) { coordsafe.erase(0); }
				if (Bfield.at(coordsafe[0].second).at(coordsafe[0].first) == '#' && Gfield.at(coordsafe[0].second).at(coordsafe[0].first) != '@')
				{
					currentpoint = coordsafe[0];
					Gfield[coordsafe[0].second][coordsafe[0].first] = '@';
					bool destchecker = 1;
					uint16_t number = 12;
					for (auto& item : coords)
					{
						for (auto& itm : item.second)
						{
							if (itm.second.first == coordsafe.at(0).first && itm.second.second == coordsafe.at(0).second)
							{
								itm.first = true;
								number = item.first;
								break;
							}
							if (number != 12)
							{
								break;
							}
						}
					}
					SetCursor(0, 14);
					std::cout << "                         \r";
					for (const auto& itm : coords[number])
					{
						destchecker &= itm.first;
					}
					if (destchecker) {
						for (const auto& itm : coords[number])
						{
							SetNerbyCoords(Bfield, Gfield, itm.second.first, itm.second.second, '@', '+');
						}
						coordsafe.clear();
						tries = 0;
					}
					else {
						if (!(currentpoint.second + 1 > 10 || currentpoint.second + 1 < 0) && (Gfield[currentpoint.second + 1][currentpoint.first] == '@'))
						{
							const_coord = 1; coordsafe[0] = std::make_pair(currentpoint.first, currentpoint.second - 1);
						}
						else if (!(currentpoint.second - 1 > 10 || currentpoint.second - 1 < 0) && (Gfield[currentpoint.second - 1][currentpoint.first] == '@'))
						{
							const_coord = 1; coordsafe[0] = std::make_pair(currentpoint.first, currentpoint.second + 1);
						}
						else if (!(currentpoint.first + 1 > 10 || currentpoint.first + 1 < 0) && (Gfield[currentpoint.second][currentpoint.first + 1] == '@'))
						{
							const_coord = 2; coordsafe[0] = std::make_pair(currentpoint.first - 1, currentpoint.second);
						}
						else if (!(currentpoint.first - 1 > 10 || currentpoint.first - 1 < 0) && (Gfield[currentpoint.second][currentpoint.first - 1] == '@'))
						{
							const_coord = 2; coordsafe[0] = std::make_pair(currentpoint.first + 1, currentpoint.second);
						}

						tries = 2;
					}
					ret = true;
					++destroyed_count;
					chckr = true;
				}
				else if (Bfield.at(coordsafe.at(0).second).at(coordsafe.at(0).first) == '.' && Bfield.at(coordsafe.at(0).second).at(coordsafe.at(0).first) != '+') {
					Gfield[coordsafe[0].second][coordsafe[0].first] = '+'; coordsafe.erase(0); tries--;
					std::map<uint16_t, std::pair<uint16_t, uint16_t>> temp;
					uint16_t count = 0;
					for (const auto& item : coordsafe)
					{
						temp[count] = item.second;
						count++;
					}
					coordsafe = temp;
					chckr = true;
				}
				else {
					coordsafe.erase(0);
					tries--;
					std::map<uint16_t, std::pair<uint16_t, uint16_t>> temp;
					uint16_t count = 0;
					for (const auto& item : coordsafe)
					{
						temp[count] = item.second;
						count++;
					}
					coordsafe = temp;
				}
			}
			else if (coordsafe.size() == 0 && tries == 1)
			{
				if (!(currentpoint.second - 1 > 10 || currentpoint.second - 1 < 0) && Gfield[currentpoint.second - 1][currentpoint.first] == '@') {
					if (Gfield[currentpoint.second - 2][currentpoint.first] != '@') { coordsafe[0] = std::make_pair(currentpoint.first, currentpoint.second - 2); }
					else { coordsafe[0] = std::make_pair(currentpoint.first, currentpoint.second - 3); }
				}
				if (!(currentpoint.second + 1 > 10 || currentpoint.second - 1 < 0) && Gfield[currentpoint.second + 1][currentpoint.first] == '@') {
					if (Gfield[currentpoint.second + 2][currentpoint.first] != '@') { coordsafe[0] = std::make_pair(currentpoint.first, currentpoint.second + 2); }
					else { coordsafe[0] = std::make_pair(currentpoint.first, currentpoint.second + 3); }
				}
				if (!(currentpoint.first - 1 > 10 || currentpoint.first - 1 < 0) && Gfield[currentpoint.second][currentpoint.first - 1] == '@') {
					if (Gfield[currentpoint.second][currentpoint.first - 2] != '@') { coordsafe[0] = std::make_pair(currentpoint.first - 2, currentpoint.second); }
					else { coordsafe[0] = std::make_pair(currentpoint.first - 3, currentpoint.second); }
				}
				if (!(currentpoint.first + 1 > 10 || currentpoint.first + 1 < 0) && Gfield[currentpoint.second][currentpoint.first + 1] == '@') {
					if (Gfield[currentpoint.second][currentpoint.first + 2] != '@') { coordsafe[0] = std::make_pair(currentpoint.first + 2, currentpoint.second); }
					else { coordsafe[0] = std::make_pair(currentpoint.first + 3, currentpoint.second); }
				}
				tries = 5;
			}
		}
		return ret;
	}

	void YourBattlefield::ShootMoving(const field& another_field, uint16_t& X, uint16_t& Y)
	{
		static std::pair<size_t, size_t> coordp = { 6, 6 };
		char memory = Gfield[coordp.second][coordp.first];
		char symb = '+';
		char chr = ' ';
		Gfield[coordp.second][coordp.first] = symb;
		while (chr != 13)
		{
			SetCursor(0, 0);
			PrintFields(another_field, Gfield, 0);
			Gfield[coordp.second][coordp.first] = symb;
			chr = _getch();
			if ((chr == 'w' || chr == 'W') && coordp.second != 1)
			{
				Gfield[coordp.second--][coordp.first] = memory;
				memory = Gfield[coordp.second][coordp.first];
				Gfield[coordp.second][coordp.first] = symb;
			}
			else if ((chr == 's' || chr == 'S') && coordp.second != 10)
			{
				Gfield[coordp.second++][coordp.first] = memory;
				memory = Gfield[coordp.second][coordp.first];
				Gfield[coordp.second][coordp.first] = symb;
			}
			else if ((chr == 'a' || chr == 'A') && coordp.first != 1)
			{
				Gfield[coordp.second][coordp.first--] = memory;
				memory = Gfield[coordp.second][coordp.first];
				Gfield[coordp.second][coordp.first] = symb;
			}
			else if ((chr == 'd' || chr == 'D') && coordp.first != 10)
			{
				Gfield[coordp.second][coordp.first++] = memory;
				memory = Gfield[coordp.second][coordp.first];
				Gfield[coordp.second][coordp.first] = symb;
			}
			else if (chr == 13)
			{
				X = coordp.first;
				Y = coordp.second;
				Gfield[Y][X] = memory;
			}
		}
	}

	bool YourBattlefield::Shoot(const field& another_field)
	{
		if (destroyed_count == 20) { throw std::exception("YOU WON"); }
		uint16_t X, Y;
		bool chk = false;
		bool ret = false;
		
		while (!chk)
		{
			ShootMoving(another_field, X, Y);
			if (X <= 10 && X > 0 && Y <= 10 && Y > 0 && Gfield.at(Y).at(X) != '#' && Gfield.at(Y).at(X) != '.')
			{
				if (Bfield.at(Y).at(X) == '#') {
					for (auto& item : coords)
					{
						uint16_t destroyed_count = 0;
						for (auto& itm : item.second)
						{
							if (itm.second == std::make_pair(X, Y))
							{
								itm.first = true;
							}
							if (itm.first == true)
							{
								destroyed_count++;
							}
						}
						if (destroyed_count == item.second.size())
						{
							for (auto& itm : item.second)
							{
								SetNerbyCoords(Bfield, Gfield, itm.second.first, itm.second.second, '#', '.');
							}
						}
					}
					ret = true;
					++destroyed_count;
				}
				chk = true;
				Gfield[Y][X] = Bfield.at(Y).at(X);
			}
			else
			{
				SetCursor(0, 17);
				std::cout << "                                                    \r";
				std::cout << "Invalid coordinates or their format";

			}
		}
		return ret;
	}

	void YourBattlefield::SetShipCoords_2_0()
	{
		std::vector<std::pair<SHORT, SHORT>> coords_safe;

		std::vector<std::vector<char>> field_view = GenField(14);

		SHORT x = 45, y = 7;
		SetCursor(35, 3);
		std::cout << "Use keys W A S D to move ship across the field   ";
		SetCursor(35, 4);
		std::cout << "Use Q to expand ship`s body and Enter to plase it";
		SetCursor(35, 5);
		std::cout << "Use keys 1 2 3 4 to select the size of the ship  ";
		SetCursor(x, y);
		PrintFieldView(field_view, x, y);
		SetCursor(5, 10);
		std::cout << "Ships with one deck: 4";
		SetCursor(5, 11);
		std::cout << "Ships with two decks: 3";
		SetCursor(5, 12);
		std::cout << "Ships with three decks: 2";
		SetCursor(5, 13);
		std::cout << "Ships with four decks: 1";
		unsigned size = '1';
		while (!ChooseShip(size, field_view, coords_safe, x, y, OneXShips, TwoXShips, ThreeXShips, FourXShips)) { size = _getch(); }
		uint16_t sc = 0;
		InvisibleCursor();
		
		while (true)
		{
			if (_kbhit()) {
				char chr = _getch();
				MovingCoreFunc(coords_safe, x, y, chr, field_view, '#');
				if (chr == 'q' || chr == 'Q')
				{
					
					SHORT counter = 0;
					bool chck = true;
					auto coords_copy = coords_safe;
					for (auto& item : coords_safe) {
						if (counter != 0) {

							if (coords_safe[0].first == item.first)
							{
								++counter;
								item.second = coords_safe[0].second;
								item.first = coords_safe[0].first + counter;
							}
							else if (coords_safe[0].second == item.second)
							{
								item.second = coords_safe[0].second + counter;
								item.first = coords_safe[0].first;
							}
							if (item.first < x + 3 || item.first >(x + 21) || item.second < y + 2 || item.second >(y + 11))
							{
								chck = false;
								break;
							}
						}
						++counter;
					}
					if (chck)
					{
						for (auto& item : coords_copy)
						{
							SetCursor(item.first, item.second);
							std::cout << field_view[item.second - y][item.first - x];
						}
						for (auto& item : coords_safe)
						{
							SetCursor(item.first, item.second);
							std::cout << '#';
						}
					}
					else
					{
						coords_safe = coords_copy;
					}

				}
				else if (chr == 13)
				{
				auto coords_safe_copy = coords_safe;
				fit_to_classic_coords(coords_safe, x, y);
				bool set = false;
				if (coords_safe.size() == 1)
					{
					if (OneXShips > 0 && SetOneCoords(coords_safe[0].first, coords_safe[0].second, sc))
					{
						for (auto& item : coords_safe_copy) {
							field_view[item.second - y][item.first - x] = '#';
						}
						SetCursor(26, 10);
						set = true;
						std::cout << OneXShips;
					}
					else
					{
						SetCursor(x, y);
						PrintFieldView(field_view, x, y);
						SetCursor(40, 21);
						std::cout << "You can`t plase this ship there!";
					}
					}
				if (coords_safe.size() == 2)
				{
					if (TwoXShips > 0 && SetTwoCoords(coords_safe[0].first, coords_safe[0].second, coords_safe[1].first, coords_safe[1].second, sc))
					{
						for (auto& item : coords_safe_copy) {
							field_view[item.second - y][item.first - x] = '#';
						}
						SetCursor(27, 11);
						set = true;
						std::cout << TwoXShips;
					}
					else
					{
						SetCursor(x, y);
						PrintFieldView(field_view, x, y);
						SetCursor(40, 21);
						std::cout << "You can`t plase this ship there!";
					}
				}
				if (coords_safe.size() == 3)
				{
					std::sort(coords_safe.begin(), coords_safe.end());
				if (ThreeXShips > 0 && SetThreeCoords(coords_safe[0].first, coords_safe[0].second, coords_safe[2].first, coords_safe[2].second, sc))
					{
						for (auto& item : coords_safe_copy) {
							field_view[item.second - y][item.first - x] = '#';
						}
						SetCursor(29, 12);
						set = true;
						std::cout << ThreeXShips;
					}
					else
					{
						SetCursor(x, y);
						PrintFieldView(field_view, x, y);
						SetCursor(40, 21);
						std::cout << "You can`t plase this ship there!";
					}
				}
				if (coords_safe.size() == 4)
				{
					std::sort(coords_safe.begin(), coords_safe.end());
					if (FourXShips > 0 && SetFourCoords(coords_safe[0].first, coords_safe[0].second, coords_safe[3].first, coords_safe[3].second, sc))
					{
						for (auto& item : coords_safe_copy) {
							field_view[item.second - y][item.first - x] = '#';
						}
						SetCursor(28, 13);
						set = true;
						std::cout << FourXShips;
					}
					else
					{
						SetCursor(x, y);
						PrintFieldView(field_view, x, y);
						SetCursor(40, 21);
						std::cout << "You can`t plase this ship there!";
					}
				}
					if (OneXShips + TwoXShips + ThreeXShips + FourXShips == 0)
					{
						system("cls");
						break;
					}
					if (set)
					{
						coords_safe.clear();
						std::map<char, size_t> size_vec = { {'1', OneXShips}, {'2', TwoXShips}, {'3', ThreeXShips}, {'4', FourXShips} };
						for (auto& item : size_vec)
						{
							if (item.second != 0 && ChooseShip(item.first, field_view, coords_safe, x, y, OneXShips, TwoXShips, ThreeXShips, FourXShips)) 
							{ break; }
						}
					}
					else {
						char size = ' ';
						switch (coords_safe.size())
						{
						case 1:
							size = '1';
							break;
						case 2:
							size = '2';
							break;
						case 3:
							size = '3';
							break;
						case 4:
							size = '4';
							break;
						}
						coords_safe.clear();
						ChooseShip(size, field_view, coords_safe, x, y, OneXShips, TwoXShips, ThreeXShips, FourXShips);
						SetCursor(40, 21);
						std::cout << "You can`t plase this ship there!";

					}
				}
				else if (chr == '1' || chr == '2' || chr == '3' || chr == '4')
				{
					ChooseShip(chr, field_view, coords_safe, x, y, OneXShips, TwoXShips, ThreeXShips, FourXShips);
				}
			}
		}
}

	void YourBattlefield::SetShipsCoords()
	{
		uint16_t shipcount = 0;
		uint16_t X_1, Y_1, X_2, Y_2;
		SetCursor(40, 5);
		std::cout << "Enter coordinates for 1x ship; " << OneXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
		bool SetterRes;
		while (OneXShips != 0) {
			SetCursor(0, 12);
			std::cout << "\rInput coordinates: " << "X " << "Y";
			SetCursor(19, 13);
			std::cin >> X_1;
			SetCursor(21, 13);
			std::cin >> Y_1;
			SetCursor(18, 13);
			std::cout << "            ";
			SetterRes = SetOneCoords(X_1, Y_1, shipcount);
			X_1 = 0; Y_1 = 0;
			if (SetterRes == false) { SetCursor(41, 6); std::cout << "Invalid coordinates or their format" << std::endl; }
			SetCursor(40, 5);
			std::cout << "Enter coordinates for 1x ship; " << OneXShips << " left" << std::endl;
			PrintField(Bfield, 45, 7);
		}
		system("cls");
		SetCursor(40, 5);
		std::cout << "Enter coordinates for 2x ship; " << TwoXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
		while (TwoXShips != 0) {
			SetCursor(0, 12);
			std::cout << "\rInput coordinates: " << "Xs " << "Ys " << "Xf " << "Yf";
			SetCursor(19, 13);
			std::cin >> X_1;
			SetCursor(22, 13);
			std::cin >> Y_1;
			SetCursor(25, 13);
			std::cin >> X_2;
			SetCursor(28, 13);
			std::cin >> Y_2;
			SetCursor(18, 13);
			std::cout << "                  ";
			SetCursor(0, 0);
			std::cin.clear();

			SetterRes = SetTwoCoords(X_1, Y_1, X_2, Y_2, shipcount);
			if (SetterRes == false) { SetCursor(41, 6); std::cout << "Invalid coordinates or their format" << std::endl; }
			SetCursor(40, 5);
			std::cout << "Enter coordinates for 2x ship; " << TwoXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
		}
		
		system("cls");
		SetCursor(40, 5);
		std::cout << "Enter coordinates for 3x ship; " << ThreeXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
		while (ThreeXShips != 0) {
			SetCursor(0, 12);
			std::cout << "\rInput coordinates: " << "Xs " << "Ys " << "Xf " << "Yf";
			SetCursor(19, 13);
			std::cin >> X_1;
			SetCursor(22, 13);
			std::cin >> Y_1;
			SetCursor(25, 13);
			std::cin >> X_2;
			SetCursor(28, 13);
			std::cin >> Y_2;
			SetCursor(18, 13);
			std::cout << "                  ";
			SetCursor(0, 0);
			std::cin.clear();

			SetterRes = SetThreeCoords(X_1, Y_1, X_2, Y_2, shipcount);
			if (SetterRes == false) { SetCursor(41, 6); std::cout << "Invalid coordinates or their format" << std::endl; }
			SetCursor(40, 5);
			std::cout << "Enter coordinates for 3x ship; " << ThreeXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
		}
		system("cls");
		SetCursor(40, 5);
		std::cout << "Enter coordinates for 4x ship; " << FourXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
	
		while (FourXShips != 0) {
			SetCursor(0, 12);
			std::cout << "\rInput coordinates: " << "Xs " << "Ys " << "Xf " << "Yf";
			SetCursor(19, 13);
			std::cin >> X_1;
			SetCursor(22, 13);
			std::cin >> Y_1;
			SetCursor(25, 13);
			std::cin >> X_2;
			SetCursor(28, 13);
			std::cin >> Y_2;
			SetCursor(18, 13);
			std::cout << "                  ";
			SetCursor(0, 0);
			std::cin.clear();

			SetterRes = SetFourCoords(X_1, Y_1, X_2, Y_2, shipcount);
			if (SetterRes == false) { SetCursor(41, 6); std::cout << "Invalid coordinates or their format" << std::endl; }
			SetCursor(40, 5);
			std::cout << "Enter coordinates for 4x ship; " << FourXShips << " left" << std::endl; PrintField(Bfield, 45, 7);
		}
		system("cls");
	}

	EnemyBattlefield::EnemyBattlefield()
	{
		Bfield = GenField(11);
		OneXShips = 4;
		TwoXShips = 3;
		ThreeXShips = 2;
		FourXShips = 1;
	}
	void EnemyBattlefield::GenRandField(char difficulty)
	{
		uint16_t shipcounter = 0;
		while (FourXShips != 0) {
			uint16_t itercount = 0;
			std::pair<uint16_t, uint16_t> cp1 = rang.GetRandCoords();
			std::pair<uint16_t, uint16_t> cp2 = rang.GetRandCoords();
			uint16_t temp = rang.CooseOne() + 1;
			if (temp == 1) {
				if (difficulty == '2' || difficulty == '3')
				{
					uint16_t tmp_1 = rang.CooseOne() + 1;
					if (tmp_1 == 1) { cp1.first = 1; }
					if (tmp_1 == 2) { cp1.first = 10; }
				}
				cp2.first = cp1.first;
				if (cp1.second - cp2.second < 3 && cp2.second - cp1.second < -3 || (cp1.first == cp2.first && cp2.second == cp1.second)) { continue; }
				while (cp1.second - cp2.second != 3 && cp1.second - cp2.second != -3)
				{
					if (itercount > 10) { break; }
					if (cp2.second > cp1.second) { cp1.second += 1; }
					else { cp2.second += 1; }
					itercount += 1;
				}
				if (cp1.second > cp2.second) { uint16_t tmp = cp2.second; cp2.second = cp1.second; cp1.second = tmp; }
			}
			else if (temp == 2) {
				if (difficulty == '2' || difficulty == '3')
				{
					uint16_t tmp_1 = rang.CooseOne() + 1;
					if (tmp_1 == 1) { cp1.second = 1; }
					if (tmp_1 == 2) { cp1.second = 10; }
				}
				cp2.second = cp1.second;
				if (cp1.first - cp2.first < 2 && cp2.first - cp1.first < -2 || (cp1.first == cp2.first && cp2.second == cp1.second)) { continue; }
				while (cp1.first - cp2.first != 3 && cp1.first - cp2.first != -3) {
					if (itercount > 10) { break; }
					if (cp2.first > cp1.first) { cp1.first += 1; }
					else { cp2.first += 1; }
					itercount += 1;
				}
				if (cp1.first > cp2.first) { uint16_t tmp = cp2.first; cp2.first = cp1.first; cp1.first = tmp; }
			}

			if (cp1.first == 0) { cp1.first += 1; }
			else if (cp2.first == 0) { cp1.first += 1; }
			else if (cp1.second == 0) { cp1.second += 1; }
			else if (cp2.second == 0) { cp2.second += 1; }

			SetFourCoords(cp1.first, cp1.second, cp2.first, cp2.second, shipcounter);	//PrintField(Bfield, 0, 0);
		}

		while (ThreeXShips != 0) {
			uint16_t itercount = 0;
			std::pair<uint16_t, uint16_t> cp1 = rang.GetRandCoords();
			std::pair<uint16_t, uint16_t> cp2 = rang.GetRandCoords();
			uint16_t temp = rang.CooseOne() + 1;
			if (temp == 1) {
				if (difficulty == '3')
				{
					uint16_t tmp_1 = rang.CooseOne() + 1;
					if (tmp_1 == 1) { cp1.first = 1; }
					if (tmp_1 == 2) { cp1.first = 10; }
				}
				else if (difficulty == '1')
				{
					if (cp1.first == 1) { cp1.first += rang.CooseEight(); }
					if (cp1.first == 10) { cp1.first -= rang.CooseEight(); }
				}
				cp2.first = cp1.first;
				if (cp1.second - cp2.second < 2 && cp2.second - cp1.second < -2 || (cp1.first == cp2.first && cp2.second == cp1.second)) { continue; }
				while (cp1.second - cp2.second != 2 && cp1.second - cp2.second != -2)
				{
					if (itercount > 10) { break; }
					if (cp2.second > cp1.second) { cp1.second += 1; }
					else { cp2.second += 1; }
					itercount += 1;
				}
				if (cp1.second > cp2.second) { uint16_t tmp = cp2.second; cp2.second = cp1.second; cp1.second = tmp; }
			}
			else if (temp == 2) {
				if (difficulty == '3')
				{
					uint16_t tmp_1 = rang.CooseOne() + 1;
					if (tmp_1 == 1) { cp1.second = 1; }
					if (tmp_1 == 2) { cp1.second = 10; }
				}
				else if (difficulty == '1')
				{
					if (cp1.second == 1) { cp1.second += rang.CooseEight(); }
					if (cp1.second == 10) { cp1.second -= rang.CooseEight(); }
				}
				cp2.second = cp1.second;
				if (cp1.first - cp2.first < 2 && cp2.first - cp1.first < -2 || (cp1.first == cp2.first && cp2.second == cp1.second)) { continue; }
				while (cp1.first - cp2.first != 2 && cp1.first - cp2.first != -2) {
					if (itercount > 10) { break; }
					if (cp2.first > cp1.first) { cp1.first += 1; }
					else { cp2.first += 1; }
					itercount += 1;
				}
				if (cp1.first > cp2.first) { uint16_t tmp = cp2.first; cp2.first = cp1.first; cp1.first = tmp; }
			}

			if (cp1.first == 0) { cp1.first += 1; }
			else if (cp2.first == 0) { cp1.first += 1; }
			else if (cp1.second == 0) { cp1.second += 1; }
			else if (cp2.second == 0) { cp2.second += 1; }

			SetThreeCoords(cp1.first, cp1.second, cp2.first, cp2.second, shipcounter);	//PrintField(Bfield, 0, 0);
		}

		while (OneXShips != 0) {
			std::pair<uint16_t, uint16_t> cp = rang.GetRandCoords(); //PrintField(Bfield, 0, 0);
			SetOneCoords(cp.first, cp.second, shipcounter);
		};

		while (TwoXShips != 0) {
			std::pair<uint16_t, uint16_t> cp1 = rang.GetRandCoords();
			std::pair<uint16_t, uint16_t> cp2 = rang.GetRandCoords();
			uint16_t temp = rang.CooseOne() + 1;
			if (temp == 1) {
				cp2.first = cp1.first;
				if (cp1.second - cp2.second < 1 && cp2.second - cp1.second < -1 || (cp1.first == cp2.first && cp2.second == cp1.second)) { continue; }
				while (cp1.second - cp2.second != 1 && cp1.second - cp2.second != -1)
				{
					if (cp2.second > cp1.second) { cp1.second += 1; }
					else { cp2.second += 1; }
				}
				if (cp1.second > cp2.second) { uint16_t tmp = cp2.second; cp2.second = cp1.second; cp1.second = tmp; }
			}
			else if (temp == 2) {
				cp2.second = cp1.second;
				if (cp1.first - cp2.first < 1 && cp2.first - cp1.first < -1 || (cp1.first == cp2.first && cp2.second == cp1.second)) { continue; }
				while (cp1.first - cp2.first != 1 && cp1.first - cp2.first != -1) {
					if (cp2.first > cp1.first) { cp1.first += 1; }
					else { cp2.first += 1; }
				}
				if (cp1.first > cp2.first) { uint16_t tmp = cp2.first; cp2.first = cp1.first; cp1.first = tmp; }

			}

			if (cp1.first == 0) { cp1.first += 1; }
			else if (cp2.first == 0) { cp1.first += 1; }
			else if (cp1.second == 0) { cp1.second += 1; }
			else if (cp2.second == 0) { cp2.second += 1; }

			SetTwoCoords(cp1.first, cp1.second, cp2.first, cp2.second, shipcounter); //PrintField(Bfield, 0, 0);};


		}
	};

	