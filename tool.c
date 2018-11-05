void toolOp(int i){
    typedef struct
    {
        int block;	//路障
        int bomb;	//炸弹
        int robot;	//机器娃娃
    }TOOL;
    TOOL tools = {0,0,0};
    int point = 100;
    char name = 'C';
    char cmd[10];
    int length = tools.block + tools.bomb + tools.robot;
    if(point < 30){
        printf("您的点数不足以购买任何道具，欢迎下次再来");
        return;
    }
    if(length >= 10){
        printf("您最多可携带10个道具，欢迎下次再来");
        return;
    }
    drawToolHouse();
    while(1){
        printf("欢迎光临道具屋，您现在拥有点数%d，请选择您所需要的道具：(输入F退出)\n%c >",100,name);
        fflush(stdin);
        scanf("%s",cmd);
        if(strcasecmp(cmd,"F")==0){
            printf("已退出道具屋，欢迎下次再来");
            break;
        }else if(strcasecmp(cmd,"1")==0){   //路障
            printf("玩家拥有路障后，可将路障放置到离当前位置前后10步内的位置。任一玩家经过路障，都将被拦截。\n");
            if(point < 50){
                printf("您的点数不足以购买路障");
            }else{
                printf("购买路障需要点数50，请问是否购买？(y/n)\n%c >",name);
                fflush(stdin);
                scanf("%s",cmd);
                if(yesOrNo(cmd,i)){
                     point -= 50;
                     tools.block ++;
                     printf("购买成功，您目前还有点数%d。\n",point);
                     break;
                }
            }
        }else if(strcasecmp(cmd,"2")==0){   //炸弹
            printf("可将炸弹放置到离当前位置前后10步内的距离，任一玩家经过该位置，将被炸伤，送往医院，住院3天。\n");
            if(point < 50){
                printf("您的点数不足以购买炸弹");
            }else{
                printf("购买炸弹需要点数50，请问是否购买？(y/n)\n%c >",name);
                fflush(stdin);
                scanf("%s",cmd);
                if(yesOrNo(cmd,i)){
                     point -= 50;
                     tools.bomb ++;
                     printf("购买成功，您目前还有点数%d。\n",point);
                     break;
                }
            }
        }else if(strcasecmp(cmd,"3")==0){   //机器娃娃
            printf("使用该道具可清扫前方路面10步内的其他道具，如炸弹、路障。道具一次有效。\n");
            printf("购买炸弹需要点数50，请问是否购买？(y/n)\n%c >",name);
                fflush(stdin);
                scanf("%s",cmd);
                if(yesOrNo(cmd,i)){
                     point -= 50;
                     tools.bomb ++;
                     printf("购买成功，您目前还有点数%d。\n",point);
                     break;
                }
        }else{
            printf("输入F退出道具屋，输入序号1-3可查看并购买道具\n");
        }
    }
}

/** \brief 画道具屋
 *
 * \return void
 *
 */
void drawToolHouse(){
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
                printf("*///////          道具屋          ///////*");
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
            printf("*       1.路障         点数:50       *");
        }else if(i==5){
            printf("*       2.机器娃娃     点数:30       *");
        }else if(i==7){
            printf("*       3.炸弹         点数:50       *");
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

