class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end()), r = 0;
        r = accumulate(nums.begin(), nums.end(), r);
        
        while(l < r){
            int mid = l + (r-l)/2;
            int curr = 0, count = 1;
            for(int i = 0; i < nums.size(); i++){
                if(curr + nums[i] > mid){
                    curr = 0;
                    count++;
                }
                curr+=nums[i];
            }
            if(count <= m){
                r = mid;
            }else l = mid + 1;
        }
        
        return l;
    }
};
