#ifndef __TRIE_HPP__
#define __TRIE_HPP__

#include <string>
#include "dynamic_array.hpp"

using namespace std;

#define ITEM_MAX_NUM 26
#define DELTA_0 'a'
// only support the lower case letter(a-z)
#define IS_LOWER_LETTER(letter) ((letter - DELTA_0)>=0 && (letter - DELTA_0)<ITEM_MAX_NUM)

class trie {
private:
    struct trie_item {
        trie_item* nexts_ptr[26]{nullptr};
        bool is_word = false;
    };

    trie_item* _root = new trie_item();
    void _delete_item(trie_item* item_ptr) {
        for(int i = 0; i < ITEM_MAX_NUM; i++) {
            if(item_ptr->nexts_ptr[i] != nullptr) {
                _delete_item(item_ptr->nexts_ptr[i]);
            }
            delete item_ptr;
        }
    }
    trie_item* _insert_item(trie_item* item_ptr, char letter) {
        if(item_ptr->nexts_ptr[letter - DELTA_0] == nullptr) {
            item_ptr->nexts_ptr[letter - DELTA_0] = new trie_item();
        }

        return item_ptr->nexts_ptr[letter - DELTA_0];
    }
    trie_item* _search_item(trie_item* item_ptr, char letter) {
        return item_ptr->nexts_ptr[letter - DELTA_0];
    }
    void _tranverse(trie_item* item_ptr, dynamic_array<string>& ret_val, string buffer) {
        if(item_ptr->is_word) ret_val.push(buffer);
        for(int i = 0; i < ITEM_MAX_NUM; i++) {
            if(item_ptr->nexts_ptr[i] != nullptr) {
                string n_buffer = buffer;
                n_buffer += DELTA_0 + i;
                _tranverse(item_ptr->nexts_ptr[i], ret_val, n_buffer);
            }
        }
    }

public:
    trie() {}
    ~trie() {
        _delete_item(_root);
    }

    bool insert(string word) {
        for(int i = 0; i < word.length(); i++) {
            if(!IS_LOWER_LETTER(word[i])) throw "word must be in lower letter";
        }
        
        trie_item* now_ptr = _root;
        for(int i = 0; i < word.length(); i++) {
            now_ptr = _insert_item(now_ptr, word[i]);
        }
        if(now_ptr->is_word == true) {
            return false;
        }
        else {
            now_ptr->is_word = true;
            return true;
        }
    }
    bool search(string word) {
        for(int i = 0; i < word.length(); i++) {
            if(!IS_LOWER_LETTER(word[i])) throw "word must be in lower letter";
        }

        trie_item* now_ptr = _root;
        for(int i = 0; i < word.length(); i++) {
            now_ptr = _search_item(now_ptr, word[i]);
            if(now_ptr == nullptr) return false;
        }
        return now_ptr->is_word;
    }
    dynamic_array<string> get_tranverse() {
        dynamic_array<string> ret_val;
        string buffer = "";
        _tranverse(_root, ret_val, buffer);
        return ret_val;
    }
};

#endif