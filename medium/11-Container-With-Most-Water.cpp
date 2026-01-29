class Solution {
public:
    int maxArea(const vector<int>& height) {
        int res = 0;
        int last_index = 0;

        for (int i = 0; i < height.size(); i++) {
            if (height[i] == 0) {
                continue;
            }
            for (int j = i + std::max(1, res / height[i]); j < height.size(); j++) {
                int current = (j - i) * std::min(height[i], height[j]);
                if (current > res) {
                    res = current;
                    last_index = j;
                }
            }
        }
        return res;
    }
};
