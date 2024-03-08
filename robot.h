#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "map.h"

using namespace std;


class Robot
{
public:
    int id;
    int x;
    int y;
    int carry;
    int state;

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
    }

    bool pull() {                                            //放置货物
        //to do
    }

    string find_path(Map* map)


};

class Robots
{
public:
    vector<Robot*> list;    //存储机器人列表

    void push(Robot* r){
        list.push_back(r);
    }

    void init(){
        if (list.empty()){    //第一次初始化
            for(int i = 0;i < 10; i++){
                int carry, x, y, state;
                scanf("%d%d%d%d", &carry, &x, &y, &state);
                getchar();
                Robot* robot = new Robot(x, y, carry, state, i);
                list.push_back(robot);
            }
        }
        else{                //后续更新
            for(int i = 0;i < list.size(); i++){
                Robot* robot = list[i];
                int x,y,state,carry;
                scanf("%d%d%d%d", &carry, &x, &y, &state);
                getchar();
                robot->x = x;
                robot->y = y;
                robot->carry = carry;
                robot->state = state;
            }
        }

    }

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