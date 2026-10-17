// Anthony Huey - 10/17/2026 - COMSC 210 - Lab 24: Goat Manager 3001
// Convert the list to a set.
// really only had to change 2 things, the push_back to insert, 
// and adding the overloaded < so it can sort itself, easy peasy.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20, MIN = 0;

int select_goat(set<Goat> trip); // can use .find
void delete_goat(set<Goat> &trip); // can use .erase
void add_goat(set<Goat> &trip, string [], string []); // use .insert
void display_trip(set<Goat> trip); 
int main_menu();

bool again = 1; // using this for the main menu, and delete loops.

int main() 
{
    srand(time(0));

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    set<Goat> mylist;
    int choice;

    while (choice != 4)
    {
        choice = main_menu();
        switch (choice)
        {
        case 1: add_goat(mylist, names, colors); break;
        case 2: delete_goat(mylist); break;
        case 3: display_trip(mylist); break;
        case 4: cout << "Goodbye."; break;
        }
    }
  
    return 0;
}

int main_menu() // Menu for interacting with goats
{               
    int choice; 
    again = 1;
    while (again != 0)
    {
        cout << "\n\t*** GOAT MANAGER 3001 ***";
        cout << "\n[1] Add a goat \n[2] Delete a goat";
        cout << "\n[3] List goats \n[4] Quit \nChoice --> ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: again = 0; break;
        case 2: again = 0; break;
        case 3: again = 0; break; 
        case 4: again = 0; break;
        default: cout << "Invalid\n"; 
        }
    }
    return choice;
}

int select_goat(set<Goat> trip) // display the goats, then ask which one.
{
    display_trip(trip);
    
    int choice;
    cout << "\nWhich goat: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

void delete_goat(set<Goat> &trip) // find goat, delete it
{
    again = 1;
    int choice;
    while (again != 0) // validate if choice is < 0 or > size.
    {
        choice = select_goat(trip);
        if (choice < 1 || choice > trip.size())
            cout <<"\nInvalid";
        else
            again = 0;
    }
    auto it = trip.begin();
    advance(it, choice - 1); 
    trip.erase(it);
}

void add_goat(set<Goat> &trip, string n[], string c[]) // add goat
{
    Goat goat = {n[rand()%SZ_NAMES], rand() % (MAX_AGE - MIN+1) + MIN, 
                 c[rand()%SZ_COLORS]};
    trip.insert(goat); 
    cout << " Adding goat..."; 
}                        

void display_trip(set<Goat> trip) // display goats
{
    int i = 0;
    for (Goat g : trip)
    {   
        i++;
        cout << "\n[" << i << "] " << g.get_name() << "(" << g.get_age()
             << " " << g.get_color() << ")";  
    }
}

