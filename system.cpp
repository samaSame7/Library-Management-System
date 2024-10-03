#include "system.h"
#include "container.h"

system::system()
{
    ctor
}

void system::Add_book()
{
    int n;
    cout << "Press: \n1-to add at first\n2-to add in specific position\n3-to add at the end.\n";
    cin >> n ;

    cout << "Enter the data: .\n";
    cin >> ;

    switch(n)
    {
    case 1 :
        c.insertFirst();
        cout << "The book successfully added:)....\n";
        break;

    case 2 :
        c.insertInSpecificPosition();
        cout << "The book successfully added:)....\n";
        break;

    case 3 :
        c.append();
        cout << "The book successfully added:)....\n";
        break;
    }
}
void system::borrow_book()
{

}

void system::remove_book()
{

}

void system::sort_book()
{

}

void system::display_book()
{

}

void system::statistics()
{

}

system::~system()
{
    //dtor
}
