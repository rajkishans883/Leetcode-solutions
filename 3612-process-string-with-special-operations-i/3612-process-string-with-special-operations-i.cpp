class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string result;

        for(auto it:s){
            if(it !='*' and it !='#' and it !='%')
                result.push_back(it);
            if(it=='*')
                if(result.size()>0)
                    result.pop_back();
            if(it=='#')
                result=result+result;
            if(it=='%')
                reverse(result.begin(),result.end());
        }
        return result;
    }
};