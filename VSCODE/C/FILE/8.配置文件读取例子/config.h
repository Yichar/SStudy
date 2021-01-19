#ifndef __CONFIG__H__
#define __CONFIG__H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>

typedef struct ConfigInfo {

    char key[64];
    char val[64];
    
}ConfigInfo;
int getFileLines(const char * path);
int isVaildlines(const char * str);
void parseFile(const char * filePath,int line,ConfigInfo **ConfigInfo);

char* getInfoByKey(char *key, ConfigInfo *configinfo, int len); 

void freeConfigInfo(ConfigInfo *configinfo);
#endif