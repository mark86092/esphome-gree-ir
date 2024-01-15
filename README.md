esphome-gree-ir
=====================

Control GREE HVAC with ESP8266, ESP32 by IR transmitter, based on the platform of [ESPHome](https://esphome.io/).


Circuit
=======

TODO

Usage
=====

1. Add external component

2. Configure climate

```
remote_transmitter:
  id: remote_transmitter_0
  pin: 4

climate:
- platform: gree_ir
  name: "gree climate"
  sensor: TEMPERATURE_SENSOR_ID
  transmitter_id: remote_transmitter_0
```
