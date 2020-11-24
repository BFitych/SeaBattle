#include "Interface.h"

void InvisibleCursor()
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

void CenrtreConsole()
{
	HWND hwnd;
	char Title[1024];
	GetConsoleTitle(Title, 1024);
	hwnd = FindWindow(NULL, Title);
	MoveWindow(hwnd, 270, 150, 900, 600, TRUE);
}


void PrintInterface(char& df, char& mode)
{
	bool choosed = false;
	uint16_t cursorcount = 0, strcount = 0;
	uint16_t color_count = 1;
	std::string running_str;
	const std::string running_str_reseter = " Just another AAA project";
	while (!choosed)
	{
		if (color_count == 10) { color_count = 1; }
		SetCursor(0, 4);
		ChangeColour(color_count);
  std::cout << std::setw(89) << " 0000  11111   0000  00000   0000  000000 000000 11     00000" << std::endl
			<< std::setw(89) << "00     11     00  00 00  00 00  00   00     00   11     00   " << std::endl
			<< std::setw(89) << " 0000  1111   000000 00000  000000   00     00   11     0000 " << std::endl
			<< std::setw(89) << "    00 11     00  00 00  00 00  00   00     00   11     00   " << std::endl
			<< std::setw(89) << " 0000  11111  00  00 00000  00  00   00     00   111111 00000" << std::endl;
		ChangeColour(7);
		std::cout << std::endl;
		ChangeColour(color_count);
		std::cout << std::setw(74) << "<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << std::endl;
		std::cout << std::setw(43) << "|";
		ChangeColour(7);
		std::cout << "   Choose difficulty level:   ";
		ChangeColour(color_count);
		std::cout << "|" << std::endl;
		std::cout << std::setw(43) << "|";
		ChangeColour(7);
		std::cout << " Press 1 to choose easy level ";
		ChangeColour(color_count);
		std::cout << "|" << std::endl;
		std::cout << std::setw(43) << "|";
		ChangeColour(7);
		std::cout << "Press 2 to choose medium level";
		ChangeColour(color_count);
		std::cout << "|" << std::endl;
		std::cout << std::setw(43) << "|";
		ChangeColour(7);
		std::cout << " Press 3 to choose hard level ";
		ChangeColour(color_count);
		std::cout << "|" << std::endl;
		std::cout << std::setw(74) << "<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << std::endl;
		ChangeColour(7);
		if (cursorcount >= 96 && cursorcount != 121) {
			running_str.pop_back();
		}
		else if (cursorcount == 121)
		{
			SetCursor(0, 17);
			std::cout << "\r                                                                                                                           ";
			strcount = 0;
			cursorcount = 0;
		}
		if (strcount <= running_str_reseter.size() - 1)
		{
			running_str.clear();
			for (int i = strcount; i >= 0; --i)
			{
				running_str += running_str_reseter[running_str_reseter.size() - 1 - i];
			}
		}
		SetCursor(cursorcount - 1, 17);
		std::cout << ' ';
		SetCursor(cursorcount, 17);
		Sleep(80);
		if (strcount <= 24)
		{
			SetCursor(0, 17);
		}
		std::cout << running_str;
		while (_kbhit()) { df = _getch(); { choosed = true; } }
		if (strcount >= running_str_reseter.size())
		{
			++cursorcount;
		}
		++strcount;
		++color_count;
	}
	auto Field = GenField(11);
	auto Field_2 = Field;
	
	system("cls");
	SetCursor(49, 0);
	std::cout << "Choose ship-placing mode";
	SetCursor(12, 16);
	std::cout << "Use keys W A S D to move ship across the field   ";
	SetCursor(12, 17);
	std::cout << "Use Q to flip ship`s body and Enter to place it  ";
	SetCursor(12, 18);
	std::cout << "          Press 1 to choose this mode            ";
	SetCursor(65, 16);
	std::cout << "Input coordinates using your keyboard";
	SetCursor(65, 17);
	std::cout << "     Press 2 to choose this mode     ";
	SetCursor(100, 9);
	std::cout << "Xs Ys Xf Yf";
	uint16_t steps = 0;
	uint16_t rpos = 2;
	while (choosed)
	{
		if (_kbhit()) { mode = _getch(); }
		if (mode == '1' || mode == '2') { choosed = false; }
		Sleep(250);
		if (steps == 1) { SetCursor(100, 10); std::cout << '5'; }
		if (steps == 2) { SetCursor(103, 10); std::cout << '5'; }
		if (steps == 3) { SetCursor(106, 10); std::cout << '5'; }
		if (steps == 4) { SetCursor(109, 10); std::cout << '6'; }
		if (steps == 5)
		{
			Field_2[5][5] = '#'; Field_2[6][5] = '#';
		}
		if (steps == 7)
		{
			steps = 0;
			rpos = 2;
			Field[5][8] = '.';
			
			Field[6][9] = '#';
			
			SetCursor(0, 0);
			PrintFields(Field, Field_2, 1);
			Sleep(200);
			Field[5][9] = '.';
			Field[6][9] = '.';
			Field_2[5][5] = '.'; Field_2[6][5] = '.';
			SetCursor(100, 10); std::cout << ' ';
			SetCursor(103, 10); std::cout << ' ';
			SetCursor(106, 10); std::cout << ' ';
			SetCursor(109, 10); std::cout << ' ';
		}

		SetCursor(0, 0);
		PrintFields(Field, Field_2, 1);
		
		Sleep(200);
		Field[5][rpos - 1] = '.'; Field[5][rpos] = '#'; Field[5][rpos + 1] = '#';
		++steps;
		++rpos;
	}
}

std::pair<size_t, size_t> TimePermutations(size_t millisec)
{
	size_t seconds = millisec / 1000;
	size_t secs = seconds % 60;
	size_t mins = seconds / 60;
	return std::make_pair(mins, secs);
}

void SetCursor(SHORT x, SHORT y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ChangeColour(size_t c)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(c));
}

