class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int,int>> v;
        for(int i=0;i<(int)Profits.size();i++) {
            v.push_back({Capital[i],Profits[i]});
        }
        sort(v.begin(),v.end());
        multiset<int, greater<int>> ms;
        int idx = 0;
        while(k--) {
            while(idx<(int)Profits.size() && W >= v[idx].first){
                ms.insert(v[idx++].second);
            }
            if(!ms.empty()) {
                W += *(ms.begin());
                ms.erase(ms.begin());
            }
        }
        return W;
    }
};
