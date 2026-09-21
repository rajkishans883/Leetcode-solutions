class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int globle_max=INT_MIN;
        int sum=0;

        for(int i=0;i<len;i++){
            sum=sum+nums[i];
            globle_max=max(globle_max,sum);
            if(sum<0){
                sum=0;
            }
        }
        return globle_max;
    }
};