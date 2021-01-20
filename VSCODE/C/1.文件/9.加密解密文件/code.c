#include "code.h"


void codestr(short *sstr, char *str, int len) {
    for(int i = 0; i < len; i++) {
       // printf("%c: ",str[i]);
       // printf(" 16进制：%x",str[i]);
        sstr[i] = ((short)str[i] << 4 ) | 0x8000  + rand()%16;
        
        // printf(" 16进制：%x",sstr[i]);
        // printf(" 16进制恢复：%c\n",(char)((sstr[i] << 1 ) >> 5));
    }
}

void decodestr(short *sstr, char *str, int len) {
    for (int i =0; i < len; i++) {
        str[i] = (char)((sstr[i] << 1 ) >> 5);
    }
    return;
}

void codeFile(const char *SrcFile, const char *CodeFile) {
    FILE *sfp = fopen(SrcFile, "r");
    if (sfp == NULL) return;

    FILE *cfp = fopen(CodeFile, "w+");
    if (cfp == NULL) return;

    char buf[1024];
    short sbuf[1024];
    int len = 0;
    while((len = fread(buf, 1, 1024, sfp)) > 0) {
        codestr(sbuf, buf, len);
        if (fwrite(sbuf, 2, len, cfp) != len) return;
    }
    fclose(sfp);
    fclose(cfp);
    return;

}

void decodeFile(const char *codeFile, const char *uncodeFile) {
     FILE *sfp = fopen(codeFile, "r");
    if (sfp == NULL) return;

    FILE *cfp = fopen(uncodeFile, "w+");
    if (cfp == NULL) return;

    char buf[1024];
    short sbuf[1024];
    int len = 0;
    while((len = fread(sbuf, 2, 1024, sfp)) > 0) {
        decodestr(sbuf, buf, len);
        if (fwrite(buf, 1, len, cfp) != len) return;
    }
    fclose(sfp);
    fclose(cfp);
    return;




}