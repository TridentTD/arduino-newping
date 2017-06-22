load("api_math.js");

let NEWPING = {
  _create: ffi('void *mgos_newping_create(int, int)'),
  _cls: ffi('void mgos_newping_close(void *)'),
  _pingcm: ffi('long  mgos_newping_ping_cm(void *)'),

  _proto: {
    // Close DHT handle. Return value: none.
    close: function() {
      return NEWPING._cls(this.newping);
    },

    ping_cm: function() {
      return NEWPING._pingcm(this.newping);
    },
  },

  // Create a NEWPING object.
  create: function(trigger_pin, echo_pin) {
    let obj = Object.create(NEWPING._proto);

    obj.newping = NEWPING._create(trigger_pin, echo_pin);
    return obj;
  },
};
