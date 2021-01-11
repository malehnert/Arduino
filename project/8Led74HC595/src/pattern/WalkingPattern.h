#ifndef _WALKING_PATTERN_H
#define _WALKING_PATTERN_H

#include "PatternBase.h"

class WalkingPattern : public InMemPatternBase
{
	protected:
		const PatternDelay* getSequence () const override { return SEQUENCE; };
		const int getLength () const override { return LENGTH; };

	private:
		static const PatternDelay SEQUENCE[];
		static const int LENGTH;
};

#endif /* _WALKING_PATTERN_H */
