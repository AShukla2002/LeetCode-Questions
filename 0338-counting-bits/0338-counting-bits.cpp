class Solution {
public:
    int bit_count(int n){
        int ct = 0;
        while(n){
            n = (n & (n-1));
            ct++;
        }
        return ct;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int ct = bit_count(i);
            ans.push_back(ct);
        }
        return ans;
    }
};