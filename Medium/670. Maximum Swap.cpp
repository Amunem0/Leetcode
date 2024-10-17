class Solution {
public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        int n = numString.size();
        vector<int> maxAtIndex(n);

        maxAtIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int rightMaxInd = maxAtIndex[i + 1];
            int rightMaxElem = numString[rightMaxInd];

            maxAtIndex[i] = numString[i] > rightMaxElem ? i : maxAtIndex[i + 1];
        }

        for (int i = 0; i < n; i++) {
            int maxAtRightIndex = maxAtIndex[i];
            int maxAtRightIndexElem = numString[maxAtRightIndex];

            if (numString[i] < maxAtRightIndexElem) {
                swap(numString[i], numString[maxAtRightIndex]);
                return stoi(numString);
            }
        }
        return num;
    }
};
