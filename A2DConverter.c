#include <stdio.h>
#include "A2DConverter.h"


void PrintReadingFaultyMessage(void)
{
	printf("Readings are faulty\n");
}


bool ConvertAnalogToDigitalAmpere(int *CurrentSamples,int NumOfCurrentSamples){
  bool AreAllSamplesOk = ALL_SAMPLES_OK;
  int loopIndex;
  
  for(loopIndex=0;loopIndex<NumOfCurrentSamples;loopIndex++){
    if(CurrentSamples[i] > 4094)
		{
      AreAllSamplesOk = ALL_SAMPLES_NOT_OK;
			PrintReadingFaultyMessage();	
      break;
		}
  }
  if(AreAllSamplesOk == ALL_SAMPLES_OK)
  {
    //Implement when all samples are ok
  }
  
  return AreAllSamplesOk ;
}
