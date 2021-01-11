#include "SplitCylonPattern.h"

const PatternDelay SplitCylonPattern::SEQUENCE[] =
{
	{ 0b00000000, 300 },
	{ 0b00011000, 200 },
	{ 0b00111100, 200 },
	{ 0b01100110, 200 },
	{ 0b11000011, 200 },
	{ 0b10000001, 200 },
	{ 0b00000000, 300 },
	{ 0b10000001, 200 },
	{ 0b11000011, 200 },
	{ 0b01100110, 200 },
	{ 0b00111100, 200 },
	{ 0b00011000, 200 }
};

const int SplitCylonPattern::LENGTH = sizeof(SplitCylonPattern::SEQUENCE) / sizeof(PatternDelay);
