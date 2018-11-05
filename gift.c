void giftOp(int i){
    char cmd[10];
    drawGiftHouse();
    printf("欢迎光临礼品屋，您现在拥有资金%d元，点数%d，请选择一件您喜欢的礼品：(请输入礼品序号)\n%c >",players[i].money,players[i].point,players[i].name);
    fflush(stdin);
    scanf("%s",cmd);
    if(strcasecmp(cmd,"1")==0){
		players[i].money += 2000;
        printf("您选择了奖金，获得2000元。\n现有资金%d元。\n",players[i].money);
    }else if(strcasecmp(cmd,"2")==0){
		players[i].point += 200;
        printf("您选择了点数卡，获得200点。\n现有点数%d。\n",players[i].point);
    }else if(strcasecmp(cmd,"3")==0){
		players[i].state = LUCKY
        printf("您选择了财神，获得财神附体状态，经过其他玩家地产均可免租金。5轮内有效。\n");
    }else{
        printf("输入错误，放弃本次机会。\n");
    }
}

/** \brief 画礼品屋
 *
 * \return void
 *
 */
void drawGiftHouse(){
    int i,j;//烟囱
    for(i=1;i<=3;i++){
        for(j=1;j<=35;j++){
            printf(" ");
        }
        for(j=1;j<=4;j++){
            if(i==1||j==1||j==4){
                printf("*");
            }else{
                printf("~");
            }
        }
        printf("\n");
    }
    for(i=4;i<=8;i++){
        for(j=1;j<=8-i;j++){
            printf(" ");
        }
        if(i==6){
                printf("*///////          礼品屋          ///////*");
        }else{
            for(j=1;j<=2*i+30;j++){
                if(i==8||i==4||j==1||j==2*i+30){
                    printf("*");
                }
                else{
                    printf("/");
                }
            }
        }
        printf("\n");
    }
    for(i=1;i<=10;i++){
        for(j=1;j<=4;j++){
            printf(" ");
        }
        if(i==3){
            printf("*              1.奖金                *");
        }else if(i==5){
            printf("*              2.礼品卡              *");
        }else if(i==7){
            printf("*              3.财神                *");
        }else{
            for(j=1;j<=38;j++){
                if(i==10||j==1||j==38){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

