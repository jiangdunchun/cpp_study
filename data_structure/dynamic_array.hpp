#pragma once

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
        T* n_p = new T[new_capacity];
        memcpy(n_p, _t_p, sizeof(T) * _size);
        delete[] _t_p;
        _t_p = n_p;
        _capacity = new_capacity;
    }


public:
    dynamic_array() {
        _t_p = new T[DYNAMIC_ARRAY_CAPACITY_MIN];
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
        if(_size) return true;
        else return false;
    }
    T at(int index) {
        if(index >= _size) throw "out of bounds";
        return _t_p[index];
    }
    void push(T item) {
        _t_p[_size++] = item;

        if(_size > _capacity / 2) {
            _resize(2 * _capacity);
        }
    }
    void insert(int index, T item) {
        if(index >= _size) throw "out of bounds";

        for(int i = _size; i > index; i--) {
            _t_p[i] = _t_p[i - 1];
        }
        _t_p[index] = item;
        _size++;

        if(_size > _capacity / 2) {
            _resize(2 * _capacity);
        }
    }
    void prepend(T item) {
        insert(0, item);
    }
    T pop() {
        T item = _t_p[_size];
        _t_p[_size] = NULL;
        _size--;

        if(_size < _capacity / 4) {
            _resize(_capacity / 2);
        }
        return item;
    }
    void remove_at(int index) {
        if(index >= _size) throw "out of bounds";

        for(int i = index; i < _size; i++) {
            _t_p[i] = _t_p[i + 1];
        }
        _t_p[_size] = NULL;
        _size--;

        if(_size < _capacity / 4) {
            _resize(_capacity / 2);
        }
    }
    int remove(T item) {
		int num = 0;
        int index = -1;
        for(int i = 0; i < _size; i++) {
            if(_t_p[i] == item) {
				num++;
                index = i;
            }
			else {
				if(num) {
					_t_p[i - num] = _t_p[i];
				}
			}
        }

		_size = _size - num;
		if(_size < _capacity / 4) {
			_resize(_capacity / 2);
		}
        return index;
    }
    int find(T item) {
        int index = -1;
        for(int i = 0; i < _size; i++) {
            if(_t_p[i] == item) {
                index = i;
            }
        }
        return index;
    }
};
