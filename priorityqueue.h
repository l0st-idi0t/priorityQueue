// priorityqueue.h
#pragma once

#include <iostream>
#include <sstream>
#include <set>
#include <string>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)

    void _recursiveFunction(NODE* node, ostream &output) {
        if (node == nullptr) return;

        _recursiveFunction(node->left, output);
        output << node->priority << " value: " << node->value << endl;
        _recursiveFunction(node->link, output);
        _recursiveFunction(node->right, output);
    }

    void deleteTree(NODE* node) {
        if (node == nullptr) return;

        deleteTree(node->left);
        if (node->link != nullptr) deleteTree(node->link);
        deleteTree(node->right);

        delete node;
        size--;
    }

    void equalHelper(NODE* node) {
        if (node == nullptr) return;

        equalHelper(node->left);
        enqueue(node->value, node->priority);
        equalHelper(node->link);
        equalHelper(node->right);
    }

    bool equalityHelper(NODE* node, NODE* otherNode) {
        if (node != otherNode) return false;

        equalHelper(node->left, otherNode->left);
        equalHelper(node->link, otherNode->link);
        equalHelper(node->right, otherNode->right);

        return true;
    }

public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {
        size = 0;
        root = nullptr;
        curr = nullptr;
    }
    
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other) {
        if (this == &other) {
            return *this;
        }

        clear();

        equalHelper(other.root);

        return *this;
    }
    
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {
        deleteTree(root);
        root = nullptr;
        curr = nullptr;
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        // TO DO: write this function.
        
        
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    void enqueue(T value, int priority) {

        NODE* prev = nullptr;
        NODE* cur = root;
        NODE* n = new NODE;

        while (cur != nullptr) {
            if (priority == cur->priority) {
                cur->dup = true;
                while (cur->link != nullptr) {
                    cur = cur->link;
                }
                cur->link = n;
                prev = nullptr;
                cur = nullptr;
            }else if (priority > cur->priority) {
                prev = cur;
                cur = cur->right;
            }else {
                prev = cur;
                cur = cur->left;
            }
        }

        n->priority = priority;
        n->value = value;
        n->dup = false;
        n->parent = prev;
        n->link = nullptr;
        n->left = nullptr;
        n->right = nullptr;

        if (root == nullptr) {
            root = n;
        }

        if (prev != nullptr) {
            if (priority > prev->priority) {
                prev->right = n;
            }else {
                prev->left = n;
            }
        }

        size++;
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T dequeue() {
        
        // TO DO: write this function.
        T valueOut;
        return valueOut; // TO DO: update this return
        
        
    }
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        return size;
        
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        
        curr = root;

        if(curr != nullptr) {
            while (curr->left != nullptr) {
                curr = curr->left;
            }
        }

    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
        // TO DO: write this function.
        if (curr == nullptr) return false;

        if (curr->link != nullptr) {
          curr = curr->link;
        }else if (curr->right != nullptr) {
            curr = curr->right;
        }else if (curr->parent != nullptr) {
          curr = curr->parent;
        }

        return true; 
        
        
    }
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {        

        stringstream result;
        _recursiveFunction(root, result);
        
        return result.str();

    }

    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T peek() {
        
        // TO DO: write this function.
        T valueOut;
        return valueOut; // TO DO: update this return
        
        
    }
    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {

        if (this == &other) {
            return true;
        }

        return equalityHelper(root, other.root);
        
    }
    
    
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};
