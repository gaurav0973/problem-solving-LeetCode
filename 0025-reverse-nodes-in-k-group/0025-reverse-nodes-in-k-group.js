/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */


var reverse = function(head, k) {
        // code here
        let prev = null;
        let curr = head;
        while(k--){
            let currNext = curr.next;
            curr.next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
};
var reverseKGroup = function(head, k) {

    if(head == null)
        return head;
    let prevLeft = null;
    let left = head;
    let ans = null;
    while(left){
        let right = left;
        for(let i=1; i<k; i++){
            if(!right.next){
                if(prevLeft)
                    prevLeft.next = left;
                return ans ? ans : head;
            }
            right = right.next;
        }

        let nextLeft = right.next;
        let newGrpHead = reverse(left, k);
        if(ans == null)
            ans = newGrpHead;
        if(prevLeft)
            prevLeft.next = newGrpHead;
        prevLeft = left;
        left = nextLeft;
    }

    return ans;
};
