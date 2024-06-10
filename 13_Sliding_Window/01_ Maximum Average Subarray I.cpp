/*
643. Maximum Average Subarray I
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000
*/

double findMaxAverage(vector<int>& nums, int k) {
    int i = 0, j = 0 , sum = 0;
    double ans = INT_MIN;
    while(j < nums.size()){
        sum += nums[j];
        if(j-i+1 == k){
            double avg = (double) sum / k;
            ans = max(ans,avg);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return ans;
}
