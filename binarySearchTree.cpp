#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node* newNode(int item){
    struct node* temp = new struct node;//alocating memory for a new node in a linked list

    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
};

struct node* initialize(struct node* node, int key){
    if (node == NULL){
        return newNode(key);
    }

    if (key < node->key){
        node->left = initialize(node->left, key);
    }
    else if (key > node->key){
        node->right = initialize(node->right, key);
    }

    return node;
}

//find the minimum number of the tree
int minimum(node* tree){
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree->key;
}

//find the maximum number of the tree
int maximum(node* tree){
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree->key;
}

//search the key
int search(node* tree, int key){
    if ( tree == NULL || tree->key == key)
    {
        if (tree == NULL)
        {
            return -1;
        }
        else{
            return tree->key;
        }
        
    }
    else{
        if (key < tree->key)
        {
            return search(tree->left, key);
        }
        else if (key > tree->key){
            return search(tree->right, key);
        }
    }
    return -1;
}

/*
pseudo code !!!

int successor(x){
    if (x.right != NULL){
        return minimum(x.right);
    }
    y = x.parent;
    while (y != NULL && x == y.right){
        x = y;
        y = y.parent;
    }
    return y;
}

int predecessor(x){
    if (x.left != NULL){
        return maximum(x.left);
    }
    y = x.parent;
    while (y != NULL && x == y.left){
        x = y;
        y = y.parent;
    }
    return y;
}

tree insert(T, x){
    y = T;
    z = null;
    while ( y != NULL ){
        z = y;
        if (x.key < y.key){
            y = y.left;
        }
        else if (x.key > y.key){
            y = y.right;
        }
    }
    x.parent = z;
    if (x.key < z.key){
        z.left = x;
    }
    else if (x.key > z.key){
        z.right = x;
    }
}


delete(T,z){
    if (z.parent.left == z){
        z.parent.left = NULL;
    }
    else{
        z.parent.right = NULL;
    }
    delete z;
}

delete(T,z){
    if (z.left = NULL){
        x = z.right;
    }
    else{
        x = z.left;
    }
    if (z.parent.left = z){
        z.parent.left = x;
    }
    else{
        z.parent.right = x;
    }
    x.parent = z.parent;
    delete z;
}


*/



int main(){

    /*
            50
           /  \
          30  70
         / \  / \ 
        20 40 60 80    
    */
    struct node* root = NULL;//initializing a tree
    root = initialize(root, 50);
    initialize(root,30);
    initialize(root,70);
    initialize(root,20);
    initialize(root,40);
    initialize(root,80);
    initialize(root,60);

    cout<<"smallest: "<<minimum(root)<<endl;
    cout<<"largest: "<<maximum(root)<<endl;
    cout<<"search 80: "<<search(root, 80)<<endl;

    return 0;
}