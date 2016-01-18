#ifndef BUTTON_DEBOUNCE_ROOT_TIMER_H
#define BUTTON_DEBOUNCE_ROOT_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int millisecond_ticks_t;

millisecond_ticks_t GetSystemTicks(void);

#ifdef __cplusplus
}
#endif

#endif //BUTTON_DEBOUNCE_ROOT_TIMER_H
