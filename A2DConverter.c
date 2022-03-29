#include <stdio.h>
#include <cmath>
#include "A2DConverter.h"


void PrintReadingFaultyMessage(void)
{
	printf("Readings are faulty\n");
}

int GetMaxValueOfConverter(int A2D_RESOLUTION)
{
	return (pow(2,A2D_RESOLUTION) - 2);
}

void AtoDConvert(int CurrentSamplesAnalog[],int NumOfCurrentSamples,int CurrentSamplesDigital[]){
	int loopIndex;
	float currentCurrentValue;
	
	for (int loopIndex=0; loopIndex< NumOfCurrentSamples; loopIndex++){
		currentCurrentValue = ((MAXCURRENTVALUE  * CurrentSamplesAnalog[loopIndex]) / (GetMaxValueOfConverter(A2D_RESOLUTION)));
		CurrentSamplesDigital[loopIndex] = round(currentCurrentValue);
	}
}

bool ConvertAnalogToDigitalAmpere(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital){
  bool AreAllSamplesOk = ALL_SAMPLES_OK;
  int loopIndex;
  
  for(loopIndex=0;loopIndex<NumOfCurrentSamples;loopIndex++){
    if(CurrentSamplesAnalog[loopIndex] > (GetMaxValueOfConverter(A2D_RESOLUTION))){
	AreAllSamplesOk = ALL_SAMPLES_NOT_OK;
	PrintReadingFaultyMessage();	
	break;
	}
  }
  if(AreAllSamplesOk == ALL_SAMPLES_OK)
  {
    AtoDConvert(CurrentSamplesAnalog, NumOfCurrentSamples,CurrentSamplesDigital);
  }
  
  return AreAllSamplesOk ;
}
