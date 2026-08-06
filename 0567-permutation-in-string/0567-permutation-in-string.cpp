class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n = s1.size(); int m = s2.size();
       if (n>m) return false;
       vector<int> need(26,0),window(26,0);
       for(unsigned char c:s1) need[c - 'a']++;
       for(int i=0;i<m;i++){
        window[s2[i]-'a']++;
        if(i>=n){
            window[s2[i-n]-'a']--;
        }
        if(i >= n-1 && window == need){
            return true;
        }
        
       }
       return false;




    }
};