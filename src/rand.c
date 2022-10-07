/*
Author: Tung
*/
long seed = 1;

long 
rand() 
{
    seed = ((seed * 1103515245U) + 12345U) & 0x7fffffff;
    return seed;
}

void
srand(long int val)
{
    seed = val;
}