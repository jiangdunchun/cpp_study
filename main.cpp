#include <iostream>
#include <vector>

#include "algorithm/sorter.hpp"

int main(int, char**) {

    std::vector<int> sort_vals;
    for (int i = 0; i < 1000; i++) {
        sort_vals.push_back(rand() % 1000 + 1);
    }
    sorter::quick_sort(sort_vals);
    sorter::heap_sort(sort_vals);

    std::string imput;
    while (1) {
        std::cin>>imput;
        if (imput == "quit") break;
    }
}