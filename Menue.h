/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menue.h
 * Author: Uni-R
 *
 * Created on 7. Februar 2018, 15:05
 */

#ifndef Menue_H
#define Menue_H
#include "Digraph.h"
#include <queue>
#include <vector>

class Menue {
public:
    Menue();
    //Menue(const Menue& orig);
    virtual ~Menue();
    void print();
    void aktuellprint();
    void neuesProjekt();
    int findProject(string s);
    void loescheProjekt();
    void wechseln();
    void test();
    void printSort();
    void kopieren();
    void bearbeiten();
    void addKnoten();
    void addKante();
    void deleteKnoten();
    void deleteKante();


private:

    int project;
    vector<Digraph> projects;

};

#endif /* Menue_H */

