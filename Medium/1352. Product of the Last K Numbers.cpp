class ProductOfNumbers {
public:
    vector<int> prefixProd;
    
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            // Reset on zero
            prefixProd.clear();
        } else {
            if (prefixProd.empty()) {
                prefixProd.push_back(num);
            } else {
                // Multiply with the last element
                prefixProd.push_back(prefixProd.back() * num);
            }
        }
    }

    int getProduct(int k) {
        if (k > prefixProd.size()) {
            // If k is larger than current size, it means a reset happened
            return 0;
        }
        if (k == prefixProd.size()) {
            return prefixProd.back();
        }
        return prefixProd.back() / prefixProd[prefixProd.size() - k - 1];
    }
};
