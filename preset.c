#include "preset.h"

static CMD_MAP cmd_map[] =
{
        {"preset user",          preset_user    },
        {"preset map",           preset_map     },
        {"preset fund",          preset_fund    },
        {"preset credic",        preset_credic  },
//        {"preset gift",          preset_gift    },
//        {"preset bomb",          preset_bomb    },
//        {"preset barrier",       preset_barrier },
//        {"preset userloc",       preset_userloc },
//        {"preset nextuser",      preset_nextuser},
};


char dump(char *dumpdir){
    FILE *out;
    out = fopen( dumpdir, "w" );
    if( out != NULL )
    {
        fprintf(out,"user ");
        for (int i = 0; i < MAX_PLAYERS; ++i) {
            if(players[i].name){
                fprintf(out,"%c",players[i].name);
            }
        }
        fprintf(out,"\n");


        for (int i = 0; i < SITE_NUM; ++i) {
            if(maps[i].owner!='0'){
                fprintf(out,"map[%d] %c %d\n",i,maps[i].owner,maps[i].level);
            }
        }

        for (int i = 0; i < MAX_PLAYERS; ++i) {
            if(players[i].name){
                fprintf(out,"fund %c %d\n",players[i].name,players[i].money);
            }
        }

        for (int i = 0; i < MAX_PLAYERS; ++i) {
            if(players[i].name){
                fprintf(out,"credit %c %d\n",players[i].name,players[i].point);
            }
        }


        fprintf(out,"\n");
//        //人物打印
//        for (int i = 0; i < MAX_PLAYERS; ++i) {
//            fprintf(out,"Player%d\n",i);
//            fprintf(out,"\n");
//            fprintf(out,"name\t\t");
//            fprintf(out,"%d", players[i].name);
//            fprintf(out,"\n");
//            fprintf(out,"state\t\t");
//            fprintf(out,"%d",players[i].state);
//            fprintf(out,"\n");
//            fprintf(out,"point\t\t");
//            fprintf(out,"%d",players[i].point);
//            fprintf(out,"\n");
//            fprintf(out,"money\t\t");
//            fprintf(out,"%d",players[i].money);
//            fprintf(out,"\n");
//            fprintf(out,"position\t\t");
//            fprintf(out,"%d",players[i].position);
//            fprintf(out,"\n");
//        }
//        //地图打印
//        for (int j = 0; j < SITE_NUM; ++j) {
//            fprintf(out,"Map%d\n",j);
//            fprintf(out,"\n");
//            fprintf(out,"type\t\t");
//            fprintf(out,"%d", maps[j].type);
//            fprintf(out,"\n");
//            fprintf(out,"owner\t\t");
//            fprintf(out,"%d",maps[j].owner);
//            fprintf(out,"\n");
//            fprintf(out,"level\t\t");
//            fprintf(out,"%d",maps[j].level);
//            fprintf(out,"\n");
//            fprintf(out,"price\t\t");
//            fprintf(out,"%d",maps[j].price);
//            fprintf(out,"\n");
//            fprintf(out,"show\t\t");
//            for (int i = 0; i < 6; ++i) {
//                fprintf(out,"%d ",maps[j].show[i]);
//            }
//            fprintf(out,"\n");
//        }
    } else{
        return F_FAIL;
    }
    fclose(out);
    return F_TRUE;
}



int find_owner(char name,PLAYER * players )
{
    int i = 0;
    while(i<4)
    {
        if((players+i)->name == name)
            return i;
        else
            i++;
    }
    return 4;
}

int find_name(char name)
{
    int i = 0;
    char lib[] = "QASJ";
    while(i<4)
    {
        if(lib[i] == name)
            return i;
        else
            i++;
    }
    return 4;
}
char preset_user (const unsigned char *cmdString)
{
    char names[5] = "";
    char rc;
    int i = 0;
    rc = sscanf((char *)cmdString, "user %s", names);
    if(1 == rc)
    {
        for(i=0 ;names[i]!='\0';i++)
        {
            names[i] = '1' + find_name(names[i]);
        }
        names[i+1] = '\0';
        if(initPlayers(names,1000,players))
            printf("Set user success\n");
        else
            printf("Set user fail\n");

        return F_TRUE;
    }
    return F_FAIL;
}

char preset_map (const unsigned char *cmdString)
{
    int pos;
    char name;
    int level;
    char rc;
    rc = sscanf((char *)cmdString, "map[%d] %c %d", &pos, &name, &level);

    if(rc == 3)
    {
        maps[pos].owner = name;
        maps[pos].level = level;
        printf("Set map success\n");
        return F_TRUE;
    }
    return F_FAIL;
}

char preset_fund (const unsigned char *cmdString)
{
    char name;
    int money;
    int i = 0;
    char rc;
    rc = sscanf ((char *)cmdString, "fund %c %d", &name, &money);
    if(rc == 2)
    {
        i = find_owner(name, players);
        players[i].money = money;
        printf("Set fund success\n");
        return F_TRUE;
    }
    return F_FAIL;
}

char preset_credic (const unsigned char *cmdString)
{
    char name;
    int credit;
    int i = 0;
    char rc;
    rc = sscanf ((char *)cmdString, "credit %c %d",&name, &credit);
    if(rc == 2)
    {
        i = find_owner(name, players);
        players[i].point = credit;
        printf("Set credit success\n");
        return F_TRUE;
    }
    return F_FAIL;

}

char god_cmd(const unsigned char *cmdString)
{
    int i = 0;
    const unsigned char *cmd = cmdString;

    for (i = 0; i < sizeof(cmd_map) / sizeof(cmd_map[0]) && cmd_map[i].action; i++)
    {
        if (strncmp((const char *)cmd, (const char *)cmd_map[i].cmd, strlen((const char *)cmd_map[i].cmd)) == 0)
        {
            return cmd_map[i].action(cmdString + strlen("preset "));
        }
    }
    printf("CMD not processed\n");
    return F_TRUE;
}

//char preset_gift(char name ,int )

//char preset_bomb(int pos);
//char preset_barrier(int pos);
//char preset_userloc(char,int,int);
//char preset_nextuser(char);
