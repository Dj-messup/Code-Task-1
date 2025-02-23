#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind() {
    id = new int[N];
    sz = new int[N];

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete [] id;
    delete [] sz;
}

void UnionFind::Union(int p, int q) {//Merge two components represented by elements p and q.
    int i = 0, j = 0;

    //Find roots for p and q
    i = Find(q);
    j = Find(p);

    if (i == j) return; //p and q share a root - i.e. they are connected
    
    if (sz[i] < sz[j]) { //merge weighted
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i; 
        sz[i] += sz[j];
    }
}
int UnionFind::Find(int p) const {  //Find the component identifier of element p. //Find the root
    int i = 0;
    //compress trees when nodes are touched
    for (i = p; i != id[i]; i = id[i])
        id[i] = id[id[i]]; 
    return id[i];
}

bool UnionFind::Connected(int p, int q) { //Check if elements p and q are in the same component.
    //If p and q share the same root they are in the same component
    return (Find(p) == Find(q));
}

//Displays the id and sz arrays
void UnionFind::Print() {
    std::cout << "ID: {";
    for (int i = 0; i < N; i++) {
        std::cout << id[i];
        if (i < N - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";    

    std::cout << "SZ: {";
    for (int i = 0; i < N; i++) {
        std::cout << sz[i];
        if (i < N - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";
} 
