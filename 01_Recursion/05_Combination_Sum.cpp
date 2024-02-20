/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Approach - 
1. Take it and and take it Becasue repetiiton is allowed
2. Don't take and move to the next index
3. For base cases - 
                    1. if sum > target and ind >= nums.size()
                    2. if sum == target push sample in answer

*/

void helper(int ind,int sum,vector<int>sample,vector<int>& nums, int target,vector<vector<int>> &ans){
    if(ind >= nums.size() || sum > target){
        return;
    }
    if(sum == target){
        ans.push_back(sample);
        return;
    }
    sample.push_back(nums[ind]);
    sum += nums[ind];
    helper(ind,sum,sample,nums,target,ans);
    sample.pop_back();
    sum -= nums[ind];
    helper(ind+1,sum,sample,nums,target,ans);
} 
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sample;
    helper(0,0,sample,candidates,target,ans);
    return ans;
}
