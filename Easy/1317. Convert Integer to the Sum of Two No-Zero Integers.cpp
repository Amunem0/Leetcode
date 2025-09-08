class Solution {
public:
    bool findNum(int num) {

        while (num > 0) {
            int rem = num % 10;
            num = num / 10;
            if (rem == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = n - 1; i >= 1; i--) {
            if (findNum(i) && findNum(n - i)) {
                return {i,n-i};
            }
        }
        return {};
    }
};
