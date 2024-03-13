#include "robot.h"
#include "Dot.h"
#include<bits/stdc++.h>
#include<queue>
using namespace std;
void Robot::move(Dot dotmap[][201],Berth *berth){
    
    if(carry) find_berth(berth);
    //有货物的话则想办法到berth那里
    else find_good(dotmap);
    //没有货物的话找货物
    if(this->direc!=-1)
        move(dotmap);
    operate(dotmap,berth);
}

bool beside(Step* a, Step* b){ //判断相邻
    if(abs(a->x - b->x) + abs(a->y - b->y) == 1)
        return true;
    else
        return false;

}

void Robot::find_good(Dot dotmap[][201]) {
<<<<<<< HEAD
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

=======
    direc=-1;
    if(dotmap[x][y].type==3) return;
    dis=new int*[201];//表示方向
    for(int i=0;i<201;i++)
        dis[i]=new int[201];
    for(int i=1;i<=200;i++)
        for(int j=1;j<=200;j++)
            dis[i][j]=-1;
    queue<pair<int,int> > q;
    int find=0;//表示是否找到最近的货物
    bool s[201][201];//表示是否遍历过
    memset(s,0,sizeof(s));
    s[x][y]=1;
    int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
    for(int i=0;i<4;i++){
        if(dotmap[x+X[i]][y+Y[i]].type==1&&dotmap[x+X[i]][y+Y[i]].type==2) continue;
        if(dotmap[x+X[i]][y+Y[i]].type==3){
            this->direc=i;
            return;
        }
        dis[x+X[i]][y+Y[i]]=i;//四周的确定方向
        s[x+X[i]][y+Y[i]]=1;
        q.push(make_pair(x+X[i],y+Y[i]));
    }
    while(!q.empty()&&!find){
        int nowx=q.front().first;
        int nowy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=nowx+X[i];
            int ny=nowy+Y[i];//下一步的坐标
            if(nx<1||nx>200||ny<0||ny>200) continue;//越界则返回
            if(s[nx][ny]) continue;//到过说明入队了也返回
            if(dotmap[nx][ny].type==1||dotmap[nx][ny].type==2) continue;//不能走也返回
            dis[nx][ny]=dis[nowx][nowy];//新扩展的是原方向走的
            if(dotmap[nx][ny].type==3){
                tar_x=nx;
                tar_y=ny;
                find=1;
                this->direc=dis[nowx][nowy];
            }//找到了方向
            s[nx][ny]=1;
            q.push(make_pair(nx,ny));
        }
    }
    delete(dis);
>>>>>>> 65acd288cb746668c89f36d6854ee9435d57a50d
}
void Robot::find_berth(Berth *berth) {
    direc=-1;
    if(!carry||(carry&&berth_id!=-1)) return;
    int minn=40001;
    string road;
    for(int i=0;i<9;i++){
        if(berth[i].dis[x][y]<minn)
            berth_id=i,minn=berth[i].dis[x][y];
    }
    //0:右边，1：左边，2：上面，3：下面
    int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
    for(int i=0;i<=3;i++)
        if(berth[id].dis[x][y]==berth[id].dis[x+X[i]][y+Y[i]]+1)
            this->direc=i;
    tar_x=berth[berth_id].x;
    tar_y=berth[berth_id].y;
}


void Robot::operate(Dot dotmap[][201], Berth* berth) {
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
        printf("%d\n", this->id);
        berth[berth_id].gl.push(g);
        g=NULL;
        fflush(stdout);
        this->carry = 0;
        this->berth_id=-1;
        tar_x=-1,tar_y=-1;
    }
}

void Robot::move(Dot dotmap[][201]){
    int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
    if(dotmap[x+X[direc]][y+Y[direc]].type==1||dotmap[x+X[direc]][y+Y[direc]].type==2)
        return;
    printf("move ");
    printf("%d ", this->id);
    printf("%d\n", direc);
    fflush(stdout);
    //path.erase(path.begin());
}



