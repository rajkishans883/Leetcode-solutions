class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int g_size=g.size();
        int s_size=s.size();
        int i=0;
        int j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g_size and j<s_size){
            if(g[i]<=s[j]){
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
        }
        return i;

    }
};