#include "robot.h"
#include "Dot.h"
#include<bits/stdc++.h>
#include<queue>
using namespace std;
void Robot::move(Dot dotmap[][201],Berth *berth){
    
    if(carry) find_good(dotmap);
    else find_berth(berth);
    move();
    operate(dotmap,berth);
}

bool beside(Step* a, Step* b){ //判断相邻
    if(abs(a->x - b->x) + abs(a->y - b->y) == 1)
        return true;
    else
        return false;

}
void Robot::find_good(Dot dotmap[][201]) {
     if(carry) return;
     queue<Step*> queue1;
     vector<Step*> vector1;
     vector<Step*> vector2;
     string road;
     bool rec[200][200];  //记录足迹
     memset(rec,0,sizeof(rec));
     Step* step = new Step(this->x, this->y, 0);
     rec[this->x][this->y] = true;
     queue1.push(step);
     vector1.push_back(step);
     tar_x=-1;
     tar_y=-1;
     //寻找第一个货物
     while(!queue1.empty()&&tar_x==-1){
         Step* s = queue1.front();
         queue1.pop();
         int x_pos, y_pos;
         int delta_x[4] = {1, 0, -1, 0};
         int delta_y[4] = {0, 1, 0, -1};
         for(int i = 0;i < 4; i++){
             x_pos = s->x + delta_x[i];
             y_pos = s->y + delta_y[i];
             if(x_pos >= 0 && x_pos < 200 && y_pos >= 0 && y_pos < 200){
                 if((dotmap[x_pos][y_pos].type == 0||dotmap[x_pos][y_pos].type == 4) && rec[x_pos][y_pos] == 0){//等于陆地
                     Step* step = new Step(x_pos, y_pos, s->dist+1);
                     queue1.push(step);
                     vector1.push_back(step);
                     rec[x_pos][y_pos] = true;
                 }
                 else if(dotmap[x_pos][y_pos].type == 3 && rec[x_pos][y_pos] == 0){
                     Step* end_step = new Step(x_pos, y_pos, s->dist + 1);
                     vector1.push_back(end_step);
                     queue1.push(end_step);
                     tar_x=x;
                     tar_y=y;//确定目标货物
                     break;
                 }
             }
         }

     }
     Step* destination = vector1[vector1.size()-1];
     int length = destination->dist;
     for(int i = length;i >= 0; i--){
         vector2.push_back(destination);
         for(int j = 0;j < vector1.size(); j++){
             if(vector1[j]->dist == destination->dist - 1 && beside(vector1[j], destination)){
                 destination = vector1[j];
                 break;
             }
         }
     }
     for (int i = vector2.size()-1;i >= 1; i--){
         int x1 = vector2[i]->x;
         int y1 = vector2[i]->y;
         int x2 = vector2[i-1]->x;
         int y2 = vector2[i-1]->y;

         if((x2-x1) == 1 && (y2-y1) == 0){
             road.push_back('0');
         }
         else if((x2-x1) == -1 && (y2-y1) == 0){
             road.push_back('1');
         }
         else if((x2-x1) == 0 && (y2-y1) == 1){
             road.push_back('3');
         }
         else if((x2-x1) == 0 && (y2-y1) == -1){
             road.push_back('2');
         }
     }

     this->path = road;

}

void Robot::find_berth(Berth *berth) {
    if(!carry||(carry&&berth_id!=-1)) return;
    int minn=40001;
    string road;
    for(int i=0;i<9;i++){
        if(berth[i].dis[x][y]<minn)
            berth_id=i,minn=berth[i].dis[x][y];
    }
    //0:右边，1：左边，2：上面，3：下面
    int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
    for(int i=0;i<3;i++)
        if(berth[id].dis[x][y]==berth[id].dis[x+X[i]][y+Y[i]]+1)
            this->path=(char)('0'+i);
    tar_x=berth[berth_id].x;
    tar_y=berth[berth_id].y;
    // while(dotmap[point->x][point->y].type != 4){
    //     int x_pos, y_pos;
    //     int delta_x[4] = {1, 0, -1, 0};
    //     int delta_y[4] = {0, 1, 0, -1};
    //     for(int i = 0;i < 4; i++) {
    //         x_pos = point->x + delta_x[i];
    //         y_pos = point->y + delta_y[i];
    //         if ( x_pos >= 0 && x_pos < 200 && y_pos >= 0 && y_pos < 200 && dotmap[x_pos][y_pos].type != 1 && dotmap[x_pos][y_pos].type != 2 ) {
    //             if (bowei_dist[x_pos][y_pos] == bowei_dist[point->x][point->y] - 1) {
    //                 if(i == 0){
    //                     road.push_back('0');
    //                 }
    //                 else if(i == 1){
    //                     road.push_back('3');
    //                 }
    //                 else if(i == 2){
    //                     road.push_back('1');
    //                 }
    //                 else if(i == 3){
    //                     road.push_back('2');
    //                 }
    //                 point->x = x_pos;
    //                 point->y = y_pos;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // this->path = road;
    // return road;
}


void Robot::operate(Dot dotmap[][201], Berth* berth) {
    if(this->x == this->tar_x && this->y == this->tar_y){
        if(dotmap[this->x][this->y].type == 3 && this->carry == 0){
            printf("get ");
            printf("%d\n", this->id);
            fflush(stdout);
            dotmap[this->x][this->y].changetype(0);
            this->carry = 1;
            tar_x=-1,tar_y=-1;
        }
        else if(dotmap[this->x][this->y].type == 4 && this->carry == 1){
            printf("pull ");
            printf("%d\n", id);
            berth[berth_id].gl.push(g);
            g=NULL;
            fflush(stdout);
            this->carry = 0;
            this->berth_id=-1;
            tar_x=-1,tar_y=-1;
        }
    }
}

void Robot::move() {
    printf("move ");
    printf("%d ", this->id);
    printf("%c\n", this->path[0]);
    fflush(stdout);
    path.erase(path.begin());
}



