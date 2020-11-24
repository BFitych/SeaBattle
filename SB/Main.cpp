#include "mainClasses.h"
#include <chrono>
#include <ctime>


void Parallel_generation(EnemyBattlefield& bf, char diff)
{
	bf.GenRandField(diff);
}

int main()
{
		system("cls");
		char diff;
		char mode;
		CenrtreConsole();
		InvisibleCursor();
		SetConsoleTitle("SeaBattle");
		PrintInterface(diff, mode);
		system("cls");
		EnemyBattlefield ebf;
		YourBattlefield ybf;
		std::thread t(Parallel_generation, std::ref(ebf), diff);
		t.detach();
		
		if (mode == '1') {
		ybf.SetShipCoords_2_0();
		}
		else if (mode == '2') {
			ybf.SetShipsCoords();
		}
		auto start = std::chrono::steady_clock().now();
		uint16_t counter_1 = 0;
		uint16_t counter_2 = 0;
		for (int i = 0; i < 100; ++i)
		{
			bool checker_1 = true;
			bool checker_2 = true;
			bool checker_3 = false;
			SetCursor(0, 0);
			PrintFields(ybf.GetField(), ebf.GetField(), 0);
			while (checker_2) {
				SetCursor(0, 17);
				std::cout << "                                                    \r";
				try {
					checker_2 = ebf.Shoot(ybf.GetField());
				}
				catch (std::exception e)
				{
					system("cls");
					SetCursor(58, 14);
					std::cout << e.what();
					checker_3 = true;
					auto finish = std::chrono::steady_clock().now();
					auto res = finish - start;
					SetCursor(47, 15);
					std::cout << "Press R to restart or ESC to exit";
					SetCursor(45, 16);
					auto time = TimePermutations(static_cast<size_t>(std::chrono::duration_cast<std::chrono::milliseconds>(res).count()));
					std::cout << "Last game lasted for: " << time.first << "mins and " << time.second << "secs";

					char checker;
					bool decision = false;
					while (!decision)
					{
						checker = _getch();
						if (checker == 'R' || checker == 'r')
						{
							main();
						}
						else if (checker == VK_ESCAPE)
						{
							system("cls");
							return 0;
						}
					}
				}
				if (checker_2) { ++counter_2; }
				SetCursor(0, 0);
				PrintFields(ybf.GetField(), ebf.GetField(), 0);
			}
			if(checker_3){}
			while (checker_1) {
				try {
					checker_1 = ybf.ComputerShoot();
				}
				catch (std::exception e)
				{
					system("cls");
					SetCursor(58, 14);
					std::cout << e.what();
					SetCursor(47, 15);
					std::cout << "Press R to restart or ESC to exit";
					SetCursor(45, 16);
					auto finish = std::chrono::steady_clock().now();
					auto res = finish - start;
					auto time = TimePermutations(static_cast<size_t>(std::chrono::duration_cast<std::chrono::milliseconds>(res).count()));
					std::cout << "Last game lasted for: " << time.first << "mins and " << time.second << "secs";
					SetCursor(0, 0);
					char checker;
					bool decision = false;
					while (!decision)
					{
						checker = _getch();
						if (checker == 'R' || checker == 'r')
						{
							main();
						}
						else if (checker == VK_ESCAPE)
						{
							system("cls");
							return 0;
						}
					}
				}
				if (checker_1) {
					++counter_1;
				}
				SetCursor(0, 0);
				PrintFields(ybf.GetField(), ebf.GetField(), 0);
			}

			if (counter_1 >= 20 || counter_2 >= 20) { break; }
			if (i == 50)
			{
				continue;
			}
		}
}
