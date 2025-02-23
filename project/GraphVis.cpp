//For a known (you provide a sequential list of at least 11 nodes and Union(p, q) sequence) set of nodes provide a graph showing the connected final component with path compression.
#include "GraphVis.h"
#include <iostream>

void GraphVis::display(const UnionFind &unionFind) {
    std::cout << "\nGraph Visualization:\n";
    std::cout << "-------------------\n";
    
    // Print all node connections
    std::cout << "Node -> Parent Connections:\n";
    for (int i = 0; i < N; i++) {
        std::cout << i << " -> ";
        
        int current = i;
        int root = unionFind.Find(i);  // Find the root for the current node
        
        while (current != root) {
            std::cout << root << " -> ";
            current = root;
            root = unionFind.Find(current);  // Get the updated root
        }
        std::cout << root << "\n";
    }
    
    // Print summary
    std::cout << "\nConnected Components:\n";
    
    bool printed[N] = {false};  // Track what we've printed
    
    for (int i = 0; i < N; i++) {
        if (!printed[i]) {
            int root = unionFind.Find(i);  // Find root for this node
            std::cout << "Component with root " << root << ": ";
            
            // Find all nodes in this component
            for (int j = 0; j < N; j++) {
                if (unionFind.Find(j) == root) {
                    std::cout << j << " ";
                    printed[j] = true;
                }
            }
            std::cout << "\n";
        }
    }
}
