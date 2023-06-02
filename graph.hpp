#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "header.hpp"


class Graph {
public:
    Graph();
private:
    void inputGraph();
    void Find_Blocks();
    void Block(bool[] , bool[], int, const bool [], Vector&);
    void cut_vertex_Block();
    void normal_Blocks( bool [],const bool []);
    void check_cv(const Vector);

private:
    Matrix matrix;
    Vector cut_vertecies;
    int GraphVertexNumber;



};




#endif //GRAPH_HPP