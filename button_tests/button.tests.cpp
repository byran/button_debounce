#include "button.h"
#include "io_pins.h"
#include "timer.h"
#include <gmock/gmock.h>

using namespace ::testing;

extern "C"
{
  static enum io_pin_state buttonPinState = io_pin_state_low;
  enum io_pin_state ReadButtonPinState(void)
  {
    return buttonPinState;
  }

  static millisecond_ticks_t currentSystemTicks = 0;
  millisecond_ticks_t GetSystemTicks(void)
  {
    return currentSystemTicks;
  }
}

class button_tests : public ::testing::Test
{
public:
  virtual void SetUp() override
  {
    buttonPinState = io_pin_state_high;
    currentSystemTicks = 0;
  }

  void FakeSetButtonPin(enum io_pin_state state)
  {
    buttonPinState = state;
    Button_Interrupt();
  }

  void ElapseMilliseconds(millisecond_ticks_t ticks)
  {
    currentSystemTicks += ticks;
  }
};

TEST_F(button_tests, The_button_is_not_pressed_if_nothing_has_happened)
{
  Button_Initialise();

  ASSERT_FALSE(Button_IsPressed());
}

TEST_F(button_tests, The_button_is_not_pressed_if_the_pin_is_high)
{
  Button_Initialise();

  FakeSetButtonPin(io_pin_state_high);

  ASSERT_FALSE(Button_IsPressed());
}

TEST_F(button_tests, The_button_is_pressed_when_the_pin_has_been_low_for_10ms)
{
  Button_Initialise();

  FakeSetButtonPin(io_pin_state_low);
  ElapseMilliseconds(10);

  ASSERT_TRUE(Button_IsPressed());
}

TEST_F(button_tests, The_button_is_not_pressed_when_the_pin_has_been_low_for_less_than_10ms)
{
  Button_Initialise();

  FakeSetButtonPin(io_pin_state_low);
  ElapseMilliseconds(9);

  ASSERT_FALSE(Button_IsPressed());
}

TEST_F(button_tests, The_button_is_not_pressed_if_there_is_button_bounce_within_the_10ms_debounce_period)
{
  Button_Initialise();

  FakeSetButtonPin(io_pin_state_low);
  ElapseMilliseconds(5);
  FakeSetButtonPin(io_pin_state_high);
  ElapseMilliseconds(1);
  FakeSetButtonPin(io_pin_state_low);
  ElapseMilliseconds(9);

  ASSERT_FALSE(Button_IsPressed());
}
