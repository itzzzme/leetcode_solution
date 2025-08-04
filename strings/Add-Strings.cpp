class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result = "";
        int carry = 0;
        int i = 0;
        while (i < num1.size() || i < num2.size() || carry) {
            int digit1 = (i < num1.size()) ? num1[i] - '0' : 0;
            int digit2 = (i < num2.size()) ? num2[i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result += (sum % 10 + '0');
            carry = sum / 10;
            i++;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
