#ifndef _CHOPSTICKS_PATTERN_H
#define _CHOPSTICKS_PATTERN_H

#include "PatternBase.h"

class ChopsticksPattern : public InMemPatternBase
{
	public:
		const int getDelay (int i) const override
		{
			static const int beat = 333;
			static const float duty = 0.67f;
			
			if (i % 2 == 0) return beat * duty;
			else return beat * (1 - duty);
		}

	protected:
		const PatternDelay* getSequence () const override { return SEQUENCE; };
		const int getLength () const override { return LENGTH; };

	private:
		static const PatternDelay SEQUENCE[];
		static const int LENGTH;
};

#endif /* _CHOPSTICKS_PATTERN_H */
