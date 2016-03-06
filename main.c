
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

//test version 2

#define TEST_SIZE	3

test_t tt[TEST_SIZE];

GFifo_t fifo;

int main(){

	test_t tmp;
	
	int cmd;
	
	GFIFO_INIT(&fifo,tt,TEST_SIZE);
	
	
	while(1){
		
		scanf("%d",&cmd);
		if(cmd == 3){
			break;
		}
		switch(cmd){
			
			case 0:
				printf("please input float int char...\r\n");
				scanf("%f %d %c",&tmp.num,&tmp.count,&tmp.ch);
				GFIFO_IN_FORCE(&fifo,tmp,test_t);
			break;
			case 1:
				if(GFIFO_OUT(&fifo,tmp,test_t)){
					printf("tmp num: %.2f\tcount: %d\t ch: %c\t\r\n",tmp.num,tmp.count,tmp.ch);
				}else{
					printf("ERROR\r\n");
				}
			break;
			case 2:
				printf("the current len of FIFO is: %d\r\n",GFIFO_LEN(&fifo));
			break;
		}
		
		do{
			int i;
			for(i = 0;i < TEST_SIZE;i++){
				tmp = tt[i];
				printf("tmp num: %.2f\tcount: %d\t ch: %c\t\r\n",tmp.num,tmp.count,tmp.ch);
			}
		}while(0);
		
	}
	
	
	return 0;
}
 
/*
//test version 1
test_t tt[128];

GFifo_t fifo;

int main(){

	test_t tmp,tmp1;
	
	GFIFO_INIT(&fifo,tt,2);

	tmp.ch = '1';
	tmp.count = 100;
	tmp.num = 12.0;
	
	printf("%d\r\n",GFIFO_EMPTY(&fifo));
	
	printf("1 %d\r\n",GFIFO_LEN(&fifo));
	//GFIFO_IN(&fifo,tmp,test_t);
	GFIFO_IN_FORCE(&fifo,tmp,test_t);
	printf("2 %d\r\n",GFIFO_LEN(&fifo));
	if(GFIFO_OUT(&fifo,tmp1,test_t)){
	
		printf("tmp1 num: %.2f\tcount: %d\t ch: %c\t\r\n",tmp1.num,tmp1.count,tmp1.ch);
	
	}
	printf("3 %d\r\n",GFIFO_LEN(&fifo));
	if(GFIFO_OUT(&fifo,tmp1,test_t)){
	
		printf("tmp1 num: %.2f\tcount: %d\t ch: %c\t\r\n",tmp1.num,tmp1.count,tmp1.ch);
	
	}
	printf("4 %d\r\n",GFIFO_LEN(&fifo));
	
	
	
	return 0;
}*/

