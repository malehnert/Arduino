#include "WalkingPattern.h"

const PatternDelay WalkingPattern::SEQUENCE[] =
{
	{ 0b10000000, 100 },
	{ 0b11000000, 100 },
	{ 0b11100000, 100 },
	{ 0b01110000, 100 },
	{ 0b00111000, 100 },
	{ 0b00011100, 100 },
	{ 0b00001110, 100 },
	{ 0b00000111, 100 },
	{ 0b00000011, 100 },
	{ 0b00000001, 100 },
	{ 0b10000000, 100 },
	{ 0b11000000, 100 },
	{ 0b11100000, 100 },
	{ 0b01110000, 100 },
	{ 0b00111000, 100 },
	{ 0b00011100, 100 },
	{ 0b00001110, 100 },
	{ 0b00000111, 100 },
	{ 0b00000011, 100 },
	{ 0b00000001, 100 }
};

const int WalkingPattern::LENGTH = sizeof(WalkingPattern::SEQUENCE) / sizeof(PatternDelay);
