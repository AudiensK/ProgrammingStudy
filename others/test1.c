#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            n--;
        } else {
            i++;
        }
    }

    return i;
}


/*int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}*/

int main()
{
    int nums[] = {0,1,2,2,3,0,4,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    int k = removeElement(nums, numsSize, val);
    printf("k= %d\n", k);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
}