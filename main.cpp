#include<iostream>
#include"MAPPA.cpp"
#include "Dot.h"
using namespace std;


int main()
{
    FILE *stream=freopen("freopen.out","w",stderr);
    MAPPA *m;
    m = new MAPPA;
    printf("a");
    m->init();
    for(int zhen = 1; zhen <= 150000; zhen ++)
    {
        int id=m->input();
//        int id = Input();//
        m->deal();//
        zhen=id;
        printf("%d", zhen);
    }
    return 0;
}
