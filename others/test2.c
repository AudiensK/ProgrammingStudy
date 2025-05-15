#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) {  // 数组大小为0或1时直接返回数组大小
        return 1;
    }  

    int s = 1;  // 当前处理的数组单元下标
    int sign = 0;  // sign==0：当前元素出现次数没有超过2次；sign==1：出现超过2次；
    while (s < numsSize) {
        if (nums[s] == nums[s - 1] && !sign) {  // s位和s-1位元素相等，并且该元素出现没有大于2次
            sign = 1;  // 如果下一位元素相等，该元素数量一定超过两次，所以将sign = 1
            s++;  // 指针进一位
        } else if (nums[s] == nums[s - 1] && sign && s != numsSize - 1) {
            // 将当前元素保存临时变量，然后将后面所有元素向前移动一位，同时把临时变量值放最后一位
            int t = nums[s];
            for (int i = s + 1; i < numsSize; i++) {
                nums[i - 1] = nums[i];
            }
            nums[numsSize - 1] = t - 1;
        } else if (nums[s] > nums[s - 1]) {
            s++;
            sign = 0;
        } else {
            break;
        }
    }

    return s;
}

int main()
{
    int nums[] = {1, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int n = removeDuplicates(nums, numsSize);

    printf("n=%d\n", n);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}