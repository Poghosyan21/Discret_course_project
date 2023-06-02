#ifndef CUT_VERTEX
#define CUT_VERTEX

#include "header.hpp"

class Cut_Vertex
{
public:
    Cut_Vertex(Matrix, int, Vector&);


private:
    Vector CutVertices();
    Vector AP(Vector []);
    void APUtil(Vector [], int, bool [], int [],int  [], int&, int, bool []);

private:
    Matrix matrix;
    Vector GraphCutVertices;
    int GraphVertexNumber;
};




#endif  //CUT_VERTEX