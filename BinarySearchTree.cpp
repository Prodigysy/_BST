#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <algorithm>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) {
    root = nullptr;
    if (other.root)
        root = new Node(other.root->key);
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

BinarySearchTree::Node* BinarySearchTree::copy(const Node* node) {
    if (!node)
        return nullptr;
    Node* newNode = new Node(node->key);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other) {
    if (this != &other) {
        deleteTree(root);
        root = copy(other.root);
    }
    return *this;
}

void BinarySearchTree::deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void BinarySearchTree::print() {
    printRecursive(root);
    std::cout << std::endl;
}

bool BinarySearchTree::insert(int key) {
    if (root == nullptr) {
        root = new Node(key);
        return true;
    }
    else {
        return insertRecursive(root, key);
    }
}

bool BinarySearchTree::contains(int key) {
    return containsRecursive(root, key);
}

bool BinarySearchTree::erase(int key) {
    return eraseRecursive(root, key);
}

bool BinarySearchTree::insertRecursive(Node*& node, int data) {
    if (node == nullptr) {
        node = new Node(data);
        return true;
    }
    if (data < node->key) {
        return insertRecursive(node->left, data);
    }
    else if (data > node->key)
    {

        return insertRecursive(node->right, data);
    }
}

bool BinarySearchTree::containsRecursive(Node* root, int key) {
    if (!root)
        return false;

    if (key == root->key)
        return true;

    if (key < root->key)
        return containsRecursive(root->left, key);
    else
        return containsRecursive(root->right, key);
}

bool BinarySearchTree::eraseRecursive(Node*& node, int data) {
    if (node == nullptr) {
        return false;
    }
    else if (data < node->key) {
        return eraseRecursive(node->left, data);
    }
    else if (data > node->key) {
        return eraseRecursive(node->right, data);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* minRight = findMinElement(node->right);
            node->key = minRight->key;
            eraseRecursive(node->right, minRight->key);
        }
        return true;
    }
}

BinarySearchTree::Node* BinarySearchTree::findMinElement(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BinarySearchTree::printRecursive(Node* root) {
    if (root) {
        printRecursive(root->left);
        std::cout << root->key << " ";
        printRecursive(root->right);
    }
}
