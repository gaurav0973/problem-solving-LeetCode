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

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr) return head;

        ListNode* left = head;
        ListNode* prevLeft = nullptr;
        ListNode* ans = nullptr;

        while (left) {
            ListNode* right = left;

            // check if k nodes exist
            for (int i = 1; i < k; i++) {
                if (!right->next) {
                    if (prevLeft)
                        prevLeft->next = left;
                    return ans ? ans : head;
                }
                right = right->next;
            }
            ListNode* nextLeft = right->next;

            ListNode* newGrpHead = reverse(left, k);

            if (ans == nullptr)
                ans = newGrpHead;

            if (prevLeft)
                prevLeft->next = newGrpHead;
            prevLeft = left;
            left = nextLeft;
        }

        return ans ? ans : head;
    }
};