#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CheckChargingCurrentRange.h"

// Test Instance 1 : before starting the coding : TC FAILED
TEST_CASE("Test Instance 1 : Check range for 2 consecutive current samples") {
  int CurrentSamples[] = {4,5};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples,2) == 1);
}
// Test Instance 1 : TC PASSED after adding Code

// Test Instance 2 : before starting the coding : TC FAILURE
TEST_CASE("Test Instance 2 : Check range for samples not available in sorted format") {
  int CurrentSamples[] = {4,6,5};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples,3) == 1);
}
// Test Instance 2 : TC PASSED after adding Code

// Test Instance 3 : before starting the coding : TC FAILURE
TEST_CASE("Test Instance 3 : Check range for 3 current samples with first and last input being consecutive") {
  int CurrentSamples[] = {4,10,5};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples, 3) == 2);
}
// Test Instance 3 : TC PASSED after adding Code

// Test Instance 4 : before starting the coding : TC PASSED
TEST_CASE("Test Instance 4 : Check range for 4 current samples") {
  int CurrentSamples[] = {4,10,5,11};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples, 4) == 2);
}

// Test Instance 5 : before starting the coding : TC PASSED
TEST_CASE("Test Instance 5 : Check range for example current samples") {
  int CurrentSamples[] = {3, 3, 5, 4, 10, 11, 12};
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples, 7) == 2);
}
