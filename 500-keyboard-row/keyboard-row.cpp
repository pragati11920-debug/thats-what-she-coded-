class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> ans;

        for (string word : words) {
            int row = -1;
            bool valid = true;

            for (char c : word) {
                c = tolower(c);
                int currentRow = -1;

                for (int i = 0; i < 3; i++) {
                    if (rows[i].find(c) != string::npos) {
                        currentRow = i;
                        break;
                    }
                }

                if (row == -1)
                    row = currentRow;
                else if (row != currentRow) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};