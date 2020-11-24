#pragma once
#include <windows.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <utility>
#include <future>
#include <functional>
#include "CheckersAndGenerators.h"

void ChangeColour(size_t c);
void SetCursor(SHORT x, SHORT y);
void PrintInterface(char& df, char& mode);
void CenrtreConsole();
void InvisibleCursor();
std::pair<size_t, size_t> TimePermutations(size_t millisec);
void PrintShootInstructions();