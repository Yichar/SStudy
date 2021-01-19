#ifndef __CODE__H__
#define __CODE__H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>


void codestr(short *sstr, char *str, int len);
void decodestr(short *sstr, char *str, int len) ;
void codeFile(const char *SrcFile, const char *CodeFile);
void decodeFile(const char *CodeFile, const char *unCodeFile);



#endif