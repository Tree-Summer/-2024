#pragma once
#include"boat.h"
// change the berth
void Boat::ship(int berthid,int nowtime){
    status =0, pos = berthid;
    time = nowtime + 1000;
    printf("ship %d %d",id,pos);
}

// go to virtual point
void Boat::go(int nowtime,int boat_capacity,Berth *berth){
    if(num==boat_capacity){
        time = nowtime +berth[pos].transport_time;
        status =0,pos =-1;
   }
}

//if the boat succeed to reach the goal
void Boat::statuschange(int nowtime,Berth *berth){
    //if(time==nowtime) status = 1;

    //from virtual point back to berth(stable)
    if(pos==-1&&time==nowtime){ 
        num = 0;
        time = nowtime+ berth[boweiid].transport_time;
        status =0,pos =boweiid;
    }
    
    /*if(pos==-1&&time==nowtime) status = 1;
    else if(pos!=-1&&time==nowtime){
        if(berth[pos].boatid==-1) status = 1;
        else status = 2;
    }*/
}