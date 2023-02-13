#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "arr_stack.h"

static const int LOW_CAPACITY = 100000;

struct Stack* stack_ctr (size_t capacity, size_t element_size)
{
    Stack *stk = (Stack *)calloc (1, sizeof (Stack));
    assert (stk);

    stk->size = 0;
    stk->capacity = capacity;
    stk->element_size = element_size;

    stk->data = (void **)calloc(capacity, element_size);
    printf ("%p", stk->data);
    return stk;
}

int push (struct Stack *stk, void *buffer)
{
    assert (stk && buffer);

    if (stk->size == stk->capacity)
    {
        realloc (stk);
    }
    assert (stk);

    memcpy ((void *)(((char *)(stk->data)) + stk->size*stk->element_size), buffer, stk->element_size);

    if (!(((char *)(stk->data)) + stk->size*stk->element_size))
    {
        return 0;
    }
    stk->size++;
    
    return 1;
}

int top(struct Stack *stk, void *buffer)
{
    assert (stk && buffer);

    if (!(stk->data && (stk->data)+0))
    {
        return 0;
    }

    memcpy (buffer, (void *)(((char *)(stk->data)) + (stk->size - 1)*stk->element_size), stk->element_size);

    if (!(buffer))
    {
        return 0;
    }

    return 1;
}

int pop (struct Stack *stk)
{
    assert (stk);

    if (!(stk->data && ((stk->data)+0) && stk->size))
    {
        return 0;
    }

    stk->size--;
    //(stk->data) + stk->size*stk->element_size = nullptr; ///not necessary

    return 1;
}

struct Stack* stack_dtr (struct Stack *stk)
{
    assert (stk);

    free (stk->data);
    free (stk);

    stk = nullptr;

    return stk;
}

void realloc (Stack *stk)
{
    assert (stk);
    size_t capacity = stk->capacity;

    if (capacity >= LOW_CAPACITY)
    {
        stk->data = (void **)realloc (stk->data, 3*(capacity/2*stk->element_size));
        stk->capacity = 3*capacity/2;
    }
    else 
    {
        stk->data = (void **)realloc (stk->data, LOW_CAPACITY*stk->element_size);
        stk->capacity = LOW_CAPACITY;
    }
}