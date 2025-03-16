class Solution {
public:
    bool canSatisfy(vector<int>&ranks, long long maxTime,int cars ){
        long long sumCars=0;
        for(int i=0;i<ranks.size();i++){
            long long countCars=sqrt(maxTime/ranks[i]);
            sumCars+=countCars;
        }

        return sumCars>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long low=1;
        long long high=*max_element(ranks.begin(),ranks.end());
        high=high*cars*cars;

        long long ans=0;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canSatisfy(ranks,mid,cars)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
