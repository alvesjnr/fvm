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
extern void _over(PARAM);
extern void _drop(PARAM);
extern void _0sp(PARAM);
extern void _q_dup(PARAM);
extern void _rot(PARAM);
extern void __rot(PARAM);
extern void _nip(PARAM);
extern void _tuck(PARAM);

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
		    				{"over", &_over},
		    				{"drop", &_drop},
		    				{"0sp", &_0sp},
		    				{"?dup", &_q_dup},
		    				{"rot", &_rot},
		    				{"-rot", &__rot},
		    				{"nip", &_nip},
		    				{"tuck", &_tuck},
			      		   };