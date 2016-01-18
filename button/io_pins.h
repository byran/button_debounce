#ifndef BUTTON_DEBOUNCE_ROOT_IO_PINS_H
#define BUTTON_DEBOUNCE_ROOT_IO_PINS_H

#ifdef __cplusplus
extern "C" {
#endif

enum io_pin_state
{
  io_pin_state_high,
  io_pin_state_low
};

enum io_pin_state ReadButtonPinState(void);

#ifdef __cplusplus
}
#endif

#endif //BUTTON_DEBOUNCE_ROOT_IO_PINS_H_H
