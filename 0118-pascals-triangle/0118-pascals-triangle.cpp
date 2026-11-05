class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        vector<int> prev = {1};
        ans.push_back(prev);

        for(int i = 0; i< numRows-1; i++){
            int n = prev.size() + 1;
            vector<int> curr(n, 1);

            for(int j = 1; j< n-1; j++){
            curr[j] = prev[j-1] + prev[j];
            }
            ans.push_back(curr);
            prev = curr;
        }
        return ans;
    }
};