class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // If character is a digit
            if (isdigit(c)) {
                digit = true;

                // If exponent has appeared,
                // this digit is after exponent
                if (exp) {
                    digitAfterExp = true;
                }
            }

            // If character is + or -
            else if (c == '+' || c == '-') {
                // Sign is allowed only at the beginning
                // or immediately after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }

            // If character is '.'
            else if (c == '.') {
                // Dot cannot appear twice
                // and cannot appear after e/E
                if (dot || exp) {
                    return false;
                }

                dot = true;
            }

            // If character is e or E
            else if (c == 'e' || c == 'E') {
                // e/E cannot appear twice
                // and there must be a digit before it
                if (exp || !digit) {
                    return false;
                }

                exp = true;
                digitAfterExp = false;
            }

            // Any other character is invalid
            else {
                return false;
            }
        }

        // There must be a digit,
        // and if exponent exists, it must have digits after it
        return digit && digitAfterExp;
    }
};