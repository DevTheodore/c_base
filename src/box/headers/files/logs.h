#ifndef __LOG_INCLUDE__
#define __LOG_INCLUDE__ 
#include "../libs.h"
#include "../syntax.h"


bool initLog(void);
bool openLog(void);
bool closeLog(void);
void LOG(int msg, int TYPE, char** param, int paramc);

#endif