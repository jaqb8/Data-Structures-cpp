#include "DoublyLinkedList.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <random>
#include <ctime>

using namespace std;

void menu_table(mt19937 generator);
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
                menu_table(generator);
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

void menu_table(mt19937 generator)
{
    Array* arr = new Array();
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
                    arr->load_from_file(fileName);
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
                    arr->delete_at(index);
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
                    arr->insert_at(value, index);
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
                    arr->find(value) ? cout << "Znaleziono podana wartosc." << endl : cout << "Nie znalezniono podanej wartosci." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy: ";
                cin >> value;

                try {
                    arr->generate_array(value, generator);
                    cout << "Utworzono tablice." << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                    break;
                }

            case '6':  //tutaj wyświetlanie tablicy
                try {
                    arr->print();
                    cout << endl;
                    break;
                } catch (string &e) {
                    cout << e << endl;
                }

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
    delete arr;
}

void menu_list(mt19937 generator) {
    DoublyLinkedList* list = new DoublyLinkedList();
    char opt;
    string file_name;
    int index, value;

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
                    cout << "Podaj indeks: ";
                    cin >> index;
                    list->delete_at(index);
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
        }
    } while(opt != '0');

    delete list;
}