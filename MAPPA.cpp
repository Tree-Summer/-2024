#include"MAPPA.h"
#include<bits/stdc++.h>
void MAPPA::init(){//初始化
	char ch[210][210];
	for(int i = 1; i <= 200; i ++)
        scanf("%s", ch[i] + 1);
    //0:land
	//1:sea
	//2:hurdle
	//3:goods
	//4:bowei
	//5:ship
    for(int i=1;i<=200;i++)
    	for(int j=1;j<=200;j++){
    		if(ch[i][j]=='.') d[i][j].type=0;
    		if(ch[i][j]=='*') d[i][j].type=1;
    		if(ch[i][j]=='#') d[i][j].type=2;
    		if(ch[i][j]=='B') d[i][j].type=4;
    	}
	for(int i=0;i<berth_num;i++){
		int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
		//berth[id].boatid=-1;
	}
	scanf("%d", &boat_capacity);
    char okk[100];
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);

}
void MAPPA::change(){
	
}
int MAPPA::input(){//交互
	scanf("%d%d",&zhen,&money);
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
        gm.end++;
        gm.G[gm.end][0]=x;
        gm.G[gm.end][1]=y;
        d[x][y].type=3;
        d[x][y].t=zhen;
        d[x][y].val=val;
	}
	    for(int i = 0; i < robot_num; i ++)
    {
        int sts;
        scanf("%d%d%d%d", &robot[i].carry, &robot[i].x, &robot[i].y, &robot[i].state);

    }
    for(int i = 0; i < 5; i ++){
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
        boat[i].boweiid = boat[i].pos;
        berth[boat[i].boweiid].boatid = i;
    }
    char okk[100];
    scanf("%s", okk);
    return zhen;
}
void MAPPA::vanish(){
	for(int i=gm.front;i!=gm.end;i++){
		i=i%gm.size;
		int x=gm.G[i][0],y=gm.G[i][1];
		if(zhen-d[x][y].t>=1000){
			d[x][y].type=0;
			gm.front++;
			gm.front=gm.front%gm.size;
		}
		else break;
	} 
}
void MAPPA::output(){
	for(int i = 0; i < robot_num; i ++)
            printf("move %d %d\n", i, rand() % 4);
        puts("OK");
        fflush(stdout);
}