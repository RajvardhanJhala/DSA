class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      int n = s.size(); int m = p.size();
      vector<int> res;
      if(n<m) return res;
      vector<int> need(26,0), window(26,0);
      for(unsigned char c:p) need[c - 'a']++;
      for(int i=0;i<n;i++){
        window[s[i]-'a']++;
        if(i>=m){
            window[s[i-m]-'a']--;
        }
        if(i>=m-1 && window == need){
            res.push_back(i-m+1);
        }
      }
      return res;
    }
};