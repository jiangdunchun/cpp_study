#pragma once

#include <vector>
#include <algorithm>

#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000

class sorter
{
public:
	static void bubble_sort(std::vector<int>& vals) {
		for (int i = 1; i < vals.size(); i++) {
			int swap_flag = 0;
			for (int j = 0; j < vals.size() - i; j++) {
				if (vals[j] > vals[j + 1]) {
					std::swap(vals[j + 1], vals[j]);
					swap_flag = 1;
				}
			}
			if (swap_flag == 0) break;
		}
	}

	static void select_sort(std::vector<int>& vals) {
		int index;
		for (int i = 0; i < vals.size(); i++) {
			index = i;
			for (int j = i + 1; j < vals.size(); j++) {
				if (vals[index] > vals[j]) index = j;
			}
			std::swap(vals[i], vals[index]);
		}
	}

	static void insert_sort(std::vector<int>& vals, int delta = 1) {
		for (int i = 0; i < delta; i++) {
			for (int j = i + delta; j < vals.size(); j += delta) {
				int buffer = vals[j];
				for (int k = j - delta; k >= 0; k -= delta){
					if (buffer < vals[k]) {
						vals[k + delta] = vals[k];
						if (k - delta < 0) vals[k] = buffer;
					}
					else {
						vals[k + delta] = buffer;
						break;
					}
				}
			}
		}
	}

	static void shell_sort(std::vector<int>& vals){
		for (int i = vals.size()/2; i > 0; i = i/2) {
			insert_sort(vals, i);
		}
	}

	static void merge_sort(std::vector<int>& vals, int start = 0, int len = -1) {
		if (len == -1) len = vals.size();

		if (len == 2) {
			if (vals[start + 1] < vals[start]) std::swap(vals[start + 1], vals[start]);
		}
		else if (len > 2) {
			merge_sort(vals, start, len / 2);
			merge_sort(vals, start + len / 2, len - len / 2);

			std::vector<int> buffer_left;
			std::vector<int> buffer_right;
			buffer_left.assign(&vals[start], &vals[start + len / 2 - 1] + 1);
			buffer_right.assign(&vals[start + len / 2], &vals[start + len - 1] + 1);

			for (int i = 0; i < len; i++) {
				if (!buffer_left.empty() && !buffer_right.empty()) {
					if (buffer_left[0] < buffer_right[0]) {
						vals[start + i] = buffer_left[0];
						buffer_left.erase(buffer_left.begin());
					}
					else {
						vals[start + i] = buffer_right[0];
						buffer_right.erase(buffer_right.begin());
					}
				}
				else if (buffer_left.empty()) {
					vals[start + i] = buffer_right[0];
					buffer_right.erase(buffer_right.begin());
				}
				else if (buffer_right.empty()) {
					vals[start + i] = buffer_left[0];
					buffer_left.erase(buffer_left.begin());
				}
			}
		}
		
	}

	static void quick_sort(std::vector<int>& vals, int start = 0, int len = -1){
		if (len == -1) len = vals.size();

		if (len < 1) return;

		int p = start, 
			flag = 0, 
			buffer = vals[start], 
			i = start, 
			j = start + len -1;

		while ( i != j) {
			if (flag == 0){
				if (vals[j] <= buffer) {
					vals[p] = vals[j];
					p = j;
					flag = 1;
				}
				else {
					j--;
				}
			}
			else {
				if (vals[i] > buffer) {
					vals[p] = vals[i];
					p = i;
					flag = 0;
				}
				else {
					i++;
				}
			}
		}

		vals[p] = buffer;
		quick_sort(vals, start, p - start);
		quick_sort(vals, p + 1, len - (p - start) - 1);
	}

	static void count_sort(std::vector<int>& vals) {
		int min = INT_MAX, max = INT_MIN;

		for (int i = 0; i < vals.size(); i++) {
			min = min < vals[i] ? min : vals[i];
			max = max > vals[i] ? max : vals[i];
		}

		int* buffer = new int[max - min + 1]{0};
		for (int i = 0; i < vals.size(); i++) {
			buffer[vals[i] - min] = buffer[vals[i] - min] + 1;
		}

		int index = 0;
		for (int i = 0; i < max - min + 1; i++) {
			for (int j = 0; j < buffer[i]; j++) {
				vals[index] = min + i;
				index++;
			}
		}
		delete[] buffer;
	}
};