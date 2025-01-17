
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

/**
 * @class BST
 * @brief A binary search tree implementation.
 *
 * This class represents a binary search tree data structure. It supports
 * operations such as insertion, deletion, and searching of elements in the tree.
 */
template <typename DataType>
class BST
{
private:
    /***** Node structure *****/
    class BinNode
    {
    public:
        DataType data;
        BinNode* left;
        BinNode* right;

        // BinNode constructors
        // Default -- data part undefined; both links null
        BinNode()
            : left(nullptr), right(nullptr)
        {}

        // Explicit Value -- data part contains item; both links null
        BinNode(DataType item)
            : data(item), left(nullptr), right(nullptr)
        {}
    };

    typedef BinNode* BinNodePointer;

public:
    /**
     * @brief Default constructor for the BST class.
     */
    BST();

    /**
     * @brief Default destructor for the BST class.
     */
    ~BST();

    /**
     * @brief Clears the binary search tree.
     */
    void clear();

    /**
     * @brief Checks if the binary search tree is empty.
     *
     * @return true if the binary search tree is empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Searches for a given item in the binary search tree.
     *
     * @param item The item to search for.
     * @return true if the item is found, false otherwise.
     */
    bool search(const DataType& item) const;

    /**
     * Inserts a new item into the binary search tree.
     *
     * @param item The item to be inserted.
     * @throws std::runtime_error if item already in the tree.
     */
    void insert(const DataType& item);

    /**
     * @brief Removes the specified item from the binary search tree.
     *
     * @param item The item to be removed.
     * @throws std::runtime_error if item not in the tree.
     */
    void remove(const DataType& item);

    /**
     * Performs an inorder traversal of the binary search tree and outputs the elements to the specified output stream.
     *
     * @param out The output stream to which the elements will be written.
     * @param separator String to separate elements (optional).
     */
    void inorder(std::ostream& out, std::string separator = "  ");

    /**
     * Performs an preorder traversal of the binary search tree and outputs the elements to the specified output stream.
     *
     * @param out The output stream to which the elements will be written.
     * @param separator String to separate elements (optional).
     */
    void preorder(std::ostream& out, std::string separator = "  ");

    /**
     * Performs an postorder traversal of the binary search tree and outputs the elements to the specified output stream.
     *
     * @param out The output stream to which the elements will be written.
     * @param separator String to separate elements (optional).
     */
    void postorder(std::ostream& out, std::string separator = "  ");

    /**
     * @brief Prints the graphical representation of the binary search tree.
     *
     * @param out The output stream to print the graph to.
     */
    void graph(std::ostream& out);

private:
    /**
     * Searches for a specific item in the binary search tree.
     *
     * @param item The item to search for.
     * @param found A reference to a boolean variable that will be set to true if the item is found, false otherwise.
     * @param locptr A reference to a pointer that will be set to the location of the found item, or nullptr if the item is not found.
     * @param parent A reference to a pointer that will be set to the parent of the found item, or nullptr if the item is not found or if the found item is the root of the tree.
     */
    void search2(const DataType& item, bool& found,
        BinNodePointer& locptr, BinNodePointer& parent);

    /**
     * @brief Recursively clears the binary search tree.
     */
    void clearAux(BinNodePointer subtreePtr);

    /**
     * Performs an inorder traversal of the binary search tree rooted at subtreePtr
     * and outputs the elements to the specified output stream.
     *
     * @param out The output stream to write the elements to.
     * @param subtreePtr A pointer to the root of the subtree to traverse.
     */
    void inorderAux(std::ostream& out,
        BinNodePointer subtreePtr,
        std::string separator = "  ");

    /**
     * Performs an preorder traversal of the binary search tree rooted at subtreePtr
     * and outputs the elements to the specified output stream.
     *
     * @param out The output stream to write the elements to.
     * @param subtreePtr A pointer to the root of the subtree to traverse.
     */
    void preorderAux(std::ostream& out,
        BinNodePointer subtreePtr,
        std::string separator = "  ");

    /**
     * Performs an postorder traversal of the binary search tree rooted at subtreePtr
     * and outputs the elements to the specified output stream.
     *
     * @param out The output stream to write the elements to.
     * @param subtreePtr A pointer to the root of the subtree to traverse.
     */
    void postorderAux(std::ostream& out,
        BinNodePointer subtreePtr,
        std::string separator = "  ");

    /**
     * Recursively prints the binary search tree in a graphical format.
     *
     * @param out The output stream to print the tree.
     * @param indent The number of spaces to indent each level of the tree.
     * @param subtreeRoot The root of the subtree to print.
     */
    void graphAux(std::ostream& out, int indent, BinNodePointer subtreeRoot);

    /***** Data Members *****/
    BinNodePointer myRoot;

}; // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline BST<DataType>::BST()
    : myRoot(nullptr)
{}

//--- Definition of destructor
template <typename DataType>
BST<DataType>::~BST()
{
    clear();
}

//--- Definition of clear()
template <typename DataType>
void BST<DataType>::clear()
{
    clearAux(myRoot);
    myRoot = nullptr;
}

//--- Definition of clearAux()
template <typename DataType>
void BST<DataType>::clearAux(BinNodePointer subtreePtr)
{
    if (subtreePtr != nullptr)
    {
        clearAux(subtreePtr->left);
        clearAux(subtreePtr->right);
        delete subtreePtr;
    }
}

//--- Definition of empty()
template <typename DataType>
inline bool BST<DataType>::empty() const
{
    return myRoot == nullptr;
}

