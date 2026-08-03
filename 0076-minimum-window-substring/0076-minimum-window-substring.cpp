class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

    vector<int> need(128, 0);
    for (unsigned char c : t) need[c]++;

    int missing = t.size();
    int low = 0, bestLen = INT_MAX, bestStart = 0;

    for (int high = 0; high < (int)s.size(); high++) {
        if (need[(unsigned char)s[high]]-- > 0) missing--;

        while (missing == 0) {
            if (high - low + 1 < bestLen) {
                bestLen = high - low + 1;
                bestStart = low;
            }
            if (++need[(unsigned char)s[low]] > 0) missing++;
            low++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
        
    }
};