#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution {
public:
    bool jumps(int index, v<int> &nums)
    {
        if(index >= nums.size())
            return true;
        
        if(nums[index] == 0)
            return false;
        
        for (int i = 1; i <= nums[index]; i++)
        {
            if(jumps(index+i, nums))
                return true;
        }
        
        return false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0)
            return true;
    
        return jumps(0, nums);
    }
};

int main()
{
    

    return 0;
}