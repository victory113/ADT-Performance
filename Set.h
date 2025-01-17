#include <iostream>

template <typename T>
class Set {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function to insert a new element in the tree
    Node* insert(Node* node, const T& value) {
        if (node == nullptr) return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        // If value already exists, do nothing (since Set doesn't allow duplicates)
        return node;
    }

    // Helper function to search for an element in the tree
    bool contains(Node* node, const T& value) const {
        if (node == nullptr) return false;
        if (value == node->data) return true;
        if (value < node->data) return contains(node->left, value);
        return contains(node->right, value);
    }

    // Helper function to find the minimum node in a subtree
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete an element from the tree
    Node* remove(Node* node, const T& value) {
        if (node == nullptr) return node;
        
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the in-order successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Helper function to print elements (in-order traversal)
    void inorderPrint(Node* node) const {
        if (node == nullptr) return;
        inorderPrint(node->left);
        std::cout << node->data << " ";
        inorderPrint(node->right);
    }

    // Helper function to deallocate nodes in destructor
    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    // Constructor
    Set() : root(nullptr) {}

    // Destructor
    ~Set() {
        clear(root);
    }

    // Public interface to insert an element
    void insert(const T& value) {
        root = insert(root, value);
    }

    // Public interface to check if an element exists
    bool contains(const T& value) const {
        return contains(root, value);
    }

    // Public interface to remove an element
    void remove(const T& value) {
        root = remove(root, value);
    }

    // Public interface to print all elements
    void print() const {
        inorderPrint(root);
        std::cout << std::endl;
    }
};