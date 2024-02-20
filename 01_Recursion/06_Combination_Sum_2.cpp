/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
Approach - 
We have to skip the results which sum up to the target but are already taken in the answer array.
1. sort array and then send it
2. Have a condition if(i > ind && nums[i] == nums[i-1]) continue;
The condition if(i > ind && nums[i] == nums[i-1]) is used to skip duplicate elements in the array nums during the recursive exploration of combinations.
nums[i] == nums[i-1]: This part checks whether the current element is equal to the previous element. If it is true, it means the current element is a duplicate.
i > ind: This part ensures that the check for duplicates is done only for elements at the same level of recursion. If i > ind, 
it means we are looking at elements in the same recursive level, and duplicates should be skipped.

3. Then the traditional approach is followed take and go to next or don't take and go to next.
*/

void helper(int ind,vector<int> nums,int target,int sum,vector<int> sample,vector<vector<int>> &ans){
    if(sum > target){
        return;
    }
    if(sum == target){
        ans.push_back(sample);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        if(i > ind && nums[i] == nums[i-1]){
            continue;
        }
        sample.push_back(nums[i]);
        sum += nums[i];
        helper(i+1,nums,target,sum,sample,ans);
        sample.pop_back();
        sum -= nums[i];
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(),candidates.end());
     vector<vector<int>> ans;
     vector<int> sample;
     helper(0,candidates,target,0,sample,ans);
     return ans;
}
