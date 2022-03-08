#include <stdio.h>
#include "CheckChargingCurrentRange.h"

int CheckChargingCurrentSamplesRange (int *CurrentSamples){
  int NumOfCurrentSamples;
  int NumOfConsecutiveRange=0;
  int DifferenceBetweenSamples;
  int LoopIndex;
  
  NumOfCurrentSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  /* Sort array */
  int Temp;
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    for (int innerLoopIndex = LoopIndex+1 ; innerLoopIndex<NumOfCurrentSamples ; innerLoopIndex++) {
      if(CurrentSamples[LoopIndex] > CurrentSamples[innerLoopIndex]) {    
               Temp = CurrentSamples[LoopIndex];    
               CurrentSamples[LoopIndex] = CurrentSamples[innerLoopIndex];    
               CurrentSamples[innerLoopIndex] = Temp;   
      }
    }
  }
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    printf("%d element : %d \n",LoopIndex,CurrentSamples[LoopIndex]);
  }
  for (LoopIndex = 0; LoopIndex< (NumOfCurrentSamples-1) ; LoopIndex++) {
    DifferenceBetweenSamples = CurrentSamples[LoopIndex + 1] - CurrentSamples[LoopIndex];
    if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1)){
      NumOfConsecutiveRange ++;
    }
  }
       return NumOfConsecutiveRange+1;
}
