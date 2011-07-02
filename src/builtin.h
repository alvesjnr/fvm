#define PARAM int *stack, int *sp
#define BLIST_LEN 8

/*arithimetic*/
extern void _add(PARAM);
extern void _sub(PARAM);
extern void _mul(PARAM);
extern void _div(PARAM);
extern void _mod(PARAM);
extern void _div_mod(PARAM);

/*stack control*/
extern void _swap(PARAM);
extern void _dup(PARAM);

/*logic*/

/* I/O */

/*builtin list*/
typedef struct {
	char key[8];
	void (*value)(PARAM);
} BIWord;

extern BIWord const
builtin_list[BLIST_LEN] = { {"+", &_add},
		    				{"-", &_sub},
		    				{"*", &_mul},
		    				{"/", &_div},
		    				{"mod", &_mod},
		    				{"/mod", &_div_mod},
		    				{"swap", &_swap},
		    				{"dup", &_dup},
			      		   };