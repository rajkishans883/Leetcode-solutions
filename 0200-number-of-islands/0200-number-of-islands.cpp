class Solution {
public:

   bool check(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis,int n,int m){
            if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && grid[i][j]=='1'){
                return true;
            }
            return false;
   }
   void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;
        int arr1[4]={1,-1,0,0};
        int arr2[4]={0,0,-1,1};

        for(int k=0;k<4;k++){
            int index1=arr1[k]+i;
            int index2=arr2[k]+j;

            if(check(index1,index2,grid,vis,n,m)){
                dfs(index1,index2,grid,vis,n,m);
            }
        }
        return;
   }

    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]=='1'){
                   if(vis[i][j]==0){
                    cout<<11<<" ";
                   count++;
                   dfs(i,j,grid,vis,n,m);
                   }
               }
            }
        }
       return count;
    }
};