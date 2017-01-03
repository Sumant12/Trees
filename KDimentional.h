//
//  KDimentional.h
//  BST
//
//  Created by Sumanth Sai on 11/10/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#ifndef KDimentional_h
#define KDimentional_h
using namespace std;


class KDDictionary{
    
public:
    int XKey;
    int YKey;
    int Value;
};

class KDNode{
public:
    KDNode* LeftChild;
    KDNode* RightChild;
    KDDictionary Dict;
    
};

class KDiementional{
public:
    KDNode* root;
    KDiementional(){
        root = NULL;
    }
    KDNode* insertInto(KDNode* root, int XKey,int YKey,int Value);
    KDNode* insert(KDNode* root, int XKey,int YKey,int Value,int depth);
    bool AreTwoPointsSame(KDNode* node1,int XKey,int YKey,int Value);
    bool searchNode(KDNode* root,int XKey,int YKey,int Value);
   bool search(KDNode* root, int XKey,int YKey,int Value,int depth);
    KDNode* FindMin(KDNode* root,int d,unsigned depth);
    KDNode* Minimum(KDNode* root,int d);
    int Height(KDNode* root);
    KDNode* Kdelete(KDNode* root,KDNode* del);
    KDNode* deleterec(KDNode* root,KDNode* del,int d);
    bool AreTwoNodesSame(KDNode* node1,KDNode* node2);
    void CopyNode(KDNode* node1,KDNode* node2);
    void printInorder(KDNode* root);
    void show(KDNode* root, ofstream* stream);
    void childshow(KDNode* root, ofstream* stream);
    KDNode* Maximum(KDNode* root,int d);
    KDNode* FindMax(KDNode* root, int d,unsigned depth);
    void leafshow(KDNode* root, int count,ofstream* stream);
};


#endif /* KDimentional_h */
