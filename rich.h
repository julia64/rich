#ifndef RICH_H_INCLUDED
#define RICH_H_INCLUDED

#define SITE_NUM 70
#define MAX_PLAYERS 4
#define FULLLEVEL   4
#define NORMAL      0
#define INHOSPITAL  1
#define INJAIL      2
#define GAMEOVER    3
#define LUCKY       4

#define WALK 1
#define BUILD 2

#define LAND 0
#define START 1
#define HOSPITAL 2
#define TOOLSHOP 3
#define GIFTSHOP 4
#define JAIL 5
#define MAGICSHOP 6
#define MINE 7

#define F_FAIL 0
#define F_TRUE 1
//全局指令标识
#define QUIT 1
#define QUERY 2
#define HELP 3

#define MAX_CMD_LENGTH 64

//定义道具对象
typedef struct
{
	int block;	//路障
	int bomb;	//炸弹
	int robot;	//机器娃娃
}TOOL;

//定义玩家对象
typedef struct {
    char name;
    char state;
    int point;
    int money;
    int position;
	int stay;	//进医院或进监狱将停留的天数
	TOOL tools;
}PLAYER;

//定义地图位置对象
typedef struct
{
    int type;   //0:土地 1:Start 2:H医院 3:T道具屋 4:G礼品屋 5:P监狱 6:M魔法屋 7:$矿地 8:角色
    char owner; //归属者：'0'-没有人归属,'Q'-钱夫人,'A'-阿土伯,'S'-孙小美,'J'-金贝贝
    int level;  //0:未被购买,1:已被购买的空地,2:茅屋,3:洋房,4:摩天楼
    int price;  //购买或升级需要的钱数
    char show[6];   //确定地图上显示的字母
}MAP;

//配置
typedef struct conf{
    int playerNum;
    int money;
}CONFIG;

MAP maps[SITE_NUM];
PLAYER players[MAX_PLAYERS];
CONFIG config;

#endif

