/*
 Julius Garma
 Hank Stalica
 Binary Search tree
 */

#ifndef HW_4_Binary_Search_Tree_Tree_h
#define HW_4_Binary_Search_Tree_Tree_h

#include <iostream>

class Tree
{
    
private:
    struct Node
    {
        int i;
        Node* left, *right;
    };
    Node* root;
    
    void add(Node* &r, int i);
    void remove(Node* &r, int i);
    bool find(Node* r, int i);
    void print(Node* r, int i);
    void clear(Node* &r, int i);
    
public:
    Tree();
    ~Tree();
    void add(int i);
    void remove(int i);
    bool find(int i) const;
    void print() const;
    void clear();
};

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    clear();
}

////////////////////////////////
// O(logn) WC: O(n)
void Tree::add(Node* &r, int i)
{
    if(r == nullptr)
    {
        Node* r = new Node;
        r->i = i;
        r->left = nullptr;
        r->right = nullptr;
    }
    else if(i < r->i)
    {
        add(r->left, i);
    }
    else
    {
        add(r->right, i);
    }
}

void Tree::add(int i)
{
    add(root, i);
}

/////////////////////////////
// O(logn) WC: O(n)
void Tree::remove(Node* &r, int i)
{
    if(r == nullptr)
    {
        return;
    }
    else if(i < r->i)
    {
        remove(r->left, i);
    }
    else if(i > r->i)
    {
        remove(r->right, i);
    }
    else
    {
        // no children
        if(r->left == nullptr && r->right == nullptr)
        {
            delete r;
            r = nullptr;
        }
        // right child only
        else if(r->left == nullptr && r->right != nullptr)
        {
            Node* p = r;
            r = r->right;
            delete p;
        }
        // left child only
        else if(r->left != nullptr && r->right == nullptr)
        {
            Node* p = r;
            r = r->right;
            delete p;
        }
        // has two children
        else
        {
            Node* p = r->right;
            while(p->left != nullptr)
            {
                p = p->left;
            }
            
            p->left = p->right;
            Node* p = r;
            r = r->right;
            delete p;
        }
    }
}

void Tree::remove(int i)
{
    remove(root, i);
}

////////////////////////////////////////////////////////////
// O(logn) WC: O(n)
bool Tree::find(Node* r, int i) const
{
    if(r == nullptr)
    {
        return false;
    }
    else if(i == r->key)
    {
        return true;
    }
    else if(i < r->key)
    {
        find(r->left, i);
    }
    else
    {
        find(r->right, i);
    }
}

bool Tree::find(int i) const
{
    find(root, i);
}

//////////////////////////////////
// in - order traversal
void Tree::print(Node* r, int i) const
{
    if(r == nullptr)
        return;
    
    print(r->left, i);
    cout << r->i << "\t";
    print(r->right, i);
}

void Tree:print(int i) const
{
    print(root);
}

//////////////////////////////////
// O(n)
void Tree::clear(Node* &r, int i)
{
    if(r == nullptr)
        return;
    
    clear(r->left, i);
    clear(r->right, i);
    delete r;
    root = nullptr;
}

void Tree::clear()
{
    clear(root);
}

#endif
