class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n=s.size();

        for(auto it:s){
            mp[it]++;
        }
        vector<pair<int,int>>vt;
        for(auto it:mp){
            vt.push_back({it.first,it.second});
        }

        sort(vt.begin(),vt.end(),[](pair<int,int>&a,pair<int,int>&b){
                return a.second>b.second;
        });
        string ans="";
        for(auto it:vt){
            for(int j=0;j<it.second;j++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};