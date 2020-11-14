#ifndef __GRAGH_HPP__
#define __GRAGH_HPP__

#include "dynamic_array.hpp"
#include "queue.hpp"
#include "heap.hpp"

template<class T_vertex, class T_edge>
class graph {
protected:
    int _vertices_capacity;
    int _vertices_size = 0;
    int _edges_size = 0;

public:
    graph(int vertices_capacity) {
        if(vertices_capacity < 1) throw "vertices capacity must > 0";

        _vertices_capacity = vertices_capacity;
    }
    virtual ~graph() {}

    bool is_empty() {
        return _vertices_size == 0;
    }
    int vertices_capacity() {
        return _vertices_capacity;
    }
    int vertices_size() {
        return _vertices_size;
    }
    int edges_size() {
        return _edges_size;
    }
    virtual T_vertex& get_vertex(int v_index) = 0;
    virtual int edges_size_of_vertex(int v_index) = 0;
    virtual T_edge& get_edge(int v_index, int e_index) = 0;
    virtual int get_neighbor(int v_index, int e_index) = 0;
    virtual bool push_vertex(T_vertex v_value) = 0;
    virtual bool push_edge(int s_index, int d_index, T_edge e_value) = 0;
    virtual bool remove_vertex(int v_index) = 0;
    virtual bool remove_edge(int s_index, int d_index) = 0;
    virtual dynamic_array<T_vertex> get_deepth_first_tranverse() = 0;
    virtual dynamic_array<T_vertex> get_breadth_first_tranverse() = 0;
    // virtual graph<T_vertex, T_edge> get_min_tree_prim() = 0;
    // virtual graph<T_vertex, T_edge> get_min_tree_kruskal() = 0;
    virtual dynamic_array<T_edge> get_min_distance(int v_index) = 0; 
};

template<class T_vertex, class T_edge>
class adjacency_list_graph: public graph<T_vertex, T_edge> {
private:
    struct edge_item {
        int v_index;
        int e_index;
        T_edge e_value;
    };
    struct edge{
        T_edge value;
        int dest_vertex_index;
        edge* next_edge_ptr = nullptr;
    };
    struct vertex{
        T_vertex value;
        edge* first_edge_ptr = nullptr;
    };

    vertex* _vertices_array;

    static bool _min_compare_func(edge_item a, edge_item b) {
        return a.e_value<b.e_value;
    }
    void _deepth_first_tranverse(int v_index, bool* is_visted_array, dynamic_array<T_vertex>& ret_array) {
        if(!is_visted_array[v_index]) {
            is_visted_array[v_index] = true;
            ret_array.push_back(_vertices_array[v_index].value);

            edge* now_ptr = _vertices_array[v_index].first_edge_ptr;

            while(now_ptr != nullptr) {
                _deepth_first_tranverse(now_ptr->dest_vertex_index, is_visted_array, ret_array);

                now_ptr = now_ptr->next_edge_ptr;
            }
        }
    }

public:
    adjacency_list_graph(int vertices_capacity):graph<T_vertex, T_edge>(vertices_capacity) {
        _vertices_array = new vertex[this->_vertices_capacity];
    }
    ~adjacency_list_graph() {
        for(int i = 0; i < this->_vertices_size; i++) {
            edge* now_ptr = _vertices_array[i].first_edge_ptr;
            edge* next_ptr = nullptr;

            while(now_ptr != nullptr) {
                next_ptr = now_ptr->next_edge_ptr;
                delete now_ptr;
                now_ptr = next_ptr;
            }
        }
        delete[] _vertices_array;
    }

