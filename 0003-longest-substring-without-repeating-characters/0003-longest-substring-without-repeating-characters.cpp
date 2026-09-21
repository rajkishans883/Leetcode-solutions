class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    set<char>mp;
    int start=0;
    int end=0;
    int maxlen=0;
    
    while(start<s.size()){
        
        
        
        if(mp.find(s[start])==mp.end()){
            mp.insert(s[start]);
            maxlen=max(maxlen,start-end+1);
            start++;
            
        }
        else{
            mp.erase(s[end]);
            end++;
        }
        
    }
        return maxlen;
        
    }
};

