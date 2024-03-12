#ifndef GoodsManager_H_H
#define GoodsManager_H_H
#pragma once
class GoodsManager{
	public:
		int front,end;
		GoodsManager(){
			front=0;
			end=0;
		}
		int G[10005][2];
		const int size=10001;
};
#endif