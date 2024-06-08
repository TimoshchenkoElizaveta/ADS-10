// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

Tree::Tree(const std::vector<char>& elements) {
    root = new Node(elements[0]);
    buildTree(root, elements);
    getPermutations(root, {elements[0]});
}

void Tree::buildTree(Node* node, const std::vector<char>& elements) {
    if (elements.size() <= 1) {
        return;
    }

    for (size_t i = 1; i < elements.size(); i++) {
        std::vector<char> newElements = elements;
        newElements.erase(newElements.begin() + i);
        node->children.push_back(new Node(elements[i]));
        buildTree(node->children.back(), newElements);
    }
}

void Tree::getPermutations(Node* node, std::vector<char>& currentPermutation) {
    if (node->children.empty()) {
        permutations.push_back(currentPermutation);
        return;
    }

    for (auto& child : node->children) {
        currentPermutation.push_back(child->data);
        getPermutations(child, currentPermutation);
        currentPermutation.pop_back();
    }
}

std::vector<char> Tree::getPerm(int n) {
    if (n > 0 && n <= permutations.size()) {
        return permutations[n - 1];
    } else {
        return {};
    }
}
