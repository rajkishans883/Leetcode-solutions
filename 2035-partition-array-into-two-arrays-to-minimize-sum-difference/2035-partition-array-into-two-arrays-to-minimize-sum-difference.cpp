class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        long long total = 0;
        for (int x : nums)
            total += x;

        vector<vector<long long>> leftSums(n + 1);
        vector<vector<long long>> rightSums(n + 1);

        // Generate all subset sums of left half
        for (int mask = 0; mask < (1 << n); mask++) {

            long long sum = 0;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    bits++;
                }
            }

            leftSums[bits].push_back(sum);
        }

        // Generate all subset sums of right half
        for (int mask = 0; mask < (1 << n); mask++) {

            long long sum = 0;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    bits++;
                }
            }

            rightSums[bits].push_back(sum);
        }

        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        long long answer = LLONG_MAX;

        for (int leftCount = 0; leftCount <= n; leftCount++) {

            int rightCount = n - leftCount;

            for (long long leftSum : leftSums[leftCount]) {

                long long target =
                    total / 2 - leftSum;

                auto &vec = rightSums[rightCount];

                auto it =
                    lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {

                    long long selected =
                        leftSum + *it;

                    answer = min(
                        answer,
                        llabs(total - 2 * selected)
                    );
                }

                if (it != vec.begin()) {

                    --it;

                    long long selected =
                        leftSum + *it;

                    answer = min(
                        answer,
                        llabs(total - 2 * selected)
                    );
                }
            }
        }

        return (int)answer;
    }
};