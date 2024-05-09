#include "BinarySearchTree.h"
#include <vector>
#include <iostream>


BinarySearchTree::Iterator::Iterator(Node* root) {
    pushLeft(root);
}

void BinarySearchTree::Iterator::pushLeft(Node* node) {
    while (node != nullptr) {
        stack.push(node);
        node = node->left;
    }
}

int BinarySearchTree::Iterator::operator*() {
    return stack.top()->key;
}

BinarySearchTree::Iterator& BinarySearchTree::Iterator::operator++() {
    Node* node = stack.top()->right;
    stack.pop();
    pushLeft(node);
    return *this;
}

bool BinarySearchTree::Iterator::operator!=(const Iterator& other) {
    return !stack.empty() || !other.stack.empty();
}

BinarySearchTree::Iterator BinarySearchTree::begin() {
    return Iterator(root);
}

BinarySearchTree::Iterator BinarySearchTree::end() {
    return Iterator(nullptr);
}


std::vector<int> unionBST(BinarySearchTree& tree1, BinarySearchTree& tree2) {
    std::vector<int> result;
    BinarySearchTree::Iterator iter1 = tree1.begin();
    BinarySearchTree::Iterator iter2 = tree2.begin();

    while (iter1 != tree1.end() && iter2 != tree2.end()) {
        if (*iter1 < *iter2) {
            result.push_back(*iter1);
            ++iter1;
        }
        else if (*iter2 < *iter1) {
            result.push_back(*iter2);
            ++iter2;
        }
        else {
            result.push_back(*iter1);
            ++iter1;
            ++iter2;
        }
    }

    while (iter1 != tree1.end()) {
        result.push_back(*iter1);
        ++iter1;
    }

    while (iter2 != tree2.end()) {
        result.push_back(*iter2);
        ++iter2;
    }

    return result;
}

std::vector<int> symmetricDifferenceBST(BinarySearchTree& tree1, BinarySearchTree& tree2) {
    std::vector<int> result;
    BinarySearchTree::Iterator iter1 = tree1.begin();
    BinarySearchTree::Iterator iter2 = tree2.begin();

    while (iter1 != tree1.end() && iter2 != tree2.end()) {
        if (*iter1 < *iter2) {
            result.push_back(*iter1);
            ++iter1;
        }
        else if (*iter2 < *iter1) {
            result.push_back(*iter2);
            ++iter2;
        }
        else {
            ++iter1;
            ++iter2;
        }
    }

    while (iter1 != tree1.end()) {
        result.push_back(*iter1);
        ++iter1;
    }

    while (iter2 != tree2.end()) {
        result.push_back(*iter2);
        ++iter2;
    }

    return result;
}

int main() {
    BinarySearchTree tree1;
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(7);
    tree1.insert(2);
    tree1.insert(4);

    BinarySearchTree tree2;
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(7);
    tree2.insert(8);
    tree2.insert(9);

    std::cout << "Tree 1 elements: ";
    tree1.print();
    std::cout << std::endl;

    std::cout << "Tree 2 elements: ";
    tree2.print();
    std::cout << std::endl;

    std::vector<int> unionResult = unionBST(tree1, tree2);
    std::cout << "Union of tree1 and tree2: ";
    for (int key : unionResult) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::vector<int> diffResult = symmetricDifferenceBST(tree1, tree2);
    std::cout << "Symmetric difference of tree1 and tree2: ";
    for (int key : diffResult) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    return 0;
}
