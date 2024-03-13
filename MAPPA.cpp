#include"MAPPA.h"
#include"Boat.cpp"
#include"Robot.cpp"
#include<bits/stdc++.h>
#include<queue>
using namespace std;
void MAPPA::precount(int id){//预处理泊位距离
	queue<pair<int,int> > q;
	bool s[210][210];
	memset(s,0,sizeof(s));//全部赋值为0
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++){
			berth[id].dis[berth[id].x+i][berth[id].y+j]=0;
			if(i==3||j==3){
				q.push(make_pair(berth[id].x+i,berth[id].y+j));
			}
		}
	int X[5]={0,1,0,-1,0};
	int Y[5]={0,0,1,0,-1};
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		s[x][y]=1;
		q.pop();
		if(d[x][y].type==1||d[x][y].type==2) continue;
		for(int i=1;i<=4;i++){
			if(x+X[i]==0||x+X[i]>200) continue;
			if(d[x+X[i]][y+Y[i]].type==1||d[x+X[i]][y+Y[i]].type==2) continue;
			berth[id].dis[x+X[i]][y+Y[i]]=min(berth[id].dis[x+X[i]][y+Y[i]],berth[id].dis[x][y]+1);
			if(!s[x+X[i]][y+Y[i]]){
				q.push(make_pair(x+X[i],y+Y[i]));
				s[x+X[i]][y+Y[i]]=1;
			}
		}
	}
	//printf("finished");
}
void MAPPA::predeal(){//预处理
	for(int i=0;i<berth_num;i++){
		//printf("berthid %d\n",i);
		precount(i);
	}
	
}
void MAPPA::init(){//初始化
	//printf("qwq");
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
	for(int i=0;i<5;i++) boat[i].id=i;
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
        scanf("%d%d\n", &boat[i].status, &boat[i].berth_id);
		//
		if(boat[i].berth_id!=-1)
        	berth[boat[i].berth_id].boatid = i;
		//
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
	for(int i=0;i<robot_num;i++){
		robot[i].move(d,berth);
	}
	//调用船函数
	for(int i=0;i<boat_num;i++){
		boat[i].move(zhen,boat_capacity,berth);
	}
	//printf("MAPPA deal");
}
void MAPPA::output(){//输出
	for(int i = 0; i < robot_num; i ++)
            printf("move %d %d\n", i, rand() % 4);
        puts("OK");
        fflush(stdout);
}