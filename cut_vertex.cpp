#include <iostream>
#include <cassert>
#include <vector>

#include "cut_vertex.hpp"
#include "header.hpp"



Cut_Vertex::Cut_Vertex(Matrix m, int num, Vector& cut_vertecies)
{
    matrix = m;
    GraphVertexNumber = num;
    cut_vertecies = CutVertices();
}



Vector Cut_Vertex::CutVertices()
{
    Vector vertices[GraphVertexNumber + 1];
    for(int i = 0; i <= GraphVertexNumber; i++)
        for(int j = 0; j <= GraphVertexNumber; j++)
            if(matrix[i][j] == 1)
                vertices[i].push_back(j);
    return  {AP(vertices)};
}



Vector Cut_Vertex::AP(Vector adj[])
{
	int disc[GraphVertexNumber + 1] = { 0 };
	int low[GraphVertexNumber + 1];
	bool visited[GraphVertexNumber + 1] = { false };
	bool isAP[GraphVertexNumber + 1] = { false };
	int time = 0, par = -1;
    Vector result;
	
	for (int u = 0; u < GraphVertexNumber + 1; u++)
		if (!visited[u])
			APUtil(adj, u, visited, disc, low,
				time, par, isAP);

	for (int u = 0; u < GraphVertexNumber + 1; u++)
		if (isAP[u] == true)
            result.push_back(u);
    return result;
}



void Cut_Vertex::APUtil(Vector adj[], int u, bool visited[],
			int disc[], int low[], int& time, int parent,
			bool isAP[])
{
	
	int children = 0;

	visited[u] = true;
	disc[u] = low[u] = ++time;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
			APUtil(adj, v, visited, disc, low, time, u, isAP);
			low[u] = std::min(low[u], low[v]);
			if (parent != -1 && low[v] >= disc[u])
				isAP[u] = true;
		}

		else if (v != parent)
			low[u] = std::min(low[u], disc[v]);
	}

	if (parent == -1 && children > 1)
		isAP[u] = true;
}

