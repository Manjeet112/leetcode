class Solution {
public:
    char processStr(string s, long long k) {
        long long m = 0;

        // Compute final length
        for (char c : s) {
            if (c == '*') {
                if (m > 0) m--;
            }
            else if (c == '#') {
                m *= 2;
            }
            else if (c == '%') {
                // length unchanged
            }
            else {
                m++;
            }
        }
        if (k >= m) return '.';

        // Work backwards
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == m - 1) return c;
                m--;
            }
            else if (c == '*') {
                m++;
            }
            else if (c == '#') {
                m /= 2;
                k %= m;
            }
             else { // '%'
                k = m - 1 - k;
            }
        }

        return '.';
    }
};