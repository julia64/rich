#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rich.h"
#include "command.h"
#include "init_players.h"		//初始化游戏配置
#include "map.h"		//有关地图的显示和改变的功能函数
#include "walk.h"		//有关掷骰子、跳转的功能函数
#include "land_trade.h"	//有关土地买、卖、收租的功能函数
#include "preset.h"
#include "tool.h"
#include "gift.h"
#include "site.h"


char temp[20] = "";
char *pt = temp;

int main(int argc, char **argv)
{
    int i = 0;
    int playerNum = 0;

    srand((int)time(0));                            //随机数种子
    playerNum = init();                             //初始化游戏
    dump(argv[1]);
    while(1 < playerNum)                            //如果两人以上人不破产
    {
        for(i = 0; i < config.playerNum ; i++) //每个玩家遍历
        {
            if(GAMEOVER== players[i].state)           //这个人已经凉了
                continue;
            if(NORMAL == players[i].state)           //如果可以走动，状态正常
            {
                rollAndJump(i);
                if(LAND == maps[players[i].position].type){ //是否为地
                    landOp(i,playerNum);
                }
				else if(HOSPITAL == maps[players[i].position].type)//医院
                {
                    historyOp(i);                   //进入医院
                }
                else if(TOOLSHOP == maps[players[i].position].type)//道具店
                {
                    toolOp(i);                    //进入道具店
                }
                else if(GIFTSHOP == maps[players[i].position].type)//礼物店
                {
                    giftOp(i);                    //进入礼物店
                }
				else if(JAIL == maps[players[i].position].type)//监狱
                {
                    jailOp(i);                    //进入监狱
                }
				else if(MAGICSHOP == maps[players[i].position].type)//魔法屋
                {
                    //magicShop();                    //进入魔法屋
                }
				else if(MINE == maps[players[i].position].type)//矿地
                {
                    mineOp(i);					//进入矿地
                }
            }
            else if(INHOSPITAL == players[i].state)       //受伤了
            {
                inStay(i,1);
            }
            else if(INJAIL     == players[i].state)       //进局子了
            {
                inStay(i,2);
            }

        }
        i = 0; //新的一轮
    }
    return 0;
}



