/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Uni-R
 * 
 * Created on 7. Februar 2018, 12:09
 */

#include "Node.h"

Node::Node() {
    indegree = outdegree = 0;
    ord = 0;
    visited = living = false;
    duration = 0;
}

/*
Node::Node(const Node& orig) {
}
 */

Node::~Node() {

}




