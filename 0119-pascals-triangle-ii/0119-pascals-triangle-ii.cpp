class Solution {
public:
    vector<int> getRow(int rowIndex) { 
        vector<int> prev = {1};

        for(int i = 0; i < rowIndex; i++){
            int n = prev.size() + 1;
            vector<int> curr(n, 1);

            for(int j = 1; j < n-1; j++){
                curr[j] = prev[j-1]  + prev[j];
            }
            prev = curr;
        }
        return prev;
    }
};