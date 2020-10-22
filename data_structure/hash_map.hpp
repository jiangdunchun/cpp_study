#ifndef __HASH_MAP_HPP__
#define __HASH_MAP_HPP__

#include "dynamic_array.hpp"

template<class T_key, class T_value>
class hash_map {
private:
    struct map_item {
        T_key key;
        T_value value;
    };

    dynamic_array<map_item>* _key_array;
    int _array_length;
    unsigned int (*_hash_func)(T_key);
    
public:
    hash_map(unsigned int (*hash_func)(T_key), int length) {
        _hash_func = hash_func;
        _array_length = length;
        _key_array = new dynamic_array<map_item>[_array_length];
    }
    ~hash_map() {
        delete[] _key_array;
    }

    void add(T_key key, T_value value) {
        int index = _hash_func(key);
        if(index >= _array_length) throw "out of bounds in hash function";

        _key_array[index].push({key, value});
    }
    bool exists(T_key key) {
        int index = _hash_func(key);
        if(index >= _array_length) throw "out of bounds in hash function";

        for(int i = 0; i < _key_array[index].size(); i++) {
            if(_key_array[index].at(i).key == key) return true;
        }
        return false;
    }
    T_value get(T_key key) {
        int index = _hash_func(key);
        if(index >= _array_length) throw "out of bounds in hash function";

        for(int i = 0; i < _key_array[index].size(); i++) {
            if(_key_array[index].at(i).key == key) return _key_array[index].at(i).value;
        }
        throw "not exist this key";
    }
    void remove(T_key key) { 
        int index = _hash_func(key);
        if(index >= _array_length) throw "out of bounds in hash function";

        for(int i = 0; i < _key_array[index].size(); i++) {
            if(_key_array[index].at(i).key == key) _key_array[index].remove_at(i);
        }
    }
};
#endif