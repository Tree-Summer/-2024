#ifndef GoodList_H_H
#define GoodList_H_H
#include"Good.h"

struct GoodListNode{
    //Good* g;
    int val;
    GoodListNode *next;
};
struct GoodList{
    GoodListNode *front;
    int size=0;
    int total_val;
    GoodList(){
        front=new GoodListNode;
        front->next=NULL;
    }
    void push(Good *new_good){//放入
        if(new_good==NULL) return;
        GoodListNode *gln=new GoodListNode;
        size++;
        total_val+=new_good->val;
        gln->val=new_good->val;
        gln->next=front->next;
        front->next=gln;
    }
    void pop(){//弹出
        if(size==0) return;
        size--; 
        front->next=(front->next)->next;
        //int good_val=(front->next)->val;
        //total_val-=good_val;
        return;
        delete(front->next);
        return;
    }
};
#endif
