class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> a;
        vector <int> b;
        vector <int> res(nums.size()); 
        int i=0, j=0, idx=0;
        
        for(i=0; i<nums.size(); i++){ 
            if(nums[i]>=0){
                b.push_back(nums[i]);
            }
            else{
                a.push_back(nums[i]);
            }
        }
        
        if(a.size() == 0){
            for(i=0; i<b.size(); i++){ 
                nums[i] = nums[i]*nums[i];
            }
            return nums; 
        }  
        
        if(b.size() == 0){
            for(i=0; i<a.size(); i++){ 
                nums[a.size() - 1 - i] = a[i]*a[i]; 
            }
            return nums; 
        }
        
        i = a.size() - 1; 
        j = 0;
        
        while(i>=0 && j<b.size()){ 
            if(a[i]*a[i] <= b[j]*b[j]){ 
                res[idx] = a[i]*a[i];
                idx++;
                i--; 
            }
            else{
                res[idx] = b[j]*b[j];
                idx++;
                j++;
            }
        }
        
        while(j<b.size()){
            res[idx] = b[j]*b[j]; 
            idx++;
            j++;
        }
        
        while(i>=0){ 
            res[idx] = a[i]*a[i]; 
            idx++;
            i--; 
        }
        
        return res;
    }
};