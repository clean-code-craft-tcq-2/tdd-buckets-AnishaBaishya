#define ALL_SAMPLES_OK      1
#define ALL_SAMPLES_NOT_OK  0

bool ConvertAnalogToDigitalAmpere(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital,int A2DResolution, int MaxCurrentValue, int MinCurrentValue);
void PrintReadingFaultyMessage(void);
float convertInputIntegerToCurrentValue(float conversionValue, float scalingFactor, int MinCurrentValue, int MaxCurrentValue);
int calculateTotalCurrentRange(int maxCurrentValue, int minCurrentValue);
float calculateMultiplyingFactor(int x, int y);
int GetMaxValueOfConverter(int ResolutionSize);
void AtoDConvert(int CurrentSamplesAnalog[],int NumOfCurrentSamples,int CurrentSamplesDigital[],int A2DResolution, int MaxCurrentValue, int MinCurrentValue);
