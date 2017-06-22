

#include "NewPing.h"

#ifdef __cplusplus
extern "C"
{
#endif

NewPing       *mgos_newping_create(uint8_t trigger_pin, uint8_t echo_pin);
void           mgos_newping_close(NewPing *newping);
unsigned long  mgos_newping_ping_cm(NewPing *newping);

#ifdef __cplusplus
}
#endif  /* __cplusplus */
