#include "robot.h"
#include "Dot.h"

bool beside(Step* a, Step* b){ //判断相邻
    if(abs(a->x - b->x) + abs(a->y - b->y) == 1)
        return true;
    else
        return false;

}



 string Robot::find_path(Dot** dotmap, int ** bowei_dist) {
     queue<Step*> queue1;
     vector<Step*> vector1;
     vector<Step*> vector2;
     string path;
     int rec[200][200];  //记录足迹
     Step* step = new Step(this->x, this->y, 0);
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
             if(dotmap[x_pos][y_pos].type == 1 && rec[x_pos][y_pos] == 0){   //type==1 陆地
                 Step* step1 = new Step(x_pos, y_pos, s->dist+1);
                 queue1.push(step1);
                 vector1.push_back(step1);
                 rec[x_pos][y_pos] = 1;
             }
             else if(dotmap[x_pos][y_pos].type == 3 && rec[x_pos][y_pos] == 0){ //type==3 货物
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
             if(dotmap[x_pos][y_pos].type == 1 && rec[x_pos][y_pos] == 0){
                 Step* step2 = new Step(x_pos, y_pos, s->dist+1);
                 queue1.push(step2);
                 vector1.push_back(step2);
                 rec[x_pos][y_pos] = 1;
             }
             else if(dotmap[x_pos][y_pos].type == 3 && rec[x_pos][y_pos] == 0){
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
             if(dotmap[x_pos][y_pos].type == 1 && rec[x_pos][y_pos] == 0){
                 Step* step3 = new Step(x_pos, y_pos, s->dist+1);
                 queue1.push(step3);
                 vector1.push_back(step3);
                 rec[x_pos][y_pos] = 1;
             }
             else if(dotmap[x_pos][y_pos].type == 3 && rec[x_pos][y_pos] == 0){
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
             if(dotmap[x_pos][y_pos].type == 1 && rec[x_pos][y_pos] == 0){
                 Step* step4 = new Step(x_pos, y_pos, s->dist+1);
                 queue1.push(step4);
                 vector1.push_back(step4);
                 rec[x_pos][y_pos] = 1;
             }
             else if(dotmap[x_pos][y_pos].type == 3 && rec[x_pos][y_pos] == 0){
                 Step* end_step = new Step(x_pos, y_pos, s->dist + 1);
                 vector1.push_back(end_step);
                 queue1.push(end_step);
                 break;
             }
         }
         //
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
             path.push_back('0');
         }
         else if((x2-x1) == -1 && (y2-y1) == 0){
             path.push_back('1');
         }
         else if((x2-x1) == 0 && (y2-y1) == 1){
             path.push_back('3');
         }
         else if((x2-x1) == 0 && (y2-y1) == -1){
             path.push_back('2');
         }
     }

     Step* point = vector1[vector1.size()-1];

     while(dotmap[point->x][point->y].type != 4){
         int x_pos, y_pos;
         //
         x_pos = point->x+1;
         y_pos = point->y;
         if(dotmap[x_pos][y_pos].type != 1 && dotmap[x_pos][y_pos].type != 2){
             if(bowei_dist[x_pos][y_pos] == bowei_dist[point->x][point->y] - 1){
                 path.push_back('0');
                 point->x = x_pos;
                 point->y = y_pos;
                 break;
             }
         }
         //
         x_pos = point->x-1;
         y_pos = point->y;
         if(dotmap[x_pos][y_pos].type != 1 && dotmap[x_pos][y_pos].type != 2){
             if(bowei_dist[x_pos][y_pos] == bowei_dist[point->x][point->y]-1){
                 path.push_back('1');
                 point->x = x_pos;
                 point->y = y_pos;
                 break;
             }
         }
         //
         x_pos = point->x;
         y_pos = point->y+1;
         if(dotmap[x_pos][y_pos].type != 1 && dotmap[x_pos][y_pos].type != 2){
             if(bowei_dist[x_pos][y_pos] == bowei_dist[point->x][point->y] - 1){
                 path.push_back('3');
                 point->x = x_pos;
                 point->y = y_pos;
                 break;
             }
         }
         //
         x_pos = point->x;
         y_pos = point->y-1;
         if(dotmap[x_pos][y_pos].type != 1 && dotmap[x_pos][y_pos].type != 2){
             if(bowei_dist[x_pos][y_pos] == bowei_dist[point->x][point->y] - 1){
                 path.push_back('2');
                 point->x = x_pos;
                 point->y = y_pos;
                 break;
             }
         }
     }
     return path;

}


void Robot::move() {
    printf("move ");
    printf("%d ", this->id);
    printf("%c\n", this->path[0]);
    path.erase(path.begin());
}