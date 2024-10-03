#include "book.h"

book::book():m_tiltle("Unknown"), m_auther("unknown"), m_isbn(0), m_generation(0), m_availability(true){}

void book::set_all_data()
{
    cout << "Enter the title: ";
    cin >> m_tiltle;
    cout << endl;

    cout << "Enter name of the auther: ";
    cin >> m_auther;
    cout << endl;

    cout << "Enter its ISBN: ";
    cin >> m_isbn;
    cout << endl;

    cout << "Enter the generation: ";
    cin >> m_generation;
    cout << endl << endl;

}

void book::set_title(string title)
{
    m_tiltle = title;

}

string book::get_title()
{
    return m_tiltle;
}

void book::set_auther(string auther)
{
    m_auther = auther;
}

string book::get_auther()
{
    return m_auther;
}

void book::set_isbn(int isbn)
{
    m_isbn = isbn;
}

int book::get_isbn()
{
    return m_isbn;
}

void book::set_generation(int generation)
{
    m_generation = generation;
}

int book::get_generation()
{
    return m_generation;
}

void book::set_availability(bool availability)
{
    m_availability = availability;
}

bool book::get_availability()
{
    return m_availability;
}

ostream&operator << (ostream&output, book&b)
{
    output << "Book data: \n" <<"Auther: " << b.get_auther() << "\nTitle: " << b.get_title() ;
    output << "\nGeneration: " << b.get_generation() << "\nISBN: " << b.get_isbn();
    output << "\nStatus: " << (b.get_availability() ? "Available" : "Borrowed") << "\n\n\n";
    return output;
}

bool book::operator==(book b)
{
    return ( m_isbn == b.get_isbn() && m_generation == b.get_generation() && m_auther == b.get_auther() && m_tiltle == b.get_title() );
}


bool book::operator!=(book b)
{
    return ( m_isbn != b.get_isbn() && m_generation != b.get_generation()&&m_auther == b.get_auther() && m_tiltle != b.get_title() );
}

book::~book(){}
