// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

struct Node {
    std::vector<Node*> children;
    char value;

    explicit Node(char val) : value(val) {}

    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Tree {
 public:
    Node* root;

    explicit Tree(const std::vector<char>& elements) {
        root = new Node('\0');
        buildTree(root, elements);
    }

    ~Tree() {
        delete root;
    }

    std::vector<std::string> getAllPermutations() const {
        std::vector<std::string> permutations;
        genPerm(root, "", &permutations);
        return permutations;
    }

 private:
    void buildTree(Node* node, const std::vector<char>& elements) {
        if (elements.empty()) {
            return;
        }

        for (char element : elements) {
            Node* child = new Node(element);
            node->children.push_back(child);

            std::vector<char> remainingElements = elements;
            remainingElements.erase(std::remove(remainingElements.begin(), remainingElements.end(), element), remainingElements.end());
            buildTree(child, remainingElements);
        }
    }

    void genPerm(Node* n, std::string cur, std::vector<std::string>* p) const {
        if (n->value != '\0') {
            cur.push_back(n->value);
        }

        if (n->children.empty()) {
            p->push_back(cur);
            return;
        }

        for (auto child : n->children) {
            genPerm(child, cur, p);
        }
    }
};

#endif  // INCLUDE_TREE_H_
