class Solution {
public:
    int maxJump(vector<int>& stones) {
        if (stones.size() == 2) {
            return stones[1] - stones[0];
        }
        
        // Initialize our bottleneck tracker with the first immediate jump
        int max_jump_bottleneck = stones[1] - stones[0];
        
        // Check the jump length when skipping exactly one stone 
        // across the entire sequence (alternating path strategy)
        for (size_t i = 2; i < stones.size(); i++) {
            int current_jump_length = stones[i] - stones[i - 2];
            max_jump_bottleneck = max(max_jump_bottleneck, current_jump_length);
        }
        
        return max_jump_bottleneck;
    }
};