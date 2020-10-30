// https://www.cnblogs.com/GNLin0820/p/9668378.html

#ifndef __RB_TREE_HPP__
#define __RB_TREE_HPP__

# include "dynamic_array.hpp"
# include "queue.hpp"

template <class T>
class rb_tree {
private:
	enum rb_color {RED, BLACK};

	struct rb_item {
		T value;

		rb_item* parent_ptr = nullptr;
		rb_item* left_ptr = nullptr;
		rb_item* right_ptr = nullptr;
		rb_color color = RED;
	};

	rb_item* _root_ptr = nullptr;

	rb_item* _find_item(T val, rb_item* n_ptr) {
		if(val == n_ptr->value) return n_ptr;

		if(val < n_ptr->value && n_ptr->left_ptr != nullptr) return _find_item(val, n_ptr->left_ptr);
		else if(val > n_ptr->value && n_ptr->right_ptr != nullptr) return _find_item(val, n_ptr->right_ptr);
		else return nullptr;
	}
	rb_item* _find_last(rb_item* n_ptr) {
		if(n_ptr->left_ptr != nullptr) return _find_last(n_ptr->left_ptr);
		else return n_ptr;
	}
	rb_item* _find_next(rb_item* n_ptr) {
		if(n_ptr->right_ptr != nullptr) return _find_next(n_ptr->right_ptr);
		else return n_ptr;
	}
	void _destroy_item(rb_item* n_ptr) {
		if(n_ptr != nullptr) {
			_destroy_item(n_ptr->left_ptr);
			_destroy_item(n_ptr->right_ptr);
			if(n_ptr->parent_ptr != nullptr) {
				if(n_ptr == n_ptr->parent_ptr->left_ptr) n_ptr->parent_ptr->left_ptr = nullptr;
				else n_ptr->parent_ptr->right_ptr = nullptr;
			}
			else {
				_root_ptr = nullptr;
			}
			delete n_ptr;
			n_ptr = nullptr;
		}
	}
	void _left_rotate(rb_item* n_ptr) {
		rb_item* p_ptr = n_ptr->parent_ptr;

		n_ptr->parent_ptr = p_ptr->parent_ptr;
		if(n_ptr->parent_ptr != nullptr) {
			if(n_ptr->value < n_ptr->parent_ptr->value) n_ptr->parent_ptr->left_ptr = n_ptr;
			else n_ptr->parent_ptr->right_ptr = n_ptr;
		}
		else {
			_root_ptr = n_ptr;
		}

		p_ptr->right_ptr = n_ptr->left_ptr;
		if(p_ptr->right_ptr != nullptr) {
			p_ptr->right_ptr->parent_ptr = p_ptr;
		}

		n_ptr->left_ptr = p_ptr;
		p_ptr->parent_ptr = n_ptr;
	}
	void _right_rotate(rb_item* n_ptr) {
		rb_item* p_ptr = n_ptr->parent_ptr;
		
		n_ptr->parent_ptr = p_ptr->parent_ptr;
		if(n_ptr->parent_ptr != nullptr) {
			if(n_ptr->value < n_ptr->parent_ptr->value) n_ptr->parent_ptr->left_ptr = n_ptr;
			else n_ptr->parent_ptr->right_ptr = n_ptr;
		}
		else {
			_root_ptr = n_ptr;
		}

		p_ptr->left_ptr = n_ptr->right_ptr;
		if(p_ptr->left_ptr != nullptr) {
			p_ptr->left_ptr->parent_ptr = p_ptr;
		}

		n_ptr->right_ptr = p_ptr;
		p_ptr->parent_ptr = n_ptr;
	}
	bool _insert_item(rb_item* n_ptr, rb_item* p_ptr) {
		if(p_ptr->value == n_ptr->value) return false;

		if(n_ptr->value > p_ptr->value) {
			if(p_ptr->right_ptr == nullptr) {
				n_ptr->parent_ptr = p_ptr;
				p_ptr->right_ptr = n_ptr;
				return true;
			}
			else {
				_insert_item(n_ptr, p_ptr->right_ptr);
			}
		}
		else {
			if(p_ptr->left_ptr == nullptr) {
				n_ptr->parent_ptr = p_ptr;
				p_ptr->left_ptr = n_ptr;
				return true;
			}
			else {
				_insert_item(n_ptr, p_ptr->left_ptr);
			}
		}
	}
	void _fix_insert(rb_item* n_ptr) {
		rb_item* p_ptr = n_ptr->parent_ptr;

		if(p_ptr->color == RED) {
			if(p_ptr->parent_ptr != nullptr) {
				rb_item* u_ptr = nullptr;
				if(p_ptr->value < p_ptr->parent_ptr->value) u_ptr = p_ptr->parent_ptr->right_ptr;
				else u_ptr = p_ptr->parent_ptr->left_ptr;

				if(u_ptr != nullptr && u_ptr->color == RED) {
					u_ptr->color = BLACK;
					p_ptr->color = BLACK;
					if(p_ptr->parent_ptr != _root_ptr) {
						p_ptr->parent_ptr->color = RED;
						_fix_insert(p_ptr->parent_ptr);
					}
				}
				else {
					if(n_ptr == p_ptr->left_ptr) {
						if(p_ptr->value < p_ptr->parent_ptr->value) {
							p_ptr->color = BLACK;
							p_ptr->parent_ptr->color = RED;
							_right_rotate(p_ptr);
						}
						else {
							_right_rotate(n_ptr);
							n_ptr->color = BLACK;
							n_ptr->parent_ptr->color = RED;
							_left_rotate(n_ptr);
						}
					}
					else {
						if(p_ptr->value > p_ptr->parent_ptr->value) {
							p_ptr->color = BLACK;
							p_ptr->parent_ptr->color = RED;
							_left_rotate(p_ptr);
						}
						else {
							_left_rotate(n_ptr);
							n_ptr->color = BLACK;
							n_ptr->parent_ptr->color = RED;
							_right_rotate(n_ptr);
						}
					}
				}
			}
		}
	}
	rb_item* _replace_remove(rb_item* n_ptr) {
		if(n_ptr->left_ptr != nullptr && n_ptr->right_ptr != nullptr) {
			rb_item* r_ptr = _find_next(n_ptr->left_ptr);
			T buffer = n_ptr->value;
			n_ptr->value = r_ptr->value;
			r_ptr->value = buffer;

			n_ptr = r_ptr;
			return _replace_remove(n_ptr);
		}
		else if(n_ptr->left_ptr != nullptr || n_ptr->right_ptr != nullptr) {
			if(n_ptr->left_ptr != nullptr) {
				T buffer = n_ptr->value;
				n_ptr->value = n_ptr->left_ptr->value;
				n_ptr->left_ptr->value = buffer;

				n_ptr = n_ptr->left_ptr;
				return _replace_remove(n_ptr);
			}
			else {
				T buffer = n_ptr->value;
				n_ptr->value = n_ptr->right_ptr->value;
				n_ptr->right_ptr->value = buffer;

				n_ptr = n_ptr->right_ptr;
				return _replace_remove(n_ptr);
			}
		}
		else {
			return n_ptr;
		}
	}
	void _fix_remove(rb_item* n_ptr) {
		rb_item* p_ptr = n_ptr->parent_ptr;
		if(p_ptr != nullptr) {
			rb_item* s_ptr = nullptr;
			bool is_left = true;
			if(n_ptr == p_ptr->left_ptr) {
				s_ptr = p_ptr->right_ptr;
				is_left = true;
			}
			else {
				s_ptr = p_ptr->left_ptr;
				is_left = false;
			}

			if(s_ptr->color == BLACK) {
				if(p_ptr->color == RED) {
					if(is_left) {
						p_ptr->color == BLACK;
						_left_rotate(s_ptr);
						return;
					}
					else {
						p_ptr->color == BLACK;
						_right_rotate(s_ptr);
						return;
					}
				}
				if(is_left && s_ptr->right_ptr != nullptr && s_ptr->right_ptr->color == RED) {
					s_ptr->right_ptr->color = BLACK;
					s_ptr->color = p_ptr->color;
					p_ptr->color = BLACK;
					_left_rotate(s_ptr);
					return;
				}
				else if(!is_left && s_ptr->left_ptr != nullptr && s_ptr->left_ptr->color == RED) {
					s_ptr->left_ptr->color = BLACK;
					s_ptr->color = p_ptr->color;
					p_ptr->color = BLACK;
					_right_rotate(s_ptr);
					return;
				}

				if(is_left && s_ptr->right_ptr == nullptr && s_ptr->left_ptr != nullptr && s_ptr->left_ptr->color == RED) {
					s_ptr->left_ptr->color = BLACK;
					s_ptr->color = RED;
					_right_rotate(s_ptr->left_ptr);
					return _fix_remove(n_ptr);
				}
				else if(!is_left && s_ptr->left_ptr == nullptr && s_ptr->right_ptr != nullptr && s_ptr->right_ptr->color == RED) {
					s_ptr->right_ptr->color = BLACK;
					s_ptr->color = RED;
					_left_rotate(s_ptr->right_ptr);
					return _fix_remove(n_ptr);
				}

				if((s_ptr->right_ptr == nullptr || s_ptr->right_ptr->color == BLACK)
					&& (s_ptr->left_ptr == nullptr || s_ptr->left_ptr->color == BLACK)) {
					if(p_ptr->color == RED) {
						p_ptr->color = BLACK;
						s_ptr->color = RED;
						return;
					}
					else {
						s_ptr->color = RED;
						return _fix_remove(p_ptr);
					}
				}
			}
			else if(p_ptr->color == BLACK && s_ptr->color == RED) {
				p_ptr->color = RED;
				s_ptr->color = BLACK;
				if(is_left) _left_rotate(s_ptr);
				else _right_rotate(s_ptr);

				return _fix_remove(n_ptr);
			}
		}
	}
	void _pre_order_tranverse(rb_item* n_ptr, dynamic_array<T>& ret_array){
		if(n_ptr != nullptr) {
			ret_array.push(n_ptr->value);
			_pre_order_tranverse(n_ptr->left_ptr, ret_array);
			_pre_order_tranverse(n_ptr->right_ptr, ret_array);
		}
	}
	void _in_order_tranverse(rb_item* n_ptr, dynamic_array<T>& ret_array){
		if(n_ptr != nullptr) {
			_in_order_tranverse(n_ptr->left_ptr, ret_array);
			ret_array.push(n_ptr->value);
			_in_order_tranverse(n_ptr->right_ptr, ret_array);
		}
	}
	void _post_order_tranverse(rb_item* n_ptr, dynamic_array<T>& ret_array){
		if(n_ptr != nullptr) {
			_post_order_tranverse(n_ptr->left_ptr, ret_array);
			_post_order_tranverse(n_ptr->right_ptr, ret_array);
			ret_array.push(n_ptr->value);
		}
	}

public:
	rb_tree() {	
	}
	~rb_tree() {
		_destroy_item(_root_ptr);
	}

