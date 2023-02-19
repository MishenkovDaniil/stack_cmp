#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ptr_stack.h"
void test_1 ();
void test_2 ();
void test_3 ();

int main ()
{
    test_1 ();
    test_2 ();
    test_3 ();

    return 0;
}

void test_1 ()
{
    clock_t t1 = 0;
    clock_t t2 = 0;

    t1 = clock ();
    
    Stack *stk = stack_ctr (sizeof (int));
    
    int kount = 1000000;

    for (int i = 0; i < kount; i++)
    {
        push (stk, (void *)&i);
    }
    //printf ("%d\n", *((int *)(stk->root->data)));

    for (int k = 0; k < 8; k++)
    {
        int count = stk->size;
        for (int i = 0; i < count/2; i++)
        {
            pop (stk);
        }
      //  printf ("%d\n", *((int *)(stk->root->data)));
        count = stk->size;

        for (int i = count; i < count + count/2; i++)
        {
            push (stk, (void *)&i);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
    }

    stack_dtr (stk);
    t2 = clock ();

    fprintf (stderr, "PTR_STACK: first test performance time - %.2f ms.\n", (double)(1000*(t2 - t1))/CLOCKS_PER_SEC);
}

void test_2 ()
{
    clock_t t1 = 0;
    clock_t t2 = 0;

    t1 = clock ();
    
    Stack *stk = stack_ctr (sizeof (int));
    
    int kount = 1000000;

    for (int i = 0; i < kount; i++)
    {
        push (stk, (void *)&i);
    }
    //printf ("%d\n", *((int *)(stk->root->data)));

    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 10000; j++)
        {
            pop (stk);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
        for (size_t j = 0; j < 10000; j++)
        {
            push (stk, (void *)&j);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
    }

    for (int k = 0; k < 9; k++)
    {
        int count = stk->size;
        for (int i = 0; i < count/2; i++)
        {
            pop (stk);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
        count = stk->size;

        for (int i = count; i < count + count/2; i++)
        {
            push (stk, (void *)&i);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
    }

    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 10000; j++)
        {
            pop (stk);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
        for (size_t j = 0; j < 10000; j++)
        {
            push (stk, (void *)&j);
        }
        //printf ("%d\n", *((int *)(stk->root->data)));
    }

    stack_dtr (stk);
    t2 = clock ();

    fprintf (stderr, "PTR_STACK: seceond test performance time - %.2f ms.\n", (double)(1000*(t2 - t1))/CLOCKS_PER_SEC);
}

void test_3 ()
{
    clock_t t1 = 0;
    clock_t t2 = 0;

    srand (time(NULL));

    void *buffer = calloc (1, sizeof (int));
    
    size_t kount = 1000000;
    
    Stack *stk = stack_ctr (sizeof (int));

    for (size_t i = 0; i < kount; i++)
    {
        int val = rand()%2 + 1;
        push (stk, (void *)&val);
        //top (stk, buffer);
        //printf ("%d\n", *((int *)buffer));
    }

    t1 = clock ();

    for (size_t i = 0; i < kount; i++)
    {
        top (stk, buffer);
        //printf ("%d\n", *((int *)buffer));
        if (*(int *)buffer == 1)
        {
            int val = rand()%2 + 1;
            push (stk, (void *)&val);
        }
        else
        {
            pop (stk);
        }
        //printf ("dpspdps[%ld]\n", stk->size);
    }

    stack_dtr (stk);
    t2 = clock ();
    free (buffer);
    
    fprintf (stderr, "ARR_STACK: third test performance time - %.2f ms.\n", (double)(1000*(t2 - t1))/CLOCKS_PER_SEC);
}