// Anthony Huey - 10/16/2026 - COMSC 210 - Lab 23: Goat Manager 3001
// Fork the given repository, then follow the 4 tasks, 
// im not writitng them here, they're on the assignment look there.
// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat 
{
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string n) {name = n;}
    Goat(string n, int a) {name = n; age = a;}
    Goat(string n, int a, string c) {name = n; age = a; color = c;}

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator< (const Goat &rhs) const {return name < rhs.name;}
};

#endif