/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Digraph.h
 * Author: Uni-R
 *
 * Created on 7. Februar 2018, 12:05
 */

#ifndef DIGRAPH_H
#define DIGRAPH_H
#include "Node.h"
#include <vector>
#include <iostream>
#include <queue>

class Digraph {
public:
    Digraph();
    Digraph(const Digraph& orig);
    virtual ~Digraph();

    void InsertNode(int m, string s, int w);    // fügt neuen Knoten 'm' mit Namen 's' und Gewicht 'w' ein		
    void InsertArc(int v, int w);               // fügt neue Kante '(v,w)' ein
    void print();
    string getName();
    void setName(string s);
    void destroy();
    int nodeBegin();
    int getIndegree(int v);
    int GetNumarcs() const;
    int nextVertex(int n);
    int FirstArc(int v);
    int NextArc(int v, int w);
    void SetOrd(int v, int index);
    void topsort();
    void topsort(int v);
    bool visited(int a);
    bool allvisited();
    int getSize();
    
    Digraph operator=(const Digraph &orig);

    int GetNumvertices() const {
        return numvertices;
    }

private: 
    string name;
    int noArc = -1;
    int numvertices = 0;                // Anzahl der Knoten eines Digraphen
    int numarcs = 0;                    // Anzahl der Kanten eines Digraphen
    vector<Node> node;                  // repräsentiert Knoten des Digraphen
    vector<vector<int>> arc;            // repräsentiert bewertete Kanten des
                                        // Digraphen (-1=keine Kante)

};

#endif /* DIGRAPH_H */

