/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
For example input={-1,0,1,2,-1,4}
We have output={{-1,0,1},{-1,-1,2}}
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums){
  int n=nums.size();
  vector<vector<int>>result;
  sort(nums.begin(),nums.end());
  if(n<3){
    result= {};
  }
  else{
    for(int i=0;i<n-2;i++){
      if(i>0&&nums[i-1]==nums[i])
      continue;
      int start=i+1,end=n-1;
      while(start<end){
        if(nums[start]+nums[end]==-nums[i]){
          result.push_back({nums[i],nums[start],nums[end]});
          start++,end--;
        }
        while(start<end&&nums[start-1]==nums[start]&&nums[end-1]==nums[end]){
          start++,end--;
          continue;
        }
        if(nums[start]+nums[end]<-nums[i]){
          start++;
        }
        else if(nums[start]+nums[end]>-nums[i]){
          end--;
        }

      }
    }
  }
  return result;
}
int main(){
  vector<int>v{-1,0,1,2,-1,-4};
  cout << "Vec:";
  for ( auto x : v) {
    cout << x << " ";
  }
  cout<<endl;
  vector<vector<int>>  u = threeSum(v);
  cout<<"triplets with sum as zero : "<<endl;
  if(u.size()==0){
    cout<<0<<endl;
  }
  else{
    for(int i = 0; i <u.size(); i++){
      for(int j =0; j <  u[i].size(); j++){
        cout << u[i][j] <<" ";
      }
      cout << endl;
    }
  }
  return 0;
}
