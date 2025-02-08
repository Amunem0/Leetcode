class NumberContainers {
public:
    unordered_map<int, int> indToNum; // ind->num   tells which number is present at an ind
    unordered_map<int, set<int>>numToind; // tell the numbers is present in which indices
    NumberContainers() {}

    void change(int index, int number) {

        if (indToNum.count(index)) {
            int prevNum = indToNum[index];
            numToind[prevNum].erase(index);
            if (numToind[prevNum].empty()) {
                numToind.erase(prevNum);
            }
        }

        indToNum[index] = number;
        numToind[number].insert(index);
    }

    int find(int number) {
        if(numToind.count(number)){
            auto ind = *numToind[number].begin();
            return ind;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
