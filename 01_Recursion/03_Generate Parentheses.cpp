/*
Approach - 
Observation - answer's length will be doubled the size of n. Ex if n = 3 then answer will be of length 6
1. Base Case - if sample string size == n * 2 then it is a valid answer.
2. open  should be less than n in order to push a new '('
3. close  should be less than open in order to push a new ')'


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

                                   (0,0,2,"")
                               /                  \
                      (1,0,2,"(")               x Not possible as open == close, close should be less than open  
                     /        \                         
         (2,0,2,"((")     (1,1,2,"()")  
      /      \                 /       \               
    x  (2,1,2,"(())")    (2,1,2,"()(")   x Not possible as open == close, close should be less than open  
          / \                 /  \ 
      x   (2,2,2,"(())"      x    (2,2,2,"()()")
              ans                      ans

*/


void helper(int open,int close,int n,string sample,vector<string> &ans){
    if(sample.size() == n * 2){
        ans.push_back(sample);
        return;
    }

    if(open < n){
        sample.push_back('(');
        helper(open+1,close,n,sample,ans);
        sample.pop_back();
    }

    if(close < open){
        sample.push_back(')');
        helper(open,close+1,n,sample,ans);
        sample.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string sample = "";
    helper(0,0,n,sample,ans);
    return ans;
}