    T_vertex& get_vertex(int v_index) {
        if(v_index >= this->_vertices_size || v_index < 0) throw "out of vertex bounds";

        return _vertices_array[v_index].value;
    }
    int edges_size_of_vertex(int v_index) {
        if(v_index >= this->_vertices_size || v_index < 0) throw "out of vertex bounds";

        int i = 0;
        edge* now_ptr = _vertices_array[v_index].first_edge_ptr;

        while(now_ptr != nullptr) {
            now_ptr = now_ptr->next_edge_ptr;
            i++;
        }
        return i;
    }
    T_edge& get_edge(int v_index, int e_index) {
        if(v_index >= this->_vertices_size || v_index < 0) throw "out of vertex bounds";

        int i = 0;
        edge* now_ptr = _vertices_array[v_index].first_edge_ptr;

        while(i < e_index && now_ptr != nullptr) {
            now_ptr = now_ptr->next_edge_ptr;
            i++;
        }
        
        if(now_ptr == nullptr) throw "out of edge bounds";

        return now_ptr->value;
    }
    int get_neighbor(int v_index, int e_index) {
        if(v_index >= this->_vertices_size || v_index < 0) throw "out of vertex bounds";

        int i = 0;
        edge* now_ptr = _vertices_array[v_index].first_edge_ptr;

        while(i < e_index && now_ptr != nullptr) {
            now_ptr = now_ptr->next_edge_ptr;
            i++;
        }

        if(now_ptr == nullptr) throw "out of edge bounds";

        return now_ptr->dest_vertex_index;
    }
    bool push_vertex(T_vertex v_value) {
        if(this->_vertices_size == this->_vertices_capacity) return false;

        _vertices_array[this->_vertices_size].value = v_value;
        this->_vertices_size++;

        return true;
    }
    bool push_edge(int s_index, int d_index, T_edge e_value) {
        if(s_index >= this->_vertices_size || s_index < 0 || d_index >= this->_vertices_size || d_index < 0) throw "out of bounds";

        edge* last_ptr = nullptr;
        edge* now_ptr = _vertices_array[s_index].first_edge_ptr;

        while(now_ptr != nullptr) {
            if(now_ptr->dest_vertex_index == d_index) return false;

            last_ptr = now_ptr;
            now_ptr = now_ptr->next_edge_ptr;
        }

        edge* new_ptr = new edge;
        new_ptr->value = e_value;
        new_ptr->dest_vertex_index = d_index;
        
        if(last_ptr == nullptr) _vertices_array[s_index].first_edge_ptr = new_ptr;
        else last_ptr->next_edge_ptr = new_ptr;

        this->_edges_size++;

        return true;
    }
    bool remove_vertex(int v_index) {
        if(v_index >= this->_vertices_size || v_index < 0) throw "out of vertex bounds";

        edge* last_ptr = nullptr;
        edge* now_ptr = _vertices_array[v_index].first_edge_ptr;
        edge* next_ptr = nullptr;

        while(now_ptr != nullptr) {
            next_ptr = now_ptr->next_edge_ptr;
            delete now_ptr;
            now_ptr = next_ptr;
            this->_edges_size--;
        }

        for(int i = v_index+1; i < this->_vertices_size; i++) {
            _vertices_array[i-1] = _vertices_array[i];
        }
        this->_vertices_size--;

        for(int i = 0; i < this->_vertices_size; i++) {
            now_ptr = _vertices_array[i].first_edge_ptr;

            while(now_ptr != nullptr) {
                next_ptr = now_ptr->next_edge_ptr;

                if(now_ptr->dest_vertex_index == v_index) {
                    if(last_ptr == nullptr) _vertices_array[i].first_edge_ptr = now_ptr->next_edge_ptr;
                    else last_ptr->next_edge_ptr = next_ptr;

                    delete now_ptr;
                    this->_edges_size--;
                }
                else {
                    if(now_ptr->dest_vertex_index > v_index) now_ptr->dest_vertex_index--;

                    last_ptr = now_ptr;
                }
                
                now_ptr = next_ptr;
            }
            last_ptr = nullptr;
        }

        return true;
    }
    bool remove_edge(int s_index, int d_index) {
        if(s_index >= this->_vertices_size || s_index < 0 || d_index >= this->_vertices_size || d_index < 0) throw "out of bounds";

        edge* last_ptr = nullptr;
        edge* now_ptr = _vertices_array[s_index].first_edge_ptr;

        while(now_ptr != nullptr) {
            if(now_ptr->dest_vertex_index == d_index) {
                if(last_ptr == nullptr) _vertices_array[s_index].first_edge_ptr = now_ptr->next_edge_ptr;
                else last_ptr->next_edge_ptr = now_ptr->next_edge_ptr;

                delete now_ptr;
                this->_edges_size--;
                return true;
            }
            last_ptr = now_ptr;
            now_ptr = now_ptr->next_edge_ptr;
        }

        return false;
    }
    dynamic_array<T_vertex> get_deepth_first_tranverse() {
        if(this->_vertices_size == 0) throw "graph is empty";

        bool* is_visted_array = new bool[this->_vertices_size]{false};
        dynamic_array<T_vertex> ret_array;
        _deepth_first_tranverse(0, is_visted_array, ret_array);
        return ret_array;
    }
    dynamic_array<T_vertex> get_breadth_first_tranverse() {
        if(this->_vertices_size == 0) throw "graph is empty";

        bool* is_visted_array = new bool[this->_vertices_size]{false};
        dynamic_array<T_vertex> ret_array;
        queue<int> buffer;

        buffer.enqueue(0);
        is_visted_array[0] = true;
        while(!buffer.is_empty()) {
            int now_index = buffer.dequeue();
            ret_array.push_back(_vertices_array[now_index].value);

            edge* now_ptr = _vertices_array[now_index].first_edge_ptr;

            while(now_ptr != nullptr) {
                if(!is_visted_array[now_ptr->dest_vertex_index]) {
                    is_visted_array[now_ptr->dest_vertex_index] = true;
                    buffer.enqueue(now_ptr->dest_vertex_index);
                }
                now_ptr = now_ptr->next_edge_ptr;
            }

            
        }

        return ret_array;
    }
    // @TODO: bug here
    adjacency_list_graph<T_vertex, T_edge> get_min_tree_prim() {
        adjacency_list_graph<T_vertex, T_edge> ret_graph(this->_vertices_capacity);
        for(int i = 0; i < this->_vertices_size; i++) {
            ret_graph.push_vertex(_vertices_array[i].value);
        }

        bool* is_visted_array = new bool[this->_vertices_size]{false};
        heap<edge_item> buffer(this->_edges_size, _min_compare_func);

        is_visted_array[0] = true;
        for(int i = 0; i < edges_size_of_vertex(0); i++) {
            edge_item new_edge_item;
            new_edge_item.v_index = 0;
            new_edge_item.e_index = i;
            new_edge_item.e_value = get_edge(new_edge_item.v_index, new_edge_item.e_index);
            buffer.push(new_edge_item);
        }
        
        while(!buffer.is_empty()) {
            edge_item now_edge_item = buffer.pop();
            int dest_index = get_neighbor(now_edge_item.v_index, now_edge_item.e_index);
            if(!is_visted_array[dest_index]) {
                ret_graph.push_edge(now_edge_item.v_index, dest_index, get_edge(now_edge_item.v_index, now_edge_item.e_index));
                is_visted_array[dest_index] = true;

                for(int i = 0; i < edges_size_of_vertex(dest_index); i++) {
                    edge_item new_edge_item;
                    new_edge_item.v_index = dest_index;
                    new_edge_item.e_index = i;
                    new_edge_item.e_value = get_edge(new_edge_item.v_index, new_edge_item.e_index);
                    buffer.push(new_edge_item);
                }
            }
        }
        
        return ret_graph;
    }
    // @TODO: bug here
    adjacency_list_graph<T_vertex, T_edge> get_min_tree_kruskal() {
        adjacency_list_graph<T_vertex, T_edge> ret_graph(this->_vertices_capacity);
        heap<edge_item> buffer(this->_edges_size, _min_compare_func);

        for(int i = 0; i < this->_vertices_size; i++) {
            ret_graph.push_vertex(_vertices_array[i].value);

            for(int j = 0; j < edges_size_of_vertex(i); j++) {
                edge_item new_edge_item;
                new_edge_item.v_index = i;
                new_edge_item.e_index = j;
                new_edge_item.e_value = get_edge(new_edge_item.v_index, new_edge_item.e_index);
                buffer.push(new_edge_item);
            }
        }

        bool* is_visted_array = new bool[this->_vertices_size]{false};

        while(!buffer.is_empty()) {
            edge_item now_edge_item = buffer.pop();
            int dest_index = get_neighbor(now_edge_item.v_index, now_edge_item.e_index);

            if(is_visted_array[now_edge_item.v_index] == false || is_visted_array[dest_index] == false) {
                ret_graph.push_edge(now_edge_item.v_index, dest_index, get_edge(now_edge_item.v_index, now_edge_item.e_index));
                is_visted_array[now_edge_item.v_index] = true;
                is_visted_array[dest_index] = true;
            }
        }

        return ret_graph;
    }
    dynamic_array<T_edge> get_min_distance(int v_index) {
        dynamic_array<T_edge> ret_array;



        return ret_array;
    }
};

#endif