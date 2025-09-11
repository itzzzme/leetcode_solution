class Solution {
public:
    string sortVowels(string s) {
        string temp = "";
        for (auto i : s) {
            if (i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U' or
                i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u') {
                temp += i;
            }
        }
        sort(temp.begin(),temp.end());
        int j=0;
        for(int i=0;i<s.size() and j<temp.size();i++){
            if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or
                s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
                    s[i]=temp[j];
                    j++;
                }
        }
        return s;
    }
};