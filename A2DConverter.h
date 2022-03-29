#define ALL_SAMPLES_OK      1
#define ALL_SAMPLES_NOT_OK  0

#define A2D_RESOLUTION  12
#define MAXCURRENTVALUE 10

bool ConvertAnalogToDigitalAmpere(int *CurrentSamplesAnalog,int NumOfCurrentSamples,int *CurrentSamplesDigital);
void PrintReadingFaultyMessage(void);
