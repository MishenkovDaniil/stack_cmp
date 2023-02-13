#include <stdio.h>
#include <time.h>

#include "ptr_stack.h"
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

    t1 = clock ();
    
    Stack *stk = stack_ctr (sizeof (int));
    
    int kount = 1000000;

    for (int i = 0; i < kount; i++)
    {
        push (stk, (void *)&i);
    }
    printf ("%d\n", *((int *)(stk->root->data)));

    for (int k = 0; k < 8; k++)
    {
        int count = stk->size;
        for (int i = 0; i < count/2; i++)
        {
            pop (stk);
        }
        printf ("%d\n", *((int *)(stk->root->data)));
        count = stk->size;

        for (int i = count; i < count + count/2; i++)
        {
            push (stk, (void *)&i);
        }
        printf ("%d\n", *((int *)(stk->root->data)));
    }

    stack_dtr (stk);
    t2 = clock ();

    fprintf (stderr, "PTR_STACK: first test performance time - %.2f ms.\n", (double)(1000*(t2 - t1))/CLOCKS_PER_SEC);
}
