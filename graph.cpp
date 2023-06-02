#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>


#include "cut_vertex.hpp"
#include "header.hpp"
#include "graph.hpp"



Graph::Graph()
{
    inputGraph();
    Cut_Vertex c(matrix, GraphVertexNumber,cut_vertecies);
    Find_Blocks();
}




void Graph::Find_Blocks()
{
    bool visited[GraphVertexNumber + 1] = { false };
    bool is_cut_vertex[GraphVertexNumber + 1] = { false };
    for(int i = 0; i< cut_vertecies.size();i++)
    {
        is_cut_vertex[cut_vertecies[i]] = true;
    }
    normal_Blocks(visited, is_cut_vertex);
    cut_vertex_Block();
}

void Graph::normal_Blocks(bool visited[], const bool is_cut_vertex[])
{
        for(int i = 1; i < GraphVertexNumber + 1; i++)
        if(!is_cut_vertex[i] && !visited[i])
        {   
            Vector cv;   
            bool block[GraphVertexNumber + 1] = {false};
            Block(block, visited, i, is_cut_vertex,cv);
            std::cout << "block :";
            for(int j = 0; j < GraphVertexNumber + 1; j++)
            {   
                if(block[j])
                    std::cout  << j << " "; 
            }
            std::cout << std::endl;
            check_cv(cv);
        }
}


void Graph::cut_vertex_Block()
{
    for(int i = 0; i < cut_vertecies.size(); i++)
        for(int j = 0; j < GraphVertexNumber + 1; j++)
            if(matrix[cut_vertecies[i]][j] == 1)
            {
                matrix[cut_vertecies[i]][j] = matrix[j][cut_vertecies[i]] = 0;
                std::cout << "block :" << cut_vertecies[i] << " " << j << std::endl ;
            }
}


void Graph::Block(bool block [], bool visited[], int num,const bool is_cut__vertex[], Vector& cv)
{
    block[num]  = true;
    visited[num] = true;
    for(int i = 1; i <= GraphVertexNumber ; i++)
        if (matrix[num][i] == 1)
        {
            matrix[num][i] = 0;
            matrix[i][num] = 0;
            if(is_cut__vertex[i])
            {
                block[i] = true;
                cv.push_back(i);
            }
            else
                Block(block, visited, i, is_cut__vertex,cv);
        }
    

}


void Graph::check_cv(Vector cv)
{
    for(int i = 0;i < cv.size(); i++)
        for(int j = 0;j < cv.size(); j++)
            matrix[cv[i]][cv[j]] = 0;
}


void Graph::inputGraph()
{
    std::ifstream input ("graph.txt");
    if(input.is_open())
        input >> GraphVertexNumber;
    Vector v;
    for(int i = 0; i <= GraphVertexNumber; i++)
        v.push_back(0);
    for(int i = 0; i <=GraphVertexNumber; i++)
        matrix.push_back(v);
    int l;
    if(input.is_open())
    {
        input >> l;
        int m,n;
        for(int i = 0; i < l; i++)
        {
            input >> m >> n;
            matrix[m][n] = matrix[n][m] = 1;
        }
    }
}
