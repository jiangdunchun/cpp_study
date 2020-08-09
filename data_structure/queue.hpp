#pragma once

template <class T>
class list_queue {
private:
	struct list_item {
		list_item* next_ptr = nullptr;
		T value;
	};

	list_item* _front_item = nullptr;
	list_item* _back_item = nullptr;
	int _size = 0;


public:
	list_queue() {
	}

	~list_queue() {
		list_item* now_item = _front_item;
		while(now_item) {
			_front_item = now_item->next_ptr;
			delete now_item;
			now_item = _front_item;
		}
	}

	int size() {
		return _size;
	}

	bool is_empty() {
		if(_size) return true;
		else return false;
	}

	T dequeue() {
		if(_size == 0) throw "list is null";
		T out_val = _front_item->value;
		list_item* now_item = _front_item->next_ptr;
		if(now_item) now_item->last_ptr = nullptr;
		delete _front_item;
		_front_item = now_item;
		_size--;
		if(_size == 0) _back_item = nullptr;
		return out_val;
	}

	void enqueue(T val) {
		list_item* new_item = new list_item;
		new_item->next_ptr = nullptr;
		new_item->value = val;

		if(_back_item) {
			_back_item->next_ptr = new_item;
		}
		_back_item = new_item;
		if(!_front_item) {
			_front_item = _back_item;
		}
		_size++;
	}
};
