#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "kernel.h"
#include "interpreter.h"

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

	if(!strcmp("-c",argv[1])){
		config_kernel(ram, RAM_LEN, dict, DICT_LEN, stack, STACK_LEN);
		run_console();
	}
	else{
		FILE *fp;		
		fp=fopen(argv[1], "r");
		if(fp==NULL) {
    		printf("Cannot open file.\n");
    		exit(1);
  		}
		char sourcecode[100];
		int i;
		for(i=0; i<100; i++){
			sourcecode[i] = fgetc(fp);
			if(sourcecode[i]==EOF)
				break;
		}
		if(config_kernel(ram, RAM_LEN, dict, DICT_LEN, stack, STACK_LEN)
		   ){
			start_kernel(sourcecode);
		}
	}
	kpanic();
}