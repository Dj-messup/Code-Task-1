#ifndef GRAPHVIS_H
#define GRAPHVIS_H

#include "UnionFind.h"
#include <iostream>

class GraphVis {
public:
    static void display(const UnionFind &unionFind); // i legit know we arent supposed to use static
};
// I know there is better ways to do this but at least its attempted lol
#endif
