#ifndef __GRAGH_HPP__
#define __GRAGH_HPP__

#include "dynamic_array.hpp"

template<class T_vertex, class T_edge>
class graph {
public:
    graph() {}
    ~graph() {}

    virtual int get_vertices_num() = 0;
    virtual int push_vertex(T_vertex v_value) = 0;
    virtual void push_edge(int s_index, int d_index, T_edge e_value) = 0;
    virtual T_vertex& get_vertex(int v_index) = 0;
    virtual T_vertex remove_vertex(int v_index) = 0;
};

template<class T_vertex, class T_edge>
class adjacency_list_graph: public graph<T_vertex, T_edge> {
private:
    struct vertex;
    struct edge;
    struct vertex{
        T_vertex value;
        dynamic_array<edge*> edges_ptr;
    };
    struct edge{
        T_edge value;
        vertex* destination_ptr;
    };
    
    dynamic_array<vertex*> _vertices_ptr;
public:
    adjacency_list_graph() {

    }
    ~adjacency_list_graph() {
        for(int i = 0; i < _vertices_ptr.size(); i++) {
            for(int j = 0; j < _vertices_ptr.at(i)->edges_ptr.size(); j++) {
                if(_vertices_ptr.at(i)->edges_ptr.at(j) != nullptr) delete _vertices_ptr.at(i)->edges_ptr.at(j);
            }
            delete _vertices_ptr.at(i);
        }
    }

    int get_vertices_num() {
        return _vertices_ptr.size();
    }
    int push_vertex(T_vertex v_value) {
        vertex* n_vertex_ptr = new vertex;
        n_vertex_ptr->value = v_value;

        _vertices_ptr.push_back(n_vertex_ptr);
        return _vertices_ptr.size()-1;
    }
    void push_edge(int s_index, int d_index, T_edge e_value) {
        if(s_index >= _vertices_ptr.size() || d_index >= _vertices_ptr.size()) throw "out of bounds";

        edge* n_edge_ptr = new edge;
        n_edge_ptr->destination_ptr = _vertices_ptr.at(d_index);
        n_edge_ptr->value = e_value;

        _vertices_ptr.at(s_index)->edges_ptr.push_back(n_edge_ptr);
    }
    T_vertex& get_vertex(int v_index) {
        if(v_index >= _vertices_ptr.size()) throw "out of bounds";

        return _vertices_ptr.at(v_index)->value;
    }
    T_vertex remove_vertex(int v_index) {
        if(v_index >= _vertices_ptr.size()) throw "out of bounds";
        
        for(int i = 0; i < _vertices_ptr.at(v_index)->edges_ptr.size(); i++) {
            if(_vertices_ptr.at(v_index)->edges_ptr.at(i) != nullptr) delete _vertices_ptr.at(v_index)->edges_ptr.at(i);
        }
        T_vertex val = _vertices_ptr.at(v_index)->value;
        delete _vertices_ptr.at(v_index);
        return val;
    }
};

#endif