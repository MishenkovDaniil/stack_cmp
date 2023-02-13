#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "arr_stack.h"
void test_1 ();

int main ()
{
    test_1 ();
    //test_2 ();
    //test_3 ();

    return 0;
}

void test_1 ()
{
    clock_t t1 = 0;
    clock_t t2 = 0;

    void *buffer = calloc (1, sizeof (int));
    t1 = clock ();
    
    size_t kount = 1000000;
    
    Stack *stk = stack_ctr (100, sizeof (int));

    for (size_t i = 0; i < kount; i++)
    {
        push (stk, (void *)&i);
    }

    top (stk, buffer);
    printf ("%d\n", *((int *)buffer));

    for (size_t k = 0; k < 8; k++)
    {
        size_t count = stk->size;
        
        for (size_t i = 0; i < count/2; i++)
        {
           pop (stk);
        }
        
        top (stk, buffer);
        printf ("%d\n", *((int *)buffer));
    
        count = stk->size;
        
        for (size_t i = count; i < count + count/2; i++)
        {
            push (stk, (void *)&i);
        }

        top (stk, buffer);
        printf ("%d\n", *((int *)buffer));
    }

    stack_dtr (stk);
    t2 = clock ();
    free (buffer);
    
    fprintf (stderr, "ARR_STACK: first test performance time - %.2f ms.\n", (double)(1000*(t2 - t1))/CLOCKS_PER_SEC);
}
