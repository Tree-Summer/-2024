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
    Robot(){};
    Robot(int x, int y, int carry, int state, int id){      //初始化
        this->id = id;
        this->x = x;
        this->y = y;
        this->carry = carry;
        this->state = state;
    }

    void move(int dir) {                                    //输出移动
        printf("move ");
        printf("%d %d", id, dir);
    }

    bool get(){                                             //抓取货物
        //to do
        return 1;
    }

    bool pull() {                                            //放置货物
        //to do
        return 1;
    }

    string find_path(Dot** dotmap, int ** bowei_dist);

    void move();                                    //输出移动
  //注释掉了，可以在MAPPA里面实现
  //或者调用MAPPA里面的一些别的文件实现

};

// class Robots
// {
// public:
//     vector<Robot*> list;    //存储机器人列表

//     void push(Robot* r){
//         list.push_back(r);
//     }

//     void init(){
//         if (list.empty()){    //第一次初始化
//             for(int i = 0;i < 10; i++){
//                 int carry, x, y, state;
//                 scanf("%d%d%d%d", &carry, &x, &y, &state);
//                 getchar();
//                 Robot* robot = new Robot(x, y, carry, state, i);
//                 list.push_back(robot);
//             }
//         }
//         else{                //后续更新
//             for(int i = 0;i < list.size(); i++){
//                 Robot* robot = list[i];
//                 int x,y,state,carry;
//                 scanf("%d%d%d%d", &carry, &x, &y, &state);
//                 getchar();
//                 robot->x = x;
//                 robot->y = y;
//                 robot->carry = carry;
//                 robot->state = state;
//             }
//         }

//     }

// };

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