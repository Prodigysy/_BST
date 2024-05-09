#pragma once
#include <stack>

class BinarySearchTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(const int k) : key(k), left(nullptr), right(nullptr) {}
    };
    Node* root;
    Node* copy(const Node* node);
    Node* findMinElement(Node* node);
    void deleteTree(Node* root);
    bool insertRecursive(Node*& node, int key);
    bool containsRecursive(Node* root, int key);
    bool eraseRecursive(Node*& node, int data);
    void printRecursive(Node* root);

public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);

    void print();
    bool insert(int key);
    bool contains(int key);
    bool erase(int key);

    class Iterator {
        private:
            std::stack<Node*> stack;
            void pushLeft(Node* node);
        public:
            Iterator(Node* root);
            int operator*();
            Iterator& operator++();
            bool operator!=(const Iterator& other);
    };

    Iterator begin();
    Iterator end();
};
