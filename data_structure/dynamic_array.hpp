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
    T at(int index) {
        if(index >= _size) throw "out of bounds";
        return _t_p[index];
    }
    void push(T value) {
        _t_p[_size] = value;
        _size++;

        if(_size > _capacity / 2) {
            _resize(2 * _capacity);
        }
    }
    void insert(int index, T value) {
        if(index >= _size) throw "out of bounds";

        for(int i = _size; i > index; i--) {
            _t_p[i] = _t_p[i - 1];
        }
        _t_p[index] = value;
        _size++;

        if(_size > _capacity / 2) {
            _resize(2 * _capacity);
        }
    }
    void prepend(T value) {
        insert(0, value);
    }
    T pop() {
        if (_size == 0) throw "array is empty";

        T value = _t_p[_size-1];
        _t_p[_size-1] = 0;
        _size--;

        if(_size < _capacity / 4) {
            _resize(_capacity / 2);
        }
        return value;
    }
    T remove_at(int index) {
        if(index >= _size) throw "out of bounds";

        T value = _t_p[index];
        for(int i = index; i < _size; i++) {
            _t_p[i] = _t_p[i + 1];
        }
        _t_p[_size-1] = 0;
        _size--;

        if(_size < _capacity / 4) {
            _resize(_capacity / 2);
        }
        return value;
    }
    int remove(T value) {
		int num = 0;
        int index = -1;
        for(int i = 0; i < _size; i++) {
            if(_t_p[i] == value) {
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
    int find(T value) {
        int index = -1;
        for(int i = 0; i < _size; i++) {
            if(_t_p[i] == value) {
                index = i;
            }
        }
        return index;
    }
};

#endif
