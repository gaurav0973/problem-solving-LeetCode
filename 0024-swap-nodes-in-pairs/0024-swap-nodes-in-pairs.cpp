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
    ListNode* reverse(ListNode* head, int times) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (times--) {
            ListNode* currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        int k = 2;
        if (head == nullptr) return head;

        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        ListNode* ans = nullptr;

        while (left) {
            ListNode* right = left;

            // check if k nodes exist
            for (int i = 1; i < k; i++) {
                if (right == nullptr) break;
                right = right->next;
            }

            if (right == nullptr) {
                if (prevLeft) prevLeft->next = left;
                break;
            }

            ListNode* nextLeft = right->next;

            // reverse k nodes
            ListNode* newHead = reverse(left, k);

            if (ans == nullptr)
                ans = newHead;

            if (prevLeft)
                prevLeft->next = newHead;

            // left becomes tail after reverse
            // left->next = nextLeft;

            prevLeft = left;
            left = nextLeft;
        }

        return ans ? ans : head;
    }
};