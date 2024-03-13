#ifndef robot_H_H
#define robot_H_H
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Dot.h"
using namespace std;
class Robot
{
public:
    int id;
    int x;
    int y;
    int carry;//robot是否携带货物
    int state;//robot是否是正常状态
    int tar_x;
    int tar_y;
    int berth_id;
    int direc;
    int **dis;
    Good* g=NULL;
    string path;
    Robot(){};
    Robot(int x, int y, int carry, int state, int id){      //初始化
        this->id = id;
        this->x = x;
        this->y = y;
        this->carry = carry;
        this->state = state;

    }
    void find_berth(Berth *berth);
    void operate(Dot dotmap[][201], Berth* berth);
    void move();
    bool change_good();//后期实现，用来改变货物
    void find_good(Dot dotmap[][201]);

    void move(Dot dotmap[][201],Berth *berth);                                    //输出移动
  //注释掉了，可以在MAPPA里面实现
  //或者调用MAPPA里面的一些别的文件实现

};
class Step
{
public:
    int x, y, dist;

    Step(int x, int y, int dist){
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};
#endif