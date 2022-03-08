#include <stdio.h>
#include "CheckChargingCurrentRange.h"

int CheckChargingCurrentSamplesRange (int *CurrentSamples){
  int NumOfCurrentSamples;
  int NumOfConsecutiveRange=0;
  int DifferenceBetweenSamples;
  int LoopIndex;
  
  NumOfCurrentSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    DifferenceBetweenSamples = CurrentSamples[LoopIndex + 1] - CurrentSamples[LoopIndex];
    if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1)){
      NumOfConsecutiveRange ++;
    }
  }
       return NumOfConsecutiveRange;
}
