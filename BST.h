//****************************************************************************************************
//
//      File:           BST.h
//
//      Student:        Michael Remphry
//
//      Assignment:     Program #9
//
//      Course Name:    Data Structures II
//
//      Course Number:  COSC 3100 - 10
//
//      Due:            April 23, 2019
//
//      This is a template for a binary search tree
//
//      Other files required:
//              1. Node.h
//
//****************************************************************************************************

#include <iostream>

#ifndef BST_H
#define BST_H

#include "Node.h"

//****************************************************************************************************

template <typename TYPE>
class BST
{
    private:
        Node <TYPE> * root;
        void _destruct(Node <TYPE> * pRoot);
        Node <TYPE> * _retrieve(Node <TYPE> * pRoot, const TYPE & dataOut) const;
        Node <TYPE> * _insert(Node <TYPE> * pRoot, const TYPE & dataIn);
        Node <TYPE> * _remove(Node <TYPE> * pRoot, const TYPE & dataOut);
        void _inOrderTraversal(Node <TYPE> * pRoot, void(*process)(TYPE data)) const;
        int _getCount(Node <TYPE> * pRoot) const;
        int _getHt(Node <TYPE> * pRoot) const;
    public:
        BST();
        ~BST();
        bool retrieve(TYPE & dataOut) const;
        bool insert(const TYPE & dataIn);
        bool remove(TYPE & dataOut);
        bool update(const TYPE & dataIn);
        void inOrderTraversal(void(*process)(TYPE data)) const;
        int getCount() const;
        int getHt() const;
        bool isEmpty() const;
        bool isFull() const;
};

//****************************************************************************************************

template <typename TYPE>
BST<TYPE>::BST()
{
    root = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE>::_destruct(Node <TYPE> * pRoot)
{
    if (pRoot)
    {
        _destruct(pRoot->left);
        _destruct(pRoot->right);
        delete pRoot;
    }
}

//****************************************************************************************************

template <typename TYPE>
BST<TYPE>::~BST()
{
    _destruct(root);
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> * BST<TYPE>::_retrieve(Node <TYPE> * pRoot, const TYPE & dataOut) const
{
    if (pRoot)
    {
        if (pRoot->data > dataOut)
        {
            pRoot = _retrieve(pRoot->left, dataOut);
        }
        else if (pRoot->data < dataOut)
        {
            pRoot = _retrieve(pRoot->right, dataOut);
        }
    }

    return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> * BST<TYPE>::_insert(Node <TYPE> * pRoot, const TYPE & dataIn)
{
    if (pRoot)
    {
        if (pRoot->data > dataIn)
        {
            pRoot->left = _insert(pRoot->left, dataIn);
        }
        else if (pRoot->data < dataIn)
        {
            pRoot->right = _insert(pRoot->right, dataIn);
        }
    }
    else
    {
        pRoot = new (nothrow) Node <TYPE>(dataIn);
    }

    return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> * BST<TYPE>::_remove(Node <TYPE> * pRoot, const TYPE & dataOut)
{
    Node <TYPE> * pMax;
    Node <TYPE> * pDel;

    if (pRoot)
    {
        if (pRoot->data > dataOut)
        {
            pRoot->left = _remove(pRoot->left, dataOut);
        }
        else if (pRoot->data < dataOut)
        {
            pRoot->right = _remove(pRoot->right, dataOut);
        }
        else
        {
            if ((pRoot->left) && (pRoot->right))
            {
                pMax = pRoot->left;

                while ((pMax) && (pMax->right))
                {
                    pMax = pMax->right;
                }

                pRoot->data = pMax->data;
                pRoot->left = _remove(pRoot->left, pMax->data);
            }
            else
            {
                pDel = pRoot;

                if (pRoot->left)
                {
                    pRoot = pRoot->left;
                }
                else
                {
                    pRoot = pRoot->right;
                }

                delete pDel;
            }
        }
    }

    return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE>::_inOrderTraversal(Node <TYPE> * pRoot, void(*process)(TYPE data)) const
{
    if (pRoot)
    {
        _inOrderTraversal(pRoot->left, process);
        process(pRoot->data);
        _inOrderTraversal(pRoot->right, process);
    }
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::_getCount(Node <TYPE> * pRoot) const
{
    int count;

    if (pRoot)
    {
        count = _getCount(pRoot->left) + 1 + _getCount(pRoot->right);
    }
    else
    {
        count = 0;
    }

    return count;
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::_getHt(Node <TYPE> * pRoot) const
{
    int height,
        lHeight,
        rHeight;

    if (pRoot)
    {
        lHeight = 1 + _getHt(pRoot->left);
        rHeight = 1 + _getHt(pRoot->right);

        if (lHeight > rHeight)
        {
            height = lHeight;
        }
        else
        {
            height = rHeight;
        }
    }
    else
    {
        height = 0;
        lHeight = 0;
        rHeight = 0;
    }

    return height;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::retrieve(TYPE & dataOut) const
{
    bool success = false;
    Node <TYPE> * pFound;

    pFound = _retrieve(root, dataOut);

    if (pFound)
    {
        dataOut = pFound-data;
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::insert(const TYPE & dataIn)
{
    bool success = false;
    Node <TYPE> * pFound;

    pFound = _retrieve(root, dataIn);

    if (!pFound)
    {
        root = _insert(root, dataIn);
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::remove(TYPE & dataOut)
{
    bool success = false;
    Node <TYPE> * pFound;

    pFound = _retrieve(root, dataOut);

    if (pFound)
    {
        dataOut = pFound->data;
        root = _remove(root, dataOut);
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::update(const TYPE & dataIn)
{
    bool success = false;
    Node <TYPE> * pFound;

    pFound = _retrieve(root, dataIn);

    if (pFound)
    {
        pFound->data = dataIn;
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE>::inOrderTraversal(void(*process)(TYPE data)) const
{
    _inOrderTraversal(root, process);
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::getCount() const
{
    return (_getCount(root));
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::getHt() const
{
    return (_getHt(root));
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isEmpty() const
{
    return (root == nullptr);
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isFull() const
{
    bool success = false;
    Node <TYPE> * pNew;

    pNew = new (nothrow) Node <TYPE>();

    if (pNew)
    {
        success = false;
        delete pNew;
    }

    return success;
}

//****************************************************************************************************

#endif