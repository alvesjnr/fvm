extern int config_kernel(void *ram_start, 
				  int ram_size, 
				  void *dict_start, 
				  int dict_size, 
				  void *stack_start, 
				  int stack_size);
extern void start_kernel(char sourcecode[]);
extern void kpanic();