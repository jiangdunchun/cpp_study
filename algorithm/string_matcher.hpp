#ifndef __STRING_MATCHER__
#define __STRING_MATCHER__

#include <string>

using namespace std;

class string_matcher{
public:
    static int naive_match(string p_ptr, string s_ptr) {
        int ret_val = -1;

        int p_len = p_ptr.length();
        int s_len = s_ptr.length();

        int p_index = 0;
        int s_index = 0;

        while(p_index < p_len) {
            bool flag = true;
            while(s_index < s_len) {
                if((p_index+s_index) >= p_len || s_ptr[s_index] != p_ptr[p_index+s_index]) {
                    flag = false;
                    break;
                }
                s_index++;
            }
            if(flag) {
                ret_val = p_index;
                break;
            }
            p_index++;
        }

        return ret_val;
    }

    static int kmp_match(string p_ptr, string s_ptr){
        int ret_val = -1;

        int p_len = p_ptr.length();
        int s_len = s_ptr.length();

        int p_index = 0;
        int s_index = 0;

        int* p_delta = new int[s_len];
        int* s_next = new int[s_len];

        // @ TODO
        for(int i = 0; i < s_len; i++) {
            p_delta[i] = 1-i;
            s_next[i] = 0;
        }

        while(p_index < p_len && s_index < s_len) {
            if(p_ptr[p_index] != s_ptr[s_index]) {
                p_index += p_delta[s_index];
                s_index = s_next[s_index];
            }
            else {
                if(s_index == (s_len-1)) {
                    ret_val = p_index - s_len + 1;
                    break;
                }
                else {
                    p_index++;
                    s_index++;
                }
            }
        }
        
        delete[] p_delta;
        delete[] s_next;
        return ret_val;
    }
};
#endif