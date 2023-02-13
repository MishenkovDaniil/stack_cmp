#ifndef ARR_STACK_H
#define ARR_STACK_H

struct Stack 
{
    void **data = nullptr;
   
    size_t size = 0;
    size_t capacity = 0;
    size_t element_size = 0;
};


struct Stack* stack_ctr (size_t capacity, size_t element_size);
int push(struct Stack* stk, void* buffer);
int top(struct Stack* stk, void* buffer);
int pop(struct Stack* stk);
struct Stack* stack_dtr(struct Stack* stk);
void realloc (Stack *stk);


#endif /* ARR_STACK_H */