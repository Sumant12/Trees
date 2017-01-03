//
//  BSTHeader.h
//  BST
//
//  Created by Sumanth Sai on 11/3/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#ifndef BSTHeader_h
#define BSTHeader_h
using namespace std;

class Dictionary{
    
public:
    int Key;
    int Value;
};

class Node{
public:
    Node* LeftChild;
    Node* RightChild;
    Dictionary Dict;
    
};



class BST {
    
    
public:
    Node* root;
    BST(){
        root = NULL;
    };
    Node* Search(Node* root, int key);
    Node* Insert(Node* node, int key,int value);
    int Height(Node* root);
    Node* Delete(Node* root, Node del);
    Node* MinNode(Node* root);
    void show(Node* root, ofstream* stream);
    void childshow(Node* root, ofstream* stream);
     void printInorder(Node* root);
    void leafshow(Node* root, int count,ofstream* stream);
    int AreElementsEqual(Node* cur, Node elem);
    Node* FindInorderSuccessor(Node* cur);
    void ReplaceCurrentNodeWithSuccessor(Node* cur, Node* temp);
};















#endif /* BSTHeader_h */
