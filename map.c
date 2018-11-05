#include "map.h"

/** \brief 初始化地图结构体
 *
 * \return void
 *
 */
void initMap(){
    int i;
    //初始化S
    maps[0].type = START;
    maps[0].owner = '0';
    maps[0].level = 0;
    maps[0].price = 0;
    //maps[0].show[0] = 'S';
    //maps[0].show[1] = '\0';
    memcpy(maps[0].show,"I",6);
    for(i=1;i<=13;i++){
        maps[i].type = LAND;
        maps[i].owner = '0';
        maps[i].level = 0;
        maps[i].price = 200;
        memcpy(maps[i].show,"0",6);
    }
    //初始化医院
    maps[14].type = HOSPITAL;
    maps[14].owner = '0';
    maps[14].level = 0;
    maps[14].price = 0;
    memcpy(maps[14].show,"H",6);
    for(i=15;i<=27;i++){
        maps[i].type = LAND;
        maps[i].owner = '0';
        maps[i].level = 0;
        maps[i].price = 200;
        memcpy(maps[i].show,"0",6);
    }
    //初始化道具屋
    maps[28].type = TOOLSHOP;
    maps[28].owner = '0';
    maps[28].level = 0;
    maps[28].price = 0;
    memcpy(maps[28].show,"T",6);
    for(i=29;i<=34;i++){
        maps[i].type = LAND;
        maps[i].owner = '0';
        maps[i].level = 0;
        maps[i].price = 500;
        memcpy(maps[i].show,"0",6);
    }
    //初始化礼品屋
    maps[35].type = GIFTSHOP;
    maps[35].owner = '0';
    maps[35].level = 0;
    maps[35].price = 0;
    memcpy(maps[35].show,"G",6);
    for(i=36;i<=48;i++){
        maps[i].type = LAND;
        maps[i].owner = '0';
        maps[i].level = 0;
        maps[i].price = 300;
        memcpy(maps[i].show,"0",6);
    }
    //初始化监狱
    maps[49].type = JAIL;
    maps[49].owner = '0';
    maps[49].level = 0;
    maps[49].price = 0;
    memcpy(maps[49].show,"P",6);
    for(i=50;i<=62;i++){
        maps[i].type = LAND;
        maps[i].owner = '0';
        maps[i].level = 0;
        maps[i].price = 300;
        memcpy(maps[i].show,"0",6);
    }
    //初始化魔法屋
    maps[63].type = MAGICSHOP;
    maps[63].owner = '0';
    maps[63].level = 0;
    maps[63].price = 0;
    memcpy(maps[63].show,"M",6);
    //初始化矿地
    for(i=64;i<=69;i++){
        maps[i].type = MINE;
        maps[i].owner = '0';
        maps[i].level = 0;
        maps[i].price = 300;
        memcpy(maps[i].show,"$",6);
    }
}

//根据序号找到归属决定颜色
//linux版本
void printColor(int num){
    int j;
    j=strlen(maps[num].show);
    if(maps[num].show[j-1] != '0'){
        switch(maps[num].show[j-1])
        {
            case 'Q':
                printf("\033[31m%c\033[0m",maps[num].show[j-1]);
                return;
            case 'A':
                printf("\033[32m%c\033[0m",maps[num].show[j-1]);
                return;
            case 'S':
                printf("\033[34m%c\033[0m",maps[num].show[j-1]);
                return;
            case 'J':
                printf("\033[33m%c\033[0m",maps[num].show[j-1]);
                return;
            default:
                printf("%c",maps[num].show[j-1]);
                return;
        }
    }else{
        switch(maps[num].owner)
        {
            case 'Q':
                printf("\033[31m%c\033[0m",maps[num].show[j-1]);
                return;
            case 'A':
                printf("\033[32m%c\033[0m",maps[num].show[j-1]);
                return;
            case 'S':
                printf("\033[34m%c\033[0m",maps[num].show[j-1]);
                return;
            case 'J':
                printf("\033[33m%c\033[0m",maps[num].show[j-1]);
                return;
            default:
                printf("%c",maps[num].show[j-1]);
                return;
        }
    }

}

/** \brief 打印地图的一行
 *
 * \param (int)左边的序号
 * \param (int)右边的序号
 * \return void
 *
 */

void printMapLine(int left, int right){
    int i,j;
    printColor(left);
//    j=strlen(maps[left].show);
//    printf("%c",maps[left].show[j-1]);
    for(i=0;i<27;i++){
        printf("%c",' ');
    }
    printColor(right);
//    j=strlen(maps[right].show);
//    printf("%c",maps[right].show[j-1]);
    printf("%c",'\n');
}


/** \brief 显示地图的函数
 *
 * \return void
 *
 */
void showMap(){
    int i,j;
    for(i=0;i<=28;i++){
//        j=strlen(maps[i].show);
//        printf("%c",maps[i].show[j-1]);
        printColor(i);
    }
    printf("%c",'\n');
    printMapLine(69, 29);
    printMapLine(68, 30);
    printMapLine(67, 31);
    printMapLine(66, 32);
    printMapLine(65, 33);
    printMapLine(64, 34);
    for(i=63;i>=35;i--){
//        j=strlen(maps[i].show);
//        printf("%c",maps[i].show[j-1]);
        printColor(i);
    }
    printf("%c",'\n');
}

/** \brief 更改地图结构体数组&&更新
 *
 * \param (int)更改地图类型：1.行走 2.买地&升级 3.
 * \param (int)原位置 S是0,最后一块矿地是69
 * \param (int)现位置
 * \param (char)移动的人or购买土地的人，例：'Q'-钱夫人
 * \return
 *
 */
void changeMap(int type, int old, int present, char people){
    int i,j,len;
    switch(type){
        case 1:
            //删除原位置的show元素
            len = strlen(maps[old].show);
            for(i=0;i<len;i++){
                if(maps[old].show[i]==people){
                    for(j=i;j<len;j++){
                        maps[old].show[j] = maps[old].show[j+1];
                    }
                }
            }


            //添加新位置的show元素
            len = strlen(maps[present].show);
            maps[present].show[len]=people;
            maps[present].show[len+1]='\0';
            return;
        case 2:
            if(maps[present].owner == '0'){
                maps[present].owner = people;
            }
            maps[present].level = maps[present].level + 1;
            return;
        default:
            return;

    }
}

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
