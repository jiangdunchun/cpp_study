#ifndef __STRING_MATCHER__
#define __STRING_MATCHER__

#include <string>

#ifdef DEBUG_MODE            
#include <iostream>

using namespace std;
#endif

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

        int* nexts = new int[s_len]{-1};

        for(int i = 1; i < s_len; i++) {
            int next = 0;
            for(int j = i-1; j > 0; j--) {
                bool flag = true; 
                for(int k = 0; k < j; k++) {
                    if(s_ptr[k] != s_ptr[k+i-j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    next = j;
                    break;
                }
            }
            nexts[i] = next;
        }

#ifdef DEBUG_MODE   
        cout << "----->kmp match next array of \"" << s_ptr << "\":";    
        for(int i = 0; i < s_len; i++) {
            cout << nexts[i] << " ";
        }
        cout << endl;
#endif

        while(p_index < p_len && s_index < s_len) {
            if(p_ptr[p_index] != s_ptr[s_index]) {
                if(nexts[s_index] < 0) {
                    p_index++;
                }
                else {
                    s_index = nexts[s_index];
                }
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
        
        delete[] nexts;
        return ret_val;
    }
};
#endif