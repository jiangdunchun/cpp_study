#include <iostream>
#include <vector>
#include <time.h>

#include "algorithm/sorter.hpp"
#include "data_structure/hash_map.hpp"
#include "data_structure/rb_tree.hpp"

unsigned int hash_int(int val){
    return (unsigned int)val%17;
}

int main(int, char**) {
    std::cout << "hello world" << std::endl;

    // test for rb_tree
    rb_tree<int> tree;
    for(int i = 0; i < 20; i++) {
        tree.insert(i);
    }
    for(int i = 0; i < 20; i++) {
        tree.remove(19-i);
    }
    
    // test for hash_map
    /*
    hash_map<int, std::string> h_map(hash_int, 17);
    for(int i = 0; i < 100; i++) {
        h_map.add(i, std::to_string(i));
    }
    std::cout << "hash map exist 56:" << h_map.exists(56) << std::endl;
    std::cout << "hash map get 56:" << h_map.get(56) << std::endl;
    */

    // test for sort
    /* 
    clock_t start, finish;

    std::vector<int> sort_vals;
    for(int i = 0; i < 20000; i++) {
        sort_vals.push_back(rand() % 50000 + 1);
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
    */

    std::string imput;
    while(1) {
        std::cin>>imput;
        if(imput == "quit") break;
    }
}