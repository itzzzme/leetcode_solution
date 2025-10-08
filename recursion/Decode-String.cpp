class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> st1;
        string str = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                st.push(num);
                st1.push(str);
                num = 0;
                str = "";
            } else if (c == ']') {
                string temp = str;
                str = st1.top();
                st1.pop();
                int repeatCount = st.top();
                st.pop();
                while (repeatCount--) {
                    str += temp;
                }
            } else {
                str += c;
            }
        }
        return str;
    }
};
