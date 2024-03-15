#ifndef robot_H_H
#define robot_H_H
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
    int *zhen;//调试用
    bool s[210][210];//表示是否遍历过
    bool able_to_move(Dot dotmap[][201], int x,int y );
    Good* g=NULL;
    string path;
    Robot(){
        carry=0;
        state=1;
        dis=new int*[210];//表示方向
        for(int i=0;i<210;i++)
            dis[i]=new int[210];
    };
    Robot(int x, int y, int carry, int state, int id){      //初始化
        dis=new int*[210];//表示方向
        for(int i=0;i<210;i++)
            dis[i]=new int[210];
        this->id = id;
        this->x = x;
        this->y = y;
        this->carry = carry;
        this->state = state;

    }
    void find_berth(Berth *berth);
    void operate(Dot dotmap[][201], Berth* berth);
    void move(Dot dotmap[][201]);
    bool change_good();//后期实现，用来改变货物
    void find_good(Dot dotmap[][201]);

    void move(Dot dotmap[][201],Berth *berth);                                    //输出移动
    void outdot(Dot **dotmap){
        for(int i=1;i<=200;i++){
            for(int j=1;j<=200;j++)
                printf("%d",dotmap[i][j].type);
        }
    }
    //调试用函数
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