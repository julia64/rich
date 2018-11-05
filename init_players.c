#include "init_players.h"

int init()
{
    char cmd[10];
    char roles[10];
    int initMoney = 0;

    printf("角色1：钱夫人（Q）\n");
    printf("角色2：阿土伯（A）\n");
    printf("角色3：孙小美（S）\n");
    printf("角色4：金贝贝（J）\n");

    do
    {
        printf("请依次输入2-4个角色编号，建立您想要建立的玩家角色（不可选择同一角色）：");
        memset(roles, 0, sizeof(roles));
        scanf("%4s",&roles);
        if(strcasecmp(&roles,"quit")==0){
            exit(0);
        }
        printf("\n");
        printf("请输入初始财产：");
        memset(cmd, 0, sizeof(cmd));
        scanf("%5s",&cmd);
        if(strcasecmp(&cmd,"quit")==0){
            exit(0);
        }
        sscanf(cmd,"%d",&initMoney);
        printf("\n");
    }while(!initPlayers(&roles,initMoney,players));

    initMap();                                     //初始化地图
    showMap();
    return config.playerNum;
}

char initPlayers(char const* num,int mon,PLAYER *playerR)
{
    //PLAYER player[4];
    PLAYER player[4];
    char name[] = "QASJ";
	//int part[4];

    int i = 0;
	while (num[i] != '\0')
	{
		i++;
	}
    if(i<=4&&i>=2)
    {
		int j;
		int a[4];
		for (j = 0; j < i; j++)
		{
		    player[j].state = NORMAL;
			player[j].stay = 0;
			player[j].tools.block = 0;
			player[j].tools.bomb = 0;
			player[j].tools.robot = 0;
			switch (num[j])  //init name
			{
			case '1': {
				if (a[0] != 1)
				{
					a[0] = 1;
					player[j].name = name[0];
				}
				else
				{
					printf("error! Same players!\n");
					return F_FAIL;
				}
			}
				break;
			case '2': {
				if (a[1] != 2)
				{
					a[1] = 2;
					player[j].name = name[1];
				}
				else
				{
					printf("error! Same players!\n");
					return F_FAIL;
				}
			}
					  break;
			case '3': {
				if (a[2] != 3)
				{
					a[2] = 3;
					player[j].name = name[2];
				}
				else
				{
					printf("error! Same players!\n");
					return F_FAIL;
				}
			}
					  break;
			case '4': {
				if (a[3] != 4)
				{
					a[3] = 4;
					player[j].name = name[3];
				}
				else
				{
					printf("error! Same players!\n");
					return F_FAIL;
				}
			}
					  break;
			default: {
				printf("error! Wrong character entered\n");
				return F_FAIL;
			}
			}
			if(mon<=50000&&mon>=1000)
                player[j].money = mon;
			else
			{
				printf("error! Entered an amount out of range\n");
				return F_FAIL;
			}
		}
        config.playerNum = i;
		config.money = mon;
		memcpy(maps[i].show,"0",6);
		memset(playerR ,     0,4* sizeof(player));
        memcpy(playerR,player,4* sizeof(player));
		return F_TRUE;
    }
    else
    {
		printf("error! Wrong the number of people who entered\n");
		return F_FAIL;
    }
}

