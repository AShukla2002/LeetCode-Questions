class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            int time = 0;
            for (int pile : piles)
                time += (pile + mid - 1) / mid;
            if (time <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};