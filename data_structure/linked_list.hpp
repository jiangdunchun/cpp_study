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
            now_item = now_item->next_ptr;
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
    T& at(int index) {
        if(index >= _size || index < 0) throw "out of bounds";

        int i = 0;
        list_item* now_item = _front_ptr;
        while(i != index) {
            now_item = now_item->next_ptr;
            i++;
        }

        return now_item->value;
    }
    T& at_reverse(int index) {
        if(index >= _size || index < 0) throw "out of bounds";

        int i = 0;
        list_item* now_item = _back_ptr;
        while(i != index) {
            now_item = now_item->last_ptr;
            i++;
        }

        return now_item->value;
    }
    T& front() {
        if(_size == 0) throw "list is empty";

        return _front_ptr->value;
    }
    T& back() {
        if(_size == 0) throw "list is empty";

        return _back_ptr->value;
    }
    void insert_at(int index, T value) {
        if(index >= _size || index < 0) throw "out of bounds";

        int i = 0;
        list_item* now_item = _front_ptr;
        while(i != index) {
            now_item = now_item->next_ptr;
            i++;
        }

        list_item* new_item = new list_item;

        new_item->last_ptr = now_item->last_ptr;
        if(new_item->last_ptr != nullptr) new_item->last_ptr->next_ptr = new_item;
        else _front_ptr = new_item;

        new_item->next_ptr = now_item;
        now_item->last_ptr = new_item;

        new_item->value = value;
        
        _size++;
    }
    void push_front(T value){
        insert_at(0, value);
    }
    void push_back(T value) {
        list_item* new_item = new list_item;
        new_item->last_ptr = _back_ptr;
        new_item->next_ptr = nullptr;
        new_item->value = value;

        if(new_item->last_ptr != nullptr) new_item->last_ptr->next_ptr = new_item;
        _back_ptr = new_item;

        if(_front_ptr == nullptr) _front_ptr = _back_ptr;

        _size++;
    }
    T remove_at(int index) {
        if(index >= _size || index < 0) throw "out of bounds";

        int i = 0;
        list_item* now_item = _front_ptr;
        while(i != index) {
            now_item = now_item->next_ptr;
            i++;
        }

        T value = now_item->value;

        if(now_item->last_ptr != nullptr) now_item->last_ptr->next_ptr = now_item->next_ptr;
        else _front_ptr = now_item->next_ptr;

        if(now_item->next_ptr != nullptr) now_item->next_ptr->last_ptr = now_item->last_ptr;
        else _back_ptr = now_item->last_ptr;

		delete now_item;
        _size--;

        return value;
    }
    T pop_front() {
        return remove_at(0);
    }
    T pop_back() {
        // @TODO: delete from the end
        return remove_at(_size-1);
    }
    int find(T value) {
        int index = -1;

        int i = 0;
        list_item* now_item = _front_ptr;
        while(i != _size) {
            if(now_item->value == value) {
                index = i;
                break;
            }
            else{
                now_item = now_item->next_ptr;
            }
            i++;
        }

        return index;
    }
    void reverse(){
        if(_size == 0) return;

        int i = 0;
        list_item* buffer;
        list_item* now_item = _front_ptr;
        while(i != _size) {
            buffer = now_item->last_ptr;
            now_item->last_ptr = now_item->next_ptr;
            now_item->next_ptr = buffer;

            now_item = now_item->last_ptr;
            i++;
        }

        buffer = _front_ptr;
        _front_ptr = _back_ptr;
        _back_ptr = buffer;
    }
};

#endif
