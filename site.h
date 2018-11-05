#ifndef SITE_H_INCLUDED
#define SITE_H_INCLUDED

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "rich.h"

void mineOp(int i);
//矿地
void jailOp(int i);
//监狱
void hospitalOp(int i);
//医院

void inHospital(int i,int type)
//在医院or监狱，不能做任何操作
//type - 1：医院，2：监狱

#endif // SITE_H_INCLUDED