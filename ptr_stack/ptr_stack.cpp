#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "ptr_stack.h"

struct Stack* stack_ctr (size_t element_size)
{
    Stack *stk = (Stack *)calloc (1, sizeof (Stack));
    assert (stk);

    stk->size = 0;
    stk->element_size = element_size;

    return stk;
}

int push(struct Stack* stk, void* buffer)
{
    assert (stk && buffer);

    size_t element_size = stk->element_size;

    Node *new_root = (Node *)calloc (1, sizeof (Node));
    if (!(new_root))
    {
        return 0;
    }
    
    new_root->data = (void *)calloc (1, element_size);
    
    if (!(new_root->data))
    {
        return 0;
    }

    memcpy (new_root->data, buffer, element_size);
    new_root->next = stk->root;

    stk->root = new_root;
    stk->size++;

    return 1;
}

int top(struct Stack *stk, void *buffer)
{
    assert (stk && buffer);
    if (!(stk->root))
    {
        return 0;
    }

    memcpy (buffer, stk->root->data, stk->element_size);
    
    if (!(buffer))
    {
        return 0;
    }

    return 1;
}

int pop(struct Stack* stk)
{
    assert (stk);

    if (!(stk->root))
    {
        return 0;
    }

    Node *new_root = stk->root->next;

    free (stk->root->data);
    free (stk->root);
    
    stk->root = new_root;
    stk->size--;

    return 1;
}

struct Stack* stack_dtr(struct Stack* stk)
{
    assert (stk);

    Node *free_node = stk->root;

    while (free_node)
    {
        Node *next_node = free_node->next;
        
        free (free_node->data);
        free (free_node);

        free_node = next_node;
    }

    free (stk);
    stk = nullptr;

    return stk;
}
