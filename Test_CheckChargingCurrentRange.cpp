#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CheckChargingCurrentRange.h"

// Test Instance 1 : before starting the coding : BUILD PASSED after adding Code
TEST_CASE("Test Instance 1 : Check range for 2 consecutive current samples") {
  int CurrentSamples[] = {4,5};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples,2) == 2);
}

// Test Instance 2 : before starting the coding : BUILD FAILURE
TEST_CASE("Test Instance 2 : Check range for samples not available in sorted format") {
  int CurrentSamples[] = {4,6,5};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples,3) == 3);
}
