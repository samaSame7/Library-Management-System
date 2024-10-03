#include "library.h"

#include <unistd.h>

#include <stdexcept>

library::library():m_numOfBooks(0), m_numOfBorrowedBooks(0), m_numOfavailableBooks(0) {}

void library::Add_book(book b)
{
    m_numOfBooks++;
    m_numOfavailableBooks++;

    int n;
    cout << "Press: \n[1] Add at first.\n[2] Add in specific position.\n[3] Add at the end.\n";
    cin >> n ;
    cout << endl;

    switch(n)
    {
    case 1 :
        catalog.insertFirst(b);
        break;

    case 2 :
        int position;
        cout << "Enter the position: \n";
        cin >> position;

        catalog.insertInSpecificPosition(position, b);
        break;

    case 3 :
        catalog.append(b);
        break;
    }
}

void library::borrow_book()
{
    display_book();

    book b = *search_by_title();

    node<book>* p = catalog.head;

    for (int i=1 ; i <= catalog.Count() ; i++)
    {
        if ( p->data.get_title() == b.get_title())
        {
            p->data.set_availability(false);
            break;
        }
        p = p->next;
    }

    cout << "The book successfully borrowed:)....\n";

    m_numOfBorrowedBooks++;
    m_numOfavailableBooks--;
}

void library::returnBook()
{
    book b = *search_by_title();

    node<book>* p = catalog.head;

    for (int i=1 ; i <= catalog.Count() ; i++)
    {
        if ( p->data.get_title() == b.get_title())
        {
            p->data.set_availability(true);
            break;
        }
        p = p->next;
    }

    cout << "The book returned successfully:)....\n";

    m_numOfBorrowedBooks--;
    m_numOfavailableBooks++;
}

void library::sort_by_title()
{
    for (node<book>*p = catalog.head ; p != nullptr ; p = p->next)
    {
        node<book>*q = p;

        for (node<book>*temp = p ; temp != nullptr ; temp = temp->next)
            if (q->data.get_title() > temp->data.get_title())
                q = temp;
        catalog.Swap(q, p);
    }
}

void library::sort_by_auther()
{
    for (node<book>*p = catalog.head ; p != nullptr ; p = p->next)
    {
        node<book>*q = p;

        for (node<book>*temp = p ; temp != nullptr ; temp = temp->next)
            if (q->data.get_auther() > temp->data.get_auther())
                q = temp;
        catalog.Swap(q, p);
    }
}

void library::sort_by_generation()
{
    for (node<book>*p = catalog.head ; p != nullptr ; p = p->next)
    {
        node<book>*q = p;

        for (node<book>*temp = p ; temp != nullptr ; temp = temp->next)
            if (q->data.get_generation() > temp->data.get_generation())
                q = temp;
        catalog.Swap(q, p);
    }
}

void library::sort_by_isbn()
{
    for (node<book>*p = catalog.head ; p != nullptr ; p = p->next)
    {
        node<book>*q = p;

        for (node<book>*temp = p ; temp != nullptr ; temp = temp->next)
            if (q->data.get_isbn() > temp->data.get_isbn())
                q = temp;
        catalog.Swap(q, p);
    }
}

void library::sort_books()
{
    int n;
    cout << "Press: \n[1] Sort by title.\n[2] Sort by author.\n[3] Sort by Generation.\n[4] Sort by ISBN.\n";
    cin >> n ;
    cout <<"\n";

    switch(n)
    {
    case 1 :
        sort_by_title();
        break;

    case 2 :
        sort_by_auther();
        break;

    case 3 :
        sort_by_generation();
        break;

    case 4 :
        sort_by_isbn();
        break;
    }
}

book* library::search_by_title()
{
    string title;
    cout << "Enter the title of the book: ";
    cin >> title;
    cout << endl;

    node<book>*p=catalog.head;

    for (int i = 1 ; i <= catalog.Count() ; i++)
    {
        if (p->data.get_title() == title)
            return &p->data;
        p=p->next;
    }

    cout << "Invalid data....\n\n";

    return nullptr;
}

book* library::search_by_auther()
{
    string auther;
    cout << "Enter the name of the auther: ";
    cin >> auther;
    cout << endl;

    node<book>*p = catalog.head;

    for (int i = 1 ; i <= catalog.Count() ; i++)
    {
        if (p->data.get_auther() == auther)
            return &p->data;
        p=p->next;
    }

    cout << "Invalid data....\n\n";
    return nullptr;
}

