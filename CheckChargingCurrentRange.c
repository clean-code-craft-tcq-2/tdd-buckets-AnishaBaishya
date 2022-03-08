#include <stdio.h>
#include "CheckChargingCurrentRange.h"

int CheckChargingCurrentSamplesRange (int *CurrentSamples, int NumOfCurrentSamples){
  int NumOfConsecutiveRange=0;
  int DifferenceBetweenSamples;
  int LoopIndex;
  int innerLoopIndex;
  
  /* Sort array */
  int Temp;
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    for (innerLoopIndex = (LoopIndex+1) ; innerLoopIndex<NumOfCurrentSamples ; innerLoopIndex++) {
      printf("LoopIndex %d , innerLoopIndex %d ,CurrentSamples[LoopIndex] %d ,CurrentSamples[innerLoopIndex] %d \n",LoopIndex,innerLoopIndex,CurrentSamples[LoopIndex],CurrentSamples[innerLoopIndex]);
      if(CurrentSamples[LoopIndex] > CurrentSamples[innerLoopIndex]) {    
               Temp = CurrentSamples[LoopIndex];    
               CurrentSamples[LoopIndex] = CurrentSamples[innerLoopIndex];    
               CurrentSamples[innerLoopIndex] = Temp;   
      }
    }
  }
  for (LoopIndex = 0; LoopIndex< (NumOfCurrentSamples-1) ; LoopIndex++) {
    DifferenceBetweenSamples = CurrentSamples[LoopIndex + 1] - CurrentSamples[LoopIndex];
    if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1)){
      NumOfConsecutiveRange ++;
    }
  }
       return NumOfConsecutiveRange+1;
}
