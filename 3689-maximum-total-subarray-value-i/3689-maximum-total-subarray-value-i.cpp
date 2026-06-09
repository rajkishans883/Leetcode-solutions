class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        int min_=INT_MAX;
        int max_=INT_MIN;
        for(int i=0;i<n;i++){
            min_=min(min_,nums[i]);
            max_=max(max_,nums[i]);

        }
        int value=max_-min_;
        for(int i=0;i<k;i++){
            sum=sum+value;
        }
        return sum;
    }
};