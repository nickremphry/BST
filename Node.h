#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
    TYPE data;
    union
    {
        Node <TYPE> * next;
        Node <TYPE> * left;
    };
    union
    {
        Node <TYPE> * prev;
        Node <TYPE> * right;
    };

    Node();
    Node(const TYPE & dataIn, Node <TYPE> * n = nullptr, Node <TYPE> * p = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
    data = 0;
    next = nullptr;
    prev = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE & dataIn, Node <TYPE> * n, Node <TYPE> * p)
{
    data = dataIn;
    next = n;
    prev = p;
}

//****************************************************************************************************

#endif NODE_H