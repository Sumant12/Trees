//
//  KDimentional.cpp
//  BST
//
//  Created by Sumanth Sai on 11/10/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "KDimentional.h"
#include <algorithm>
#include<fstream>
using namespace std;

//Wrapper for Insert
KDNode* KDiementional::insertInto(KDNode* root,int XKey,int YKey,int Value){
    
    return insert(root, XKey, YKey,Value, 0);
}

//Inserts Node into KD Tree
KDNode* KDiementional::insert(KDNode* root,int XKey,int YKey,int Value,int depth){
    
    
    if(root == NULL){
        root = new KDNode();
        root->Dict.XKey = XKey;
        root->Dict.YKey = YKey;
        root->Dict.Value = Value;
        root->LeftChild = NULL;
        root->RightChild = NULL;
        return root;
    }
    
    unsigned cd = depth%2;
    int current ;
    int rootEle ;
    
    
    if(cd == 0){
        current = XKey;
        rootEle = root->Dict.XKey;
    }
    else{
        
        current = YKey;
        rootEle = root->Dict.YKey;
    }
    
    if(current<=rootEle){
        root->LeftChild = insert(root->LeftChild, XKey, YKey, Value, depth+1);
    }
    else{
        root->RightChild = insert(root->RightChild, XKey, YKey, Value, depth+1);
    }
    return root;
}

//Checks if two points are same
bool KDiementional::AreTwoPointsSame(KDNode* node1,int XKey,int YKey,int Value){
    
    if(node1->Dict.XKey == XKey && node1->Dict.YKey == YKey && node1->Dict.Value == Value){
        return true;
    }
    return false;
}

//Searches for a node
bool KDiementional::searchNode(KDNode* root,int XKey,int YKey,int Value){
    return search(root,XKey,YKey,Value,0);
}

//Searches for a node in KD Tree
bool KDiementional::search(KDNode* root,int XKey,int YKey,int Value,int depth){
    if(root == NULL){
        return false;
    }
    if(AreTwoPointsSame(root, XKey,YKey,Value)){
        //        KDNode* k1 = new KDNode() ;
        //        k1->Dict.XKey = XKey;
        //        k1->Dict.YKey = YKey;
        //        k1->Dict.Value = Value;
        //        return k1;
        return true;
    }
    
    unsigned cd = depth%2;
    int current ;
    int rootEle ;
    
    
    if(cd == 0){
        current = XKey;
        rootEle = root->Dict.XKey;
    }
    else{
        
        current = YKey;
        rootEle = root->Dict.YKey;
    }
    
    if(current<=rootEle){
        return search(root->LeftChild, XKey, YKey,Value ,depth+1);
    }
    else{
        return search(root->RightChild, XKey, YKey,Value, depth+1);
    }
    
    //return root;
}


int KDiementional::Height(KDNode* root){
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
    
    return height;}
int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

//Find Min Node in KD Tree
KDNode* KDiementional::Minimum(KDNode* root,int d){
    return FindMin(root, d, (d+1)%2);
}


KDNode* KDiementional::FindMin(KDNode* root, int d,unsigned depth){
    
    if(root == NULL){
        return root;
    }
    unsigned cd = depth% 2;
    
    //If Curremt Dimension is same as the requested Dimension
    
    //If Current Dimension is different from the requested Dimension
    int current ;
    int l =100000;
    int r = 100000;
    KDNode* FindMinOfLeftNode = new KDNode();
    KDNode* FindMinOfRightNode = new KDNode();
    if(d == 0){
        
        if(cd ==d){
            if(root->LeftChild == NULL){
                return root;}
            return FindMin(root->LeftChild,d,depth+1);
            
        }
        current = root->Dict.XKey;
        //rootEle = root->Dict.XKey;
        if(root->LeftChild != NULL){
            FindMinOfLeftNode = FindMin(root->LeftChild, d, depth+1);
            l =FindMinOfLeftNode->Dict.XKey;}
        //       cout<<"Value of left min node is"<<endl;
        //        cout<<"["<<FindMinOfLeftNode->Dict.XKey<<","<<FindMinOfLeftNode->Dict.YKey<<","<<FindMinOfLeftNode->Dict.Value<<"]"<<endl;
        if(root->RightChild != NULL){
            FindMinOfRightNode = FindMin(root->RightChild, d, depth+1);
            r =FindMinOfRightNode->Dict.XKey;
        }
        //        cout<<"Value of right min node is"<<endl;
        //           cout<<"["<<FindMinOfRightNode->Dict.XKey<<","<<FindMinOfRightNode->Dict.YKey<<","<<FindMinOfRightNode->Dict.Value<<"]"<<endl;
        int minValue = (l <= current) ? l : ((r <= current) ? r : current);
        if(minValue== l){
            return FindMinOfLeftNode;
        }
        if(minValue ==r){
            return FindMinOfRightNode;
        }
        if(minValue == current){
            return root;
        }
        
    }
    else{
        if(cd ==d){
            if(root->LeftChild == NULL){
                return root;}
            return FindMin(root->LeftChild,d,depth+1);
            
        }
        
        current = root->Dict.YKey;
        //rootEle = root->Dict.XKey;
        if(root->LeftChild != NULL){
            FindMinOfLeftNode = FindMin(root->LeftChild, d, depth+1);
            l =FindMinOfLeftNode->Dict.YKey;}
        if(root->RightChild != NULL){
            FindMinOfRightNode = FindMin(root->RightChild, d, depth+1);
            r =FindMinOfRightNode->Dict.YKey;
        }
        
        
        int minValue = (l <= current) ? l : ((r <= current) ? r : current);
        if(minValue== l){
            return FindMinOfLeftNode;
        }
        if(minValue ==r){
            return FindMinOfRightNode;
        }
        
        if(minValue == current){
            return root;
        }
        
        
        
    }
    return root;
}


