//价值评估函数
//确定路径的函数
#include <bits/stdc++.h>
using namespace std;

struct goods
//物品类
{
    //读入的物品的参数
    public:
    int x, y, val, time;//位置，价值, 第几帧加入的
    goods* next;//指向下一个的指针
    goods(){x=0, y=0, val=0;next=NULL};
    goods(int x1,int y1,int val1,goods*nextone){x=x1, y=y1, val=val1;next=nextone}
}goods;

struct goodslist
{
    public:
    goods *first;
    goods *end;
    int num;
    goodslist(){
        first.x =
    }

    void input(int x ,int y, int val){
        goods *newone = new goods(x,y,val,NULL);
        end->next= newone;
        end = newone;
    }
    void die(int time1){
        if(time1-time==1000){
            delete
        }
    }
}goodslist;

goodlist *tail;