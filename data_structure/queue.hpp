#pragma once

template <class T>
class queue {
private:
	struct queue_item {
		queue_item* next_ptr = nullptr;
		T value;
	};

	queue_item* _front_ptr = nullptr;
	queue_item* _back_ptr = nullptr;
	int _size = 0;

public:
	queue() {
	}
	~queue() {
		queue_item* now_item = _front_ptr;
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
		if(_size) return true;
		else return false;
	}
	T dequeue() {
		if(_size == 0) throw "list is null";
		T out_val = _front_ptr->value;
		queue_item* now_item = _front_ptr->next_ptr;
		if(now_item) now_item->last_ptr = nullptr;
		delete _front_ptr;
		_front_ptr = now_item;
		_size--;
		if(_size == 0) _back_ptr = nullptr;
		return out_val;
	}

	void enqueue(T val) {
		queue_item* new_item = new queue_item;
		new_item->next_ptr = nullptr;
		new_item->value = val;

		if(_back_ptr) {
			_back_ptr->next_ptr = new_item;
		}
		_back_ptr = new_item;
		if(!_front_ptr) {
			_front_ptr = _back_ptr;
		}
		_size++;
	}
};
