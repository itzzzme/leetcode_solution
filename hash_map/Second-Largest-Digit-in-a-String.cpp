class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for (auto i : s)
            if (isdigit(i))
                st.insert(i - '0'); 
        if (st.size() <= 1)
            return -1;
        auto it = st.rbegin(); 
        ++it;
        return *it;
    }
};
