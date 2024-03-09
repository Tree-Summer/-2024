#include<iostream>
#include"bowei.h"
using namespace std;

int boat_capacity;

class boat
{
    public:
    int id;//beat's id
    int num;//num of goods
    int pos;//bowei id
    int status;//0--moving  1-- over  2--waiting
    int time;//

//
    int boweiid;
//

    void ship(int id,int nowtime);
    void go(int nowtime);
    void statuschange(int nowtime);
    void backtoberth(int nowtime);
    
}boat[5];

// change the berth
void boat::ship(int berthid,int nowtime){
    status =0, pos = berthid;
    time = nowtime + 1000;
    printf("ship %d %d",id,pos);
}

// go to virtual point
void boat::go(int nowtime){
    if(num==boat_capacity){
        time = nowtime + berth[pos].transport_time;
        status =0,pos =-1;
   }
}

// from virtual point back to berth(stable)
void boat::backtoberth(int nowtime){
    num = 0;
    time = nowtime + berth[boweiid].transport_time;
    status =0,pos =boweiid;
}

//if the boat succeed to reach the goal
void boat::statuschange(int nowtime){
    //if(time==nowtime) status = 1;
    if(pos==-1&&time==nowtime) backtoberth(nowtime); 
    /*if(pos==-1&&time==nowtime) status = 1;
    else if(pos!=-1&&time==nowtime){
        if(berth[pos].boatid==-1) status = 1;
        else status = 2;
    }*/
}