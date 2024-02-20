/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

                    []
           /                    \
          [1]                   []
        /     \              /     \
      [1, 2]  [1]           [2]    []
     /    \     |          /   \   / \
  [1,2,3] [1,2] [1]       [2,3] [2] []
   ...   ...   ...        ...   ...


Approach - 
1. Take or don't take
2. take and move to next index
3. don't take and move to next index
4. for base case --> if ind >= nums.size() simply push sample array in answer array.

*/


void helper(int ind,vector<int>& candidates,int target,vector<int>& sample,vector<vector<int>> &ans,int &sum){
    if(sum > target || ind >= candidates.size()){
        return;
    }
    if(sum == target){
        ans.push_back(sample);
        return;
    }
    sum += candidates[ind];
    sample.push_back(candidates[ind]);
    helper(ind,candidates,target,sample,ans,sum);

    sum -= candidates[ind];
    sample.pop_back();
    helper(ind+1,candidates,target,sample,ans,sum);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sample;
    int sum = 0;
    helper(0,candidates,target,sample,ans,sum);
    return ans;
}
