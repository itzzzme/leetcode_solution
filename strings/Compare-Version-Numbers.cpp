class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        stringstream ss1(version1), ss2(version2);
        string temp;

        while (getline(ss1, temp, '.')) {
            v1.push_back(stoi(temp)); 
        }

        while (getline(ss2, temp, '.')) {
            v2.push_back(stoi(temp)); 
        }

        int len1 = v1.size(), len2 = v2.size();
        int maxLen = max(len1, len2);

        for (int i = 0; i < maxLen; ++i) {
            int val1 = i < len1 ? v1[i] : 0;
            int val2 = i < len2 ? v2[i] : 0;

            if (val1 < val2) return -1;
            if (val1 > val2) return 1;
        }

        return 0;
    }
};
