#ifndef __APP_MYTIME_H
#define __APP_MYTIME_H

typedef struct 
{
    uint8_t  Hour;
    uint8_t  Minute;
    uint8_t  Second;
    uint16_t Year;
    uint8_t  Month;
    uint8_t  Day;
}mytime_t;

extern mytime_t myTime;
extern mytime_t myTimeTemp;

void MyTimeSecondRun(void);
void MyTimeFun(void);

#endif