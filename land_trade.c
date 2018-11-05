#include "land_trade.h"

void landOp(int i,int playerNum)
{
    char cmd[10];
    if(maps[players[i].position].owner == '0')//是否为空地
    {
        if(players[i].money<maps[players[i].position].price){
            printf("资金不足，无法购买\n");
        }
        else{
            printf("是否要购买此空地（%d元)?y/n\n%c >",maps[players[i].position].price,players[i].name);                  //你买不买？
            //等待用户输入y/n
            fflush(stdin);
            scanf("%s",cmd);
            if(yesOrNo(cmd,i)){
                 landBuy(i);
                 changeMap(BUILD, players[i].position, players[i].position, players[i].name);
            }
        }
    }
    else if(players[i].name == maps[players[i].position].owner)           //哦是我的地
    {
        if(maps[players[i].position].level < FULLLEVEL)     //还没有满级的话
        {
            if(players[i].money<maps[players[i].position].price){
                printf("资金不足，无法升级\n");
            }
            else{
                printf("是否要将该处升级(%d元)?y/n\n%c >",maps[players[i].position].price,players[i].name);                  //你买不买？
                //等待用户输入y/n
                fflush(stdin);
                scanf("%s",cmd);
                if(yesOrNo(cmd,i)){
                     houseUpgrade(i);
                     changeMap(BUILD, players[i].position, players[i].position, players[i].name);
                }
            }
        }
    }
    else if(GAMEOVER != players[maps[players[i].position].owner].state)//是没有出局的别人的地
    {
        if(LUCKY != players[i].state)  //没有财神
        {
            landRent(i,playerNum);             //收租
            printf("玩家%c需付租金%d元,剩余%d元\n",players[i].name,(maps[players[i].position].price)/2,players[i].money);
        }
    }
    outJudge(i);
}

/** \brief 买地
* \param (PLAYERS *)当前玩家对象
* \return (int)当前玩家剩余钱数
*/
int landBuy(int i)
{
    int pay;        //当前所处空地的地价
    int money;    //当前用户的所有钱数
    int site;
    site = players[i].position;
    pay = maps[site].price;
    if(players[i].money<pay){
        printf("资金不足，无法购买\n");
    }
    else{
        players[i].money -= pay;   //买地后钱数减少
        (maps[site].level)++;                   //地产升级
        maps[site].owner = players[i].name; //地产所有者改变
    }
    return players[i].money;
}

/** \brief 卖地
* \param (PLAYERS *)当前玩家对象
* \return (int)当前玩家剩余钱数
*/
int landSell(int i)
{
    int sell;       //当前土地的抵押价格
    int site;        //当前所处位置索引
    site = players[i].position;  //根据玩家确定当前所处位置
    sell = 2*(maps[site].price*maps[site].level);
    players[i].money += sell;    //当前玩家钱数增加
    maps[site].level = 0;                   //土地变为空地
    maps[site].owner = '0';                 //土地所有者为无
    return players[i].money;
}

/** \brief 收租
* \param (PLAYERS *)当前玩家对象
* \param (int)玩家人数
* \return (int)当前玩家剩余钱数
*/
int landRent(int i,int playerNum)
{
    int rent;       //当前土地的租金
    char ownerName;         //土地所有者
    int site;        //当前所处位置索引
    int j = 0;
    site = players[i].position;
    ownerName = maps[site].owner;
    //找到土地所有者在整伦游戏中的次序，进而得到土地所有者的全部信息
    while((j<playerNum)&&(players[j].name!=ownerName)){
        j++;
    }
    rent = (maps[site].price)/2;
    players[i].money -= rent;    //当前玩家钱数减少
    players[j].money += rent;          //土地所有者钱数增加
    return players[i].money;
}

/** \brief 房产升级
* \param (PLAYERS *)当前玩家对象
* \return (int)当前玩家剩余钱数
*/
int houseUpgrade(int i)
{
    int pay;        //当前所处位置升级需付金额
    int site;          //当前玩家所处位置
    site = players[i].position;
    (maps[site].level)++;   //房产升级
    pay = maps[site].price;
    players[i].money -= pay;   //升级后钱数减少
    return players[i].money;
}

//破产判断
void outJudge(int i){
    int k;
    if(players[i].money < 0)   //没钱了
    {
        players[i].state = GAMEOVER;//凉了
        config.playerNum--;
        houseRecycle(i);
        if(config.playerNum>1){
            houseRecycle(i);
            printf("玩家%c破产，游戏继续\n",players[i].name);
        }
        else{
            for(k=0;k<4;k++){
                if(players[k].state == NORMAL){
                    printf("玩家%c破产，玩家%c获胜游戏结束\n",players[i].name,players[k].name);
                    getc(stdin);
                    exit(0);
                }
            }
        }
    }
    else printf("玩家%c还剩%d元\n",players[i].name,players[i].money);
}

//破产房产回收
void houseRecycle(int i)
{
    int j = 0;
    for(;j<70;j++){
        if(players[i].name == maps[j].owner){
            maps[j].owner = '0';
            maps[j].level = 0;
        }
    }
}

