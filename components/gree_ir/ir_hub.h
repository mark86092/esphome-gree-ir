#pragma once

#include "esphome/components/climate_ir/climate_ir.h"
#include <map>
#include <tuple>

namespace esphome {
namespace gree_ir {

typedef std::tuple<const climate::ClimateMode, const climate::ClimateFanMode,
                   const int>
    IRConditionerConf;

class IRConditionerCode {
public:
  const int32_t *code;
};

const std::vector<int32_t> match(const IRConditionerConf);
const std::vector<int32_t> match(const climate::ClimateMode mode,
                                 const climate::ClimateFanMode fan_mode,
                                 const int target_temperature);

} // namespace gree_ir
} // namespace esphome
