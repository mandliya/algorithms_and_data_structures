#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums) {
        int pres = nums[0],curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==pres){
                curr++;
            }
            if(nums[i]!=pres){
                curr--;
            }
            if(curr==0){
                pres = nums[i];
                curr=1;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==pres){
              count++;
          }
        }
        if(count>=nums.size()/2){
          return pres;
        }

        return -1;
}
int main(){
  vector<int> vect{2,2,1,1,1,2,2};
  int output = majorityElement(vect);
  cout<<output;
}
