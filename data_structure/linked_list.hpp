#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

template <class T>
class linked_list {
private:
    struct list_item {
        T value;

        list_item* last_ptr = nullptr;
        list_item* next_ptr = nullptr;
    };

    list_item* _front_ptr = nullptr;
    list_item* _back_ptr = nullptr;
    int _size = 0;

public:
    linked_list() {
    }
    ~linked_list() {
        list_item* now_item = _front_ptr;
        while(now_item) {
            _front_ptr = now_item->next_ptr;
            delete now_item;
            now_item = _front_ptr;
        }
    }

    int size() {
        return _size;
    }
    bool is_empty() {
        return _size == 0;
    }
    T at(int index) {
        if(index >= _size) throw "out of bounds";
        list_item* now_item = _front_ptr;
        for(int i = 0; i < index; i++) {
            now_item = now_item->next_ptr;
        }
        return now_item->value;
    }
    T at_reverse(int index) {
        if(index >= _size) throw "out of bounds";
        list_item* now_item = _back_ptr;
        for(int i = 0; i < index; i++) {
            now_item = now_item->last_ptr;
        }
        return now_item->value;
    }
    void push_front(T value){
        list_item* new_item = new list_item;
        new_item->last_ptr = nullptr; 
        new_item->next_ptr = _front_ptr;
        new_item->value = value;

        if(_front_ptr){
            _front_ptr->last_ptr = new_item;
        }
        _front_ptr = new_item;
        if(!_back_ptr) {
            _back_ptr = _front_ptr;
        }
        _size++;
    }
    T pop_front() {
        if(_size == 0) throw "list is null";
        T value = _front_ptr->value;
        list_item* now_item = _front_ptr->next_ptr;
        if(now_item) now_item->last_ptr = nullptr;
        delete _front_ptr;
        _front_ptr = now_item;
        _size--;
        if(_size == 0) _back_ptr = nullptr;
        return value;
    }
    void push_back(T value) {
        list_item* new_item = new list_item;
        new_item->last_ptr = _back_ptr;
        new_item->next_ptr = nullptr;
        new_item->value = value;

        if(_back_ptr) {
            _back_ptr->next_ptr = new_item;
        }
        _back_ptr = new_item;
        if(!_front_ptr) {
            _front_ptr = _back_ptr;
        }
        _size++;
    }
    T pop_back() {
        if(_size == 0) throw "list is null";
        T value = _back_ptr->value;
        list_item* now_item = _back_ptr->last_ptr;
        if(now_item)  now_item->next_ptr = nullptr;
        delete _back_ptr;
        _back_ptr = now_item;
        _size--;
        if(_size == 0) _front_ptr = nullptr;
        return value;
    }
    T front() {
        if(_size == 0) throw "list is null";
        return _front_ptr->value;
    }
    T back() {
        if(_size == 0) throw "list is null";
        return _back_ptr->value;
    }
    void insert(int index, T value) {
        if(index >= _size) throw "out of bounds";

        list_item* now_item = _front_ptr;
        for(int i = 0; i < index; i++) {
            now_item = now_item->next_ptr;
        }

        list_item* new_item = new list_item;
        new_item->last_ptr = now_item->last_ptr;
        new_item->next_ptr = now_item;
        new_item->value = value;

        if(new_item->last_ptr) new_item->last_ptr->next_ptr = new_item;
        if(new_item->next_ptr) new_item->next_ptr->last_ptr = new_item;

        if(!new_item->last_ptr) _front_ptr = new_item;
        if(!new_item->next_ptr) _back_ptr = new_item;
        _size++;
    }
    void remove_at(int index) {
        if(index >= _size) throw "out of bounds";

        list_item* now_item = _front_ptr;
        for(int i = 0; i < index; i++) {
            now_item = now_item->next_ptr;
        }

        if(now_item->last_ptr) now_item->last_ptr->next_ptr = now_item->next_ptr;
        else _front_ptr = now_item->next_ptr;

        if(now_item->next_ptr) now_item->next_ptr->last_ptr = now_item->last_ptr;
        else _back_ptr = now_item->last_ptr;

		delete now_item;
        _size--;
    }
    int remove(T value){
		int num = 0;
        int index = -1;
        list_item* now_item = _front_ptr;
		while(now_item){
			list_item* next_item = now_item->next_ptr;
			if(now_item->value == value){
				index = num;
				if(now_item->last_ptr) now_item->last_ptr->next_ptr = now_item->next_ptr;
				else _front_ptr = now_item->next_ptr;

				if(now_item->next_ptr) now_item->next_ptr->last_ptr = now_item->last_ptr;
				else _back_ptr = now_item->last_ptr;

				delete now_item;
				_size--;
			}
			now_item = next_item;
			num++;
		}
        return index;
    }
    void reverse(){
        list_item* buffer;
        list_item* now_item = _front_ptr;
        while(now_item){
            buffer = now_item->last_ptr;
            now_item->last_ptr = now_item->next_ptr;
            now_item->next_ptr = buffer;

            now_item = now_item->next_ptr;
        }

        buffer = _front_ptr;
        _front_ptr = _back_ptr;
        _back_ptr = buffer;
    }
};
#endif
