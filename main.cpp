#include "DoublyLinkedList.h"
#include "Array.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <random>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <Windows.h>
#include "Test.h"

using namespace std;

void menu_table(mt19937 generator);
void menu_list(mt19937 generator);
void menu_heap(mt19937 generator);
void menu_bst(mt19937 generator);

int main() {

//    DoublyLinkedList *l = new DoublyLinkedList();
//    l->load_from_file("tab1.txt");
//    l->delete_node(6);
//    l->delete_node(10);
//    l->delete_node(2);
//    l->delete_node(4);
//    l->delete_node(8);
//    l->insert_at(2, 0);
//    l->insert_at(6, 1);
//    l->insert_at(8, 2);
//    l->insert_at(4, 1);
//    l->insert_at(0, 0);
//    return 0;


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
        cout << "4.Drzewo BST" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getche();
        cout << endl;

        switch (option){
            case '1':
                menu_table(generator);
                break;

            case '2':
                menu_list(generator);
                break;

            case '3':
                menu_heap(generator);
                break;

            case '4':
                menu_bst(generator);
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
    //cout << "7.Pomiar - dodawanie" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_table(mt19937 generator)
{
    //Test test;
    Array arr;
    char opt;
    string fileName;
    int index, value;

    do{
        displayMenu("--- TABLICA ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwę zbioru:";
                cin >> fileName;

                try {
                    arr.load_from_file(fileName);
                    cout << "Wczytano z pliku." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }


            case '2': //tutaj usuwanie elemenu z tablicy
                cout << "Podaj indeks: ";
                cin >> index;

                try {
                    arr.delete_at(index);
                    cout << "Usunieto." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << "Podaj indeks: ";
                cin >> index;
                cout << "Podaj wartosc: ";
                cin >> value;

                try {
                    arr.insert_at(value, index);
                    cout << "Dodano." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << "Podaj wartosc: ";
                cin >> value;

                try {
                    arr.find(value) ? cout << "Znaleziono podana wartosc." << endl : cout << "Nie znalezniono podanej wartosci." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy: ";
                cin >> value;

                try {
                    arr.generate_array(value, generator);
                    cout << "Utworzono tablice." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '6':  //tutaj wyświetlanie tablicy
                try {
                    arr.print();
                    cout << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

//            case '7':
//                test.begin();
//                arr.insert_at(50,400);
//                test.stop();
//                cout << "(ns): " << test.timeElapsed() << endl;
//
//                break;
        }

    } while (opt != '0');

}

void menu_list(mt19937 generator) {
    DoublyLinkedList* list = new DoublyLinkedList();
    char opt;
    string file_name;
    int index, value;
    Test t;

    do {
        displayMenu("--- LISTA ---");
        opt = getche();
        cout << endl;
        switch(opt) {
            case '1': // load from file
                try {
                    cout << "Podaj nazwe zbioru: ";
                    cin >> file_name;
                    list->load_from_file(file_name);
                    cout << "Wczytano z pliku." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '2': // delete node
                try{
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    list->delete_node(value);
                    cout << "Usunieto." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '3': // insert node
                cout << "Podaj indeks: ";
                cin >> index;
                cout << "Podaj wartosc: ";
                cin >> value;

                try {
                    list->insert_at(value, index);
                    cout << "Dodano wartosc." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '4': // find
                cout << "Podaj wartosc: ";
                cin >> value;

                try {
                    list->find(value) ? cout << "Znaleziono podana wartosc." << endl : cout << "Nie znaleziono podanej wartosci." << endl;
                    break;
                } catch(string &e) {
                    cout << e << endl;
                    break;
                }


            case '5': // create list
                cout << "Podaj ilosc elementow listy: ";
                cin >> value;

                try {
                    list->generate_list(value, generator);
                    cout << "Utworzono liste." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }


            case '6': // print list
                try {
                    list->print_forward();
                    cout << endl;
                    list->print_backward();
                    cout << endl;
                } catch (string &e) {
                    cout << e << endl;
                }

//            case '7':
//                t.begin();
//                list->insert_front(5);
//                t.stop();
//                cout << "Elapsed: " << t.timeElapsed() << endl;
//                break;

        }
    } while(opt != '0');

    delete list;
}

void menu_heap(mt19937 generator) {
    Heap *heap = new Heap(10);
    char opt;
    string file_name;
    int index, value;


    do {
        displayMenu("--- KOPIEC ---");
        opt = getche();
        cout << endl;
        switch(opt) {
            case '1': // load from file
                try {
                    cout << "Podaj nazwe zbioru: ";
                    cin >> file_name;
                    heap->load_from_file(file_name);
                    cout << "Wczytano z pliku." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '2': // delete root
                try{
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    heap->delete_item(value);
                    cout << "Usunieto." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '3': // insert
                cout << "Podaj wartosc: ";
                cin >> value;

                try {
                    heap->add(value);
                    cout << "Dodano wartosc." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '4': // find
                cout << "Podaj wartosc: ";
                cin >> value;

                try {
                    heap->find(value) ? cout << "Znaleziono podana wartosc." << endl : cout << "Nie znaleziono podanej wartosci." << endl;
                    break;
                } catch(string &e) {
                    cout << e << endl;
                    break;
                }


            case '5': // create list
                cout << "Podaj ilosc elementow kopca: ";
                cin >> value;

                try {
                    heap->generate_heap(value, generator);
                    cout << "Utworzono kopiec." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }


            case '6': // print heap
                try {
                    heap->print_2D();
                    cout << endl;
                } catch (string &e) {
                    cout << e << endl;
                }

//            case '7':
//                t.begin();
//                list->insert_front(5);
//                t.stop();
//                cout << "Elapsed: " << t.timeElapsed() << endl;
//                break;
        }
    } while(opt != '0');

    delete heap;
}

void menu_bst(mt19937 generator) {
    BinarySearchTree *bst = new BinarySearchTree();
    char opt;
    string file_name;
    int index, value;


    do {
        displayMenu("--- DRZEWO BST ---");
        opt = getche();
        cout << endl;
        switch(opt) {
            case '1': // load from file
                try {
                    cout << "Podaj nazwe pliku: ";
                    cin >> file_name;
                    bst->load_from_file(file_name);
                    cout << "Wczytano z pliku." << endl;
                    break;
                } catch(string &e) {
                    cout << e << endl;
                    break;
                }

            case '2': // delete root
                try {
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    bst->delete_node(value);
                    cout << "Usunieto." << endl;
                    break;
                } catch(string &e) {
                    cout << e << endl;
                    break;
                }

            case '3': // insert
                cout << "Podaj wartosc: ";
                cin >> value;
                bst->insert_node(value);
                cout << "Dodano." << endl;
                break;

            case '4': // find
                cout << "Podaj wartosc: ";
                cin >> value;
                bst->find(value) ? cout << "Znaleziono podana wartosc." << endl : cout << "Nie znaleziono podanej wartosci." << endl;
                break;

            case '5': // create list
                try {
                    cout << "Podaj ilosc elementow: ";
                    cin >> value;
                    bst->generate_bst(value, generator);
                    cout << "Utworzono." << endl;
                    break;
                } catch(string &e) {
                    cout << e << endl;
                    break;
                }

            case '6':
                bst->print_2D();
                break;

//            case '7':
//                t.begin();
//                list->insert_front(5);
//                t.stop();
//                cout << "Elapsed: " << t.timeElapsed() << endl;
//                break;

        }
    } while(opt != '0');

    delete bst;
}