/*
Author: Tung
*/
#define LONG_MAX 0x7fffffff 
long seed = 1;

long 
rand() 
{
    seed = ((seed * 1103515245U) + 12345U) & LONG_MAX;
    return seed;
}

void
srand(long val)
{
    seed = val;
}

long
randint(long max)
{
    /*
    Generate a random integer in range [0, max], inclusive at both end
    Edgecases:
        - max < 0
    */
    if (max < 0) {
        return -1;
    }
    unsigned long num_vals = (unsigned long) LONG_MAX + 1;
    unsigned long num_bins = (unsigned long) max + 1;
    unsigned long bin_cnt = num_vals / num_bins; 
    unsigned long remainder = num_vals % num_bins;

    long rand_num = rand();
    while (rand_num >= num_vals - remainder) {
        rand_num = rand();
    }

    return rand_num / bin_cnt;
}