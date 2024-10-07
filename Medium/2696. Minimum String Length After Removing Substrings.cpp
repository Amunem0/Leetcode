
//APPROACH 1
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty()) {
                if (st.top() == 'A' && s[i] == 'B' ||
                    st.top() == 'C' && s[i] == 'D') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};


//APPROACH 2
// class Solution {
// public:
//     int minLength(string s) {
//         stack<char> st;
//         for (int i = 0; i < s.length(); i++) {
//             if (!st.empty()) {
//                 if (st.top() == 'A' && s[i] == 'B' ||
//                     st.top() == 'C' && s[i] == 'D') {
//                     st.pop();
//                 } else {
//                     st.push(s[i]);
//                 }
//             } else {
//                 st.push(s[i]);
//             }
//         }
//         return st.size();
//     }
// };

class Solution {
public:
    int minLength(string s) {
        int i = 0;
        int j = 1;
        int n = s.length();

        while (j < n) {
            if (i < 0) {
                i++;
                s[i] = s[j];
            }
            else if ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D')) {
                i--;
            } else {
                i++;
                s[i] = s[j];
            }
            j++;
        }
        return i + 1;
    }
};
