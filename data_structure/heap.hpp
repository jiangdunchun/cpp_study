#ifndef __HEAP_HPP__
#define __HEAP_HPP__

template<class T>
class heap {
private:
    T* _t_p;
    int _capacity;
    int _size = 0;
    bool (*_compare_func)(T m_val, T l_val);

    void _fix() {
        for(int i = _size/2-1; i >=0; i--) {
            if((2*i+2) >= _size) {
                if(_compare_func(_t_p[2*i+1], _t_p[i])) {
                    T buffer = _t_p[i];
                    _t_p[i] = _t_p[2*i+1];
                    _t_p[2*i+1] = buffer;
                }
            }
            else {
                if(_compare_func(_compare_func(_t_p[2*i+1],_t_p[2*i+2])?_t_p[2*i+1]:_t_p[2*i+2], _t_p[i])) {
                    if(_compare_func(_t_p[2*i+1], _t_p[2*i+2])) {
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
    heap(int capacity, bool (*compare_func)(T m_val, T l_val)) {
        _compare_func = compare_func;

        _capacity = capacity; 
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
    void push(T value) {
        if (_size == _capacity) throw "heap is full";

        _t_p[_size] = value;
        _size++;
        _fix();
    }
    T top() {
        if (_size == 0) throw "heap is empty";

        return _t_p[0];
    }
    T pop() {
        if (_size == 0) throw "heap is empty";

        T value = _t_p[0];
        _t_p[0] = _t_p[_size-1];
        _t_p[_size-1] = 0;
        _size--;
        _fix();
        return value;
    }
};

#endif