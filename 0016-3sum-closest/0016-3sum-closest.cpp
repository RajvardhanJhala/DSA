class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int result_sum = 0;
        int n = nums.size();
        int min_diff = INT_MAX; 
        
        for(int i = 0; i < n; i++){
            int left = i + 1;
            int right = n - 1;
            
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                
                if(sum == target){
                    return sum;
                }
                
                int diff = abs(sum - target);
                
                if(min_diff > diff){
                    min_diff = diff;
                    result_sum = sum;
                }
                
                if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return result_sum;
    }
};