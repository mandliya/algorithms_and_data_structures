#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    int n1=s1.length(),n2=s2.length(),flag=0;
	    vector<char> ucl;
	    for(int i=0;i<n1;i++){
	        flag=0;
	        for(int j=0;j<n2;j++){
	            if(s1[i]==s2[j]){
	                flag=1;
	            }
	        }
	        if(flag==0){
	            ucl.push_back(s1[i]);
	        }
	    }
        for(int i=0;i<n2;i++){
	        flag=0;
	        for(int j=0;j<n1;j++){
	            if(s2[i]==s1[j]){
	                flag=1;
	            }
	        }
	        if(flag==0){
	            ucl.push_back(s2[i]);
	        }
	    }
	    for(int i=0;i<ucl.size()-1;i++){
	        for(int j=i+1;j<ucl.size();j++){
	            if(ucl[i]==ucl[j]){
	                ucl.erase(ucl.begin()+j);
	                i--;
	                j--;
	            }
	        }
	    }
	    sort(ucl.begin(),ucl.end());
	    for(int i=0;i<ucl.size();i++){
	        cout<<ucl[i];
	    }
	    cout<<endl;
	}
	return 0;
}
