class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        for (auto i : text)
            mp[i]++;
        int cnt = 0;
        while (mp['b'] and mp['a'] and mp['l'] and mp['o'] and mp['n']) {
            if(mp['l']<2 or mp['o']<2) return cnt;
            cnt++;
            mp['b']--, mp['a']--, mp['l'] -= 2, mp['o']-=2, mp['n']--;
        }
        return cnt;
    }
};