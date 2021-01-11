#include "src/pattern/ChopsticksPattern.h"
#include "src/pattern/CylonPattern.h"
#include "src/pattern/DrainPattern.h"
#include "src/pattern/FillPattern.h"
#include "src/pattern/RandomPattern.h"
#include "src/pattern/SplitCylonPattern.h"
#include "src/pattern/WalkingPattern.h"

// Definitions
#define LATCH_PIN 11    // (11) ST_CP [RCK] on 74HC595
#define CLOCK_PIN 9     //  (9) SH_CP [SCK] on 74HC595
#define DATA_PIN 12     // (12)    DS  [S1] on 74HC595
#define SW_ISR_VECTOR 0 // Pin 2 = ISR vector (0) for the switch

// Global Variables

// Declare and initialize the patterns.
static const ChopsticksPattern chop = ChopsticksPattern();
static const CylonPattern cylon = CylonPattern();
static const DrainPattern drain = DrainPattern();
static const FillPattern fill = FillPattern();
static const RandomPattern rando = RandomPattern();
static const SplitCylonPattern splitCylon = SplitCylonPattern();
static const WalkingPattern walk = WalkingPattern();

static const IPattern* patterns[] =
{
  &fill,
  &drain,
  &walk,
  &cylon,
  &splitCylon,
  &chop,
  &rando
};
static const int szPatterns = sizeof(patterns) / sizeof(IPattern*);

static volatile bool patternChangeRequested;
static volatile int currentPatternIdx;

void switchIsr ()
{
  patternChangeRequested = true;
//  Serial.println("patternChangeRequested = true");
}

void setup ()
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);  
  pinMode(CLOCK_PIN, OUTPUT);
  attachInterrupt(SW_ISR_VECTOR, switchIsr, FALLING);
//  Serial.begin(9600);
}

void updateShiftRegister (byte leds)
{
   digitalWrite(LATCH_PIN, LOW);
   shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
   digitalWrite(LATCH_PIN, HIGH);
}

void loop ()
{
  const IPattern *pattern = patterns[currentPatternIdx];
  
  for (int i = 0; i < pattern->getCount(); i++)
  {
    if (patternChangeRequested)
    {
      currentPatternIdx++;
      if (currentPatternIdx >= szPatterns) currentPatternIdx = 0;
//      Serial.print("currentPatternIdx = ");
//      Serial.println(currentPatternIdx, DEC);
      patternChangeRequested = false;
      return;
    }

    updateShiftRegister(pattern->getPattern(i));
    delay(pattern->getDelay(i));
  }
}
