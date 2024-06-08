// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::string> allPermutations = tree.getAllPermutations();
    if (n > 0 && n <= allPermutations.size()) {
        std::string perm = allPermutations[n - 1];
        return std::vector<char>(perm.begin(), perm.end());
    } else {
        return std::vector<char>();
    }
}
