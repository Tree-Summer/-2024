#ifndef Berth_H_H
#define Berth_H_H
#pragma once
#include <iostream>
using namespace std;
#include <queue>

#include "dot.h"
class Berth
{
    public:
    int x,y;//泊位的左上角
    int transport_time;//到虚拟点的时间
    int loading_speed;//装货速度
    int boatid;//目前在泊位上的船的id
    int value;//泊位现在有多少价值的物品
    int space;//在泊位上有多少空位
    queue<int> waiting;//正在等待的船
    const int maxn=40001; 
    int** dis;
    //maxn:不可达，dis里面存储berth到各个点的最短距离，也是各个点到berth的最短距离
    Berth(){
        dis=new int*[201];
        for(int i=0;i<201;i++)
            dis[i]=new int[201];
        for(int i=1;i<=20;i++)
            for(int j=1;j<=20;j++)
                dis[i][j]=maxn;
        this -> boatid = -1;
        this->value=0;
   }
   ~Berth(){
    delete(dis);
   }
};
#endif

