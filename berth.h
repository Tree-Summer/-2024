#ifndef Berth_H_H
#define Berth_H_H
#pragma once
#include "dot.h"
class Berth
{
    public:
    int x,y;
    int transport_time;
    int loading_speed;
    int boatid;
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
    }
    Berth(int x, int y, int transporttime, int loadingspeed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transporttime;
        this -> loading_speed = loadingspeed;
        this -> boatid = -1;
   }
   ~Berth(){
    delete(dis);
   }
};
#endif

