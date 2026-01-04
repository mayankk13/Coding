// Input: words = ["abc","car","ada","racecar","cool"]
// Output: "ada"

class Solution {
public:
    bool isPalindrome(string str) {
        if (str.length() == 0 || str.length() == 1) {
            return true;
        }
        int low = 0;
        int high = str.length()-1;

        while (low <= high) {
            if (str[low] != str[high]) {
                return false;
            }
            else {
                low++;
                high--;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (isPalindrome(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};