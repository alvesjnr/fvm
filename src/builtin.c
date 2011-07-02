#define PARAM int *stack, int *sp

void _add(PARAM){
	// ( a b -- a+b )
	stack[*sp-2] = stack[*sp-2] + stack[*sp-1];
	(*sp)--;
}

void _sub(PARAM){
	// 	( a b -- a-b )
	stack[*sp-2] = stack[*sp-2] - stack[*sp-1];
	(*sp)--;
}

void _mul(PARAM){
	// 	( a b -- b*a )
	stack[*sp-2] = stack[*sp-2] * stack[*sp-1];
	(*sp)--;
}

void _div(PARAM){
	// 	( a b -- a/b )
	stack[*sp-2] = stack[*sp-2] / stack[*sp-1];
	(*sp)--;
}

void _mod(PARAM){
	// 	( a b -- b%a )
	stack[*sp-2] = stack[*sp-2] % stack[*sp-1];
	(*sp)--;
}

void _div_mod(PARAM){
	// 	( a b -- a/b a%b )
	stack[*sp] = stack[*sp-2] / stack[*sp-1];
	stack[*sp-2] = stack[*sp-2] % stack[*sp-1];
	stack[*sp-1] = stack[*sp];
}

void _swap(PARAM){
	// ( a b -- b a )
	stack[*sp] = stack[*sp-1];
	stack[*sp-1] = stack[*sp-2];
	stack[*sp-2] = stack[*sp];
}

void _dup(PARAM){
	//	( a -- a a )
	stack[*sp] = stack[*sp-1];
	(*sp)++;
}

