#ifndef Berth_H_H
#define Berth_H_H
#pragma once
#include <iostream>
using namespace std;
#include <queue>

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

    Berth(){}
    Berth(int x, int y, int transporttime, int loadingspeed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transporttime;
        this -> loading_speed = loadingspeed;
        this -> boatid = -1;
        this -> value = 0;
   }
  // void renew(,Boat *boat);
};
#endif

