#include "GraphVis.h"
#include <iostream>

//I know this isnt a graph but I figure I could submit it to you for you to look over to help with creating a graph 
void GraphVis::display(UnionFind &unionFind) {
    std::cout << "\nGraph Visualization:\n";
    std::cout << "-------------------\n";
    
    // Print the edge list representation.
    // Each non-root node is connected to its parent.
    std::cout << "Edge List Representation (each edge is shown as (node, parent)):\n";
    for (int i = 0; i < N; i++) {
        int current = i;
        int parent = unionFind.Find(current);
        if (current != parent) {
            std::cout << "(" << current << ", " << parent << ")\n";
        }
    }
    
    // Print full node -> parent paths (after path compression).
    std::cout << "\nFull Node -> Parent Paths (after path compression):\n";
    for (int i = 0; i < N; i++) {
        std::cout << i << " -> ";
        int current = i;
        int root = unionFind.Find(current);
        while (current != root) {
            std::cout << root << " -> ";
            current = root;
            root = unionFind.Find(current);
        }
        std::cout << root << "\n";
    }
    
    // Print connected components (spanning trees).
    std::cout << "\nConnected Components (Spanning Trees):\n";
    bool printed[N] = {false};
    for (int i = 0; i < N; i++) {
        if (!printed[i]) {
            int compRoot = unionFind.Find(i);
            std::cout << "Component with root " << compRoot << ":\n   Nodes: ";
            for (int j = 0; j < N; j++) {
                if (unionFind.Find(j) == compRoot) {
                    std::cout << j << " ";
                    printed[j] = true;
                }
            }
            std::cout << "\n";
        }
    }
}
