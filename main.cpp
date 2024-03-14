#include<iostream>
#include"MAPPA.cpp"
using namespace std;


int main()
{
    //FILE *stream=freopen("freopen.out","w",stderr);
    MAPPA m;
    //printf("a");
    m.init();
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        int id=m.input();
        //int id = Input();//
        m.deal();//
        zhen=id;
    }
    return 0;

}
