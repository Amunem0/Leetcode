class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(auto& elem:mp){
            int key=2*elem.first;
            if( key != 0 && mp.find(key)!=mp.end()){
                return true;
            }
            if (key == 0 && elem.second > 1) {
                return true;
            }
        }
        return false;
    }
};
