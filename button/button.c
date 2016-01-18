#include "button.h"
#include "io_pins.h"
#include "timer.h"

#define DEBOUNCE_MILLISECONDS 10

static millisecond_ticks_t buttonLastInterruptTicks;
static bool buttonDown;

void Button_Initialise(void)
{
  buttonLastInterruptTicks = GetSystemTicks();
  buttonDown = false;
}

static millisecond_ticks_t TimeSinceLastInterrupt(void)
{
  return GetSystemTicks() - buttonLastInterruptTicks;
}

bool Button_IsPressed(void)
{
  return buttonDown && (TimeSinceLastInterrupt() >= DEBOUNCE_MILLISECONDS);
}

void Button_Interrupt(void)
{
  buttonDown = ReadButtonPinState() == io_pin_state_low;
  buttonLastInterruptTicks = GetSystemTicks();
}