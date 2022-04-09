
#include "config.h"
int isVaildLines(const char * str) {
    if (strchr(str,':') == NULL) 
        return 0;
    return 1;
}
int getFileLines(const char *filePath) {
    FILE* file = fopen(filePath,"r");
    if (file == NULL) {
        perror("fopen");
        return -1;
    }
    char buf[1024] = {0};
    int lines = 0;
    while (fgets(buf, 1024, file) != NULL) {
        if (isVaildLines(buf)) {
            lines++;
            memset(buf, 0, 1024);
        }
    }


    fclose(file);
    return lines;
    

}

void parseFile(const char * filePath,int lines,ConfigInfo **configinfo) {
    ConfigInfo * info = (ConfigInfo *)malloc(sizeof(ConfigInfo) * lines);

    if (info == NULL) return;

    FILE *file = fopen(filePath, "r");
    if (file == NULL) return;

    char buf[1024];
    int index = 0;
    while (fgets(buf, 1024, file) != NULL) {
        if (isVaildLines(buf)) {
            memset(info[index].key, 0, 64);
            memset(info[index].val, 0, 64);
            char *pos = strchr(buf,':');
            strncpy(info[index].key, buf, pos - buf);
            strncpy(info[index].val, pos + 1, strlen(pos+1) - 1);
            index++;
        }
        memset(buf, 0, 1024);
    }
    *configinfo = info;
}


char* getInfoByKey(char *key, ConfigInfo *configinfo, int len) {
    for (int i = 0; i < len; i++) {
        // printf("%s : %s\n",configinfo[i].key,configinfo[i].val);
        // printf("%s,|%s|\n", key, configinfo[i].key);
        // printf("%d,%d\n", strlen(key), strlen(configinfo[i].key));
        if (strcmp(key,configinfo[i].key) == 0)
            return configinfo[i].val;
    }
    return NULL;

}

void freeConfigInfo(ConfigInfo *configinfo) {
   
     if (configinfo != NULL) 
            free(configinfo);
 
    return;
}