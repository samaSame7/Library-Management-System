#ifndef CONTAINER_H
#define CONTAINER_H

#include "node.h"

#include <iostream>
using namespace std;

template<class t>
class container
{
public:
    node<t>* head;

    container();
    virtual ~container();

    bool isEmpty();
    void insertFirst(t newvalue);
    void insertBefore(t item, t newvalue);
    void insertInSpecificPosition(int position, t newvalue);
    void append (t newvalue);//add at last
    void display();
    int Count();
    bool Search(t key);
    t del(t b);
    t remove_by_position(int position);
    void Reverse();
    void Merge(node<t>*y);
    void Sort();
    void Swap(node<t>*&p, node<t>*&q);
};

#endif // CONTAINER_H

template<class t>
container<t>::container()
{
    head = nullptr;
}

template<class t>
bool container<t>::isEmpty()
{
    return (head == nullptr);//length==0;
}

template<class t>
void container<t>::insertFirst( t newvalue )
{
    node<t>* newnode= new node<t>;
    newnode->data=newvalue;

    if (isEmpty())
    {
        newnode->next=nullptr;
        head = newnode;

        cout << "The book successfully added:)....\n";
    }

    else
    {
        newnode->next=head;
        head=newnode;

        cout << "The book successfully added:)....\n";
    }
}

template<class t>
void container<t>::display()
{
    node<t>*temp=head;

    while(temp!=nullptr)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

template<class t>
int container<t>::Count()
{
    int counter=0;

    node<t>* temp=head;

    while(temp!=nullptr)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

template<class t>
bool container<t>::Search(t key)
{
    bool found= false;

    node<t>* temp=head;

    while(temp!=nullptr)
    {
        if (temp->data==key)
            found=true;
        temp=temp->next;
    }
    return found;
}

template<class t>
void container<t>::insertInSpecificPosition(int position, t newvalue)
{
    if (isEmpty())
        insertFirst(newvalue);
    else
    {
        if (position <= Count() + 1)
        {
            node<t>*temp = head;

            for (int i=0 ; i < position - 2 ; i++)
            {
                temp = temp->next;
            }

            node<t>* newnode = new node<t>;
            newnode->data = newvalue;
            newnode->next = temp->next;
            temp->next = newnode;

            cout << "The book successfully added:)....\n";
        }

        else
            cout << "This position is out of range..."<<endl;
    }

}

template<class t>
void container<t>::insertBefore(t item, t newvalue)
{
    if (isEmpty())
        insertFirst(newvalue);
    else
    {
        if (Search(item))
        {
            node<t>*temp = head;

            while (temp != nullptr && temp->next->data != item)
            {
                temp = temp->next;
            }

            node<t>* newnode = new node<t>;
            newnode->data = newvalue;

            newnode->next = temp->next;
            temp->next = newnode;

            cout << "The book successfully added:)....\n";
        }

        else
            cout<<"This item is not found..\n";
    }
}

template<class t>
void container<t>::append (t newvalue)
{
    if (isEmpty())
        insertFirst(newvalue);

    else
    {
        node<t>* temp=head;

        while (temp->next!=nullptr)//الوحيدة الل شرطها مختلف
        {
            temp=temp->next;
        }

        node<t>* newnode=new node<t>;
        newnode->data=newvalue;
        temp->next=newnode;
        newnode->next=nullptr;

        cout << "The book successfully added:)....\n";
    }
}

template<class t>
t container<t>::del(t b)
{
    if (isEmpty())
        cout <<"List is empty, no items to delete...\n";

    else
    {
        t x;
        //لو همسح أول نود
        if (head->data.get_title() == b.get_title())
        {
            x = head->data;
            node<t>* delptr = head;
            head = head->next;
            delete delptr;
        }

        // لو همسح نود غير الأولى
        else
        {
            node<t>* prevptr = nullptr;
            node<t>* delptr = head;

            while (delptr->data.get_title() != b.get_title())
            {
                prevptr = delptr;
                delptr = delptr->next;
            }

            prevptr->next = delptr->next;
            x = delptr->data;

            delete delptr;
        }
        return x;
    }
}

template<class t>
t container<t>::remove_by_position(int position)
{
    if (isEmpty())
        cout <<"List is empty, no items to delete...\n";

    else
    {
        if (position > Count() || position < 1 )
            cout <<"This position does not exist...\n";

        else
        {
            node<t>*p;
            node<t>*q;
            t x;

            if (position == 1)
            {
                x = head->data;
                p = head;
                head = head->next;
                delete p;
            }

            else
            {
                p = head;
                q = nullptr;

                for (int i = 0 ; i < position-1 && p ; i++)
                {
                    q = p;
                    p = p->next;
                }

                if ( p != nullptr )
                {
                    q->next = p->next;
                    x = p->data;
                    delete p;
                }
            }
            return x;
        }
    }
}

template<class t>
void container<t>::Reverse()
{
    if (isEmpty())
        cout <<"List is empty, no items to reverse...\n";

    else
    {
        node<t> *prev;
        node<t> *next;
        node<t> *current;

        prev=nullptr;
        current=head;
        next=current->next;

        while(next!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;

        }
        head=prev;
    }
}

template<class t>
void container<t>::Merge(node<t>*y)
{
    node<t>*temp = head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=y;

    Sort();
}

template<class t>
void container<t>::Sort()
{

    for (node<t>*x = head ; x!=nullptr ; x=x->next)
    {
        node<t>*y = x;

        for (node<t>*z = x ; z!=nullptr ; z = z->next)
        {
            if ( y->data > z->data)
                y = z;
        }

        Swap(y, x);
    }

}

template<class t>
void container<t>::Swap(node<t>*&x, node<t>*&y)
{
    t data = x->data;
    x->data = y->data;
    y->data = data;

}

template<class t>
container<t>::~container() {}
