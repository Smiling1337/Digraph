/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menue.cpp
 * Author: Uni-R
 * 
 * Created on 7. Februar 2018, 15:05
 */

#include "Menue.h"

Menue::Menue() {
}

/*
Menue::Menue(const Menue& orig) {
}*/

Menue::~Menue() {
}

void Menue::print() {
    for (int i = 0; i < projects.size(); i++) {
        cout << projects[i].getName() << endl;
    }
}

void Menue::aktuellprint() {
    projects[project].print();
}

void Menue::neuesProjekt() {
    string s;
    cout << "Wie soll das Project heißen?" << endl;
    cin >> s;
    Digraph D;
    projects.push_back(D);
    projects[projects.size() - 1].setName(s);
    project = findProject(s);
    cout << "Neues Project erstellt! ID: " << project << endl;
}

int Menue::findProject(string s) {

    for (int i = 0; i < projects.size(); i++) {
        if (s == projects[i].getName()) {
            return i;
        }

    }
}

void Menue::loescheProjekt() {
    projects[project].destroy();
    projects.erase(projects.begin() + project);
    cout << "Project gelöscht" << endl;
}

void Menue::wechseln() {
    string s;
    cout << "In welches Project wollen Sie wechseln? Geben Sie den Namen an!" << endl;
    cin >> s;
    project = findProject(s);
    cout << "Project gewechselt! ID: " << project << endl;
}

void Menue::test() {
    // Graph aufbauen *************************************************

    // Knoten:
    projects[project].InsertNode(0, "Besprechen", 4);
    projects[project].InsertNode(1, "Zeichnen", 14);
    projects[project].InsertNode(2, "Einmessen", 1);
    projects[project].InsertNode(3, "Genehmigen", 21);
    projects[project].InsertNode(4, "Angebot Fundament", 7);
    projects[project].InsertNode(5, "Angebot Rohbau", 14);
    projects[project].InsertNode(6, "Fundament", 5);
    projects[project].InsertNode(7, "Rohbau", 20);

    // Kanten:
    projects[project].InsertArc(0, 1);

    projects[project].InsertArc(1, 2);
    projects[project].InsertArc(1, 3);
    projects[project].InsertArc(1, 4);
    projects[project].InsertArc(1, 5);

    projects[project].InsertArc(2, 6);
    projects[project].InsertArc(3, 6);
    projects[project].InsertArc(4, 6);
    projects[project].InsertArc(5, 7);

    projects[project].InsertArc(6, 7);
}

void Menue::printSort() {
    projects[project].topsort();
}

void Menue::kopieren() {
    string s;
    cout << "Wie soll das Project heißen?" << endl;
    cin >> s;
    Digraph D = projects[project];
    projects.push_back(D);
    projects[projects.size() - 1].setName(s);
    project = findProject(s);
    cout << "Project kopiert! ID: " << project << endl;
}

void Menue::bearbeiten() {
    int c = -1;

    while (c != 9) {

        cout << "\nMenue" << endl;
        cout << " 1: Knoten hinzufügen" << endl;
        cout << " 2: Kante hinzufügen" << endl;
        cout << " 3: Knoten löschen" << endl;
        cout << " 4: Kante löschen" << endl;
        cout << " 9: ENDE" << endl;

        cin >> c;

        switch (c) {

            case 1: 
                // hier ergänzen
                addKnoten();
                break;

            case 2: 
                // hier ergänzen
                addKante();
                break;

            case 3: 
                // hier ergänzen
                deleteKnoten();
                break;

            case 4:
                // hier ergänzen
                deleteKante();
                break;

            case 9: // Ende
                return;
                break;
        }
    }
}

void Menue::addKnoten() {
    string s;
    int c;
    cout << "Welchen Knoten wollen Sie zum Graphen hinzufügen?" << endl;
    aktuellprint();
    cout << "Name des Vorgangs:" << endl;
    cin >> s;
    cout << "Wie lange dauert der Vorgang?" << endl;
    cin >> c;
    projects[project].InsertNode(projects[project].getSize() + 1, s, c);
    bearbeiten();
}

void Menue::addKante() {
    int start, ende;
    cout << "Zu welchem Knoten wollen Sie eine Kante hinzufügen?" << endl;
    aktuellprint();
    cout << "Startknoten:" << endl;
    cin >> start;
    cout << "Zielknoten:" << endl;
    cin >> ende;
    projects[project].InsertArc(start, ende);
    bearbeiten();
}

void Menue::deleteKnoten() {

}

void Menue::deleteKante() {

}
