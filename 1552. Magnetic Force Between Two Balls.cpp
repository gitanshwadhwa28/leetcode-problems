class Solution {
public:
    int maxDistance(vector<int>& v, int m) {
        int l = 0, r, n = v.size(), mid, count, i, j;
        sort(v.begin(), v.end());
        r = v[n-1] - v[0];
        
        while(l < r){
            
            mid = l + (r-l)/2;
            count = 0;
            for(i = 0; i < n;){
                j = i;
                while(j < n && v[j] - v[i] <= mid) j++;
                i = j;
                count++;
            }
            
            if(count < m) r = mid;
            else l = mid+1;
            
        }
        
        return l;
    }
};