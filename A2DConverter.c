#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "A2DConverter.h"


void PrintReadingFaultyMessage(void)
{
	printf("Readings are faulty\n");
}

float convertInputIntegerToCurrentValue(float conversionValue, float scalingFactor, int MinCurrentValue, int MaxCurrentValue){
	float currentValue;	
	currentValue = MinCurrentValue + (MaxCurrentValue * conversionValue * scalingFactor);
	return currentValue;
}

int calculateTotalCurrentRange(int maxCurrentValue, int minCurrentValue) {
	int totalCurrentRange;
	totalCurrentRange = maxCurrentValue - minCurrentValue;
	return totalCurrentRange;
}

float calculateMultiplyingFactor(int x, int y) {
	float multiplyingFactor;
	multiplyingFactor = float(x) / float(y);
	return multiplyingFactor;
}

int GetMaxValueOfConverter(int ResolutionSize)
{
	return (pow(2,ResolutionSize) - 2);
}

void AtoDConvert(int CurrentSamplesAnalog[],int NumOfCurrentSamples,int CurrentSamplesDigital[],int A2DResolution, int MaxCurrentValue, int MinCurrentValue){
	int loopIndex;
	int totalCurrentRange;
	float currentCurrentValue;
	int maxConverterValue; 
	float conversionValue;
	float scalingFactor;
	
	maxConverterValue = GetMaxValueOfConverter(A2DResolution);
	totalCurrentRange = calculateTotalCurrentRange(MaxCurrentValue, MinCurrentValue);
	scalingFactor = calculateMultiplyingFactor(totalCurrentRange, MaxCurrentValue);
	for (loopIndex=0; loopIndex< NumOfCurrentSamples; loopIndex++){
		conversionValue = calculateMultiplyingFactor(CurrentSamplesAnalog[loopIndex], maxConverterValue);
		currentCurrentValue = convertInputIntegerToCurrentValue(conversionValue, scalingFactor, MinCurrentValue, MaxCurrentValue);
		CurrentSamplesDigital[loopIndex] = round(currentCurrentValue);
		if(CurrentSamplesDigital[loopIndex] <0){
			CurrentSamplesDigital[loopIndex] = abs(CurrentSamplesDigital[loopIndex]);
		}
	}
}

bool ConvertAnalogToDigitalAmpere(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital,int A2DResolution, int MaxCurrentValue, int MinCurrentValue){
  bool AreAllSamplesOk = ALL_SAMPLES_OK;
  int loopIndex;
  
  for(loopIndex=0;loopIndex<NumOfCurrentSamples;loopIndex++){
    if(CurrentSamplesAnalog[loopIndex] > (GetMaxValueOfConverter(A2DResolution))){
	AreAllSamplesOk = ALL_SAMPLES_NOT_OK;
	PrintReadingFaultyMessage();	
	break;
	}
  }
  if(AreAllSamplesOk == ALL_SAMPLES_OK)
  {
	 AtoDConvert(CurrentSamplesAnalog, NumOfCurrentSamples,CurrentSamplesDigital,int A2DResolution, int MaxCurrentValue, int MinCurrentValue);
  }
  
  return AreAllSamplesOk ;
}
