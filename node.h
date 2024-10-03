#ifndef NODE_H
#define NODE_H

template<class t>

class node
{
public:
    t data;
    node* next;

    node();
    virtual ~node();

};

#endif // NODE_H

template<class t>
node<t>::node():next(nullptr) {}

template<class t>
node<t>::~node() {}
