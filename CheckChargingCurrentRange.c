#include <stdio.h>
#include "CheckChargingCurrentRange.h"

void SortArray(int ChargingCurrentSamplesArray[], int NumOfCurrentSamples){
  int Temp, LoopIndex, innerLoopIndex;
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    for (innerLoopIndex = (LoopIndex+1) ; innerLoopIndex<NumOfCurrentSamples ; innerLoopIndex++) {
      if(ChargingCurrentSamplesArray[LoopIndex] > ChargingCurrentSamplesArray[innerLoopIndex]) {    
               Temp = ChargingCurrentSamplesArray[LoopIndex];    
               ChargingCurrentSamplesArray[LoopIndex] = ChargingCurrentSamplesArray[innerLoopIndex];    
               ChargingCurrentSamplesArray[innerLoopIndex] = Temp;   
      }
    }
  }
}

int FindConsecutiveSamples(int Sample1,int Sample2)
{
  int DifferenceBetweenSamples;
  int ConsecutiveSample =0;
  DifferenceBetweenSamples = Sample2 - Sample1;
  if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
  {
    ConsecutiveSample = 1;
  }   
  return ConsecutiveSample;
}

int CheckChargingCurrentSamplesRange (int *CurrentSamples, int NumOfCurrentSamples){
  int NumOfConsecutiveRange = 0;
  int ConsecutiveSample;
  int LoopIndex;
  
  SortArray(CurrentSamples,NumOfCurrentSamples);
  
  for (LoopIndex = 0; LoopIndex< (NumOfCurrentSamples-1) ; LoopIndex++) {
    ConsecutiveSample = FindConsecutiveSamples(CurrentSamples[LoopIndex],CurrentSamples[LoopIndex+1]);
    NumOfConsecutiveRange = NumOfConsecutiveRange+ConsecutiveSample;
  }
  return NumOfConsecutiveRange+1;
}
