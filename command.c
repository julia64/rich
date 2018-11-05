#include "command.h"

/**判断是否为全局命令quit/query/help
* \param (char*)玩家输入
* \param (int)当前玩家索引
* \return (int)QUIT/QUERY/HELP default:0
*/
int judgeGlobalCmd(char *cmd,int i){
    if(strncasecmp(cmd,"quit",4)==0){
        exit(0);
        return QUIT;
    }
    else if(strncasecmp(cmd,"query",5)==0){
        printf("你当前的资产为：%d元\n",players[i].money);
        printf("你当前的点数为：%d\n%c >",players[i].point,players[i].name);
        //要不要显示房产
        return QUERY;
    }
    else if(strncasecmp(cmd,"help",4)==0){
        printf(":)\n%c >",players[i].name);
        return HELP;
    }
    else return 0;
}

/**判断是否为y/n，若为"y"，返回1；若为"n",返回1；若为“quit”，退出;若为其他，则提示，并重新输入
* \param (char*)玩家输入
* \param (int)当前玩家索引
* \return (int)"y"-1,非"y"-0
*/
int yesOrNo(char *cmd,int i)
{
     while(strcasecmp(cmd,"y")!=0){
        if(strcasecmp(cmd,"n")==0){
            break;
        }
        else if(strcasecmp(cmd,"quit")==0)
        {
            //exit(0);
        }
        else{
            printf("请输入y/n\n");
            printf("%c >",players[i].name);
            fflush(stdin);
            memset(cmd,'\0',sizeof(cmd));
            scanf("%s",cmd);
        }
    }
    if(strcasecmp(cmd,"y")==0) return 1;
    else return 0;
}
