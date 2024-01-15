#pragma once

#include "esphome/components/climate_ir/climate_ir.h"

namespace esphome {
namespace gree_ir {

// Values for GREE IR Controllers
// Temperature
const uint8_t GREE_TEMP_MIN = 24; // Celsius
const uint8_t GREE_TEMP_MAX = 29; // Celsius
const float GREE_TEMP_STEP = 1.0f;
const bool GREE_SUPPORT_DRY = false;
const bool GREE_SUPPORT_FAN_ONLY = false;

class ConditionerConfig {
public:
  const climate::ClimateMode mode;
  const climate::ClimateFanMode fan_mode;
  const int target_temperature;
  const int32_t *code;
};

class GreeIRClimate : public climate_ir::ClimateIR {
public:
  GreeIRClimate()
      : climate_ir::ClimateIR(
            GREE_TEMP_MIN, GREE_TEMP_MAX, GREE_TEMP_STEP, GREE_SUPPORT_DRY,
            GREE_SUPPORT_FAN_ONLY,
            {climate::CLIMATE_FAN_AUTO, climate::CLIMATE_FAN_LOW,
             climate::CLIMATE_FAN_MEDIUM, climate::CLIMATE_FAN_HIGH},
            {climate::CLIMATE_SWING_BOTH}) {}

  climate::ClimateTraits traits() override;

protected:
  // Transmit via IR the state of this climate controller.
  void transmit_state() override;
  uint8_t temperature_();
};

} // namespace gree_ir
} // namespace esphome
