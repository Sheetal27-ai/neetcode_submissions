class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string str : strs) {
            encoded += to_string(str.length());
            encoded += "#";
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.length()) {

            // Read the length
            int len = 0;

            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++; // Skip '#'

            // Read exactly 'len' characters
            string str = s.substr(i, len);

            result.push_back(str);

            i += len;
        }

        return result;
    }
};