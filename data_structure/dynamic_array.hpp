#ifndef __DYNAMIC_ARRAY_HPP__
#define __DYNAMIC_ARRAY_HPP__

#include <cstring>

#define DYNAMIC_ARRAY_CAPACITY_MIN 16

template <class T>
class dynamic_array {
private:
    T* _t_p;
    int _size = 0;
    int _capacity = DYNAMIC_ARRAY_CAPACITY_MIN;

    void _resize(int new_capacity) {
        if(new_capacity < DYNAMIC_ARRAY_CAPACITY_MIN) return;
        T* n_p = new T[new_capacity]();
        memcpy(n_p, _t_p, sizeof(T) * _size);
        delete[] _t_p;
        _t_p = n_p;
        _capacity = new_capacity;
    }

public:
    dynamic_array() {
        _t_p = new T[DYNAMIC_ARRAY_CAPACITY_MIN]();
    }
    ~dynamic_array() {
        delete[] _t_p;
    }

    int size() {
        return _size;
    }
    int capacity() {
        return _capacity;
    }
    bool is_empty() {
        return _size == 0;
    }
    T& at(int index) {
        if(index >= _size || index < 0) throw "out of bounds";
        return _t_p[index];
    }
    void insert_at(int index, T value) {
        if(index >= _size || index < 0) throw "out of bounds";

        for(int i = _size; i > index; i--) {
            _t_p[i] = _t_p[i-1];
        }
        // @TODO: use memcpy
        // memcpy(&_t_p[index+1], &_t_p[index], sizeof(T) * (_size-index));
        _t_p[index] = value;
        _size++;

        if(_size > _capacity / 2) {
            _resize(2 * _capacity);
        }
    }
    void push_front(T value) {
        insert_at(0, value);
    }
    void push_back(T value) {
        _t_p[_size] = value;
        _size++;

        if(_size > _capacity / 2) {
            _resize(2 * _capacity);
        }
    }
    T remove_at(int index) {
        if(index >= _size || index < 0) throw "out of bounds";

        T value = _t_p[index];
        for(int i = index; i < _size; i++) {
            _t_p[i] = _t_p[i+1];
        }
        // @TODO: use memcpy
        // memcpy(&_t_p[index], &_t_p[index+1], sizeof(T) * (_size-index-1));
        // @TODO: set last position to null
        //_t_p[_size-1] = NULL;
        _size--;

        if(_size < _capacity / 4) {
            _resize(_capacity / 2);
        }
        return value;
    }
    T pop_front() {
        return remove_at(0);
    }
    T pop_back() {
        return remove_at(_size-1);
    }
    int find(T value) {
        int index = -1;
        for(int i = 0; i < _size; i++) {
            if(_t_p[i] == value) {
                index = i;
                break;
            }
        }
        return index;
    }
};

#endif
