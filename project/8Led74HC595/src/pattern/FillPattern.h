#ifndef _FILL_PATTERN_H
#define _FILL_PATTERN_H

#include "PatternBase.h"

class FillPattern : public IPattern
{
	public:
		FillPattern () : IPattern() {}
		const int getCount () const override { return 9; }
		const int getDelay (int i) const override { return 200; }
		
		const byte getPattern (int i) const override
		{
			byte pattern = 0;
			for (int b = 0; b < i; b++)
			{
				bitSet(pattern, b);
			}
			return pattern;
		}
};

#endif /* _FILL_PATTERN_H */
