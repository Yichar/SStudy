#include "config.h"

int main()
{

    char filepath[128] = "./config.txt";
    int len = getFileLines(filepath);
    printf("文件有效行数为：%d\n", len);

    ConfigInfo *configInfo = (ConfigInfo *)malloc(sizeof(ConfigInfo) * 5);

    parseFile(filepath, len, &configInfo);

    printf("英雄ID：%s\n", getInfoByKey("heroID", configInfo, len));
    printf("英雄姓名：%s\n", getInfoByKey("heroName", configInfo, len));
    printf("英雄攻击：%s\n", getInfoByKey("heroAtk", configInfo, len));
    printf("英雄防御：%s\n", getInfoByKey("heroDef", configInfo, len));
    printf("英雄描述：%s\n", getInfoByKey("heroInfo", configInfo, len));
    printf("英雄装备：%s\n", getInfoByKey("heroZB", configInfo, len) ? getInfoByKey("heroZB", configInfo, len) : "没查到" );


    freeConfigInfo(configInfo);
    configInfo = NULL;
    return 0;
}