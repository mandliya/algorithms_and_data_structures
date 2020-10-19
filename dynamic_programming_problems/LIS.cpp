#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//const int mod = 998244353;
const int mod = 1e9+7;
#define pb push_back
#define mp make_pair
#define sz size
#define fi first
#define se second
#define nl "\n"
#define ps(x) fixed<<setprecision(x)
#define all(x) (x).begin(), (x).end()
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
//*****************************************************************************************//
int LIS(vector<int>& arr, int n) {
    if(n<=1) return n;
    vector<int>dp; 
    dp.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(dp.back()<arr[i])
            dp.push_back(arr[i]);
        else{
            int j=lower_bound(dp.begin(), dp.end(), arr[i])-dp.begin();
            dp[j]=arr[i];
         }
    }
    return dp.size();
}
void code(){	
	int n; cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int res=LIS(arr, n);
	cout<<res<<nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  	freopen("output.txt", "w", stdout);
	#endif

	int T=1; //cin>>T;
	for(int i=1; i<=T; i++) code();
	
	#ifndef ONLINE_JUDGE
    	cerr<<"Actual : "<<1.0*clock()/CLOCKS_PER_SEC<<" sec\n";
	#endif
	return 0;
}
