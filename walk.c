#include "walk.h"

void rollAndJump(int i)
{
    char cmd[20];
    int step;
    int stepInput = 0;
    printf("请掷骰子(指令：Roll)\n%c >",players[i].name);
    fflush(stdin);
    memset(cmd,'\0',sizeof(cmd));
    fgets(cmd,10,stdin);
    fgets(cmd,10,stdin);
    //scanf("%s",&cmd);
    while(sscanf(cmd,"step %d",&stepInput)!=1 && strncasecmp(cmd,"roll",4)!=0){
        if(judgeGlobalCmd(cmd,i)==0){
            printf("请输入正确指令\n%c >",players[i].name);
        }
        fflush(stdin);
        memset(cmd,'\0',sizeof(cmd));
        fgets(cmd,10,stdin);

    }
    if(strncasecmp(cmd,"roll",4)==0)
    {
        step = 1+rand()%6; //生成骰子点数
    }
    else
    {
        step = stepInput;
    }
    printf("%c > 你的回合:你移动了%d格\r\n",players[i].name,step);
    //更改地图显示
    changeMap(WALK,
              players[i].position,
              (players[i].position+step)%70,
              players[i].name);
    //显示新地图
    showMap();
    players[i].position = (players[i].position+step)%70;
}
