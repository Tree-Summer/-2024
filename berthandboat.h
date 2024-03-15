#include"Berth.h"
#include"Boat.h"

void renew(Boat *boat,Berth *berth){
    //船只在泊位等待的状态转移
    for(int i =0;i<10;i++){
        if(!berth[i].waiting.empty()&&berth[i].boatid==-1){
            berth[i].boatid = berth[i].waiting.front();
            berth[i].waiting.pop();
            boat[berth[i].boatid].status = 1;
        }
    }
}

void updateboatandberth(pair<int,int> q,Boat *boat,Berth *berth){
    if(q.first!=-1){
    //    berth[q.first].space--;
    //    berth[q.first].value-=q.second;
        boat[berth[q.first].boatid].num++;
    }
}