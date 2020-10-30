#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

template <class T>
class queue {
private:
	struct queue_item {
		T value;

		queue_item* next_ptr = nullptr;
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
		if(_size == 0) return true;
		else return false;
	}
	T dequeue() {
		if(_size == 0) throw "list is null";

		T out_val = _front_ptr->value;

		queue_item* n_ptr = _front_ptr->next_ptr;
		delete _front_ptr;
		_front_ptr = n_ptr;

		_size--;
		if(_size == 0) _back_ptr = nullptr;

		return out_val;
	}
	void enqueue(T val) {
		queue_item* n_ptr = new queue_item;
		n_ptr->next_ptr = nullptr;
		n_ptr->value = val;

		if(_back_ptr != nullptr) _back_ptr->next_ptr = n_ptr;
		_back_ptr = n_ptr;

		if(_size == 0) _front_ptr = _back_ptr;

		_size++;
	}
};

#endif