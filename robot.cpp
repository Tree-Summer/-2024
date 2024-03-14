#include "robot.h"
#include "Dot.h"
#include<bits/stdc++.h>
#include<queue>
using namespace std;

void Robot::move(Dot dotmap[][210],Berth *berth){
    
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

bool Robot::able_to_move(Dot dotmap[][210],int x,int y ){
    if(x==0||x>200) return 0;
    if(y==0||y>200) return 0;
    if(dotmap[x][y].type==1) return 0;
    if(dotmap[x][y].type==2) return 0;
    return 1;
}

void Robot::find_good(Dot dotmap[][210]) {
    direc=-1;
    if(dotmap[x][y].type==3) return;
    for(int i=1;i<=200;i++)
        for(int j=1;j<=200;j++)
            dis[i][j]=-1;
    queue<pair<int,int> > q;
    int find=0;//表示是否找到最近的货物
    memset(s,0,sizeof(s));
    s[x][y]=1;
    int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
    for(int i=0;i<4;i++){
        if(!able_to_move(dotmap,x+X[i],y+Y[i])) continue;
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
            if(nx==tar_x&&y==tar_y){
                find=1;
                this->direc=dis[nowx][nowy];
                return;
            }
            if(dotmap[nx][ny].type==3){
                tar_x=nx;
                tar_y=ny;
                find=1;
                this->direc=dis[nowx][nowy];
                return;
            }//找到了方向
            s[nx][ny]=1;
            q.push(make_pair(nx,ny));
        }
    }
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


void Robot::operate(Dot dotmap[][210], Berth* berth) {
    if(dotmap[this->x][this->y].type == 3 && this->carry == 0){
        printf("get ");
        printf("%d\n", this->id);
        dotmap[this->x][this->y].changetype(0);
        this->carry = 1;
        tar_x=-1,tar_y=-1;
     }
    else if(dotmap[this->x][this->y].type == 4 && this->carry == 1){
        printf("pull ");
        printf("%d\n", this->id);
        berth[berth_id].gl.push(g);
        g=NULL;
        this->carry = 0;
        this->berth_id=-1;
        tar_x=-1,tar_y=-1;
    }
}

void Robot::move(Dot dotmap[][210]){
    int X[4]={1,-1,0,0},Y[4]={0,0,-1,1};
    if(direc==-1) return;
    if(!able_to_move(dotmap,x+X[direc],y+Y[direc]))
        return;
    printf("move ");
    printf("%d ", this->id);
    printf("%d\n", direc);
    //path.erase(path.begin());
}



