#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRecursive(root->left, key);
        } else {
            root->right = insertRecursive(root->right, key);
        }
        return root;
    }

    bool search(int key) {
        return searchRecursive(root, key);
    }

    bool searchRecursive(Node* root, int key) {
        if (root == nullptr) {
            return false;
        }
        if (root->key == key) {
            return true;
        }
        return key < root->key ? searchRecursive(root->left, key) : searchRecursive(root->right, key);
    }

    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }

    void inorderRecursive(Node* root) {
        if (root != nullptr) {
            inorderRecursive(root->left);
            cout << root->key << " ";
            inorderRecursive(root->right);
        }
    }

    void preorder() {
        preorderRecursive(root);
        cout << endl;
    }

    void preorderRecursive(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }

    void postorder() {
        postorderRecursive(root);
        cout << endl;
    }

    void postorderRecursive(Node* root) {
        if (root != nullptr) {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
            cout << root->key << " ";
        }
    }

    void deleteNode(int key) {
        root = deleteRecursive(root, key);
    }

    Node* deleteRecursive(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRecursive(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            root->key = minValue(root->right);
            root->right = deleteRecursive(root->right, root->key);
        }
        return root;
    }

    int minValue(Node* root) {
        int minValue = root->key;
        while (root->left != nullptr) {
            root = root->left;
            minValue = root->key;
        }
        return minValue;
    }
};


int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder(); 

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    cout << "Searching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 50" << endl;
    tree.deleteNode(50);

    cout << "Inorder Traversal After Deletion: ";
    tree.inorder(); 

    return 0;
}
