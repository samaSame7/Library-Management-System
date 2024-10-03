#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class book
{
private:
    string m_tiltle;
    string m_auther;
    int m_isbn;
    int m_generation;
    bool m_availability;

public:
    //bool m_availability;

    book();
    virtual ~book();

    void set_all_data();

    void set_title(string title);
    string get_title();

    void set_auther(string auther);
    string get_auther();

    void set_isbn(int isbn);
    int get_isbn();

    void set_generation(int generation);
    int get_generation();

    void set_availability(bool availability);
    bool get_availability();

    friend ostream&operator << (ostream&output, book&b);
    bool operator==(book b);
    bool operator!=(book b);
};

#endif // BOOK_H
