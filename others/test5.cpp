#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        struct Elements {
            int e;
            int n = 0;
        };

        struct Elements ele_of_nums[size];

        for (int i = 0; i < size; i++) {
            int t = nums.at(i);
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
    vector<int> nums = {6,5,5};
    Solution obj;
    int number = obj.majorityElement(nums);
    cout << number << endl;

    return 0;
}