class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = *max_element(weights.begin(), weights.end()), r = 0, res = 0;
        r = accumulate(weights.begin(), weights.end(), r);
    
        while(l <= r){
            int mid = l + (r-l)/2;
            int d = 1, curr = 0;
            for(int i = 0; i < weights.size(); i++){
                if(curr + weights[i] > mid){
                    curr = 0;
                    d++;
                }
                curr+=weights[i];
            }
            if(d > days){
                l = mid+1;
            }else r = mid-1;
        }
        return l;
    }
};