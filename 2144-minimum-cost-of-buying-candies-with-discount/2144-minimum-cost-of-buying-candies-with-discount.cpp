class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int min_cost=0;
        for (int i=0;i<n;i++){
            cout<<cost[i]<<" ";
        }
        if(n==1)return cost[0];
        if(n==2)return cost[0]+cost[1];
        for(int i=0;i<n;){
           if(i<n && i+1<n){
            min_cost=min_cost+cost[i]+cost[i+1];
            i=i+2;
           }
           else if(i<n && i+1==n){
            min_cost=min_cost+cost[i];
            i=i+1;
           }
           if(i<n){
            i++;
           }
        }
        return min_cost;
    }
};