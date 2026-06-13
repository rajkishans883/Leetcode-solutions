class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string answer;
        int n=words.size();
        // reverse(weights.begin(),weights.end());
        unordered_map<int,int>mp;
        vector<char>ch(26,'a');
        
        for(int i=0;i<26;i++){
            ch.push_back(('a'+i));
        }
        reverse(ch.begin(),ch.end());
        for(int i=0;i<26;i++){
            mp[i]=weights[i];
        }
        for(int var=0;var<n;var++){
            int sum=0;
            for( auto it : words[var]){
                int w=it-'a';
                int value=mp[w];
                sum=sum+value;
            }
            cout<<sum<<endl;
            char c=ch[sum%26];
            answer.push_back(c);
        }
        return answer;
    }
};