#include<iostream>
#include "Unionfind.h"

using namespace std;

int main() {
    Unionfind uf;
    
    // Create some nodes
    Node a, b, c, d;
    
    // Initialize nodes as individual sets
    uf.makeSet(&a);
    uf.makeSet(&b);
    uf.makeSet(&c);
    uf.makeSet(&d);
    
    // Check initial parent of each node
    cout << "Initial parents:\n";
    cout << "Parent of a: " << uf.findSet(&a) << endl;
    cout << "Parent of b: " << uf.findSet(&b) << endl;
    cout << "Parent of c: " << uf.findSet(&c) << endl;
    cout << "Parent of d: " << uf.findSet(&d) << endl;
    
    // Perform unions
    uf.Union(&a, &b);
    uf.Union(&c, &d);
    uf.Union(&a, &c);
    
    // Check final parent and size of each set
    cout << "\nAfter unions:\n";
    cout << "Parent of a: " << uf.findSet(&a) << ", Size: " << uf.findSet(&a)->size << endl;
    cout << "Parent of b: " << uf.findSet(&b) << ", Size: " << uf.findSet(&b)->size << endl;
    cout << "Parent of c: " << uf.findSet(&c) << ", Size: " << uf.findSet(&c)->size << endl;
    cout << "Parent of d: " << uf.findSet(&d) << ", Size: " << uf.findSet(&d)->size << endl;

    return 0;
}



