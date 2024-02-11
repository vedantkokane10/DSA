#include<bits/stdc++.h>
using namespace std;

// Subsequences with sum equal to  k

// gives all the sub-sequence
void helper(int ind,vector<int> &arr,vector<int> &sample,int &sum,int target){

	if(sum == target){
		for(auto x:sample){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}

	if(sum > target || ind >= arr.size()){
		return;
	}	
	
	sample.push_back(arr[ind]);
	sum += arr[ind];
	helper(ind+1,arr,sample,sum,target);
	sample.pop_back();
	sum -= arr[ind];
	helper(ind+1,arr,sample,sum,target);
}


 // returns the first sub-sequence
bool helper2(int ind,vector<int> &arr,vector<int> &sample,int &sum,int target){
	if(sum == target){
		for(auto x:sample){
			cout<<x<<" ";
		}
		cout<<endl;
		return true;
	}

	if(sum > target || ind >= arr.size()){
		return false;
	}	
	
	sample.push_back(arr[ind]);
	sum += arr[ind];
	if(helper2(ind+1,arr,sample,sum,target) == true){
		return true;	
	}
	sample.pop_back();
	sum -= arr[ind];
	if(helper2(ind+1,arr,sample,sum,target) == true){
		return true;	
	}
}


// returns count
int helper3(int ind,vector<int> &arr,vector<int> &sample,int &sum,int target){
	if(sum == target){
		return 1;
	}

	if(sum > target || ind >= arr.size()){
		return 0;
	}	
	
	sample.push_back(arr[ind]);
	sum += arr[ind];
	int a = helper3(ind+1,arr,sample,sum,target);
	sample.pop_back();
	sum -= arr[ind];
	int b = helper3(ind+1,arr,sample,sum,target);
	return a+b;
}


int main(){
	vector<int> arr = {1,2,1,2,1,1};
	vector<int> sample;
	int target = 2,sum = 0;
	int cnt = helper3(0,arr,sample,sum,target);
	cout<<cnt<<endl;
	return 0;
}
