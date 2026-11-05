class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
      int maxi = -1;
      vector<int> ans;

      for(int i = arr.size()-1; i >= 0; i--){
            ans.push_back(maxi);
           maxi = max(maxi, arr[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};