//--- Definition of search()
template <typename DataType>
bool BST<DataType>::search(const DataType& item) const
{
    bool found = false;
    // add code here
    BST<DataType>::BinNodePointer locptr = myRoot;

    while (!found && locptr != nullptr)
        if (item < locptr->data) {
            locptr = locptr->left;
        }
        else if (item > locptr->data) {
            locptr = locptr->right;
        }
        else {
            found = true;
        }

    // return appropriate value
    return found;
}

//--- Definition of insert()
template <class DataType>
inline void BST<DataType>::insert(const DataType& item)
{
    BST<DataType>::BinNodePointer
        locptr = myRoot,   // search pointer
        parent = nullptr;  // pointer to parent of current node

    // Find insertion point
    while (locptr != nullptr)
    {
        parent = locptr;
        if (item < locptr->data)       // descend left
            locptr = locptr->left;
        else                           // descend right (handles duplicates)
            locptr = locptr->right;
    }

    // Insert new node
    locptr = new BST<DataType>::BinNode(item);
    if (parent == nullptr)        // empty tree
        myRoot = locptr;
    else if (item < parent->data)  // insert to left of parent
        parent->left = locptr;
    else                           // insert to right of parent
        parent->right = locptr;
}
//--- Definition of remove()
template <class DataType>
void BST<DataType>::remove(const DataType& item)
{
    bool found;                      // signals if item is found
    BST<DataType>::BinNodePointer
        x,                            // points to node containing
        parent;                       //    "    " parent of x and xSucc
    search2(item, found, x, parent);

    if (!found)
    {
        throw std::runtime_error("Item not in the BST");
        return;
    }
    //else
    if (x->left != nullptr && x->right != nullptr)
    {                                // node has 2 children
        // Find x's inorder successor and its parent
        BST<DataType>::BinNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != nullptr)       // descend left
        {
            parent = xSucc;
            xSucc = xSucc->left;
        }

        // Move contents of xSucc to x and change x
        // to point to successor, which will be removed.
        x->data = xSucc->data;
        x = xSucc;
    } // end if node has 2 children

    // Now proceed with case where node has 0 or 1 child
    BST<DataType>::BinNodePointer
        subtree = x->left;             // pointer to a subtree of x
    if (subtree == nullptr)
        subtree = x->right;
    if (parent == nullptr)            // root being removed
        myRoot = subtree;
    else if (parent->left == x)       // left child of parent
        parent->left = subtree;
    else                              // right child of parent
        parent->right = subtree;
    delete x;
}

//--- Definition of inorder()
template <class DataType>
inline void BST<DataType>::inorder(std::ostream& out, std::string separator)
{
    inorderAux(out, myRoot, separator);
}

template <class DataType>
inline void BST<DataType>::preorder(std::ostream& out, std::string separator)
{
    preorderAux(out, myRoot, separator);
}

template <class DataType>
inline void BST<DataType>::postorder(std::ostream& out, std::string separator)
{
    postorderAux(out, myRoot, separator);

}

//--- Definition of graph()
template <class DataType>
inline void BST<DataType>::graph(std::ostream& out)
{
    graphAux(out, 0, myRoot);
}

//--- Definition of search2()
template <class DataType>
void BST<DataType>::search2(const DataType& item, bool& found,
    BST<DataType>::BinNodePointer& locptr,
    BST<DataType>::BinNodePointer& parent)
{
    // Add code here
    locptr = myRoot;  // Start at the root
    parent = nullptr; // Initialize parent as nullptr
    found = false;
    while (!found && locptr != nullptr) {

        if (item < locptr->data) {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (item > locptr->data) {
            parent = locptr;
            locptr = locptr->right;
        }
        else {
            found = true;
        }
    }
    // This should work exactly the same as search, 
    // but the locptr, found, and parent pointers will 
    // be passed by reference
    // and therefore returned to the calling function. 
    // see (remove)
}

template <class DataType>
void BST<DataType>::inorderAux(std::ostream& out,
    BST<DataType>::BinNodePointer subtreeRoot,
    std::string separator)
{
    if (subtreeRoot != nullptr)
    {
        inorderAux(out, subtreeRoot->left, separator);    // L operation
        out << subtreeRoot->data << separator;      // V operation
        inorderAux(out, subtreeRoot->right, separator);   // R operation
    }
}

template <class DataType>
void BST<DataType>::preorderAux(std::ostream& out,
    BST<DataType>::BinNodePointer subtreeRoot,
    std::string separator)
{
    if (subtreeRoot != nullptr)
    {
        out << subtreeRoot->data << separator;      // V operation
        preorderAux(out, subtreeRoot->left, separator);    // L operation
        preorderAux(out, subtreeRoot->right, separator);   // R operation
    }
}

template <class DataType>
void BST<DataType>::postorderAux(std::ostream& out,
    BST<DataType>::BinNodePointer subtreeRoot,
    std::string separator)
{
    if (subtreeRoot != nullptr)
    {
        postorderAux(out, subtreeRoot->left, separator);    // L operation
        postorderAux(out, subtreeRoot->right, separator);   // R operation
        out << subtreeRoot->data << separator;      // V operation
    }
}



//--- Definition of graphAux()
#include <iomanip>

template <class DataType>
void BST<DataType>::graphAux(std::ostream& out, int indent,
    BST<DataType>::BinNodePointer subtreeRoot)
{
    if (subtreeRoot != nullptr)
    {
        graphAux(out, indent + 8, subtreeRoot->right);
        out << std::setw(indent) << " " << subtreeRoot->data << std::endl;
        graphAux(out, indent + 8, subtreeRoot->left);
    }
    else
        out << std::setw(indent) << " " << "_" << std::endl;
}