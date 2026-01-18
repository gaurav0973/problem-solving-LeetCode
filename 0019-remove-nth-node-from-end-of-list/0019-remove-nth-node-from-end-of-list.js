/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let fast = head;
    for(let i=1; i<=n; i++){
        fast = fast.next;
        if(fast == null)
            return head.next;
    }

    let slow = head;
    while(fast.next){
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return head;

};