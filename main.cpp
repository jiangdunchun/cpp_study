#include <iostream>
#include <vector>
#include <time.h>

#include "algorithm/sorter.hpp"
#include "algorithm/string_matcher.hpp"
#include "data_structure/hash_map.hpp"
#include "data_structure/rb_tree.hpp"
#include "data_structure/heap.hpp"
#include "data_structure/trie.hpp"
#include "data_structure/huffman_tree.hpp"

using namespace std;

unsigned int hash_int(int val){
    return (unsigned int)val%17;
}

bool max_heap_contrast_int(int a, int b) {
    return a<b;
}

int main(int, char**) {
    cout << "hello world" << endl;

    // test for rb_tree
    /*
    rb_tree<int> tree;
    for(int i = 0; i < 20; i++) {
        tree.insert(i);

        // dynamic_array<int> pre_array = tree.get_pre_order_tranverse();
        // cout << "pre order tranverse of tree after insert " << i << ":";
        // for(int j = 0; j < pre_array.size(); j++) {
        //      cout << pre_array.at(j) << ",";
        // }
        // cout << endl;

        // dynamic_array<int> in_array = tree.get_in_order_tranverse();
        // cout << "in order tranverse of tree after insert " << i << ":";
        // for(int j = 0; j < in_array.size(); j++) {
        //      cout << in_array.at(j) << ",";
        // }
        // cout << endl;
    }

    dynamic_array<int> pre_array = tree.get_pre_order_tranverse();
    cout << "----->pre order tranverse of tree :";
    for(int j = 0; j < pre_array.size(); j++) {
            cout << pre_array.at(j) << ",";
    }
    cout << endl;

    dynamic_array<int> in_array = tree.get_in_order_tranverse();
    cout << "----->in order tranverse of tree :";
    for(int j = 0; j < in_array.size(); j++) {
            cout << in_array.at(j) << ",";
    }
    cout << endl;

    dynamic_array<int> level_array = tree.get_level_order_tranverse();
    cout << "----->level order tranverse of tree :";
    for(int j = 0; j < level_array.size(); j++) {
            cout << level_array.at(j) << ",";
    }
    cout << endl;
    

    for(int i = 0; i < 20; i++) {
        tree.remove(19-i);
        // dynamic_array<int> pre_array = tree.get_pre_order_tranverse();
        // cout << "pre order tranverse of tree after delete " << 19-i << ":";
        // for(int j = 0; j < pre_array.size(); j++) {
        //      cout << pre_array.at(j) << ",";
        // }
        // cout << endl;

        // dynamic_array<int> in_array = tree.get_in_order_tranverse();
        // cout << "in order tranverse of tree after delete " << 19-i << ":";
        // for(int j = 0; j < in_array.size(); j++) {
        //      cout << in_array.at(j) << ",";
        // }
        // cout << endl;
    }
    */
    
    // test for hash_map
    /*
    hash_map<int, string> h_map(hash_int, 17);
    for(int i = 0; i < 100; i++) {
        h_map.add(i, to_string(i));
    }
    for(int i = 0; i < 20; i++) {
        h_map.remove(i);
    }
    cout << "hash map exist 56:" << h_map.exists(10) << endl;
    cout << "hash map get 56:" << h_map.get(10) << endl;
    */

    // test for heap
    /*
    heap<int> m_heap(10, max_heap_contrast_int);
    for(int i = 0; i < 10; i++) {
        m_heap.push(i);
    }
    for(int i = 0; i < 10; i++) {
        cout << "max_heap pop " << m_heap.pop() << endl;
    }
    */

    // test for sorter
    /* 
    clock_t start, finish;

    vector<int> sort_vals;
    for(int i = 0; i < 20000; i++) {
        sort_vals.push_back(rand() % 50000 + 1);
    }

    vector<int> sort_vals_0(sort_vals);
    start = clock();
    sorter::bubble_sort(sort_vals_0);
    finish = clock();
    cout << "bubble_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_1(sort_vals);
    start = clock();
    sorter::select_sort(sort_vals_1);
    finish = clock();
    cout << "select_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_2(sort_vals);
    start = clock();
    sorter::insert_sort(sort_vals_2);
    finish = clock();
    cout << "insert_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_3(sort_vals);
    start = clock();
    sorter::shell_sort(sort_vals_3);
    finish = clock();
    cout << "shell_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_4(sort_vals);
    start = clock();
    sorter::merge_sort(sort_vals_4);
    finish = clock();
    cout << "merge_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_5(sort_vals);
    start = clock();
    sorter::quick_sort(sort_vals_5);
    finish = clock();
    cout << "quick_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_6(sort_vals);
    start = clock();
    sorter::heap_sort(sort_vals_6);
    finish = clock();
    cout << "heap_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_7(sort_vals);
    start = clock();
    sorter::count_sort(sort_vals_7);
    finish = clock();
    cout << "count_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_8(sort_vals);
    start = clock();
    sorter::bucket_sort(sort_vals_8);
    finish = clock();
    cout << "bucket_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;

    vector<int> sort_vals_9(sort_vals);
    start = clock();
    sorter::radix_sort(sort_vals_9);
    finish = clock();
    cout << "radix_sort time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s"  << endl;
    */

    // test for string_matcher
    /*
    char* p_ptr = "abcdefghijklmnopqrstuvwxyz";
    char* s_ptr = "stu";
    cout << "naive match " << string_matcher::naive_match(p_ptr, s_ptr) << endl;
    cout << "kmp match " << string_matcher::kmp_match(p_ptr, s_ptr) << endl;
    */

    // test for trie
    /*
    trie my_trie;
    char* hello_str = "hello";
    char* world_str = "world";
    char* hi_str = "hi";
    char* hide_str = "hide";
    char* work_str = "work";
    char* hire_str = "hire";

    my_trie.insert(hello_str);
    my_trie.insert(world_str);
    my_trie.insert(hi_str);
    my_trie.insert(hide_str);
    my_trie.insert(work_str);
    
    cout << "search \"" << hire_str << "\"" << "in trie:" << my_trie.search(hire_str) << endl;
    cout << "search \"" << hide_str << "\"" << "in trie:" << my_trie.search(hide_str) << endl;

    dynamic_array<string> word_array = my_trie.get_tranverse();
    cout << "----->tranverse of trie:";
    for(int j = 0; j < word_array.size(); j++) {
            cout << word_array.at(j) << ",";
    }
    cout << endl;
    */

    // test for huffman_tree
    /*
    int huffman_array[5] = {10, 30, 60, 120, 56};
    huffman_tree<int> my_huffman_tree(huffman_array, 5);
    */


    string imput;
    while(1) {
        cin>>imput;
        if(imput == "quit") break;
    }
}