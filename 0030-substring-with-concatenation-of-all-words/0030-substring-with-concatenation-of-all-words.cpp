class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(); int m = words.size();
        int L = words[0].size();
        int window_width = L * m;
        vector<int> res;
        if (n < window_width) return res;

        unordered_map<string,int> need;
        for (string& w : words) need[w]++;

        for (int offset = 0; offset < L; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string,int> window;

            for (int right = offset; right + L <= n; right += L) {
                string word = s.substr(right, L);

                if (need.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, L);
                        window[leftWord]--;
                        left += L;
                        count--;
                    }
                    if (count == m) {
                        res.push_back(left);
                        string leftWord = s.substr(left, L);
                        window[leftWord]--;
                        left += L;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + L;
                }
            }
        }
        return res;
    }
};