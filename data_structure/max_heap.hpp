#ifndef __MAX_HEAP_HPP__
#define __MAX_HEAP_HPP__

template<class T>
class max_heap {
private:
    T* _t_p;
    int _capacity;
    int _size = 0;

    void _fix() {
        for(int i = _size/2-1; i >=0; i--) {
            if((2*i+2) >= _size) {
                if(_t_p[2*i+1] > _t_p[i]) {
                    T buffer = _t_p[i];
                    _t_p[i] = _t_p[2*i+1];
                    _t_p[2*i+1] = buffer;
                }
            }
            else {
                if((_t_p[2*i+1]>_t_p[2*i+2]?_t_p[2*i+1]:_t_p[2*i+2]) > _t_p[i]) {
                    if(_t_p[2*i+1]>_t_p[2*i+2]) {
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
    max_heap(int size) {
        _capacity = size; 
        _t_p = new T[_capacity]();
    }
    ~max_heap() {
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