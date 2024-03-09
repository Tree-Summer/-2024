#include "robot.h"


bool beside(Step* a, Step* b){ //判断相邻
    if(abs(a->x - b->x) + abs(a->y - b->y) == 1)
        return true;
    else
        return false;
}

//机器人的取物简单逻辑

/*
string Robot::find_path(Map *map) {
    queue<Step*> queue1;
    vector<Step*> vector1;
    string path;
    int rec[200][200];  //记录足迹
    Point* u = new Point(this->x, this->y, 1);
    Step* step = new Step(u->x, u->y, 0);
    rec[this->x][this->y] = 1;
    queue1.push(step);
    vector1.push_back(step);
    int distance = 0;

    //寻找第一个货物
    while(!queue1.empty()){
        Step* s = queue1.front();
        queue1.pop();
        //
        int x_pos = s->x + 1;
        int y_pos = s->y;
        if(x_pos >= 0 && x_pos < 200 && y_pos >= 0 && y_pos < 200){
            if(map->cnt[x_pos][y_pos]->type == 1 && rec[x_pos][y_pos] == 0){   //type==1 陆地
                Step* step1 = new Step(x_pos, y_pos, s->dist+1);
                queue1.push(step1);
                vector1.push_back(step1);
                rec[x_pos][y_pos] = 1;
            }
            else if(map->cnt[x_pos][y_pos]->type == 3 && rec[x_pos][y_pos] == 0){ //type==3 货物
                Step* end_step = new Step(x_pos, y_pos, s->dist + 1);
                vector1.push_back(end_step);
                queue1.push(end_step);
                break;
            }
        }
        //
        x_pos = s->x - 1;
        y_pos = s->y;
        if(x_pos >= 0 && x_pos < 200 && y_pos >= 0 && y_pos < 200){
            if(map->cnt[x_pos][y_pos]->type == 1 && rec[x_pos][y_pos] == 0){
                Step* step2 = new Step(x_pos, y_pos, s->dist+1);
                queue1.push(step2);
                vector1.push_back(step2);
                rec[x_pos][y_pos] = 1;
            }
            else if(map->cnt[x_pos][y_pos]->type == 3 && rec[x_pos][y_pos] == 0){
                Step* end_step = new Step(x_pos, y_pos, s->dist + 1);
                vector1.push_back(end_step);
                queue1.push(end_step);
                break;
            }
        }
        //
        x_pos = s->x;
        y_pos = s->y + 1;
        if(x_pos >= 0 && x_pos < 200 && y_pos >= 0 && y_pos < 200){
            if(map->cnt[x_pos][y_pos]->type == 1 && rec[x_pos][y_pos] == 0){
                Step* step3 = new Step(x_pos, y_pos, s->dist+1);
                queue1.push(step3);
                vector1.push_back(step3);
                rec[x_pos][y_pos] = 1;
            }
            else if(map->cnt[x_pos][y_pos]->type == 3 && rec[x_pos][y_pos] == 0){
                Step* end_step = new Step(x_pos, y_pos, s->dist + 1);
                vector1.push_back(end_step);
                queue1.push(end_step);
                break;
            }
        }
        //
        x_pos = s->x;
        y_pos = s->y - 1;
        if(x_pos >= 0 && x_pos < 200 && y_pos >= 0 && y_pos < 200){
            if(map->cnt[x_pos][y_pos]->type == 1 && rec[x_pos][y_pos] == 0){
                Step* step4 = new Step(x_pos, y_pos, s->dist+1);
                queue1.push(step4);
                vector1.push_back(step4);
                rec[x_pos][y_pos] = 1;
            }
            else if(map->cnt[x_pos][y_pos]->type == 3 && rec[x_pos][y_pos] == 0){
                Step* end_step = new Step(x_pos, y_pos, s->dist + 1);
                vector1.push_back(end_step);
                queue1.push(end_step);
                break;
            }
        }
        //
    }
    Step* destination = vector1[vector1.size()-1];
    
}*/