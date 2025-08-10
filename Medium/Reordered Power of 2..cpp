class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st;

        for(int i=0;i<=29;i++){
            string power2=to_string(1<<i);
            sort(power2.begin(),power2.end());
            st.insert(power2);
        }

        string strNum=to_string(n);
        sort(strNum.begin(),strNum.end());

        return (st.count(strNum));
    }
};
