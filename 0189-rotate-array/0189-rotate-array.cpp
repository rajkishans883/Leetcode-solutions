class Solution {
public:
    
    void rev(vector<int>&arr,int low,int high){
       while(low<high)
       {
           swap(arr[low],arr[high]);
           low++;
           high--;
           
       }
    }
    void rotate(vector<int>& nums, int d) {
       int n=nums.size();
        d=d%n;
       rev(nums,0,n-d-1); //rotate first d elements
       rev(nums,n-d,n-1);  //rotate n-d remaining elements
       rev(nums,0,n-1);  //rotate all elements
    
    }
   

        
     
};