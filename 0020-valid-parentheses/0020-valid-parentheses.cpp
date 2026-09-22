class Solution {
public:
    bool isValid(string x){
        
        stack<char >s;
        char c;
        int i=0;
        while(i<x.length()){
            c=x[i];
            if(c=='('|| c=='{' || c=='['){
                s.push(c);
            }
            
            else {
                if(!s.empty()){
                char check=s.top();
                if(check=='(' &&  c==')' ||check=='{' && c=='}' || check=='[' && c==']'){
                    s.pop();
                  }
                  else{
                      return false;
                  }
                }
                else{
                    return false;
                }
                
                
            }
            i++;
        }
        if(s.empty())
                return true;
          else 
            return false;
    
    }
};