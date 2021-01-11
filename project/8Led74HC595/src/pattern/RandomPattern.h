#ifndef _RANDOM_PATTERN_H
#define _RANDOM_PATTERN_H

#include "PatternBase.h"

class RandomPattern : public IPattern
{
	public:
		RandomPattern () : IPattern() {}
		const int getCount () const override { return 24; }
		const byte getPattern (int i) const override { return random(0, 255); }
		const int getDelay (int i) const override { return 100; }
};

#endif /* _RANDOM_PATTERN_H */
