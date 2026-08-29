class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int l = 0;

        while(l < n) {
            int r = l;

            // Find the complete group
            while(r + 1 < n && arr[r + 1].first - arr[r].first <= limit) {
                r++;
            }

            // Collect original indices of this group
            vector<int> indices;

            for(int i = l; i <= r; i++) {
                indices.push_back(arr[i].second);
            }

            // Sort original indices
            sort(indices.begin(), indices.end());

            // Put smallest values at smallest indices
            for(int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = arr[l + i].first;
            }

            l = r + 1;
        }

        return nums;
    }
};