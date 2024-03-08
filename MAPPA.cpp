#include"MAPPA.h"
#include<bits/stdc++.h>
void MAPPA::init(){
	char ch[210][210];
	for(int i = 1; i <= 200; i ++)
        scanf("%s", ch[i] + 1);
    /*
    ‘.’ ： 空地 
	‘*’ ： 海洋 
	‘#’ ： 障碍 
	‘A’ ： 机器人起始位置，总共10个。 
	‘B’ ： 大小为4*4，表示泊位的位置,泊位标号在后泊位处初始化。
    */
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
}
void MAPPA::change(int zhen){
	
}
void MAPPA::update(int zhen){
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
}
void MAPPA::vanish(int zhen){
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
