#ifndef __HUFFMAN_TREE__
#define __HUFFMAN_TREE__

#include "heap.hpp"
#include "dynamic_array.hpp"

template<class T>
class huffman_tree {
private:
    struct huffman_item {
        T value;
        int index = -1;
        huffman_item* left_ptr = nullptr;
        huffman_item* right_ptr = nullptr;

        bool is_null() {
            return left_ptr != nullptr || right_ptr != nullptr;
        }
    };
    
    unsigned int _size = 0;
    huffman_item* _root_ptr = nullptr;

    static bool _min_compare_func(huffman_item* a, huffman_item* b) {
        return a->value<b->value;
    }
    void _delete_item(huffman_item* n_ptr) {
        if(n_ptr->left_ptr != nullptr) {
            _delete_item(n_ptr->left_ptr);
            n_ptr->left_ptr = nullptr;
        }
        if(n_ptr->right_ptr != nullptr) {
            _delete_item(n_ptr->right_ptr);
            n_ptr->right_ptr = nullptr;
        }

        delete n_ptr;
        n_ptr = nullptr;
    }
    void _pre_order_tranverse(huffman_item* n_ptr, dynamic_array<int>& ret_array){
		if(n_ptr != nullptr) {
			ret_array.push_back(n_ptr->index);
			_pre_order_tranverse(n_ptr->left_ptr, ret_array);
			_pre_order_tranverse(n_ptr->right_ptr, ret_array);
		}
	}
	void _in_order_tranverse(huffman_item* n_ptr, dynamic_array<int>& ret_array){
		if(n_ptr != nullptr) {
			_in_order_tranverse(n_ptr->left_ptr, ret_array);
			ret_array.push_back(n_ptr->index);
			_in_order_tranverse(n_ptr->right_ptr, ret_array);
		}
	}
	void _post_order_tranverse(huffman_item* n_ptr, dynamic_array<int>& ret_array){
		if(n_ptr != nullptr) {
			_post_order_tranverse(n_ptr->left_ptr, ret_array);
			_post_order_tranverse(n_ptr->right_ptr, ret_array);
			ret_array.push_back(n_ptr->index);
		}
	}

public:
    huffman_tree(T* vals, unsigned int length) {
        _size = length;

        heap<huffman_item*>* min_heap = new heap<huffman_item*>(length, _min_compare_func);
        for(int i = 0; i < length; i++) {
            huffman_item* n_ptr = new huffman_item();
            n_ptr->value = vals[i];
            n_ptr->index = i;
            min_heap->push(n_ptr);
        }

        while(min_heap->size() > 1) {
            huffman_item* f_ptr = min_heap->pop();
            huffman_item* s_ptr = min_heap->pop();

            huffman_item* n_ptr = new huffman_item();
            n_ptr->value = f_ptr->value + s_ptr->value;
            n_ptr->left_ptr = f_ptr;
            n_ptr->right_ptr = s_ptr;

            min_heap->push(n_ptr);
            _root_ptr = n_ptr;
        }

        delete min_heap;
    }
    ~huffman_tree() {
        if(_root_ptr != nullptr) {
            _delete_item(_root_ptr);
        }
    }

    int size() {
        return _size;
    }
    dynamic_array<int> get_pre_order_tranverse() {
        dynamic_array<T> ret_val;
        _pre_order_tranverse(_root_ptr, ret_val);
        return ret_val;
    }
    dynamic_array<int> get_in_order_tranverse() {
		dynamic_array<T> ret_array;
		_in_order_tranverse(_root_ptr, ret_array);
		return ret_array;
	}
	dynamic_array<int> get_post_order_tranverse() {
		dynamic_array<T> ret_array;
		_post_order_tranverse(_root_ptr, ret_array);
		return ret_array;
	}
	dynamic_array<int> get_level_order_tranverse() {
		dynamic_array<int> ret_array;
		queue<huffman_item*> buffer;

		if(_root_ptr != nullptr) {
			buffer.enqueue(_root_ptr);
			while(!buffer.is_empty()) {
				huffman_item* n_ptr = buffer.dequeue();
				ret_array.push_back(n_ptr->index);
				if(n_ptr->left_ptr != nullptr) buffer.enqueue(n_ptr->left_ptr);
				if(n_ptr->right_ptr != nullptr) buffer.enqueue(n_ptr->right_ptr);
			}
		}
		return ret_array;
	}
};

#endif