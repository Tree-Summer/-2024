//对于地图与泊位的交互
#ifndef MAPPA_H_H
#define MAPPA_H_H
#include "Dot.h"
#include "Robot.h"
#include "GoodsManager.h"
class MAPPA{
	public:
		const int n = 200;
		const int robot_num = 10;
		const int berth_num = 10;
		const int boat_num=5;
		const int N = 210;
		int zhen,money;
		int boat_capacity;
		GoodsManager gm;
		Dot **d;
		Berth berth[20];
		Boat boat[6];
		Robot robot[11];
		void predeal();
		void init();
		int input();
		void vanish();
		void output();
		void deal();
		void precount(int id);//预处理泊位到各个点最短距离
		MAPPA(){
			d=new Dot*[210];//表示方向
        	for(int i=0;i<210;i++)
            	d[i]=new Dot[210];
			//printf("MAPPA INIT");
		};
}; 
#endif

