class Solution {
public:
    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2,
                                long long midProduct) {
        long long productCount = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) {
                int left = 0;
                int right = n - 1;
                int m=-1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long long prod = 1LL* nums1[i] * nums2[mid];

                    if (prod <= midProduct) {
                        m = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                productCount += m + 1;
            } else {
                //-ve products
                int left = 0;
                int right = n - 1;
                int m=n;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    long long prod = 1LL* nums1[i] * nums2[mid];

                    if (prod <= midProduct) {
                        m = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                productCount += n-m;
                
            }
        }
        return productCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long ans = 0;
        long long left = -1e10; // min Product possible
        long long right = 1e10; // max Product possible

        while (left <= right) {
            long long midProd = left + (right - left) / 2;
            long long countSmallest = findCountSmallest(nums1, nums2, midProd);

            if (countSmallest >= k) {
                ans = midProd;
                right = midProd - 1;
            } else {
                left = midProd + 1;
            }
        }
        return ans;
    }
};
