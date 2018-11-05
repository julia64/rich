#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "rich.h"

void initMap();     //初始化地图
void showMap();     //显示地图
void changeMap(int type, int old, int present, char people);   //更改地图结构体数组&&更新
void printColor(int num);
void drawToolHouse();
void printMapLine(int left, int right);

#endif // MAP_H_INCLUDED
