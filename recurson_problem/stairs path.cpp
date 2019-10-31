#include<bits/stdc++.h>
using namespace std;

vector<string> gsp(int n){
    if(n==0){
        vector<string> g;
         g.push_back("");
            return g;
    }
     if(n<0){
        vector<string> g;
            return g;
    }
    vector<string> ans;
    vector<string> x=gsp(n-1);

    vector<string> x1=gsp(n-2);

    vector<string> x2=gsp(n-3);

     for(int i=0;i<x.size();i++){
        ans.push_back(x[i]+"1");
    }
      for(int i=0;i<x1.size();i++){
        ans.push_back(x1[i]+"2");
    }
     for(int i=0;i<x2.size();i++){
        ans.push_back(x2[i]+"3");
    }
    return ans;

}
int main(){
    vector<string> g=gsp(12);
    int counter=0;
    for(int i=0;i<g.size();i++){
        cout<<g[i]<<endl;
        counter++;
    }
      cout<<counter<<endl;
}
