class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> v;
        for(int i=0;i<(int)buildings.size();i++) {
            v.push_back({buildings[i][0], -1*buildings[i][2]});
            v.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(v.begin(),v.end());
        multiset<int, greater<int>> s;
        vector<vector<int>> ans;
        int prev_ = -1;
        int pos = 0;
        for(int i=0;i<(int)v.size();i++) {
            pos = v[i].first;
            if(v[i].second < 0) {
                s.insert(abs(v[i].second));
            } else {
                s.erase(s.find(v[i].second));
            }
            if(s.empty()) {
                prev_ = 0;
                ans.push_back({pos, prev_});    
            }
            else if(*(s.begin()) != prev_) {
                prev_ = *(s.begin());
                ans.push_back({pos, prev_});
            }
        }
        return ans;
    }
};
