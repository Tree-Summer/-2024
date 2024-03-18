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
    int prestatus;//之前的状态
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
            //if( berth[i].gl.total_val>max&&berth[i].space<=0){ 注释掉这里。应该这里有错
            if(berth[i].gl.f_val>max&&berth[i].boatid==-1){
                maxid =i; max = berth[i].gl.total_val;
            }
        }
        berth_id=maxid;
        berth[berth_id].boatid=id;
        berth[berth_id].space+= boat_capacity;
        time = nowtime+ 500;
        printf("ship %d %d\n",id,berth_id);
        return;
    //if(berth_id!=-1&& berth[berth_id].gl.total_val==0 &&berth[berth_id].gl.size==0 && num!=boat_capacity)
    }else {
            for(int i = 0;i < 10;i++){
                if( berth[i].gl.f_val>max&&berth[i].space<=0){
                    maxid = i; max = berth[i].gl.total_val;
                }
            }
            if(maxid == -1) return;
            berth[berth_id].boatid=-1;
            berth[maxid].boatid=id;
            
            berth[berth_id].space-= boat_capacity - num;
            berth_id = maxid;
            berth[berth_id].space+= boat_capacity - num;

            time = nowtime+ 500;
            printf("ship %d %d\n",id,berth_id);
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
        num=0;
        printf("go %d\n",id);
    }
}
void Boat::move(int nowtime,int boat_capacity,Berth* berth){
    fprintf(stderr,"%d %d %d\n",status,id,berth_id);
    if(status==0) return;//船现在不能移动
    if(status==2){
        ship(nowtime,boat_capacity,berth);
        return;
    }//在外面等待
    if(berth_id==-1) ship(nowtime,boat_capacity,berth);//驶出虚拟点
    else load(berth,boat_capacity,nowtime);//装载
    prestatus=status;
}