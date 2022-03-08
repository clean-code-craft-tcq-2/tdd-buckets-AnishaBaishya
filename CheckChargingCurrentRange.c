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
  printf("DifferenceBetweenSamples %d \n",DifferenceBetweenSamples);
  if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
  {
    ConsecutiveSample = 1;
  }   
  return ConsecutiveSample;
}

int CheckChargingCurrentSamplesRange (int *CurrentSamples, int NumOfCurrentSamples){
  int NumOfConsecutiveRange = 0;
  int NumOfChargingCurrentRanges = 0;
  int ConsecutiveSample;
  int LoopIndex;
  
  SortArray(CurrentSamples,NumOfCurrentSamples);
  
  for (LoopIndex = 0; LoopIndex< (NumOfCurrentSamples-1) ; LoopIndex++) {
    ConsecutiveSample = FindConsecutiveSamples(CurrentSamples[LoopIndex],CurrentSamples[LoopIndex+1]);
    printf("ConsecutiveSample %d \n",ConsecutiveSample);
    //NumOfConsecutiveRange = NumOfConsecutiveRange+ConsecutiveSample;
    if(!ConsecutiveSample){
      printf("NumOfChargingCurrentRanges1 %d \n",NumOfChargingCurrentRanges);
      NumOfChargingCurrentRanges++;
    }
    if(LoopIndex == (NumOfCurrentSamples-2)){
      NumOfChargingCurrentRanges++;
      printf("NumOfChargingCurrentRanges2 %d \n",NumOfChargingCurrentRanges);
    }
  }
  printf("NumOfChargingCurrentRanges3 %d \n",NumOfChargingCurrentRanges);
  return NumOfChargingCurrentRanges;
}
