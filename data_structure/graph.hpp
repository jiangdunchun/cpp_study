#ifndef __GRAGH_HPP__
#define __GRAGH_HPP__

template<class T>
class graph {
private:
    struct node_item {
        T value;
        edge_item* first_edge_ptr = nullptr;
    };
    struct edge_item {

    };

public:

};

#endif