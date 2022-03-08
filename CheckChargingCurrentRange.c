#include <stdio.h>
#include "CheckChargingCurrentRange.h"

void SortArray(int ChargingCurrentSamplesArray[], int NumOfCurrentSamples){
  int i = 0;
  while (++i < NumOfCurrentSamples)
  {
    if (ChargingCurrentSamplesArray[i] < ChargingCurrentSamplesArray[i-1])
    {
      int tmp = ChargingCurrentSamplesArray[i]; 
      ChargingCurrentSamplesArray[i] = ChargingCurrentSamplesArray[i-1];
      ChargingCurrentSamplesArray[i-1] = tmp;
      i = 0;
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

void PrintFunction(int MinRangeValue, int MaxRangeValue, int NumOfOccurenceInRange){
  printf("\n%d-%d , %d", MinRangeValue, MaxRangeValue, NumOfOccurenceInRange);
}

int CheckChargingCurrentSamplesRange (int *CurrentSamples, int NumOfCurrentSamples){
  int NumOfConsecutiveRange = 0;
  int NumOfChargingCurrentRanges = 0;
  int ConsecutiveSample;
  int LoopIndex;
  
  SortArray(CurrentSamples,NumOfCurrentSamples);
  LowerRangeValue = CurrentSamples[0];
  for (LoopIndex = 0; LoopIndex< (NumOfCurrentSamples-1) ; LoopIndex++) {
    ConsecutiveSample = FindConsecutiveSamples(CurrentSamples[LoopIndex],CurrentSamples[LoopIndex+1]);
    NumOfConsecutiveRange = NumOfConsecutiveRange+ConsecutiveSample;
    if(!ConsecutiveSample){
      PrintFunction(LowerRangeValue,CurrentSamples[LoopIndex] , (NumOfConsecutiveRange+1));
      LowerRangeValue = CurrentSamples[LoopIndex+1];
      NumOfConsecutiveRange = 0;
      NumOfChargingCurrentRanges++;
    }
    if(LoopIndex == (NumOfCurrentSamples-2)){
      PrintFunction(LowerRangeValue,CurrentSamples[LoopIndex+1] , (NumOfConsecutiveRange+1));
      NumOfChargingCurrentRanges++;
    }
  }
  return NumOfChargingCurrentRanges;
}
