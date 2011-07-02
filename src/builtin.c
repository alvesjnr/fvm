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

void _over(PARAM){
	//	( a b -- a b a )
	stack[*sp] = stack[*sp-2];
	(*sp)++;
}

void _drop(PARAM){
	//	( a -- )
	(*sp)--;
}

void _0sp(PARAM){
	//	( a b ... -- )
	*sp = 0;
}

void _q_dup(PARAM){
	//?dup
	//( n -- n n | 0 , duplicate only if non-zero, '|' means OR )
	if(*sp-1){
		stack[*sp] = stack[*sp-1];
		(*sp)++;
	}
}

void _rot(PARAM){
	// rot
	//	( a b c ... b c a )
	stack[*sp] = stack[*sp-1];
	stack[*sp-1] = stack[*sp-3];
	stack[*sp-2] = stack[*sp];
	stack[*sp-3] = stack[*sp-1];
}

void __rot(PARAM){
	// -rot
	//	( a b c ... c a b )
	stack[*sp] = stack[*sp-1];
	stack[*sp-1] = stack[*sp-2];
	stack[*sp-2] = stack[*sp-3];
	stack[*sp-3] = stack[*sp];
}

void _nip(PARAM){
	//	( a b -- b ) swap drop ;
	stack[*sp-2] = stack[*sp-1];
	(*sp)--;
}

void _tuck(PARAM){
	//	( a b -- b a b ) swap over ;
	stack[*sp] = stack[*sp-2];
	(*sp)++;
}

void _equ(PARAM){
	//	( a b -- b==b ) swap over ;
	if(stack[*sp-1] == stack[*sp-2])
		stack[*sp] = 0;
	else
		stack[*sp] = -1;
	(*sp)++;
}

void _gte(PARAM){
	//	( a b -- b>a ) swap over ;
	if(stack[*sp-1] > stack[*sp-2])
		stack[*sp] = 0;
	else
		stack[*sp] = -1;
	(*sp)++;
}

void _lte(PARAM){
	//	( a b -- b<a ) swap over ;
	if(stack[*sp-1] < stack[*sp-2])
		stack[*sp] = 0;
	else
		stack[*sp] = -1;
	(*sp)++;
}

void _gteq(PARAM){
	//	( a b -- b>a ) swap over ;
	if(stack[*sp-1] >= stack[*sp-2])
		stack[*sp] = 0;
	else
		stack[*sp] = -1;
	(*sp)++;
}

void _lteq(PARAM){
	//	( a b -- b<=a ) swap over ;
	if(stack[*sp-1] <= stack[*sp-2])
		stack[*sp] = 0;
	else
		stack[*sp] = -1;
	(*sp)++;
}

void _invert(PARAM){
	//	( a b -- b>b ) swap over ;
	stack[*sp-1] = ~stack[*sp-1];
	(*sp)++;
}



