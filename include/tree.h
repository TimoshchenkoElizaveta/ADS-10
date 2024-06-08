// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 public:
    struct Node {
        char data;
        std::vector<Node*> children;

        Node(char data) : data(data) {}
    };

 private:
    Node* root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node* node, const std::vector<char>& elements);
    void getPermutations(Node* node, std::vector<char>& currentPermutation);

 public:
    Tree(const std::vector<char>& elements);
    std::vector<char> getPerm(int n);
};
#endif  // INCLUDE_TREE_H_
