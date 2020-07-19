#include <iostream>
#include <vector>
#include <time.h>

#include "algorithm/sorter.hpp"

int main(int, char**) {
    clock_t start, finish;

    std::vector<int> sort_vals;
    for (int i = 0; i < 10000; i++) {
        sort_vals.push_back(rand() % 10000 + 1);
    }

    std::vector<int> sort_vals_0(sort_vals);
    start = clock();
    sorter::bubble_sort(sort_vals_0);
    finish = clock();
    std::cout << "bubble_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_1(sort_vals);
    start = clock();
    sorter::select_sort(sort_vals_1);
    finish = clock();
    std::cout << "select_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_2(sort_vals);
    start = clock();
    sorter::insert_sort(sort_vals_2);
    finish = clock();
    std::cout << "insert_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_3(sort_vals);
    start = clock();
    sorter::shell_sort(sort_vals_3);
    finish = clock();
    std::cout << "shell_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_4(sort_vals);
    start = clock();
    sorter::merge_sort(sort_vals_4);
    finish = clock();
    std::cout << "merge_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_5(sort_vals);
    start = clock();
    sorter::quick_sort(sort_vals_5);
    finish = clock();
    std::cout << "quick_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_6(sort_vals);
    start = clock();
    sorter::heap_sort(sort_vals_6);
    finish = clock();
    std::cout << "heap_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_7(sort_vals);
    start = clock();
    sorter::count_sort(sort_vals_7);
    finish = clock();
    std::cout << "count_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_8(sort_vals);
    start = clock();
    sorter::bucket_sort(sort_vals_8);
    finish = clock();
    std::cout << "bucket_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::vector<int> sort_vals_9(sort_vals);
    start = clock();
    sorter::radix_sort(sort_vals_9);
    finish = clock();
    std::cout << "radix_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << std::endl;

    std::string imput;
    while (1) {
        std::cin>>imput;
        if (imput == "quit") break;
    }
}