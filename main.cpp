/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Uni-R
 *
 * Created on 7. Februar 2018, 12:04
 */

#include <cstdlib>
#include "Digraph.h"
#include "Menue.h"


using namespace std;

/*
 * 
 */

int main() {
    /*Digraph G, H;

    // Graph aufbauen *************************************************

    // Knoten:
    G.InsertNode(0, "Besprechen", 4);
    G.InsertNode(1, "Zeichnen", 14);
    G.InsertNode(2, "Einmessen", 1);
    G.InsertNode(3, "Genehmigen", 21);
    G.InsertNode(4, "Angebot Fundament", 7);
    G.InsertNode(5, "Angebot Rohbau", 14);
    G.InsertNode(6, "Fundament", 5);
    G.InsertNode(7, "Rohbau", 20);

    // Kanten:
    G.InsertArc(0, 1);

    G.InsertArc(1, 2);
    G.InsertArc(1, 3);
    G.InsertArc(1, 4);
    G.InsertArc(1, 5);

    G.InsertArc(2, 6);
    G.InsertArc(3, 6);
    G.InsertArc(4, 6);
    G.InsertArc(5, 7);

    G.InsertArc(6, 7); */

    // Menue: ******************************************
    Menue M;

    int c = -1;

    while (c != 9) {

        cout << "\nMenue" << endl;
        cout << " 1: Aktuelles Projekt ausgeben" << endl;
        cout << " 2: Neues Projekt" << endl;
        cout << " 3: Aktuelles Projekt löschen" << endl;
        cout << " 4: Projekt wechseln" << endl;
        cout << " 5: Reihenfolge planen" << endl;
        cout << " 6: Mindestlaufzeit" << endl;
        cout << " 7: Alle Projecte ausgeben" << endl;
        cout << " 8: Testdaten eingeben lassen / Daten eingeben" << endl;
        cout << " 0: Projekt in neues Projekt Kopieren" << endl;
        cout << " 9: ENDE" << endl;

        cin >> c;

        switch (c) {
            case 0:
                M.kopieren();
                break;
                
            case 1: // Aktuelles Projekt ausgeben -- Aufgabe 1
                // hier ergänzen
                //G.print();
                M.aktuellprint();
                break;

            case 2: // Neues Projekt -- Aufgabe 2
                // hier ergänzen
                M.neuesProjekt();
                break;

            case 3: // Aktuelles Projekt löschen -- Aufgabe 2
                // hier ergänzen
                M.loescheProjekt();
                break;

            case 4: // Projekt wechseln -- Aufgabe 2
                // hier ergänzen
                M.wechseln();
                break;

            case 5: // Reihenfolge planen -- Aufgabe 3
                // hier ergänzen
                M.printSort();
                break;

            case 6: // Mindestlaufzeit-- Aufgabe 4
                // hier ergänzen
                break;
            case 7: // Projekte auflisten
                // hier ergänzen
                M.print();
                break;

            case 8:
                cout << "Für Manuelle eingabe wählen Sie die 1, rest Testdaten werden eingegeben" << endl;
                cin >> c;
                if(c == 1){
                    M.bearbeiten();
                }
                else {
                    M.test();
                }
                
                break;

            case 9: // Ende
                return (EXIT_SUCCESS);
                break;
        }

    }
    return (EXIT_SUCCESS);
}



