#ifndef BUTTON_DEBOUNCE_BUTTON_H
#define BUTTON_DEBOUNCE_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void Button_Initialise(void);
bool Button_IsPressed(void);
void Button_Interrupt(void);

#ifdef __cplusplus
}
#endif

#endif //BUTTON_DEBOUNCE_BUTTON_H
