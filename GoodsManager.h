#ifndef GoodsManager_H_H
#define GoodsManager_H_H
#include "Good.h"
class GoodsManager{
	public:
		int front=0,end=0;
		GoodsManager(){
			front=1;
			end=0;
			G=new Good[100005];
		}
		Good *G;
		const int size=100001;
};
#endif