class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;

        // Traverse the string from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') {
                continue;
            }

            // Convert letters to uppercase
            result += toupper(s[i]);
            count++;

            // Add a dash after every k characters
            if (count == k) {
                result += '-';
                count = 0;
            }
        }

        // Remove the extra dash at the end
        if (!result.empty() && result.back() == '-') {
            result.pop_back();
        }

        // Reverse to restore the original order
        reverse(result.begin(), result.end());

        return result;
    }
};