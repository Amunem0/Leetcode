class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>ans;
        int i=0;
        int count=0;
        while(i<n){
            freq[A[i]]++;
            freq[B[i]]++;
            if(freq[A[i]]==2){
                count++;
            }
            if(freq[B[i]]==2 && B[i]!=A[i]){
                count++;
            }
            ans.push_back(count);
            i++;
        }
        return ans;
    }
};
