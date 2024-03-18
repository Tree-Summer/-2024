#ifndef Berth_H_H
#define Berth_H_H

#include <iostream>
using namespace std;
#include <queue>
#include "GoodList.h"
class Berth
{
    public:
    int x,y;//泊位的左上角
    int transport_time;//到虚拟点的时间
    int loading_speed;//装货速度
    int boatid;//目前在泊位上的船的id
    int f_value;//泊位将来回到达的value最大值
    int space;//在泊位上有多少船的空位
    queue<int> waiting;//正在等待的船
    const int maxn=40001; 
    int** dis;
    GoodList gl;
    //maxn:不可达，dis里面存储berth到各个点的最短距离，也是各个点到berth的最短距离
    Berth(){
        this -> boatid = -1;
   }
   ~Berth(){
    delete(dis);
   }
};
#endif

