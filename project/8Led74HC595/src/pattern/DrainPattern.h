#ifndef _DRAIN_PATTERN_H
#define _DRAIN_PATTERN_H

#include "PatternBase.h"

class DrainPattern : public IPattern
{
	public:
		DrainPattern () : IPattern() {}
		const int getCount () const override { return 9; }
		const int getDelay (int i) const override { return 200; }
		
		const byte getPattern (int i) const override
		{
			byte pattern = 255;
			for (int b = 0; b < i; b++)
			{
				bitClear(pattern, b);
			}
			return pattern;
		}
};

#endif /* _DRAIN_PATTERN_H */
