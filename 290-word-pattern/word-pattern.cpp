class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];

            if (mp.count(ch) && mp[ch] != words[i])
                return false;

            if (rev.count(words[i]) && rev[words[i]] != ch)
                return false;

            mp[ch] = words[i];
            rev[words[i]] = ch;
        }

        return true;
    }
};