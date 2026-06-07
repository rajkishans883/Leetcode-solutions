/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        int n=d.size();
        unordered_map<int,TreeNode*>mp;
        set<int>st;
        for(int i=0;i<n;i++){

                if(mp.find(d[i][0])==mp.end()){
                    mp[d[i][0]]= new TreeNode(d[i][0]);
                    
                    st.insert(d[i][0]);
                }
                if(mp.find(d[i][1])==mp.end()){
                    mp[d[i][1]]=new TreeNode(d[i][1]);
                    
                    st.insert(d[i][1]);
                }
        }

        for(int i=0;i<n;i++){
            int parent=d[i][0];
            int child=d[i][1];
            int direction=d[i][2];
            if(st.find(child)!=st.end()){
                st.erase(child);
            }

            if(direction==1){
                mp[parent]->left=mp[child];
            }
            if(direction==0){
                mp[parent]->right=mp[child];
            }
        }
        int root;
        for(auto s:st){
            root=s;
        }
        cout<<st.size()<<endl;
        return mp[root];
    }
};