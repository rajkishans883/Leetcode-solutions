class Solution {
public:

   int climbstairs(int n,vector<int>&vt) {
        
        if( n<=1)return 1;
        if(vt[n]!=0)return vt[n];
        return vt[n]=climbstairs(n-1,vt)+climbstairs(n-2,vt);
    }

    int climbStairs(int n) {
       vector<int>vt(n+1,0);
       return climbstairs(n,vt);
    }
};