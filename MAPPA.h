//��ͼ��,֧��ʹ�ý���
#include "Dot.h"
#include "GoodsManager.h"
class MAPPA{
	public:
		GoodsManager gm;
		Dot d[201][201];
		void init();
		void update(int zhen);
		void change(int zhen); 
		void vanish(int zhen);
}; 


