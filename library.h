#ifndef LIBRARY_H
#define LIBRARY_H

#include "container.h"
#include "book.h"

class library
{
private:
    container<book>catalog;
    size_t m_numOfBooks;
    size_t m_numOfBorrowedBooks;
    size_t m_numOfavailableBooks;


public:
    library();
    virtual ~library();

    void Add_book(book b);
    void borrow_book();
    void remove_book(book b);
    void returnBook();
    void display_book();
    void statistics();
    void Menu();
    void run();

    book* search_by_title();
    book* search_by_auther();
    book* search_by_generation();
    book* search_by_isbn();
    void search_books();

    void sort_by_title();
    void sort_by_auther();
    void sort_by_generation();
    void sort_by_isbn();
    void sort_books();

};

#endif // LIBRARY_H
