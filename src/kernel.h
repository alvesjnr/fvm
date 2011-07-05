extern int config_kernel(char *code_start,
				  void *ram_start, 
				  int ram_size, 
				  void *dict_start, 
				  int dict_size, 
				  void *stack_start, 
				  int stack_size);
extern void start_kernel();
extern void kpanic();
extern void get_code_chunk(char *chunk);

extern struct WDict{
	char wname[8];
	int pointer;
};

extern struct WCode{
	char control;
	char code[9];
};
