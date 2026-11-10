class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i =0; i< n-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            unordered_set<int> mpp;

            for(int  j = i+1; j< n; j++){
                int complement  = -nums[i] - nums[j];

                if(mpp.find(complement) != mpp.end()){
                    vector<int> temp = {
                        nums[i], nums[j], complement
                    };

                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            
                mpp.insert(nums[j]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};