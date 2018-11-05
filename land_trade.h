#ifndef LAND_TRADE_H_INCLUDED
#define LAND_TRADE_H_INCLUDED

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "rich.h"
#include "command.h"
#include "map.h"

void landOp(int i,int playerNum);
//买地
int landBuy(int i);
//卖地
int landSell(int i);
//收租
int landRent(int i,int playerNum);
//房产升级
int houseUpgrade(int i);
//出局判断
void outJudge(int i);
//出局清空房产
void houseRecycle(int i);


#endif // LAND_TRADE_H_INCLUDED
