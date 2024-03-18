#ifndef GoodList_H_H
#define GoodList_H_H
#include"Good.h"

struct GoodListNode{
    //Good* g;
    int val=0;
    GoodListNode *next;
};
struct GoodList{
    public:
    GoodListNode *front,*end;
    int size=0;
    int total_val=0;//已经到达港口的货物值
    int f_val=0;//预期到达港口的货物值
    GoodList(){
        front=new GoodListNode;
        end=NULL;
    }
    void push(Good *new_good){//放入
        if(new_good==NULL) return;
        GoodListNode *gln=new GoodListNode;
        size++;
        total_val+=new_good->val;
        gln->val=new_good->val;
        fprintf(stderr,"%d %d %d \n",size,total_val,gln->val);
        if(size==1){
            front->next=gln;
            end=gln;
            return;
        }
        end->next=gln;
        end=gln;
    }
    void pop(){//弹出
        if(size==0) return;
        size--; 
        GoodListNode* g=front->next;
        total_val-=g->val;
        front->next=g->next;
        delete(g);
        return;
    }
};
#endif
