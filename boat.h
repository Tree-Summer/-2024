#ifndef boat_H_H
#define boat_H_H
#pragma once
#include <iostream>
#include "berth.h"

class Boat
{
    public:
    int id;//beat's id
    int num;//num of goods
    int pos;//bowei id
    int status;//0--moving  1-- over  2--waiting

    int time;//

    int boweiid;
    void ship(int nowtime,int boat_capacity,Berth *berth);
    void go(int nowtime,int boat_capacity,Berth *berth);
    void statuschange(int nowtime,int boat_capacity,Berth *berth);
};
#endif