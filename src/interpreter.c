#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "builtin.h"

extern int sp;
extern void push_stack(int value);
extern int pop_stack();


void define_word(char word_definition[]){
        
    const char* token = " \n";
    const char* end = "END";

    char *key = strtok(word_definition,token);
    char *value = strtok(NULL,end);

    //insert a key-value into names dictionary
    printf("added %s: %s\n",key,value);

}

void parse(char source[], char *stack){
    
    const char* token = " \n";
    const char* end_token = ";";
    char *source_copy = (char*)malloc(sizeof(char)*strlen(source));

    char *word = strtok(source,token);
    while (word != NULL)
    {

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
            if(apply_word(word,stack))
                kpanic();
        }

        word = strtok (NULL, token);
    }
}

int apply_word(char *word, int *stack){
    
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
            (builtin_list[i]).value(stack,&sp); //its like javascript
            return 0;
        }
    }

    return 1;
}


