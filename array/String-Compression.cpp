class Solution {
public:
    // This is also known as Run-Length Encoding
    int compress(vector<char>& chars) {
        int idx = 0;  
        int i = 0;    
        while (i < chars.size()) {
            char c = chars[i];
            int cnt = 0;
            while (i < chars.size() && chars[i] == c) {
                i++;
                cnt++;
            }
            chars[idx++] = c;
            if (cnt > 1) {
                for (char c : to_string(cnt)) {
                    chars[idx++] = c;
                }
            }
        }

        return idx;
    }
};
