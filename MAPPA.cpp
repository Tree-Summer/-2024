#include"MAPPA.h"
#include<bits/stdc++.h>
void MAPPA::predeal(){//预处理

}
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
    for(int i=1;i<=200;i++){
    	for(int j=1;j<=200;j++){
    		if(ch[i][j]=='.') d[i][j].type=0;
    		if(ch[i][j]=='*') d[i][j].type=1;
    		if(ch[i][j]=='#') d[i][j].type=2;
    		if(ch[i][j]=='B') d[i][j].type=4;
    	}
	}
	for(int i=0;i<berth_num;i++){
		int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++){
				Dot* now=d[berth[id].x+j]+(berth[id].y+k);
				now->changetype(4);
				now->berth=berth+id;
			}//对应的点指向berth
		//berth[id].boatid=-1;
	}
	scanf("%d", &boat_capacity);
	predeal();
    char okk[100];
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}
int MAPPA::input(){//读入交互
	scanf("%d%d",&zhen,&money);
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		int x, y, val;
        scanf("%d%d%d", &x, &y, &val);//存储货物
        gm.end++;
        gm.G[gm.end].x=x;
        gm.G[gm.end].y=y;
		gm.G[gm.end].time=zhen;
		gm.G[gm.end].val=val;
        d[x][y].type=3;
		d[x][y].good=gm.G+gm.end;//货物对应的点指向货物
	}
	for(int i = 0; i < robot_num; i ++)
    {
        scanf("%d%d%d%d", &robot[i].carry, &robot[i].x, &robot[i].y, &robot[i].state);
    }
    for(int i = 0; i < 5; i ++){
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
		//
        boat[i].boweiid = boat[i].pos;
        berth[boat[i].boweiid].boatid = i;
		//
		if(zhen==1) berth[boat[i].pos].space += boat_capacity;
    }
    char okk[100];
    scanf("%s", okk);
    return zhen;
}
void MAPPA::vanish(){//货物消失逻辑,采用循环的队列
	for(int i=gm.front;i!=gm.end;i++){
		i=i%gm.size;
		int x=gm.G[i].x,y=gm.G[i].y;
		if(zhen-gm.G[i].time>=1000){
			d[x][y].changetype(0);
			gm.front++;
			gm.front=gm.front%gm.size;
		}
		else break;
	} 
}
void MAPPA::deal(){//处理拿取货物
	//调用船函数
	//调用机器人函数
	//printf("MAPPA deal");
}
void MAPPA::output(){//输出
	for(int i = 0; i < robot_num; i ++)
            printf("move %d %d\n", i, rand() % 4);
        puts("OK");
        fflush(stdout);
}