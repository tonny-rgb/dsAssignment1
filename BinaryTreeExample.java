// Binary Tree Node Representation
package practice;

class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    public void insert(int key) {
        root = insertRecursive(root, key);
    }

    private Node insertRecursive(Node root, int key) {
        if (root == null) {
            return new Node(key);
        }
        if (key < root.key) {
            root.left = insertRecursive(root.left, key);
        } else {
            root.right = insertRecursive(root.right, key);
        }
        return root;
    }

    public boolean search(int key) {
        return searchRecursive(root, key);
    }

    private boolean searchRecursive(Node root, int key) {
        if (root == null) {
            return false;
        }
        if (root.key == key) {
            return true;
        }
        return key < root.key ? searchRecursive(root.left, key) : searchRecursive(root.right, key);
    }

    public void inorder() {
        inorderRecursive(root);
        System.out.println();
    }

    private void inorderRecursive(Node root) {
        if (root != null) {
            inorderRecursive(root.left);
            System.out.print(root.key + " ");
            inorderRecursive(root.right);
        }
    }

    public void preorder() {
        preorderRecursive(root);
        System.out.println();
    }

    private void preorderRecursive(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorderRecursive(root.left);
            preorderRecursive(root.right);
        }
    }

    public void postorder() {
        postorderRecursive(root);
        System.out.println();
    }

    private void postorderRecursive(Node root) {
        if (root != null) {
            postorderRecursive(root.left);
            postorderRecursive(root.right);
            System.out.print(root.key + " ");
        }
    }

    public void delete(int key) {
        root = deleteRecursive(root, key);
    }

    private Node deleteRecursive(Node root, int key) {
        if (root == null) {
            return root;
        }
        if (key < root.key) {
            root.left = deleteRecursive(root.left, key);
        } else if (key > root.key) {
            root.right = deleteRecursive(root.right, key);
        } else {

            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            root.key = minValue(root.right);
            root.right = deleteRecursive(root.right, root.key);
        }
        return root;
    }

    private int minValue(Node root) {
        int minValue = root.key;
        while (root.left != null) {
            root = root.left;
            minValue = root.key;
        }
        return minValue;
    }
}

public class BinaryTreeExample {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
     
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        System.out.println("Inorder Traversal:");
        tree.inorder(); 

        System.out.println("Preorder Traversal:");
        tree.preorder();

        System.out.println("Postorder Traversal:");
        tree.postorder();

        // Search for a key
        System.out.println("Searching for 40: " + (tree.search(40) ? "Found" : "Not Found"));

        // Delete a node
        System.out.println("\nDeleting 50");
        tree.delete(50);

        System.out.println("Inorder Traversal After Deletion:");
        tree.inorder(); 
    }
}

