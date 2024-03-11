#include <iostream>
class Boat
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
    // void go(int nowtime,int boat_capacity,Berth *berth);
    void statuschange(int nowtime);
    void backtoberth(int nowtime);
    
};



// change the berth
void Boat::ship(int berthid,int nowtime){
    status =0, pos = berthid;
    time = nowtime + 1000;
    printf("ship %d %d",id,pos);
}

// go to virtual point
// void Boat::go(int nowtime,int boat_capacity,Berth *berth){
//     if(num==boat_capacity){
//         time = nowtime +berth[pos].transport_time;
//         status =0,pos =-1;
//    }
// }

// from virtual point back to berth(stable)
// void Boat::backtoberth(int nowtime,Berth *berth){
//     num = 0;
//     time = nowtime+ berth[boweiid].transport_time;
//     status =0,pos =boweiid;
// }

//if the boat succeed to reach the goal
void Boat::statuschange(int nowtime){
    //if(time==nowtime) status = 1;
    if(pos==-1&&time==nowtime) backtoberth(nowtime); 
    /*if(pos==-1&&time==nowtime) status = 1;
    else if(pos!=-1&&time==nowtime){
        if(berth[pos].boatid==-1) status = 1;
        else status = 2;
    }*/
}