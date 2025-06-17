/*  多数元素
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2
 

提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // Boyer-Moore 投票算法
    int majorityElement(vector<int>& nums) {
        // int size = nums.size();
        // int candidate = nums[0];
        // int count = 1;

        // for (int i=1; i<size; i++) {
        //     if (count == 0) {
        //         candidate = nums[i];
        //     }

        //     if (candidate == nums[i]) {
        //             count++;
        //         } else {
        //             count--;
        //         }
        // }

        // return candidate;

        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }

        return candidate;
    }

    // 遍历计数
    int majorityElement1(vector<int>& nums) {
        int size = nums.size();
        struct Elements {
            int e;
            int n = 0;  // 默认初始化
        };

        // struct Elements ele_of_nums[size];
        Elements ele_of_nums[size];  // C++中可以省略关键字struct

        for (int i = 0; i < size; i++) {
            // int t = nums.at(i);  // 有边界检查
            int t = nums[i]; // 直接使用[]访问效率更高，但是没有边界检查
            for (int l = 0; l < size; l++) {
                if (ele_of_nums[l].n == 0) {
                    ele_of_nums[l].e = t;
                    ele_of_nums[l].n++;
                    break;
                } else if (t == ele_of_nums[l].e) {
                    ele_of_nums[l].n++;
                    break;
                }
            }
            
        }

        int max = 0;
        for (int i = 1; i < size; i++) {
            if (ele_of_nums[i].n >= ele_of_nums[max].n) {
                max = i;
            }
        }

        return ele_of_nums[max].e;
    }
};


int main()
{
    vector<int> nums = {3,2,3};
    Solution obj;
    int number = obj.majorityElement(nums);
    cout << number << endl;

    return 0;
}