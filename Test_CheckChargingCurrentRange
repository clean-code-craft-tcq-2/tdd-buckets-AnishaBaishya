#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CheckChargingCurrentRange.h"

// Test Instance 1 : before starting the coding : BUILD FAILURE
TEST_CASE("Test Instance 1 : Check range for 2 consecutive current samples") {
  int CurrentSamples[] = {4,5};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples) == 1);
}
