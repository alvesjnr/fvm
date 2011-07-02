#include <string.h>

int is_a_number(const char *word){
	int i;
	int len = strlen(word);

	for(i=0; i<len; i++)
		if(!isdigit(word[i]))
			return 0;
	return 1;
}

