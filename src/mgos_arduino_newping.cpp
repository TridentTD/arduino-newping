

#include <math.h>
#include "mgos_arduino_newping.h"

#define MGOS_NEWPING_RES_FAIL -12700

NewPing *mgos_newping_create(uint8_t trigger_pin, uint8_t echo_pin) {
  return new NewPing(trigger_pin, echo_pin);
}

void mgos_newping_close(NewPing *newping) {
  if (newping != nullptr) {
    delete newping;
    newping = nullptr;
  }
}

unsigned long  mgos_newping_ping_cm(NewPing *newping) {
  if (newping == nullptr) return MGOS_NEWPING_RES_FAIL;
  float res = newping->ping_cm();
  return isnan(res) ? MGOS_NEWPING_RES_FAIL : res;
}
