#ifndef PRESET_H
#define PRESET_H
#include "rich.h"
#include "map.h"
#include "land_trade.h"
#include "init_players.h"


typedef int (*CMD_ACTION)(const unsigned char* cmdString);

typedef struct
{
    unsigned char cmd[MAX_CMD_LENGTH];
    CMD_ACTION  action;
} CMD_MAP;


int find_owner(char name,PLAYER * players );
char god_cmd(const unsigned char *cmdString);
char dump(char *dumpdir);

char preset_user (const unsigned char *cmdString);
char preset_map (const unsigned char *cmdString);
char preset_fund (const unsigned char *cmdString);
char preset_credic (const unsigned char *cmdString);
//char preset_gift(const unsigned char *cmdString);
//char preset_bomb(const unsigned char *cmdString);
//char preset_barrier(const unsigned char *cmdString);
//char preset_userloc(const unsigned char *cmdString);
//char preset_nextuser(const unsigned char *cmdString);

extern MAP maps[SITE_NUM];
extern PLAYER players[MAX_PLAYERS];
extern CONFIG config;
#endif
