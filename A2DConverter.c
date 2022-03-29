#include <stdio.h>
#include "A2DConverter.h"


void PrintReadingFaultyMessage(void)
{
	printf("Readings are faulty\n");
}

void AtoDConvert(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital){
	int loopIndex;
	float currentCurrentValue;
	
	for (int loopIndex=0; loopIndex< NumOfCurrentSamples; loopIndex++){
		currentCurrentValue = ((10 * CurrentSamplesAnalog[loopIndex]) / 4094);
		CurrentSamplesDigital[loopIndex] = round(currentCurrentValue);
		if(CurrentSamplesDigital[loopIndex] < 0)
		{
			CurrentSamplesDigital[loopIndex] = abs(CurrentSamplesDigital[loopIndex]);
		}
	}
}

bool ConvertAnalogToDigitalAmpere(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital){
  bool AreAllSamplesOk = ALL_SAMPLES_OK;
  int loopIndex;
  
  for(loopIndex=0;loopIndex<NumOfCurrentSamples;loopIndex++){
    if(CurrentSamplesAnalog[loopIndex] > 4094){
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
