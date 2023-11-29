#ifndef __LANG_INCLUDE__
#define __LANG_INCLUDE__ 
//static char** MSG_DB;
#include "../libs.h"
char* getMsg(int msg);
extern bool initLang(void);
bool linitLang(void);
char* boolToText(bool b);
int YNmemStock(void);
char** getMSGDB(void);
void setMSGDB(char** v);
#endif