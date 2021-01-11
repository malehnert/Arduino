#ifndef _SPLIT_CYLON_PATTERN_H
#define _SPLIT_CYLON_PATTERN_H

#include "PatternBase.h"

class SplitCylonPattern : public InMemPatternBase
{
	protected:
		const PatternDelay* getSequence () const override { return SEQUENCE; };
		const int getLength () const override { return LENGTH; };

	private:
		static const PatternDelay SEQUENCE[];
		static const int LENGTH;
};

#endif /* _SPLIT_CYLON_PATTERN_H */
