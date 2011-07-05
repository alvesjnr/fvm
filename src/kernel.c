#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"

#define CODECHUNK_LIMIT 40
#define SOURCE_SIZE 1024


/*global definitions start here*/
char *ram;
char *dict;
int stack[100];
int ram_len;
int dict_len;
int stack_len;

int sp;	/*main stackpointer*/
char *source; /*main program pointer*/
unsigned int pc; /*a pointer to the source*/

 
void kpanic(){
	printf("KPANIC!!!");
	exit(1);
}

int config_kernel(char *code_start,
				  void *ram_start, 
				  int ram_size, 
				  void *dict_start, 
				  int dict_size, 
				  int *stack_start, 
				  int stack_size){
	
	source = code_start;
	ram = ram_start;
	dict = dict_start;
	//stack = stack_start;
	ram_len = ram_size; 
	dict_len = dict_size; 
	stack_len = stack_size;

	sp = 0;
	pc = 0;

	return 1;
}

void start_kernel(){
	
	char code_chunk[CODECHUNK_LIMIT];
	while(1){
		get_code_chunk(code_chunk);
		parse(code_chunk); //fixme: dont parse all in a single punch!)
	}
}

void run_console(){
	//only for emulation on a computer
	char input[100];
	while(1){
		scanf("%s",input);
		parse(input);
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

void get_code_chunk(char *chunk){
	int i=0;
	do{
		chunk[i++] = source[pc++];
	}while(i<CODECHUNK_LIMIT && source[pc-1]!='\n' && source[pc-1]!=';');
	chunk[i]='\0';
}