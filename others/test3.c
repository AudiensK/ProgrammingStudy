#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    int t;
    for (int k1 = 0; k1 < k; k1++) {
        t = nums[numsSize - 1];
        for (int id = numsSize - 1; id > 0; id--) {
            nums[id] = nums[id - 1];
        }
        nums[0] = t;
    }
}

int main()
{
    int nums[] = {1,2,3,4,5,6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    
    rotate(nums, numsSize, k);

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

/*
123456

*/