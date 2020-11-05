#include <iostream>
#include <vector>
#include <time.h>

#include "data_structure/queue.hpp"
#include "data_structure/heap.hpp"
#include "data_structure/dynamic_array.hpp"
#include "data_structure/linked_list.hpp"
#include "data_structure/hash_map.hpp"
#include "data_structure/rb_tree.hpp"
#include "data_structure/trie.hpp"
#include "data_structure/huffman_tree.hpp"

#include "algorithm/sorter.hpp"
#include "algorithm/string_matcher.hpp"

using namespace std;

unsigned int hash_int(int val){
    return (unsigned int)val%17;
}
bool min_compare_int(int a, int b) {
    return a<b;
}
bool max_compare_int(int a, int b) {
    return a>b;
}

int main(int, char**) {
    cout << "hello world" << endl;

    // test for queue
    /*
    cout << "test for queue------------->"<< endl;
    queue<int> my_queue;
    for(int i = 0; i < 100; i++) {
        my_queue.enqueue(i);
    }
    while(true) {
        cout << "ths size of my_queue : " << my_queue.size() << endl;
        if(!my_queue.is_empty()) {
            cout << "dequeue my_queue : " << my_queue.dequeue() << endl;
        }
        else {
            cout << "my_queue is empty and break!"<< endl;
            break;
        }
    }
    cout << "-----------------------------"<< endl;
    */

    // test for heap
    /*
    cout << "test for min heap------------->"<< endl;
    heap<int> min_heap(100, min_compare_int);
    for(int i = 0; i < 100; i++) {
        min_heap.push(i);
    }
    while(true) {
        cout << "ths size of min_heap : " << min_heap.size() << endl;
        if(!min_heap.is_empty()) {
            cout << "pop min_heap : " << min_heap.pop() << endl;
        }
        else {
            cout << "min_heap is empty and break!"<< endl;
            break;
        }
    }
    cout << "-----------------------------"<< endl;
    cout << "test for max heap------------->"<< endl;
    heap<int> max_heap(100, max_compare_int);
    for(int i = 0; i < 100; i++) {
        max_heap.push(i);
    }
    while(true) {
        cout << "ths size of max_heap : " << max_heap.size() << endl;
        if(!max_heap.is_empty()) {
            cout << "pop max_heap : " << max_heap.pop() << endl;
        }
        else {
            cout << "max_heap is empty and break!"<< endl;
            break;
        }
    }
    cout << "-----------------------------"<< endl;
    */
    
    // test for dynamic_array
    /*
    cout << "test for dynamic_array------------->"<< endl;
    dynamic_array<int> my_dynamic_array;
    
    for(int i = 0; i < 50; i++) {
        my_dynamic_array.push_back(i%10);
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < my_dynamic_array.size(); i++) {
        my_dynamic_array.at(i) = i;
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 50; i++) {
        my_dynamic_array.push_front(i);
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 50; i++) {
        my_dynamic_array.insert_at(1, -1);
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 50; i++) {
        my_dynamic_array.remove_at(1);
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 20; i++) {
        my_dynamic_array.pop_front();
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 20; i++) {
        my_dynamic_array.pop_back();
    }
    cout << "ths size of my_dynamic_array : " << my_dynamic_array.size() << endl;
    cout << "ths capacity of my_dynamic_array : " << my_dynamic_array.capacity() << endl;
    cout << "the items in my_dynamic_array : ";
    for(int i = 0; i < my_dynamic_array.size(); i++) {
        cout << my_dynamic_array.at(i) << ", ";
    }
    cout << endl;

    cout << "find 50 in my_dynamic_array : " << my_dynamic_array.find(50) << endl;
    cout << "find 10 in my_dynamic_array : " << my_dynamic_array.find(10) << endl;
    cout << "-----------------------------"<< endl;
    */

    // test for linked_list
    /*
    cout << "test for linked_list------------->"<< endl;
    linked_list<int> my_linked_list;
    
    for(int i = 0; i < 50; i++) {
        my_linked_list.push_back(i%10);
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < my_linked_list.size(); i++) {
        my_linked_list.at(i) = i;
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 50; i++) {
        my_linked_list.push_front(i);
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 50; i++) {
        my_linked_list.insert_at(1, -1);
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 50; i++) {
        my_linked_list.remove_at(1);
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 20; i++) {
        my_linked_list.pop_front();
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    for(int i = 0; i < 40; i++) {
        my_linked_list.pop_back();
    }
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;

    my_linked_list.reverse();
    cout << "ths size of my_linked_list : " << my_linked_list.size() << endl;
    cout << "the items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at(i) << ", ";
    }
    cout << endl;
    cout << "the reverse items in my_linked_list : ";
    for(int i = 0; i < my_linked_list.size(); i++) {
        cout << my_linked_list.at_reverse(i) << ", ";
    }
    cout << endl;

    cout << "find 50 in my_linked_list : " << my_linked_list.find(50) << endl;
    cout << "find 10 in my_linked_list : " << my_linked_list.find(10) << endl;
    cout << "-----------------------------"<< endl;    
    */

    // test for hash_map
    /*
    cout << "test for hash_map------------->"<< endl;
    hash_map<int, string> my_hash_map(hash_int, 17);
    for(int i = 0; i < 100; i++) {
        my_hash_map.push(i, to_string(i));
    }
    for(int i = 0; i < 100; i++) {
        cout << "the items in hash_map: "<< i << ", "<< my_hash_map.at(i) << endl;
    }
    for(int i = 0; i < 20; i++) {
        cout << "remove item from hash map:" << i << ","<< my_hash_map.remove(i) << endl;
    }
    for(int i = 20; i < 100; i++) {
        cout << "the items in hash_map: "<< i << ", "<< my_hash_map.at(i) << endl;
    }
    cout << "hash map exist 10:" << my_hash_map.exist(10) << endl;
    cout << "hash map get 56:" << my_hash_map.at(56) << endl;
    cout << "-----------------------------"<< endl;
    */

    // test for rb_tree
    /*
    rb_tree<int> my_rb_tree(max_compare_int);
    for(int i = 0; i < 20; i++) {
        my_rb_tree.push(i);
    }

    dynamic_array<int> pre_array = my_rb_tree.get_pre_order_tranverse();
    cout << "pre order tranverse of my_rb_tree: ";
    for(int j = 0; j < pre_array.size(); j++) {
            cout << pre_array.at(j) << ",";
    }
    cout << endl;

    dynamic_array<int> in_array = my_rb_tree.get_in_order_tranverse();
    cout << "in order tranverse of my_rb_tree: ";
    for(int j = 0; j < in_array.size(); j++) {
            cout << in_array.at(j) << ",";
    }
    cout << endl;

    dynamic_array<int> level_array = my_rb_tree.get_level_order_tranverse();
    cout << "level order tranverse of my_rb_tree: ";
    for(int j = 0; j < level_array.size(); j++) {
            cout << level_array.at(j) << ",";
    }
    cout << endl;
    

    for(int i = 0; i < 5; i++) {
        my_rb_tree.remove(i);
    }

    dynamic_array<int> pre_array_0 = my_rb_tree.get_pre_order_tranverse();
    cout << "pre order tranverse of my_rb_tree: ";
    for(int j = 0; j < pre_array_0.size(); j++) {
            cout << pre_array_0.at(j) << ",";
    }
    cout << endl;

    dynamic_array<int> in_array_0 = my_rb_tree.get_in_order_tranverse();
    cout << "in order tranverse of my_rb_tree: ";
    for(int j = 0; j < in_array_0.size(); j++) {
            cout << in_array_0.at(j) << ",";
    }
    cout << endl;

    dynamic_array<int> level_array_0 = my_rb_tree.get_level_order_tranverse();
    cout << "level order tranverse of my_rb_tree: ";
    for(int j = 0; j < level_array_0.size(); j++) {
            cout << level_array_0.at(j) << ",";
    }
    cout << endl;
    */

    // test for trie
    /*
    cout << "test for trie------------->"<< endl;
    trie my_trie;
    string hello_str = "hello";
    string world_str = "world";
    string hi_str = "hi";
    string hide_str = "hide";
    string work_str = "work";
    string hire_str = "hire";

    my_trie.insert(hello_str);
    my_trie.insert(world_str);
    my_trie.insert(hi_str);
    my_trie.insert(hide_str);
    my_trie.insert(work_str);
    
    cout << "search \"" << hire_str << "\"" << "in my_trie:" << my_trie.search(hire_str) << endl;
    cout << "search \"" << hide_str << "\"" << "in my_trie:" << my_trie.search(hide_str) << endl;

    dynamic_array<string> word_array = my_trie.get_tranverse();
    cout << "tranverse of my_trie:";
    for(int j = 0; j < word_array.size(); j++) {
            cout << word_array.at(j) << ",";
    }
    cout << endl;
    cout << "-----------------------------"<< endl;
    */

    // test for huffman_tree
    
    cout << "test for huffman_tree------------->"<< endl;
    int my_huffman_array[5] = {10, 30, 60, 120, 56};
    huffman_tree<int> my_huffman_tree(my_huffman_array, 5);
    cout << "test for trie------------->"<< endl;
    

    // test for sorter
    /*
    cout << "test for sorter------------->"<< endl;
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
    cout << "-----------------------------"<< endl;    
    */

    // test for string_matcher
    /*
    cout << "test for string_matcher------------->"<< endl;
    // @TODO: change the test str
    string p_str = "";
    for(int i = 1; i < 100000; i++) {
        p_str += "xy";
    }
    p_str += "z";
    string s_str = "xyxyxyxyxyz";
    clock_t str_start, str_finish;

    str_start = clock();
    cout << "naive match " << string_matcher::naive_match(p_str, s_str) << endl;
    str_finish = clock();
    cout << "naive match time:" << (double)(str_finish - str_start) / CLOCKS_PER_SEC << "s"  << endl;

    str_start = clock();
    cout << "kmp match " << string_matcher::kmp_match(p_str, s_str) << endl;
    str_finish = clock();
    cout << "kmp match time:" << (double)(str_finish - str_start) / CLOCKS_PER_SEC << "s"  << endl;
    cout << "-----------------------------"<< endl; 
    */

    string imput;
    while(1) {
        cin>>imput;
        if(imput == "quit") break;
    }
}