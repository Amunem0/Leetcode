class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();

        vector<vector<char>>rotatedArray(n,vector<char>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotatedArray[i][j]=box[j][i];
            }
        }
        for(auto &row:rotatedArray){
            reverse(row.begin(),row.end());
        }

        for(int col=0;col<m;col++){
            for(int row=n-1;row>=0;row--){
                if(rotatedArray[row][col]=='.'){
                    int stoneRow=-1;

                    for(int k=row-1;k>=0;k--){
                        if(rotatedArray[k][col]=='*'){
                            break;
                        }   
                        if(rotatedArray[k][col]=='#'){
                            stoneRow=k;
                            break;
                        }
                    }
                    if(stoneRow!=-1){
                        rotatedArray[row][col]='#';
                        rotatedArray[stoneRow][col]='.';
                    }
                }
            }
        }
        return rotatedArray;
    }
};
