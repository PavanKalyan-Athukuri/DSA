class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Boolean array for broken letters
        vector<int> brokenArray(26, 0);
        for (char c : brokenLetters) {
            brokenArray[c - 'a'] = 1;
        }

        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {  // extract words
            bool canType = true;
            for (char c : word) {
                if (brokenArray[c - 'a']) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }

        return count;
    }
};