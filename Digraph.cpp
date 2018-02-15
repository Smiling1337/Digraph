/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Digraph.cpp
 * Author: Uni-R
 * 
 * Created on 7. Februar 2018, 12:05
 */

#include "Digraph.h"

Digraph::Digraph() {

}

Digraph::Digraph(const Digraph& orig) {
    name = orig.name;
    noArc = orig.noArc;
    node = orig.node;
    numarcs = orig.numarcs;
    numvertices = orig.numvertices;
}

Digraph::~Digraph() {
    for(int i = 0; i < arc.size(); i++){
        arc[i].clear();
    }
    arc.clear();
    node.clear();
}

void Digraph::InsertNode(int m, string s, int w) {
    Node n;
    vector<int> v;
    n.SetOrd(m);
    n.SetName(s);
    n.SetDuration(w);
    n.SetVisited(false);
    n.SetLiving(false);
    node.push_back(n);
    numvertices++;

    for (int i = 0; i < node.size() - 1; i++) {
        v.push_back(-1);
        arc[i].push_back(-1);
    }
    v.push_back(-1);
    arc.push_back(v);

}

void Digraph::InsertArc(int v, int w) {
    arc[v][w] = 1;
    node[v].SetOutdegree(node[v].GetOutdegree() + 1);
    node[w].SetIndegree(node[w].GetIndegree() + 1);
}

void Digraph::print() {
    for (int i = 0; i < node.size(); i++) {
        cout << node[i].GetOrd() << ": " << node[i].GetName() << " " << node[i].GetDuration() << endl;

        for (int j = 0; j < node.size(); j++) {
            int zahl = arc[i][j];
            if (zahl == 1) {
                cout << i << " " << j << " | ";
            }
        }
        cout << endl;
    }
}

string Digraph::getName() {
    return name;
}

void Digraph::destroy() {
    for (int i = 0; i < arc.size(); i++) {
        arc[i].clear();
    }
    arc.clear();
    node.clear();
}

void Digraph::setName(string s) {
    name = s;
}

int Digraph::nodeBegin() {
    int i = node[0].GetOrd();
    return i;
}

int Digraph::getIndegree(int v) {
    return node[v].GetIndegree();
}

int Digraph::nextVertex(int n) {
    n++;
    if (n < node.size()) {
        return n;
    }
    return -1;
}

int Digraph::FirstArc(int v) {
    for (int i = 0; i < arc.size(); i++) {
        if (arc[v][i] != -1) {
            return i;
        }
    }
}

int Digraph::NextArc(int v, int w) {
    for (int i = w + 1; i < arc.size(); i++) {
        if (arc[v][i] != -1) {
            return i;
        }
    }
    return -1;
}

void Digraph::SetOrd(int v, int index) {
    node[v].SetOrd(index);
}

bool Digraph::visited(int a) {
    for (int i = 0; i < arc.size(); i++) {
        if (arc[a][i] != noArc) {
            if (!node[i].IsLiving()) {
                return false;
            }
        }
    }
    return true;
}

bool Digraph::allvisited() {
    for (int i = 0; i < node.size(); i++) {
        if (!node[i].IsVisited()) {
            return false;
        }
    }
    return true;
}

void Digraph::topsort(int v) {
    queue<int> q; // Schlange für Auswahlkandidaten
    int *indegree = new int[node.size()];
    int sortIndex = 0; // Sortierindex
    int duration = 0;
    //int v = FirstVertex();

    while (v != -1) {
        indegree[v] = node[v].GetIndegree(); // Eingangsgrade initialisieren

        if (indegree[v] == 0)
            q.push(v); // Knoten mit idegree=0 in Schlange aufnehmen
        v = nextVertex(v);
    }

    while (!q.empty()) { // Solange bis Schlange leer
        v = q.front(); // nächster Knoten aus Schlange lesen
        q.pop(); // und aus Schlange entfernen
        node[v].SetOrd(sortIndex); // Sortierindex vom Knoten v setzen
        sortIndex++; // Sortierindex inkrementoieren
        int w = FirstArc(v); // erste von v ausgehende Kante (v,w)
        duration = duration + node[v].GetDuration();

        cout << node[v].GetOrd() << " " << node[v].GetName() << " " << node[v].GetDuration() << endl;
        while (w != -1) { // für alle Nachfolger von v
            indegree[w]--; // Eingangsgrad von w dekrementieren

            if (indegree[w] == 0)
                q.push(w); // Knoten mit idegree=0 in Schlange aufnehmen
            
            w = NextArc(v, w); // nächste Kante (v,w)
        }
    }
    cout << duration << endl;
}

void Digraph::topsort() {
    int tmp;
    for (int i = 0; i < node.size(); i++) {
        if (node[i].GetOrd() == 0) {
            tmp = node[i].GetOrd();
        }
    }
    topsort(tmp);
}

Digraph Digraph::operator=(const Digraph& orig) {
    name = orig.name;
    noArc = orig.noArc;
    node = orig.node;
    numarcs = orig.numarcs;
    numvertices = orig.numvertices;
    return *this;
}

int Digraph::getSize() {
    return node.size();
}

