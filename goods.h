//
//价值评估函数
//确定路径的函数
#include<iostream>
using namespace std;
//物品类
class goods
{
    //读入的物品的参数
    public:
    int x, y, val, time;//位置，价值, 第几帧加入的
    goods* next;//指向下一个的指针
    goods(){x=-1, y=-1, val=-1;next=NULL;}//构造函数
    goods(int x1,int y1,int val1){x=x1, y=y1, val=val1;next=NULL;}//重构构造函数
};

//物品的链表类
class goodslist
{
    public:
    goods *first,*end;//链表头(空指针) 链表尾
    int num,totalval;//物品数 价值总数

    //构造函数
    goodslist(){first->next = end;num=0;}
    //输入函数
    void input(int x ,int y, int val);
    //消失函数
    void die(int time1);
    //平均值函数
    int average();
};

//输入函数
void goodslist::input(int x ,int y, int val){
    
    goods* newone = new goods(x,y,val);
    if(end==NULL){
        first->next = newone;
        end = newone;
    }else{
        end->next= newone;
        end = newone;
    }
    num++,totalval+=val;
}

//消失函数
void goodslist::die(int time1){
    goods *tmp = first->next;
    while(tmp!=end){
        if(time1-tmp->time>=1000){
            first->next = tmp->next;
            totalval-=tmp->val,num--;
            delete tmp;
            tmp = first->next;
        }else break;
    }
}

//平均值函数
int goodslist::average(){
    return (float)totalval/(float)num;
}

