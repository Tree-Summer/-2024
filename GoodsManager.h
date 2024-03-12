#ifndef GoodsManager_H_H
#define GoodsManager_H_H
#pragma once
#include "Good.h"
class GoodsManager{
	public:
		int front,end;
		GoodsManager(){
			front=0;
			end=0;
		}
		Good G[10005];
		const int size=10001;
};
#endif