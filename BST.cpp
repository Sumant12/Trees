//
//  BST.cpp
//  BST
//
//  Created by Sumanth Sai on 11/10/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BSTHeader.h"
#include <algorithm>
#include<fstream>
using namespace std;

//Inserts Node into the BST
Node* BST::Insert(Node* root, int key,int value){
    if(root == NULL){
        root = new Node();
        root->Dict.Key = key;
        root->Dict.Value = value;
        root->LeftChild = NULL;
        root->RightChild = NULL;
    }
    else if(key <= root->Dict.Key){
        
        root->LeftChild = Insert(root->LeftChild, key, value);
        
    }
    else{
        root->RightChild =    Insert(root->RightChild, key, value);
        
    }
    
    
    return root;
    
}

//Searches for a key in the BST
Node* BST::Search(Node* root , int key){
    
    if(root == NULL || root->Dict.Key == key){
        return root;
    }
    else if(key<= root->Dict.Key){
        return  Search(root->LeftChild, key);
    }
    else{
        return  Search(root->RightChild, key);
    }
}

//Gives Height of the BST
int BST::Height(Node* root){
    
    int height =0;
    if(root == NULL){
        return -1;
    }
    
    else{
        int LeftValue = Height(root->LeftChild);
        int RightChild = Height(root->RightChild);
        int MaxValue = max(LeftValue,RightChild);
        height = MaxValue+1;
    }
    
    return height;
}

//Checks if two nodes are same
int BST::AreElementsEqual(Node* root, Node elem)
{
    if (root == NULL)return 0;
    else
    {
        if ((root->Dict.Key == elem.Dict.Key) && (root->Dict.Value == elem.Dict.Value))
            return 1;
    }
    return 0;
}

//Traversing throught the Tree to find the left most child
Node* BST::MinNode(Node* root){
    Node* n1 = root;
    while(n1->LeftChild != NULL){
        n1= n1->LeftChild;
    }
    return n1;
}

//Find the InOrderSuccessor
Node* BST::FindInorderSuccessor(Node* root)
{
    if (root == NULL)return NULL;
    while(root->LeftChild != NULL)
    {
        root = root->LeftChild;
    }
    return root;
}


//Delete function
Node* BST::Delete(Node* root, Node del){
    
    if(root==NULL){
        return root;
    }
    
    else if(root->Dict.Key <  del.Dict.Key){
        root->RightChild = Delete(root->RightChild, del);
        
        // root->LeftChild = Delete(root->LeftChild, del);
    }
    //    else if(root->Dict.Key >=  del.Dict.Key ){
    //
    //        //root->RightChild = Delete(root->RightChild, del);
    //        root->LeftChild = Delete(root->LeftChild, del);
    //
    //
    //    }
    
    else if(root->Dict.Key >=  del.Dict.Key){
        
        if(AreElementsEqual(root, del) == 1)
            
        {
            if(root->LeftChild == NULL && root->RightChild !=NULL){
                Node* tmp = root->RightChild;
                delete root;
                return tmp;
            }
            
            else if(root->RightChild == NULL && root->LeftChild !=NULL){
                Node* tmp = root->LeftChild;
                delete root;
                return tmp;
            }
            else if(root->LeftChild == NULL && root->RightChild == NULL){
                
                delete root;
                root = NULL;
            }
            else if(root->LeftChild != NULL && root->RightChild != NULL){
                Node* temp = FindInorderSuccessor(root->RightChild);
                root->Dict.Key= temp->Dict.Key;
                root->Dict.Value = temp->Dict.Value;
                root->RightChild= Delete(root->RightChild, *temp);
            }
        }
        else{
            root->LeftChild = Delete(root->LeftChild, del);
        }
    }
    return root;
}



//These three functions are used to generate dot files
void BST::leafshow(Node* root, int count,ofstream* stream){
    
    *stream<<"null"<< count <<"[shape=point]\n";
    *stream<<"\""<<root->Dict.Key<<","<<root->Dict.Value<<"\""<<"-> null"<< count <<"\n";
}

void BST::childshow(Node* root, ofstream* stream){
    
   static int count =0;
    if(root->LeftChild){
        
        *stream<<"\""<<root->Dict.Key<<","<<root->Dict.Value<<"\""<<"->"<<"\""<<root->LeftChild->Dict.Key<<","<<root->LeftChild->Dict.Value<<"\""<<"\n";
        childshow(root->LeftChild, stream);
    }
    else{
        leafshow(root,count++,stream);
    }
    
    
    if(root->RightChild){
        
        *stream<<"\""<<root->Dict.Key<<","<<root->Dict.Value<<"\""<<"->"<<"\""<<root->RightChild->Dict.Key<<","<<root->RightChild->Dict.Value<<"\""<<"\n";
        childshow(root->RightChild, stream);
    }
    
    else{
        leafshow(root,count++,stream);
    }
    
}
void BST::show(Node* root,ofstream* stream){
    *stream<<"digraph BST{\n";
    *stream<<" node [fontname=\"Arial\"];\n";
    if(!root){
        *stream << "\n";
        
    }
    
    else if(!root->RightChild && !root->LeftChild){
        *stream << root->Dict.Key<<"n";
    }
    
    else {
        childshow(root, stream);
        
    }
    
    *stream<< "}\n";
}
void BST::printInorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout <<"["<< root->Dict.Key<< " " << root->Dict.Value <<"]"<< "  ";
    
    printInorder(root->LeftChild);
    
    printInorder(root->RightChild);
    
    
    
}


