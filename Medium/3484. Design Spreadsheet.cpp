class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet=vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        char alpha=cell[0];
        string numeric=cell.substr(1);

        int alphaToNum=tolower(alpha)-'a';
        int numericToNum=stoi(numeric);

        sheet[numericToNum-1][alphaToNum]=value;
    }
    
    void resetCell(string cell) {
        char alpha=cell[0];
        string numeric=cell.substr(1);

        int alphaToNum=tolower(alpha)-'a';
        int numericToNum=stoi(numeric);
        sheet[numericToNum-1][alphaToNum]=0;
    }
    
    int getValue(string formula) {
        string removeEqual=formula.substr(1);

        int plusInd=removeEqual.find('+');
        string leftStr=removeEqual.substr(0,plusInd);
        string rightStr=removeEqual.substr(plusInd+1);

        int leftDigit=0,rightDigit=0;
        if(!isdigit(leftStr[0])){
           char alpha=leftStr[0];
            string numeric=leftStr.substr(1);

            int alphaToNum=tolower(alpha)-'a';
            int numericToNum=stoi(numeric); 
            leftDigit=sheet[numericToNum-1][alphaToNum];
        }

        if(!isdigit(rightStr[0])){
           char alpha=rightStr[0];
           string numeric=rightStr.substr(1);

            int alphaToNum=tolower(alpha)-'a';
            int numericToNum=stoi(numeric); 
            rightDigit=sheet[numericToNum-1][alphaToNum];
        }
        if(isdigit(leftStr[0])){
            leftDigit=stoi(leftStr);
        }
        if(isdigit(rightStr[0])){
            rightDigit=stoi(rightStr);
        }
        return leftDigit+rightDigit;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
