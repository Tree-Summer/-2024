#ifndef boat_H_H
#define boat_H_H
#include <iostream>
#include "Berth.h"

class Boat
{
    public:
    int id;//beat's id
    int num;//num of goods
    int berth_id;//bowei id
    int status;//0--moving  1-- over  2--waiting

    int time;//next order's time
    void load(Berth* berth,int boat_capacity,int nowtime);
    void move(int nowtime,int boat_capacity,Berth* berth);
    void output(int nowtime);
    void ship(int nowtime,int boat_capacity,Berth *berth);
    void go(int nowtime,int boat_capacity,Berth *berth);
    void statuschange(int nowtime,int boat_capacity,Berth *berth);
};
#endif