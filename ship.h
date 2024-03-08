#include<iostream>
#include"bowei.h"
using namespace std;

class boat
{
    int id;//beat's id
    int num;//num of goods
    int pos;//bowei id
    int status;//0--moving  1-- over  2--waiting
    int time;//
    void ship(int id,int nowtime);
    void go(int nowtime);
    void statuschange(int nowtime);
}boat[5];

void boat::ship(int boweiid,int nowtime){
    status =0,pos = boweiid;
    time = nowtime+1000;
    printf("ship %d %d",id,pos);
}

void boat::go(int nowtime){
    time =nowtime + berth[pos].transporttime;
    status =0,pos =-1;
}

void boat::statuschange(int nowtime){
    if(time==nowtime) status = 1;
}