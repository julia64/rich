//矿地
void mineOp(int i){
	switch(players[i].position)
		{
			case 69:
				players[i].point += 20;
				printf("恭喜你挖到了思聪家的矿，获得点数20\n现有点数%d\n",players[i].point);
				return;
			case 66:
				players[i].point += 40;
				printf("恭喜你挖到了思聪家的矿，获得点数40\n现有点数%d\n",players[i].point);
				return;
			case 64:
				players[i].point += 60;
				printf("恭喜你挖到了思聪家的矿，获得点数60\n现有点数%d\n",players[i].point);
				return;
			case 68:
			case 65:
				players[i].point += 80;
				printf("恭喜你挖到了思聪家的矿，获得点数80\n现有点数%d\n",players[i].point);
				return;
			case 67:
				players[i].point += 100;
				printf("恭喜你挖到了思聪家的矿，获得点数100\n现有点数%d\n",players[i].point);
				return;
		}
}

//监狱
void jailOp(int i){
	players[i].state = INJAIL;
	players[i].stay = 2;
	printf("铁门～铁窗～铁锁链～这里是进来了就出不去监狱。\n您将在此停留两回合。\n");
}

//医院
void hospitalOp(int i){
	printf("闻到消毒水的香味了吗？这里是治不好也死不了医院\n"); 
}

//在医院or监狱，不能做任何操作
//type - 1：医院，2：监狱
void inHospital(int i,int type){
	if(1 == type){
		printf("您还将在医院停留%d回合",player[i].stay);
	}
	if(2 == type){
		printf("您还将在监狱停留%d回合",player[i].stay);
	}
	player[i].stay--；
	if(player[i].stay == 0){
		player[i].state = NORMAL;
	}
}
