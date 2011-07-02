#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"

/*global definitions start here*/
char *ram;
char *dict;
int stack[100];
int ram_len;
int dict_len;
int stack_len;

int sp;

void print_stack(){
	int i=0;
	for(i=0; i<sp; i++)
		printf("|%i|",stack[i]);
}
 
void kpanic(){
	printf("KPANIC!!!");
	exit(1);
}

int config_kernel(void *ram_start, 
				  int ram_size, 
				  void *dict_start, 
				  int dict_size, 
				  int *stack_start, 
				  int stack_size){
	

	ram = ram_start;
	dict = dict_start;
	//stack = stack_start;
	ram_len = ram_size; 
	dict_len = dict_size; 
	stack_len = stack_size;

	sp = 0;

	return 1;
}

void start_kernel(char sourcecode[]){
	parse(sourcecode, stack); //fixme: dont parse all in a single punch!)
}

void run_console(){
	char input[100];
	while(1){
		printf(">");
		scanf("%s",input);
		parse(input,stack);
	}
}
void push_stack(int value){

	if(sp==stack_len)
		kpanic();
    
    stack[sp++] = value;
}

int pop_stack(){

	if(sp==0)
		kpanic();

	return stack[--sp];
}

