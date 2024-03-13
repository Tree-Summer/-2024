#ifndef GoodList_H_H
#define GoodList_H_H
#pragma once
#include"Good.h"
struct GoodListNode{
    Good* g;
    GoodListNode *next;
};
struct GoodList{
    GoodListNode *front,*end;
    int size=0;
    int total_val;
    GoodList(){
        front=new GoodListNode;
        end=front;
    }
    void push(Good *new_good){//放入
        GoodListNode *gln=new GoodListNode;
        size++;
        total_val+=new_good->val;
        gln->g=new_good;
        end->next=gln;
        end=gln;
    }
    Good* pop(){//弹出
        if(size==0) return nullptr;
        front->next=(front->next)->next;
        Good* good=(front->next)->g;
        total_val-=good->val;
        delete(front->next);
        size--;
        return good;
    }
};
#endif
