#ifndef Berth_H_H
#define Berth_H_H
#pragma once
class Berth
{
    public:
    int x,y;
    int transport_time;
    int loading_speed;
    int boatid;
    Berth(){}
    Berth(int x, int y, int transporttime, int loadingspeed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transporttime;
        this -> loading_speed = loadingspeed;
        this -> boatid = -1;
   }
};
#endif

