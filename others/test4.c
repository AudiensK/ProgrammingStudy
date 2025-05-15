#include <stdio.h>
#include <stdbool.h>


bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 1;
    } else if (nums[0] == 0) {
        return 0;
    }

    bool can = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == 0) {
            for (int si = 0; si < i; si++) {
                if (nums[si] > i - si) {
                    can = 1;
                    break;
                } else {
                    can = 0;
                }
            }
            
            if (!can) {
                break;
            }
        }
    }

    return can;
}


int main()
{
    int nums[] = {1,0,0,0,3,0,0,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = canJump(nums, numsSize);
    printf("%d", ret);

    return 0;
}