#include <iostream>
using namespace std;

// Node structure for the AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of the tree
int height(Node* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of the node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotate function
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root
}

// Left rotate function
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root
}

// Function to insert a key in the AVL tree
Node* insert(Node* node, int key) {
    // Perform the normal BST insert
    if (!node) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else { // Duplicates are not allowed in the AVL Tree
        return node;
    }

    // Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // If the node becomes unbalanced, there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // return the (unchanged) node pointer
}

// Function to find the node with the minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

// Function to delete a key from the AVL tree
Node* deleteNode(Node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (!root) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else { // If key is same as root's key
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, return
    if (!root) {
        return root;
    }

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for a key in the AVL tree
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false; // Key not found
    }
    if (key == root->key) {
        return true; // Key found
    } else if (key < root->key) {
        return search(root->left, key); // Search in the left subtree
    } else {
        return search(root->right, key); // Search in the right subtree
    }
}

// Function to perform inorder traversal of the tree
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}