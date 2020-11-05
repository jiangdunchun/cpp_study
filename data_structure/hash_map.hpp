#ifndef __HASH_MAP_HPP__
#define __HASH_MAP_HPP__

#include "dynamic_array.hpp"

//#include <iostream>

template<class T_key, class T_value>
class hash_map {
private:
    struct map_item {
        T_key key;
        T_value value;
    };

    dynamic_array<map_item>* _key_array;
    int _array_size;
    unsigned int (*_hash_func)(T_key);
    
public:
    hash_map(unsigned int (*hash_func)(T_key), int size) {
        if(size < 1) throw "length must be >= 1";

        _hash_func = hash_func;
        _array_size = size;
        _key_array = new dynamic_array<map_item>[_array_size];
    }
    ~hash_map() {
        delete[] _key_array;
    }

    void push(T_key key, T_value value) {
        int index = _hash_func(key);
        if(index >= _array_size) throw "out of bounds in hash function";

        _key_array[index].push_back({key, value});
    }
    bool exist(T_key key) {
        int index = _hash_func(key);
        if(index >= _array_size) throw "out of bounds in hash function";

        for(int i = 0; i < _key_array[index].size(); i++) {
            if(_key_array[index].at(i).key == key) return true;
        }
        return false;
    }
    T_value& at(T_key key) {
        int index = _hash_func(key);
        if(index >= _array_size) throw "out of bounds in hash function";

        for(int i = 0; i < _key_array[index].size(); i++) {
            if(_key_array[index].at(i).key == key) return _key_array[index].at(i).value;
        }
        throw "not exist this key";
    }
    T_value remove(T_key key) { 
        T_value value;
        int index = _hash_func(key);
        if(index >= _array_size) throw "out of bounds in hash function";

        for(int i = 0; i < _key_array[index].size(); i++) {
            if(_key_array[index].at(i).key == key) 
            {
                value = _key_array[index].at(i).value;
                _key_array[index].remove_at(i);
                break;
            }
        }
        return value;
    }
};

#endif