	bool insert(T val) {
		rb_item* n_ptr = new rb_item();
		n_ptr->value = val;

		if(_root_ptr == nullptr) {
			_root_ptr = n_ptr;
			_root_ptr->color = BLACK;
			return true;
		}
		else {
			if(_insert_item(n_ptr, _root_ptr)) {
				_fix_insert(n_ptr);
				return true;
			}
			else {
				delete n_ptr;
				return false;
			}
		}
	}
	bool remove(T val) {
		if(_root_ptr == nullptr) throw "tree is null";

		rb_item* n_ptr = _find_item(val, _root_ptr);
		if(n_ptr == nullptr) return false;

		n_ptr = _replace_remove(n_ptr);
		if(n_ptr->color == BLACK) {
			_fix_remove(n_ptr);
		}
		_destroy_item(n_ptr);
		return true;
	}
	dynamic_array<T> get_pre_order_tranverse() {
		dynamic_array<T> ret_array;
		_pre_order_tranverse(_root_ptr, ret_array);
		return ret_array;
	}
	dynamic_array<T> get_in_order_tranverse() {
		dynamic_array<T> ret_array;
		_in_order_tranverse(_root_ptr, ret_array);
		return ret_array;
	}
	dynamic_array<T> get_post_order_tranverse() {
		dynamic_array<T> ret_array;
		_post_order_tranverse(_root_ptr, ret_array);
		return ret_array;
	}
	dynamic_array<T> get_level_order_tranverse() {
		dynamic_array<T> ret_array;
		queue<rb_item*> buffer;

		if(_root_ptr != nullptr) {
			buffer.enqueue(_root_ptr);
			while(!buffer.is_empty()) {
				rb_item* n_ptr = buffer.dequeue();
				ret_array.push(n_ptr->value);
				if(n_ptr->left_ptr != nullptr) buffer.enqueue(n_ptr->left_ptr);
				if(n_ptr->right_ptr != nullptr) buffer.enqueue(n_ptr->right_ptr);
			}
		}
		return ret_array;
	}
};

#endif