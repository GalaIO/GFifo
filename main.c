
/*
 * Author: 	    GalaIO
 * Date:   	    2015-8-3 10:05 PM
 * Description: test the GFifo.
 *
**/
#include <stdio.h>

#include "GFifo.h"

typedef struct {
	float num;
	int count;
	char ch;
}test_t; 

test_t tt[128];

GFifo_t fifo;

int main(){

	test_t tmp,tmp1;
	
	GFIFO_INIT(&fifo,tt,128);

	tmp.ch = '1';
	tmp.count = 100;
	tmp.num = 12.0;
	
	printf("%d",GFIFO_EMPTY(&fifo));
	
	GFIFO_IN(&fifo,tmp,test_t);
	
	GFIFO_OUT(&fifo,tmp1,test_t);
	
	printf("tmp1 num: %.2f\tcount: %d\t ch: %c\t\r\n",tmp1.num,tmp1.count,tmp1.ch);
	
	GFIFO_OUT(&fifo,tmp1,test_t);
	
	printf("tmp1 num: %.2f\tcount: %d\t ch: %c\t\r\n",tmp1.num,tmp1.count,tmp1.ch);
	
	return 0;
}

