#pragma once

template <class T_key, class T_value>
class rb_tree {
private:	
	struct rb_item {
		rb_item* parent_ptr = nullptr;
		rb_item* left_ptr = nullptr;
		rb_item* right_ptr = nullptr;
		bool red = true;
		T_key key;
		T_value value;
	};

	rb_item* root_ptr = nullptr;

	bool _is_left(rb_item* n_ptr) {
		if(n_ptr->parent_ptr != nullptr) {
			if(n_ptr->parent_ptr->left_ptr == n_ptr) return true;
			else return false;
		}
		throw "this item don't have parent";
	}

	void _rotate(rb_item* n_ptr) {
		rb_item* p_ptr = n_ptr->parent_ptr;
		if(p_ptr != nullptr) {
			if(_is_left(n_ptr)) {
				p_ptr->left_ptr = n_ptr->right_ptr;
				if(p_ptr->left_ptr != nullptr) p_ptr->left_ptr->parent_ptr = p_ptr;
				n_ptr->right_ptr = p_ptr;
			}
			else {
				p_ptr->right_ptr = n_ptr->left_ptr;
				if(p_ptr->right_ptr != nullptr) p_ptr->right_ptr->parent_ptr = p_ptr;
				n_ptr->left_ptr = p_ptr;
			}
			n_ptr->parent_ptr = p_ptr->parent_ptr;
			if(n_ptr->parent_ptr == nullptr) root_ptr = n_ptr;
			else {
				if(n_ptr->key < n_ptr->parent_ptr->key) n_ptr->parent_ptr->left_ptr = n_ptr;
				else n_ptr->parent_ptr->right_ptr = n_ptr;
			}
			p_ptr->parent_ptr = n_ptr;
		}
	}

	rb_item* _get_brother(rb_item* n_ptr){
		rb_item* b_ptr;
		if(n_ptr->parent_ptr != nullptr) {
			if (_is_left(n_ptr)) b_ptr = n_ptr->parent_ptr->right_ptr;
			else b_ptr = n_ptr->parent_ptr->left_ptr;
		}
		return b_ptr;
	}

	void _delete_item(rb_item* item_ptr) {
		if(item_ptr != nullptr) {
			_delete_item(item_ptr->left_ptr);
			_delete_item(item_ptr->right_ptr);
			if(item_ptr->parent_ptr != nullptr) {
				if(_is_left(item_ptr)) item_ptr->parent_ptr->left_ptr = nullptr;
				else item_ptr->parent_ptr->right_ptr = nullptr;
			}
			delete item_ptr;
			item_ptr = nullptr;
		}
	}

	bool _insert_item(rb_item* item_ptr, rb_item* n_ptr, rb_item* p_ptr) {
		if(n_ptr == nullptr) {
			if(p_ptr != nullptr) {
				if(item_ptr->key < p_ptr->key) {
					p_ptr->left_ptr = item_ptr;
				}
				else {
					p_ptr->right_ptr = item_ptr;
				}
			}
			if (root_ptr == nullptr) {
				root_ptr = item_ptr;
				root_ptr->red = false;
			}
			item_ptr->parent_ptr = p_ptr;
			return true;
		}
		else {
			if(item_ptr->key == n_ptr->key) return false;
			else if(item_ptr->key < n_ptr->key) {
				return _insert_item(item_ptr, n_ptr->left_ptr, n_ptr);
			}
			else {
				return _insert_item(item_ptr, n_ptr->right_ptr, n_ptr);
			}
		}
	}

	int _remove_item(T_key key, rb_item* n_ptr, rb_item* p_ptr, int left) {
		return 0;
	}

	void _fix(rb_item* n_ptr) {
		if(n_ptr->parent_ptr != nullptr && n_ptr->parent_ptr->red == true) {
			rb_item* u_ptr = _get_brother(n_ptr->parent_ptr);
			if(u_ptr != nullptr && u_ptr->red == true) {
				u_ptr->red = false;
				n_ptr->parent_ptr->red = false;

				if(n_ptr->parent_ptr->parent_ptr != root_ptr) n_ptr->parent_ptr->parent_ptr->red = true;

				_fix(n_ptr->parent_ptr->parent_ptr);
			}
			else {
				if(_is_left(n_ptr) == _is_left(n_ptr->parent_ptr)) {
					n_ptr->parent_ptr->red = false;
					n_ptr->parent_ptr->parent_ptr->red = true;
					_rotate(n_ptr->parent_ptr);
				}
				else {
					_rotate(n_ptr);
					n_ptr->red = false;
					n_ptr->parent_ptr->red = true;
					_rotate(n_ptr);
				}
			}
		}
	}
	
public:
	rb_tree() {	
	}

	~rb_tree() {
		_delete_item(root_ptr);
	}

	bool insert(T_key key, T_value value) {
		rb_item* item_ptr = new rb_item();
		item_ptr->key = key;
		item_ptr->value = value;

		if(_insert_item(item_ptr, root_ptr, nullptr, 0)) {
			_fix(item_ptr);
			return true;
		}
		else {
			delete item_ptr;
			return false;
		}
	}

	int remove(T_key key) {
		return 0;
	}
};