#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "kernel.h"

#define RAM_LEN 512
#define DICT_LEN 256
#define STACK_LEN 256
#define INT_SIZE 4 //32 bits uC, 4 bytes len int word

/*arduino 2k ram simulation*/
char ram[RAM_LEN];	//words definitions are here. 
char dict[DICT_LEN]; //each entry is [name]@[address] 10 bytes each entry.
int stack[STACK_LEN/INT_SIZE]; //256 bytes (64 word) deep (not so much, isn't it?)


int main(int argc, char *argv[]){
	
	if(argc != 2){
		printf("use: %s <sourcecode>\n", argv[0]);
		return 1;
	}

	char *sourcecode = argv[1];

	if(config_kernel(ram, RAM_LEN, dict, DICT_LEN, stack, STACK_LEN)
	   ){
		start_kernel(sourcecode);
	}
	kpanic();
}