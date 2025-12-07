#include <stdio.h>

bool TestAndSet(bool *lock);

int main()
{
    bool lock = true;
    printf("%d", TestAndSet(&lock));

    return 0;
}

bool TestAndSet(bool *lock)
{
    bool old;
    old = *lock;
    *lock = true;
    return old;
}