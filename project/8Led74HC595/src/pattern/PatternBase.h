#ifndef _PATTERN_BASE_H
#define _PATTERN_BASE_H

#if ARDUINO < 100
#error Unsupported version.  Must be v100+.
#endif

#include "Arduino.h"

struct PatternDelay
{
	byte Pattern;
	int Delay;
};

class IPattern
{
	public:
		const virtual int getCount () const = 0;
		const virtual byte getPattern (int i) const = 0;
		const virtual int getDelay (int i) const = 0;
};

class InMemPatternBase : public IPattern
{
	public:
		const virtual int getCount () const { return getLength(); }
		const virtual byte getPattern (int i) const { return getSequence()[i].Pattern; }
		const virtual int getDelay (int i) const { return getSequence()[i].Delay; }

	protected:
		const virtual PatternDelay* getSequence () const = 0;
		const virtual int getLength () const = 0;
};

#endif /* _PATTERN_BASE_H */