//Copies the data of one node into the other
void KDiementional::CopyNode(KDNode* node1,KDNode* node2){
    
    node1->Dict.XKey = node2->Dict.XKey;
    node1->Dict.YKey = node2->Dict.YKey;
    node1->Dict.Value = node2->Dict.Value;
}

//Checks if two nodes are same
bool KDiementional::AreTwoNodesSame(KDNode* node1,KDNode* node2){
    
    if(node1->Dict.XKey == node2->Dict.XKey && node1->Dict.YKey == node2->Dict.YKey && node1->Dict.Value == node2->Dict.Value){
        return true;
    }
    return false;
}

KDNode* KDiementional::Kdelete(KDNode* root,KDNode* del){
    
    
    return deleterec(root, del, 0);
}

//Deletes a node from the KD tree and maintains the structure of KD
KDNode* KDiementional::deleterec(KDNode* root,KDNode* del,int depth){
    
    if(root == NULL){
        // delete root;
        return NULL;
    }
    
    int cd= depth%2;
    
    //Found the node which is to be deleted
    if(AreTwoNodesSame(root, del)){
        if(root->RightChild !=NULL){
            
            KDNode* minNode = FindMin(root->RightChild, cd,(cd+1)%2);
            CopyNode(root, minNode);
            root->RightChild = deleterec(root->RightChild, minNode, depth+1);
            
        }
        
        else if(root->LeftChild != NULL){
            
            
            KDNode* minNode = FindMin(root->LeftChild, cd,(cd+1)%2);
            
            CopyNode(root, minNode);
            root->RightChild = deleterec(root->LeftChild, minNode, depth+1);
            root->LeftChild = NULL;
        }
        else{
            delete root;
            return NULL;
            
        }
        return root;
    }
    
    //Current Node is Not Found,Recurse down
    
    
    if(cd ==0){
        if(del->Dict.XKey <=root->Dict.XKey ){
            //if(root->Dict.XKey <= del->Dict.XKey){
            root->LeftChild = deleterec(root->LeftChild, del, depth+1);
            
        }
        
        else{
            root->RightChild = deleterec(root->RightChild, del, depth+1);
        }}
    if(cd ==1){
        if(del->Dict.YKey <=root->Dict.YKey ){
            root->LeftChild = deleterec(root->LeftChild, del, depth+1);
        }
        else{
            root->RightChild = deleterec(root->RightChild, del, depth+1);
        }
    }
    
    
    
    return root;
}

//Inorder traversal of KD tree
void KDiementional::printInorder(KDNode* root){
    if(root == NULL){
        return ;
    }
    cout <<"["<< root->Dict.XKey << "  " << root->Dict.YKey << "   " << root->Dict.Value <<"]"<<"  " ;
    printInorder(root->LeftChild);
    
    
    printInorder(root->RightChild);
    
    
    
}

void KDiementional::leafshow(KDNode* root, int count,ofstream* stream){
    
    *stream<<"null"<< count <<"[shape=point]\n";
    *stream<<"\""<<root->Dict.XKey<<","<<root->Dict.YKey<<","<<root->Dict.Value<<"\""<<"-> null"<<count <<"\n";
}


void KDiementional::childshow(KDNode* root, ofstream* stream){
    
    static int count =0;
    if(root->LeftChild){
        
        
        
        *stream<<"\""<<root->Dict.XKey<<","<<root->Dict.YKey<<","<<root->Dict.Value<<"\""<<"->"<<"\""<<root->LeftChild->Dict.XKey<<","<<root->LeftChild->Dict.YKey<<","<<root->LeftChild->Dict.Value<<"\""<<"\n";
        childshow(root->LeftChild, stream);
        
    }
    else{
        leafshow(root,count++,stream);
    }
    
    if(root->RightChild){
        *stream<<"\""<<root->Dict.XKey<<","<<root->Dict.YKey<<","<<root->Dict.Value<<"\""<<"->"<<"\""<<root->RightChild->Dict.XKey<<","<<root->RightChild->Dict.YKey<<","<<root->RightChild->Dict.Value<<"\""<<"\n";
        childshow(root->RightChild, stream);
        
    }
    
    else{
        leafshow(root,count++,stream);
    }
    
    
}

void KDiementional::show(KDNode* root,ofstream* stream){
    *stream<<"digraph KD{\n";
    *stream<<" node [fontname=\"Arial\"];\n";
    if(!root){
        *stream << "\n";
        
    }
    
    else if(!root->RightChild && !root->LeftChild){
        *stream << "\""<<root->Dict.XKey<<","<<root->Dict.YKey<<","<<root->Dict.Value<<"\""<<"n";
    }
    
    else {
        childshow(root, stream);
        
    }
    
    *stream<< "}\n";
}


