/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string binary = "";
        while (temp != NULL) {
            binary += to_string(temp->val);
            temp = temp->next;
        }
        int power = 0;
        int ans = 0;

        for (int i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                ans += pow(2, power);
            }
            power++;
        }
        return ans;
    }
};
