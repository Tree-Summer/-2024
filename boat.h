#ifndef boat_H_H
#define boat_H_H
#include <iostream>
#include "berth.h"

class Boat
{
    public:
    int id;//beat's id
    int num;//num of goods
    int berth_id;//bowei id
    int status;//0--moving  1-- over  2--waiting

    int time;//next order's time
    void load(Berth* berth,int boat_capacity,int nowtime);
    void move(int nowtime,int boat_capacity,Berth* berth);
    void output(int nowtime);
    void ship(int nowtime,int boat_capacity,Berth *berth);
    void go(int nowtime,int boat_capacity,Berth *berth);
    void statuschange(int nowtime,int boat_capacity,Berth *berth);
};
#endif

void Boat::ship(int nowtime,int boat_capacity,Berth *berth){

    int max = -1;
    int maxid = -1;
    if(berth_id==-1){
        for(int i = 0;i < 10;i++){
            if( berth[i].gl.total_val>max&&berth[i].space<=0){
                maxid =i; max = berth[i].gl.total_val;
            }
        }
        berth[maxid].boatid=id;
        berth_id = maxid;
        berth[berth_id].space+= boat_capacity;

        time = nowtime+ 500;
        if(berth_id==-1) return;
        printf("ship %d %d\n",id,berth_id);
        return;
    }else if(berth_id!=-1&& berth[berth_id].gl.total_val==0 &&berth[berth_id].gl.size==0 && num!=boat_capacity){
            for(int i = 0;i < 10;i++){
                if( berth[i].gl.total_val>max&&berth[i].space<=0){
                    maxid = i; max = berth[i].gl.total_val;
                }
            }
            if(maxid == -1) return;
            else{
            berth[berth_id].boatid=-1;
            berth[maxid].boatid=id;
            
            berth[berth_id].space-= boat_capacity - num;
            berth_id = maxid;
            berth[berth_id].space+= boat_capacity - num;

            time = nowtime+ 500;
            if(berth_id==-1) return;

            printf("ship %d %d\n",id,berth_id);
            return;
            }
    }else{
        return;
    }
}


// go to virtual point
void Boat::load(Berth* berth,int boat_capacity,int nowtime){
    int k=min(boat_capacity-num,berth[berth_id].gl.size);
    if(berth[berth_id].gl.size==0) ship(nowtime,boat_capacity,berth);
    for(int i=1;i<=k;i++){
        berth[berth_id].gl.pop();
    }
    num+=k;
    if(num==boat_capacity||15000-nowtime<=berth[berth_id].transport_time){
        berth[berth_id].boatid=-1;
        berth_id=-1;
        printf("go %d\n",id);
    }
}
/*
//if the boat succeed to reach the goal
void Boat::statuschange(int nowtime,int boat_capacity,Berth *berth){
    //if(time==nowtime) status = 1;

    //from virtual point back to berth(stable)
    if(berth_id==-1&&status==1){
        num = 0;
        time = nowtime+ berth[berth_id].transport_time;
        berth[boweiid].space+=boat_capacity;
        status =0,pos =boweiid;
        //对于泊位选择的初步逻辑函数为一次比一次
        float max = (float)berth[0].value/(float)berth[0].transport_time,id=-1;

        for(int i = 0;i < 10;i++){
            if( berth[i].space<0 && (float)berth[i].value/ (float)berth[i].transport_time>max){
                id =i; max = (float)berth[i].value/ (float)berth[i].transport_time;
        }
        num = 0;
        time = nowtime+ berth[id].transport_time;
        status =0,pos = id;
    }

    //去泊点的状态转移
    if(pos!=-1&&time==nowtime){
        if(berth[pos].boatid==-1) status = 1;
        else{
            status = 2;
            berth[pos].waiting.push(id);
        }
    }
}*/
void Boat::move(int nowtime,int boat_capacity,Berth* berth){
    if(nowtime%1000==0)
        fprintf(stderr,"%d %d \n",id,berth_id);
    if(status==0) return;//船现在不能移动
    if(status==2&&berth_id!=-1){
        printf("ship %d %d\n",id,berth_id);
        return;
    }//在外面等待
    if(berth_id==-1) ship(nowtime,boat_capacity,berth);//驶出虚拟点
    else load(berth,boat_capacity,nowtime);//装载
}