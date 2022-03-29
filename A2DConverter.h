#define ALL_SAMPLES_OK      1
#define ALL_SAMPLES_NOT_OK  0

bool ConvertAnalogToDigitalAmpere(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital,int A2DResolution, int MaxCurrentValue, int MinCurrentValue);
void PrintReadingFaultyMessage(void);
