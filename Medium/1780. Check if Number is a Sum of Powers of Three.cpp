class Solution {
public:
    bool checkPowersOfThree(int n) {
        int dup = n;
        while (dup > 0) {
            int rem = dup % 3;
            if (rem == 2) {
                return false;
            }
            dup = dup / 3;
        }
        return true;
    }
};
