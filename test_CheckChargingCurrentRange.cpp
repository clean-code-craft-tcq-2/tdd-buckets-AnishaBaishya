#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CheckChargingCurrentRange.h"
#include "A2DConverter.h"

#define A2D_RESOLUTION  12
#define MAXCURRENTVALUE 10
#define MINCURRENTVALUE 0

// Test Instance 1 : before starting the coding : TC FAILED
TEST_CASE("Test Instance 1 : Check range for 2 consecutive current samples") {
  int CurrentSamples[] = {4,5};
  int numberOfSamples = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples,numberOfSamples) == 1);
}
// Test Instance 1 : TC PASSED after adding Code

// Test Instance 2 : before starting the coding : TC FAILURE
TEST_CASE("Test Instance 2 : Check range for samples not available in sorted format") {
  int CurrentSamples[] = {4,6,5};
  int numberOfSamples = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples,numberOfSamples) == 1);
}
// Test Instance 2 : TC PASSED after adding Code

// Test Instance 3 : before starting the coding : TC FAILURE
TEST_CASE("Test Instance 3 : Check range for 3 current samples with first and last input being consecutive") {
  int CurrentSamples[] = {4,10,5};
  int numberOfSamples = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples, numberOfSamples) == 2);
}
// Test Instance 3 : TC PASSED after adding Code

// Test Instance 4 : before starting the coding : TC PASSED
TEST_CASE("Test Instance 4 : Check range for 4 current samples") {
  int CurrentSamples[] = {4,10,5,11};
  int numberOfSamples = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples, numberOfSamples) == 2);
}

// Test Instance 5 : before starting the coding : TC PASSED
TEST_CASE("Test Instance 5 : Check range for example current samples") {
  int CurrentSamples[] = {3, 3, 5, 4, 10, 11, 12};
  int numberOfSamples = sizeof(CurrentSamples) / sizeof(CurrentSamples[0]);
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamples, numberOfSamples) == 2);
}
  
//A2D Conversion
// Test Instance 1 
TEST_CASE("Test Instance 1 : Error Reading available") {
  int CurrentSamplesAnalog[] = {4095};
  int numberOfSamples = sizeof(CurrentSamplesAnalog) / sizeof(CurrentSamplesAnalog[0]);
  int CurrentSamplesDigital[numberOfSamples];
  REQUIRE(ConvertAnalogToDigitalAmpere(CurrentSamplesAnalog, numberOfSamples,CurrentSamplesDigital,A2D_RESOLUTION,MAXCURRENTVALUE,MINCURRENTVALUE) == ALL_SAMPLES_NOT_OK);
}

// Test Instance 2 
TEST_CASE("Test Instance 2 : Test Conversion and Setting of Ranges for 12 bit") {
  int CurrentSamplesAnalog[] = {4094, 819,3790,1230,1640,2870};
  int numberOfSamples = sizeof(CurrentSamplesAnalog) / sizeof(CurrentSamplesAnalog[0]);
  int CurrentSamplesDigital[numberOfSamples];
  
  int ExpectedCurrentinAmps[] = {10, 2, 9, 3, 4 , 7};
  REQUIRE(ConvertAnalogToDigitalAmpere(CurrentSamplesAnalog, numberOfSamples,CurrentSamplesDigital,A2D_RESOLUTION,MAXCURRENTVALUE,MINCURRENTVALUE) == ALL_SAMPLES_OK);
  for(int i = 0; i < numberOfSamples; ++i)
	{
		REQUIRE(CurrentSamplesDigital[i] == ExpectedCurrentinAmps[i]);
	}
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamplesDigital, numberOfSamples) == 3);
}

// Test Instance 3 
#define A2D_RESOLUTION  10
#define MAXCURRENTVALUE 15
#define MINCURRENTVALUE -15

TEST_CASE("Test Instance 3 : Test Conversion and Setting of Ranges for 10 bit") {
  int CurrentSamplesAnalog[] = {1022,511,0};
  int numberOfSamples = sizeof(CurrentSamplesAnalog) / sizeof(CurrentSamplesAnalog[0]);
  int CurrentSamplesDigital[numberOfSamples];
  
  int ExpectedCurrentinAmps[] = {15,0,15};
  REQUIRE(ConvertAnalogToDigitalAmpere(CurrentSamplesAnalog, numberOfSamples,CurrentSamplesDigital,A2D_RESOLUTION,MAXCURRENTVALUE,MINCURRENTVALUE) == ALL_SAMPLES_OK);
  for(int i = 0; i < numberOfSamples; ++i)
	{
		REQUIRE(CurrentSamplesDigital[i] == ExpectedCurrentinAmps[i]);
	}
  REQUIRE(CheckChargingCurrentSamplesRange(CurrentSamplesDigital, numberOfSamples) == 2);
}
	
