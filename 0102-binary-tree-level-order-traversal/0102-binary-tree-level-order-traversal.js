/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(!root)
        return [];
    const q = [];
    q.push(root);
    const ans = [];
    while(q.length > 0){
        let n = q.length;
        let temp = [];
        for(let i=1; i<=n; i++){
            let currNode = q.shift();
            temp.push(currNode.val);
            if(currNode.left)
                q.push(currNode.left);
            if(currNode.right)
                q.push(currNode.right);
        }
        ans.push(temp);
    }
    return ans;
};
