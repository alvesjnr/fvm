#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "builtin.h"
#include "kernel.h"

#define RUNNING_ON_PC

extern int sp;
extern void push_stack(int value);
extern int pop_stack();
extern int stack[];
extern int dict_cont;
extern struct WDict *wdict;

#ifdef RUNNING_ON_PC
void print_stack(){
    int i=0;
    for(i=0; i<sp; i++)
        printf("%i ",stack[i]);
    printf("\n");
}
#endif

void parse(char source[]){
    
    const char* token = " \n";
    const char* end_token = ";";
    char *source_copy = (char*)malloc(sizeof(char)*strlen(source));

    char *word = strtok(source,token);
    while (word != NULL)
    {

#ifdef RUNNING_ON_PC
        if(!strcmp(word,".s")){
            print_stack();
            break;
        }
#endif

        if(!strcmp(word,"end") || !strcmp(word,"END")){
            exit(0);
        }

        if(!strcmp(word,":")){
            //parse a word definition
            char *word_definition = strtok(NULL,end_token);
            strcpy(source_copy,strtok(NULL,"END"));
            
            printf("parsing: %s\n",word_definition);
            define_word(word_definition);
            
            word = strtok(source_copy,token);
        }
        if(is_a_number(word)){
            //push number to stack
            printf("pushing number %i\n",atoi(word));
            push_stack(atoi(word));
        }
        else {
            //apply a preentered word
            printf("applying word %s\n",word);
            if(apply_word(word))
                kpanic();
        }

        word = strtok (NULL, token);
    }
}

int apply_word(char *word){
    
    //check for output
    if(!strcmp(word,".")){
        //it only make sens on my pc!
        printf("removing %i\n", pop_stack());
        return 0;
    }

    //check for builtin word
    int i;
    for(i=0; i<BLIST_LEN; i++){
        if(!strcmp(word, builtin_list[i].key)){
            builtin_list[i].value(stack,&sp);
            return 0;
        }
    }

    return 1;
}

void define_word(char word_definition[]){
        
    //const char* token = " \n";
    //const char* end = ";";

    //printf("%s\n",word_definition);
    //char *key = strtok(word_definition,token);
    //char *value = strtok(NULL,end);

    //strcpy(wdict[dict_cont].wname,"key");
    //dict_cont++;
    //insert a key-value into names dictionary
    //printf("added %s: %s\n",key,value);

}
