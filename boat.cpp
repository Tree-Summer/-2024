#pragma once
#include"boat.h"
// change the berth

void Boat::ship(int nowtime,int boat_capacity,Berth *berth){

    float max = (float)berth[0].value;
    int maxid=-1;
    if(berth[pos].value==0){
        for(int i = 0;i < 10;i++){
            if( berth[i].space<0 && (float)berth[i].value>max){
                maxid =i; max = (float)berth[i].value;
            }
        }
    }

    berth[pos].space-=boat_capacity-num;
    berth[maxid].space+=boat_capacity-num;
    berth[pos].boatid = -1;
    pos = maxid;
    time = nowtime+ 500;
    status =0;
    time = nowtime + 1000;
    printf("ship %d %d",id,pos);
}

// go to virtual point
void Boat::go(int nowtime,int boat_capacity,Berth *berth){
    if(num==boat_capacity||(nowtime+berth[pos].transport_time==15000)){
        time = nowtime +berth[pos].transport_time;
        berth[pos].boatid = -1;
        status =0,pos =-1;
    }
}

//if the boat succeed to reach the goal
void Boat::statuschange(int nowtime,int boat_capacity,Berth *berth){
    //if(time==nowtime) status = 1;

    //from virtual point back to berth(stable)
    if(pos==-1&&time==nowtime){
        num = 0;
        time = nowtime+ berth[boweiid].transport_time;
        berth[boweiid].space+=boat_capacity;
        status =0,pos =boweiid;
        //对于泊位选择的初步逻辑函数为一次比一次
        /*
        float max = (float)berth[0].value/(float)berth[0].transport_time,id=-1;

        for(int i = 0;i < 10;i++){
            if( berth[i].space<0 && (float)berth[i].value/ (float)berth[i].transport_time>max){
                id =i; max = (float)berth[i].value/ (float)berth[i].transport_time;
            }
        }
        num = 0;
        time = nowtime+ berth[id].transport_time;
        status =0,pos = id;
        */
    }

    //去泊点的状态转移
    if(pos!=-1&&time==nowtime){
        if(berth[pos].boatid==-1) status = 1;
        else{
            status = 2;
            berth[pos].waiting.push(id);
        }
    }
}