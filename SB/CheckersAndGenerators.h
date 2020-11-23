#pragma once
#include <utility>
#include <cinttypes>
#include <ctime>
#include <vector>
#include <random>

using field = std::vector<std::vector<char>>;

class RandomGenerator
{
public:
	RandomGenerator();
	std::pair<uint16_t, uint16_t> GetRandCoords();
	uint16_t CooseOne();
	uint16_t CooseEight();
private:
	uint16_t seed;
	void IncreaseSeed();
	uint16_t PRNG();
};
void SetNerbyCoords(const field& source, field& gamef, uint16_t X, uint16_t Y, char chr_1, char chr_2);
bool CheckNerbyCoord(const field& source, uint16_t X, uint16_t Y);
field GenField(const uint16_t sz);
void PrintField(const field& gameField, uint16_t Xc, uint16_t Yc);
void PrintFields(const field& f1, const field& f2, uint16_t mode);



