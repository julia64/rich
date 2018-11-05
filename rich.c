#include "rich.h"

void findHouses(int i)
{
    int j = 0;
    for(;j<70;j++){
        if(players[i].name == maps[j].owner){
            maps[j].owner = '0';
            maps[j].level = 0;
        }
    }
}
