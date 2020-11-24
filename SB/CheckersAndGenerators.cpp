#include "CheckersAndGenerators.h"
#include "Interface.h"

std::mutex mut;
field GenField(const uint16_t sz)
{
	if (sz == 11) {
		return
		{ { ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'l' },
		{ '1', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '2', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '3', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '4', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '5', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '6', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '7', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '8', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ '9', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{ 'l', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' } };
	}
	else if (sz == 10) {
		return
		{
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.' } };
	}
	else if (sz == 12) {
		return
		{ { ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'l' },
		{ '1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ 'l', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' } };
	}
	else if (sz == 13) {
		return
		{ { ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'l' },
		{ '1', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#' },
		{ '2', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#' },
		{ '3', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#' },
		{ '4', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#' },
		{ '5', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.' },
		{ '6', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#' },
		{ '7', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#' },
		{ '8', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#' },
		{ '9', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#' },
		{ 'l', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' } };
	}
	return field(11, std::vector<char>(11, '.'));
}

bool CheckNerbyCoord(const field& source, uint16_t X, uint16_t Y)
{
	field f(10, std::vector<char>(10, '.'));
	uint16_t countX = 0, countY = 0;
	for (uint16_t i = 1; i < 11; ++i)
	{
		countX = 0;
		for (uint16_t j = 1; j < 11; ++j)
		{
			f[countY][countX] = source[i][j];
			++countX;
		}
		++countY;
	}
	//PrintField(f);
	bool checker = false;
	if (X <= 10 && X >= 0 && Y <= 10 && Y >= 0)
	{
		if (f[Y][X] != '.') { checker = true; }
		else if (!(X + 1 >= 10 || X + 1 < 0) && f[Y][X + 1] == '#') { checker = true; }
		else if (!(X - 1 >= 10 || X - 1 < 0) && f[Y][X - 1] == '#') { checker = true; }
		else if (!(Y + 1 >= 10 || Y + 1 < 0) && f[Y + 1][X] == '#') { checker = true; }
		else if (!(Y - 1 >= 10 || Y - 1 < 0) && f[Y - 1][X] == '#') { checker = true; }
		else if (!(X + 1 >= 10 || X + 1 < 0 || Y + 1 >= 10 || Y + 1 < 0) && f[Y + 1][X + 1] == '#') { checker = true; }
		else if (!(X + 1 >= 10 || X + 1 < 0 || Y - 1 >= 10 || Y - 1 < 0) && f[Y - 1][X + 1] == '#') { checker = true; }
		else if (!(X - 1 >= 10 || X - 1 < 0 || Y + 1 >= 10 || Y + 1 < 0) && f[Y + 1][X - 1] == '#') { checker = true; }
		else if (!(X - 1 >= 10 || X - 1 < 0 || Y - 1 >= 10 || Y - 1 < 0) && f[Y - 1][X - 1] == '#') { checker = true; }
	}
	return checker;
}

void SetNerbyCoords(const field& source, field& gamef, uint16_t X, uint16_t Y, char chr_1, char chr_2)
{
	X--, Y--;
	field f(10, std::vector<char>(10, '.'));
	uint16_t countX = 0, countY = 0;
	for (uint16_t i = 1; i < 11; ++i)
	{
		countX = 0;
		for (uint16_t j = 1; j < 11; ++j)
		{
			f[countY][countX] = source[i][j];
			++countX;
		}
		++countY;
	}
	//PrintField(f);
	if (X <= 10 && X >= 0 && Y <= 10 && Y >= 0)
	{
		gamef[Y + 1][X + 1] = chr_1;
		if (!(Y + 1 >= 10 || Y + 1 < 0) && gamef[Y + 2][X + 1] == ' ' && f[Y + 1][X] == '.') { gamef[Y + 2][X + 1] = chr_2; }
		if (!(Y - 1 >= 10 || Y - 1 < 0) && gamef[Y][X + 1] == ' ' && f[Y - 1][X] == '.') { gamef[Y][X + 1] = chr_2; }
		if (!(X + 1 >= 10 || X + 1 < 0) && gamef[Y + 1][X + 2] == ' ' && f[Y][X + 1] == '.') { gamef[Y + 1][X + 2] = chr_2; }
		if (!(X - 1 >= 10 || X - 1 < 0) && gamef[Y + 1][X] == ' ' && f[Y][X - 1] == '.') { gamef[Y + 1][X] = chr_2; }
		if (!(X + 1 >= 10 || X + 1 < 0 || Y + 1 >= 10 || Y + 1 < 0) && gamef[Y + 2][X + 2] == ' ' && f[Y + 1][X + 1] == '.') { gamef[Y + 2][X + 2] = chr_2; }
		if (!(X - 1 >= 10 || X - 1 < 0 || Y + 1 >= 10 || Y + 1 < 0) && gamef[Y + 2][X] == ' ' && f[Y + 1][X] == '.') { gamef[Y + 2][X] = chr_2; }
		if (!(X + 1 >= 10 || X + 1 < 0 || Y - 1 >= 10 || Y - 1 < 0) && gamef[Y][X + 2] == ' ' && f[Y][X + 1] == '.') { gamef[Y][X + 2] = chr_2; }
		if (!(X - 1 >= 10 || X - 1 < 0 || Y - 1 >= 10 || Y - 1 < 0) && gamef[Y][X] == ' ' && f[Y - 1][X - 1] == '.') { gamef[Y][X] = chr_2; }
	}
}

	RandomGenerator :: RandomGenerator()
	{
		srand(static_cast<int16_t>(time(NULL)));
		seed = std::rand();
	}
	std::pair<uint16_t, uint16_t> RandomGenerator :: GetRandCoords()
	{
		IncreaseSeed();
		return std::make_pair(PRNG(), PRNG());
	}
	uint16_t RandomGenerator::CooseOne()
	{
		srand(static_cast<int16_t>(time(NULL)));
		return (std::rand() + 1) % 2;
	}
	uint16_t RandomGenerator:: CooseEight()
	{
		srand(static_cast<int16_t>(time(NULL)));
		return (std::rand() + 1) % 9;
	}
	void RandomGenerator::IncreaseSeed()
	{
		seed++;
	}
	uint16_t RandomGenerator::PRNG()
	{
		seed = (8253729 * seed + 2396403);
		return seed % 11;
	}
	
	void PrintFields(const field& f1, const field& f2, uint16_t mode)
	{
		std::mutex m;
		m.lock();
		bool flag_1;
		if (mode == 0) {
			std::cout << std::setw(50) << "      Your field       " << std::setw(45) << "   Computer`s field    " << std::endl;
		}
		else if (mode == 1) {
			std::cout << std::endl << std::endl << std::setw(50) << "   WASD-moving mode    " << std::setw(45) << " Coordinate-input mode " << std::endl ;
		}
		std::cout << std::setw(50) << "#=====================#" << std::setw(45) << "#=====================#" << std::endl;
		for (size_t sideOne = 0; sideOne < f1.size(); sideOne++)
		{
			if (sideOne != f1.size()) { std::cout << std::setw(28) << '|'; }
			flag_1 = true;
			for (size_t sideTwo = 0; sideTwo < f1.size(); sideTwo++)
			{
				if (!flag_1)
				{
					std::cout << ' ';
				}
				flag_1 = false;
				std::cout << f1.at(sideOne).at(sideTwo);
			}
			if (sideOne != f1.size()) { std::cout << '|' << std::setw(23) << '|'; }
			flag_1 = true;
			for (size_t sideTwo = 0; sideTwo < f2.size(); sideTwo++)
			{
				if (!flag_1)
				{
					std::cout << ' ';
				}
				flag_1 = false;
				std::cout << f2.at(sideOne).at(sideTwo);
			}
			if (sideOne != f1.size()) { std::cout << '|' << std::endl; }
		}
		std::cout << std::setw(50) << "#=====================#" << std::setw(45) << "#=====================#" << std::endl;
		m.unlock();
	}

	void PrintField(const field& gameField, uint16_t Xc, uint16_t Yc)
	{
		bool flag;
		SetCursor(Xc, Yc);
		std::cout << "#=====================#" << std::endl;
		for (size_t sideOne = 0; sideOne < gameField.size(); sideOne++)
		{
			SetCursor(Xc, ++Yc);
			if (sideOne != gameField.size()) { std::cout << '|'; }
			flag = true;
			for (size_t sideTwo = 0; sideTwo < gameField.size(); sideTwo++)
			{
				if (!flag)
				{
					std::cout << ' ';
				}
				flag = false;
				std::cout << gameField.at(sideOne).at(sideTwo);
			}
			if (sideOne != gameField.size()) { std::cout << '|' << std::endl; }
		}
		SetCursor(Xc, ++Yc);
		std::cout << "#=====================#" << std::endl;
	}