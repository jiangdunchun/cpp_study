#pragma once
template <class T>
class linked_list {
private:
    struct list_item
    {
        list_item* last_ptr = nullptr;
        list_item* next_ptr = nullptr;
        T value;
    };

    list_item* _front_item = nullptr;
    list_item* _back_item = nullptr;
    int _size = 0;


public:
    linked_list() {
    }

    ~linked_list() {
        list_item* now_item = _front_item;
        while (now_item) {
            _front_item = now_item->next_ptr;
            delete now_item;
            now_item = _front_item;
        }
    }

    int size() {
        return _size;
    }

    int is_empty() {
        if (_size) return 1;
        else return 0;
    }

    T at(int index) {
        if (index >= _size) throw "out of bounds";
        list_item* now_item = _front_item;
        for (int i = 0; i < index; i++) {
            now_item = now_item->next_ptr;
        }
        return now_item->value;
    }

    T at_reverse(int index) {
        if (index >= _size) throw "out of bounds";
        list_item* now_item = _back_item;
        for (int i = 0; i < index; i++) {
            now_item = now_item->last_ptr;
        }
        return now_item->value;
    }

    void push_front(T val) {
        list_item* new_item = new list_item;
        new_item->last_ptr = nullptr; 
        new_item->next_ptr = _front_item;
        new_item->value = val;

        if (_front_item) {
            _front_item->last_ptr = new_item;
        }
        _front_item = new_item;
        if (!_back_item) {
            _back_item = _front_item;
        }
        _size++;
    }

    void pop_front() {
        if (_size == 0) throw "list is null";
        list_item* now_item = _front_item->next_ptr;
        if (now_item) now_item->last_ptr = nullptr;
        delete _front_item;
        _front_item = now_item;
        _size--;
        if (_size == 0) _back_item = nullptr;
    }

    void push_back(T val) {
        list_item* new_item = new list_item;
        new_item->last_ptr = _back_item;
        new_item->next_ptr = nullptr;
        new_item->value = val;

        if (_back_item) {
            _back_item->next_ptr = new_item;
        }
        _back_item = new_item;
        if (!_front_item) {
            _front_item = _back_item;
        }
        _size++;
    }

    void pop_back() {
        if (_size == 0) throw "list is null";
        list_item* now_item = _back_item->last_ptr;
        if (now_item)  now_item->next_ptr = nullptr;
        delete _back_item;
        _back_item = now_item;
        _size--;
        if (_size == 0) _front_item = nullptr;
    }

    T front() {
        if (_size == 0) throw "list is null";
        return _front_item->value;
    }

    T back() {
        if (_size == 0) throw "list is null";
        return _back_item->value;
    }

    void insert(int index, T val) {
        if (index >= _size) throw "out of bounds";

        list_item* now_item = _front_item;
        for (int i = 0; i < index; i++) {
            now_item = now_item->next_ptr;
        }

        list_item* new_item = new list_item;
        new_item->last_ptr = now_item->last_ptr;
        new_item->next_ptr = now_item;
        new_item->value = val;

        if (new_item->last_ptr) new_item->last_ptr->next_ptr = new_item;
        if (new_item->next_ptr) new_item->next_ptr->last_ptr = new_item;

        if (!new_item->last_ptr) _front_item = new_item;
        if (!new_item->next_ptr) _back_item = new_item;
        _size++;
    }

    void remove_at(int index) {
        if (index >= _size) throw "out of bounds";

        list_item* now_item = _front_item;
        for (int i = 0; i < index; i++) {
            now_item = now_item->next_ptr;
        }

        if (now_item->last_ptr) now_item->last_ptr->next_ptr = now_item->next_ptr;
        else _front_item = now_item->next_ptr;

        if (now_item->next_ptr) now_item->next_ptr->last_ptr = now_item->last_ptr;
        else _back_item = now_item->last_ptr;

		delete now_item;
        _size--;
    }

    int remove(T item) {
		int num = 0;
        int index = -1;
        list_item* now_item = _front_item;
		while (now_item) {
			list_item* next_item = now_item->next_ptr;
			if (now_item->value == item) {
				index = num;
				if (now_item->last_ptr) now_item->last_ptr->next_ptr = now_item->next_ptr;
				else _front_item = now_item->next_ptr;

				if (now_item->next_ptr) now_item->next_ptr->last_ptr = now_item->last_ptr;
				else _back_item = now_item->last_ptr;

				delete now_item;
				_size--;
			}
			now_item = next_item;
			num++;
		}
        return index;
    }

    void reverse() {
        list_item* buffer;
        list_item* now_item = _front_item;
        while (now_item) {
            buffer = now_item->last_ptr;
            now_item->last_ptr = now_item->next_ptr;
            now_item->next_ptr = buffer;

            now_item = now_item->next_ptr;
        }

        buffer = _front_item;
        _front_item = _back_item;
        _back_item = buffer;
    }
};
