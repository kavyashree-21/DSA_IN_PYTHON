
import java.util.*;

class Solution {
    private int postIndex;
    private Map<Integer, Integer> map;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIndex = postorder.length - 1;
        map = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }

        return construct(inorder, postorder, 0, inorder.length - 1);
    }

    private TreeNode construct(int[] inorder, int[] postorder,
                               int left, int right) {
        if (left > right) {
            return null;
        }

        int value = postorder[postIndex--];
        TreeNode root = new TreeNode(value);

        int mid = map.get(value);

        root.right = construct(inorder, postorder, mid + 1, right);
        root.left = construct(inorder, postorder, left, mid - 1);

        return root;
    }
}
