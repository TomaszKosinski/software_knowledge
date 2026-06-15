// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndexMap;

        for(int i = 0; i<nums.size(); ++i)
        {
            unordered_map<int,int>::iterator it = numToIndexMap.find(target - nums[i]);
            if(it != numToIndexMap.end())
            {
                cout<<"Bingo:"<<it->second<<","<<i<<endl;
                return {it->second, i};
            }
            numToIndexMap[nums[i]] = i;
        }

        return {-1,-1};
    }
};



int main()
{
    cout<<"Starting 1 Two Sum"<<endl;

    Solution solution;

    vector<int> input1{2,7,11,15};
    int target1 = 9;
    vector<int> expectedOutput1{0,1};
    auto output1 = solution.twoSum(input1, target1);

    vector<int> input2{3,2,4};
    int target2 = 6;
    vector<int> expectedOutput2{1,2};
    auto output2 = solution.twoSum(input2, target2);

    vector<int> input3{3,3};
    int target3 = 6;
    vector<int> expectedOutput3{0,1};
    auto output3 = solution.twoSum(input3, target3);

    vector<int> input4{4,-2,5,0,6,3,2,7};
    auto output4 = solution.twoSum(input4, 1);

    return 0;
}