book* library::search_by_generation()
{
    int generation;
    cout << "Enter the generation of the book: ";
    cin >> generation;
    cout << endl;

    node<book>*p = catalog.head;

    for (int i = 1 ; i <= catalog.Count() ; i++)
    {
        if (p->data.get_generation() == generation)
            return &p->data;
        p = p->next;
    }

    cout << "Invalid data....\n\n";
    return nullptr;
}

book* library::search_by_isbn()
{
    int isbn;
    cout << "Enter the ISBN of the book: ";
    cin >> isbn;
    cout << endl;

    node<book>*p = catalog.head;

    for (int i = 1 ; i <= catalog.Count() ; i++)
    {
        if (p->data.get_isbn() == isbn)
            return &p->data;
        p = p->next;
    }

    cout << "Invalid data....\n\n";
    return nullptr;
}

void library::search_books()
{
    int n;
    cout << "Press: \n[1] Search by Title.\n[2] Search by Author.\n[3] Search by Generation.\n[4] Search by ISBN.\n";;
    cin >> n ;
    cout <<"\n";

    switch(n)
    {
    case 1 :
    {
        book *b = search_by_title();
        if (b != nullptr)
            cout << *b << endl;
        break;
    }

    case 2 :
    {
        book *b = search_by_auther();
        if (b != nullptr)
            cout << *b << endl;
        break;
    }

    case 3 :
    {
        book *b = search_by_generation();
        if (b != nullptr)
            cout << *b << endl;
        break;
    }

    case 4 :
    {
        book *b = search_by_isbn();
        if (b != nullptr)
            cout << *b << endl;
        break;
    }
    }
}

void library::remove_book(book b)
{
    int n;
    cout << "Press: \n[1] Remove by position.\n[2] Remove by value.\n";
    cin >> n ;
    cout <<"\n";

    switch(n)
    {
    case 1 :
        int position;
        cout << "Enter the position: ";
        cin >> position;
        cout << endl;

        catalog.remove_by_position(position);
        m_numOfBooks--;
        m_numOfavailableBooks--;
        break;

    case 2 :
        book b = *search_by_title();
        catalog.del(b);
        m_numOfBooks--;
        m_numOfavailableBooks--;
        break;
    }

    cout << "The book has been deleted... ";
}

void library::display_book()
{
    if (catalog.isEmpty())
    {
        cout << "There is no books...." << endl;
        sleep(2);
        system("cls");
    }

    else
        catalog.display();
}

void library::statistics()
{
    cout << "The number of books in the library is: " << m_numOfBooks << "\n";
    cout << "The number of borrowed books in the library is: " << m_numOfBorrowedBooks << "\n" ;
    cout << "The number of available books in the library is: " << m_numOfavailableBooks << "\n\n" ;
}

void library::Menu()
{
    cout<<"     Library Management System     "<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"[1] Add new book."<<endl;
    cout<<"[2] Borrow a book."<<endl;
    cout<<"[3] Return book."<<endl;
    cout<<"[4] Remove book."<<endl;
    cout<<"[5] Sort the books."<<endl;
    cout<<"[6] Search for a book."<<endl;
    cout<<"[7] Display all books."<<endl;
    cout<<"[8] Statistics."<<endl;
    cout<<"[9] Exit the program."<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Enter your choice: ";
}

void library::run()
{
    int ch=0;

    try
    {
        while( ch != 9 )
        {
            Menu();
            cin >> ch;
            cout << endl;
            if (cin.fail())
            {
                throw invalid_argument("Invalid input. Please enter an integer.");
            }

            sleep(1);
            system("cls");

            book b;

            switch (ch)
            {
            case 1:
                b.set_all_data();
                Add_book(b);
                sleep(2);
                system("cls");
                break;

            case 2:
                borrow_book();
                sleep(2);
                system("cls");
                break;

            case 3:
                returnBook();
                sleep(2);
                system("cls");
                break;

            case 4:
                remove_book(b);
                sleep(2);
                cout << "\nAfter Removing: \n";

                display_book();
                sleep(3);
                system("cls");
                break;

            case 5:
                sort_books();

                cout << "\nAfter sorting: \n";

                display_book();
                sleep(3);
                system("cls");
                break;

            case 6:
                search_books();
                sleep(2);
                system("cls");
                break;

            case 7:
                display_book();
                sleep(2);
                system("cls");
                break;

            case 8:
                statistics();
                sleep(2);
                system("cls");
                break;

            case 9:
                cout << "Exiting the program......" << endl;
                sleep(2);
                system("cls");
                return;

            default:
                cout<<"Invalid choice try again...... "<<endl;
                sleep(2);
                system("cls");
                break;
            }
        }
    }
    catch (const invalid_argument& e)
    {
        cerr << e.what() << endl;
    }
}


library::~library() {}
