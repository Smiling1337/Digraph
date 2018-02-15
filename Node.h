/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Uni-R
 *
 * Created on 7. Februar 2018, 12:09
 */

#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
public:
    Node();
    //Node(const Node& orig);
    virtual ~Node();
    int GetDuration() {
        return duration;
    }
    
    int GetIndegree() const {
        return indegree;
    }

    bool IsLiving() {
        return living;
    }

    string GetName()  {
        return name;
    }

    int GetOrd() {
        return ord;
    }
   
    int GetOutdegree() const {
        return outdegree;
    }

    bool IsVisited() {
        return visited;
    }

    void SetDuration(int duration) {
        this->duration = duration;
    }
    
    void SetIndegree(int indegree) {
        this->indegree = indegree;
    }

    void SetLiving(bool living) {
        this->living = living;
    }

    void SetName(string name) {
        this->name = name;
    }

    void SetOrd(int ord) {
        this->ord = ord;
    }

    
    void SetOutdegree(int outdegree) {
        this->outdegree = outdegree;
    }
     

    void SetVisited(bool visited) {
        this->visited = visited;
    }



private:

    string name; // Name
    int duration; // Zeit(dauer)
    int indegree; // Eingangsgrad
    int outdegree; // Ausgangsgrad
    int ord; // Ordnungszahl des Knotens
    bool visited; // Knoten-"besucht"-Marke
    bool living; // Knoten existiert

};

#endif /* NODE_H */

