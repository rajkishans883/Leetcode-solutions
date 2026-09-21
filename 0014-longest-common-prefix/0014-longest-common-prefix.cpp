class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int len=str.size();
        if(len=0)return "";
        string prefix=str[0];

        for(int i=1;i<str.size();i++){
            int j=0;

            while(j<prefix.size()&&
                    j<str[i].size() &&
                    prefix[j]==str[i][j]
            
            ){
                j++;
            }
            prefix=prefix.substr(0,j);
            if(prefix.size()==0)return "";
        }
        return prefix;
    }
};