#ifndef __MAX_HEAP_HPP__
#define __MAX_HEAP_HPP__

enum heap_type{
    MAX_HEAP,
    MIN_HEAP
};

template<class T>
class heap {
private:
    T* _t_p;
    int _capacity;
    int _size = 0;
    bool (*_contrast_func)(T p_val, T n_val);

    void _fix() {
        for(int i = _size/2-1; i >=0; i--) {
            if((2*i+2) >= _size) {
                if(_contrast_func(_t_p[2*i+1], _t_p[i])) {
                    T buffer = _t_p[i];
                    _t_p[i] = _t_p[2*i+1];
                    _t_p[2*i+1] = buffer;
                }
            }
            else {
                if(_contrast_func(_contrast_func(_t_p[2*i+1],_t_p[2*i+2])?_t_p[2*i+1]:_t_p[2*i+2], _t_p[i])) {
                    if(_contrast_func(_t_p[2*i+1], _t_p[2*i+2])) {
                        T buffer = _t_p[i];
                        _t_p[i] = _t_p[2*i+1];
                        _t_p[2*i+1] = buffer;
                    }
                    else {
                        T buffer = _t_p[i];
                        _t_p[i] = _t_p[2*i+2];
                        _t_p[2*i+2] = buffer;
                    }
                }
            }
        }
    }

public:
    heap(int size, bool (*contrast_func)(T p_val, T n_val)) {
        _contrast_func = contrast_func;

        _capacity = size; 
        _t_p = new T[_capacity]();
    }
    ~heap() {
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
    T top() {
        if (_size == 0) throw "heap is empty";

        return _t_p[0];
    }
    void push(T value) {
        if (_size == _capacity) throw "heap is full";

        _t_p[_size] = value;
        _size++;
        _fix();
    }
    T pop() {
        if (_size == 0) throw "heap is empty";

        T value = _t_p[0];
        _t_p[0] = _t_p[_size-1];
        _t_p[_size-1] = NULL;
        _size--;
        _fix();
        return value;
    }
};

#endif