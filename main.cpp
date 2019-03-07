#include "DoublyLinkedList.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <random>
#include <ctime>

using namespace std;

void menu_list(mt19937 generator);

int main() {
    // random numbers generator
    mt19937 generator;
    generator.seed(time(0));

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getche();
        cout << endl;

        switch (option){
            case '1':
                //menu_table();
                break;

            case '2':
                menu_list(generator);
                break;

            case '3':
                //menu_heap();
                break;
        }

    } while (option != '0');


    return 0;
}

void displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_list(mt19937 generator) {
    DoublyLinkedList* list = nullptr;
    char opt;
    string file_name;
    int index, value;

    do {
        displayMenu("--- LISTA ---");
        opt = getche();
        cout << endl;
        switch(opt) {
            case '1': // load from file
                cout << "Podaj nazwe zbioru: ";
                cin >> file_name;
                list = new DoublyLinkedList();
                list->load_from_file(file_name);
                break;

            case '2': // delete node
                if(!list) {
                    cout << "Nie wczytano listy." << endl;
                    break;
                } else {
                    cout << "Podaj indeks: ";
                    cin >> index;
                    list->delete_at(index);
                    break;
                }

            case '3': // insert node
                if(!list) {
                    cout << "Nie wczytano listy." << endl;
                    break;
                } else {
                    cout << "Podaj indeks: ";
                    cin >> index;
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    list->insert_at(value, index);
                    break;
                }

            case '4': // find
                if(!list) {
                    cout << "Nie wczytano listy." << endl;
                    break;
                } else {
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    list->find(value);
                    break;
                }

            case '5': // create list
                cout << "Podaj ilosc elementow listy: ";
                cin >> value;
                list = new DoublyLinkedList();
                list->generate_list(value, generator);
                break;

            case '6': // print list
                if(!list) {
                    cout << "Nie wczytano listy." << endl;
                    break;
                } else {
                    list->print_forward();
                    list->print_backward();
                    break;
                }
        }
    } while(opt != '0');

    delete list;
}