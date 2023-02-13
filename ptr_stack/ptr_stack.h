#ifndef PTR_STACK_H
#define PTR_STACK_H

struct Node
{
    void *data = nullptr;
    Node *next = nullptr;
};

struct Stack
{
    Node *root = nullptr;
    size_t size = 0;
    size_t element_size = 0;
};

struct Stack* stack_ctr (size_t element_size);
int push(struct Stack* stk, void* buffer);
int top(struct Stack* stk, void* buffer);
int pop(struct Stack* stk);
struct Stack* stack_dtr(struct Stack* stk);

#endif /* PTR_STACK_H */