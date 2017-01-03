//
//  main.cpp
//  BST
//
//  Created by Sumanth Sai on 11/3/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "BSTHeader.h"
#include "KDimentional.h"
#include <algorithm>
#include <math.h>
#include <list>
#include <map>
#include <sstream>
using namespace std;


int main(int argc, const char * argv[]) {
    //TestCase1
    cout<<"*******TestCase1*******"<<endl;
    BST b1 ;
    int b1_arr[20];
    b1_arr[0] = 0;
    b1_arr[1] = 1000;
    int List1[100][100];
    
    // list<int> l2;
    int Key,Value;
    b1.root = b1.Insert(b1.root, b1_arr[0], 0);
    List1[0][0] = b1_arr[0];
    List1[0][1] = 0;
    b1.root= b1.Insert(b1.root, b1_arr[1], 1);
    List1[1][0] = b1_arr[1];
    List1[1][1] = 1;
    for(int i =2;i<=15;i++){
        Key = (b1_arr[i-2]+b1_arr[i-1])/2;
        Value = i;
        b1.Insert(b1.root, Key, Value);
        b1_arr[i] = Key;
        List1[i][0] = Key;
        List1[i][1]= Value;
        
    }
    
    cout<<endl;
    cout<<"InOrder Traversal of BST after Data Insertion: "<<endl;
    cout<<endl;
    b1.printInorder(b1.root);
    cout<<endl;
    
    cout<<endl;
    ofstream *file = new ofstream;
    file->open("t1.dot");
    if(file->is_open())
    {
        b1.show(b1.root, file);
        file->close();
    }
    else
        cout<< "No file has been created!\n";
    
    cout<<"t1.dot file is generated"<<endl<<endl;
    
    //TestCase2
    
    cout<<"*******TestCase2*******"<<endl;
    KDiementional kd1;
    int kd1_arr[20];
    kd1_arr[0] = 0;
    kd1_arr[1] = 500;
    int List2[100][100];
    kd1.root = kd1.insertInto(kd1.root, kd1_arr[0], 500-kd1_arr[0],0);
    List2[0][0] = kd1_arr[0];
    List2[0][1] = 500-kd1_arr[0];
    List2[0][2] = 0;
    kd1.root= kd1.insertInto(kd1.root, kd1_arr[1],500-kd1_arr[1], 1);
    List2[1][0] = kd1_arr[1];
    List2[1][1] = 500-kd1_arr[1];
    List2[1][2] = 1;
    for(int i =2;i<=15;i++){
        Key = (kd1_arr[i-2]+kd1_arr[i-1])/2;
        Value = i;
        kd1.root= kd1.insertInto(kd1.root, Key,500-Key, Value);
        kd1_arr[i] = Key;
        List2[i][0] = Key;
        List2[i][1] = 500-Key;
        List2[i][2] = Value;
        
        
    }
    
    cout<<endl;
    cout<<"InOrder Traversal of KD after Data Insertion: "<<endl;
    cout<<endl;
    kd1.printInorder(kd1.root);
    cout<<endl;
    
    
    cout<<endl;
    ofstream *filekd1 = new ofstream;
    filekd1->open("t2.dot");
    if(filekd1->is_open())
    {
        kd1.show(kd1.root, filekd1);
        filekd1->close();
    }
    else
        cout<< "No file has been created!\n";
    
    cout<<"t2.dot file is generated"<<endl<<endl;
    
    cout<<endl;
    
    
    //TestCase3
    
    cout<<"*******TestCase3*******"<<endl<<endl;
    
    cout<<"Generating a list of 200 data items and Inserting data with distinct keys"<<endl<<endl;
    
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"n = No. of Nodes in the tree \t Height of BST T3 \t lg n \t \t√n "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;;
    BST b2;
    int b2_arr[220];
    for(int i =0;i<=200;i++){
        if(i%20 ==0){
            
            
            cout<<i<<"\t\t\t\t\t\t\t\t\t"<<b2.Height(b2.root)<<"\t\t\t\t"<<log(i)<<"\t\t"<<sqrt(i)<<endl;
        }
        int Key = rand();
        int Value = rand();
        b2.root =  b2.Insert(b2.root, Key, Value);
        b2_arr[i] = Key;
        
    }
    
    cout<<"-------------------------------------------------------------------------"<<endl;;
    cout<<endl<<endl;
    //TestCase4
    cout<<"*******TestCase4*******"<<endl<<endl;
    
    cout<<"Generating a list of 200 data items and Inserting data with distinct keys"<<endl<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"n = No. of Nodes in the tree \t Height of BST T4 \t lg n \t \t√n "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;;
    KDiementional kd2;
    for(int i =0;i<=200;i++){
        if(i%20 ==0){
            cout<<i<<"\t\t\t\t\t\t\t\t\t"<<kd2.Height(kd2.root)<<"\t\t\t\t"<<log(i)<<"\t\t"<<sqrt(i)<<endl;
        }
        int XKey = 0+rand()%(50);
        int YKey = 0+rand()%(50);
        int Value = i+1;
        kd2.root =  kd2.insertInto(kd2.root, XKey, YKey,Value);
        
    }
    
    cout<<"-------------------------------------------------------------------------"<<endl;
    
    
    //TestCase5
    cout<<"*******TestCase5*******"<<endl<<endl;
    cout<<"Inserting 10 elements chosen using Reservior Technique from List 1 randomly to the search tree"<<endl;
    BST b3;
    int input[16];
    for(int i =0;i<=15;i++){
        input[i] = i;
    }
    
    int k =10;
    
    int i;      int RandomReserve[k];
    for (i = 0; i < k; i++)
        RandomReserve[i] = input[i];
    
    
    srand(time(NULL));
    
    for (; i < 16; i++)
    {
        
        int j = rand() % (i+1);
        
        if (j < k)
            RandomReserve[j] = input[i];
    }
    
    
    for(int i =0;i<=9;i++){
        int randomNumber = RandomReserve[i];
        Key = List1[randomNumber][0];
        Value = List1[randomNumber][1];
        
        b3.root = b3.Insert(b3.root, Key, Value);
        
    }
    
    cout<<endl;
    cout<<"Inorder Traversal before deletion of root Node in BST"<<endl<<endl;;
    b3.printInorder(b3.root);
    
    ofstream *file1 = new ofstream;
    file1->open("5a.dot");
    if(file1->is_open())
    {
        b3.show(b3.root, file1);
        file1->close();
    }
    else
        cout<< "No file has been created!\n";
    
    cout<<endl;
    cout<<"5a.dot file is generated"<<endl<<endl;
    //Deleting the root
    cout<<"Deleting thr root element"<<endl;
    b3.root = b3.Delete(b3.root, *b3.root);
    //b3.root = b3.Delete(b3.root, b3.root->Dict.Key);
    cout<<endl;
    cout<<"Inorder Traversal After deletion of root Node in BST"<<endl<<endl;;
    b3.printInorder(b3.root);
    cout<<endl;
    ofstream *file2 = new ofstream;
    file2->open("5b.dot");
    if(file2->is_open())
    {
        b3.show(b3.root, file2);
        file2->close();
    }
    else
        cout<< "No file has been created!\n";
    
    cout<<"5b.dot file is generated"<<endl<<endl;
    //TestCase6
    cout<<"*******TestCase6*******"<<endl<<endl;
    cout<<"Inserting 10 elements chosen using Reservior Technique from List 1 randomly to the KD tree"<<endl;
    
    KDiementional kd3;
    int inputk[16];
    for(int i =0;i<=15;i++){
        inputk[i] = i;
    }
    
    int k1 =10;
    
    int i1;
    int RandomReserveK[k1];
    for (i1 = 0; i1 < k1; i1++)
        RandomReserveK[i1] = inputk[i1];
    
    
    srand(time(NULL));
    
    for (; i1 < 16; i1++)
    {
        
        int j = rand() % (i1+1);
        
        if (j < k1)
            RandomReserveK[j] = inputk[i1];
    }
    
    cout<<endl;
    for(int i =0;i<=9;i++){
        int randomNumber = RandomReserveK[i];
        int XKey = List2[randomNumber][0];
        int  YKey = List2[randomNumber][1];
        int Value = List2[randomNumber][2];
        
        kd3.root = kd3.insertInto(kd3.root, XKey,YKey, Value);
        
    }
    
    
    cout<<"Inorder Traversal before deletion of root Node in KD Tree"<<endl;
    kd3.printInorder(kd3.root);
    
    ofstream *filekd3 = new ofstream;
    
    filekd3->open("6a.dot");
    if(filekd3->is_open())
    {
        kd3.show(kd3.root, filekd3);
        filekd3->close();
    }
    else
        cout<< "No file has been created!\n";
    
    
    cout<<endl<<endl;
    cout<<"6a.dot is created"<<endl;
    //Deleting the root
    KDNode* nodedel = kd3.root;
    
    
    kd3.root = kd3.Kdelete(kd3.root, nodedel);
    cout<<endl;
    cout<<"Inorder Traversal After deletion of root Node in KD Tree"<<endl;
    kd3.printInorder(kd3.root);
    cout<<endl;
    ofstream *filekd3d = new ofstream;
    filekd3d->open("6b.dot");
    if(filekd3d->is_open())
    {
        kd3.show(kd3.root, filekd3d);
        filekd3d->close();
    }
    else
        cout<< "No file has been created!\n";
    
    cout<<endl;
    cout<<"6b.dot is created"<<endl;
    cout<<endl<<endl;
    //TestCase7
    
    BST b4 ;
    int b4_arr[40];
    b4_arr[0] = 0;
    b4_arr[1] = 1000;
    
    
    
    cout<<"TestCase7"<<endl;
    cout<<"*******TestCase7*******"<<endl<<endl;
    b4.root = b4.Insert(b4.root, b4_arr[1], 1);
    
    for(int i =2;i<=20;i++){
        
        if(i<=10){
            Key = (b4_arr[i-2]+b4_arr[i-1])/2;
            Value = i;
            b4.Insert(b4.root, Key, Value);
            b4_arr[i] = Key;
        }
        
        
        
        if(i>10){
            Key = b4_arr[i-10];
            Value =i;
            b4.Insert(b4.root, Key, Value);
            
            
        }
    }
    
    
    
    
    
    cout<<"Data Inserted into BST is"<<endl<<endl;
    b4.printInorder(b4.root);
    cout<<endl;
  
    cout<<"----------------------------------------------------------------------------------"<<endl;
    cout<<"stage   data item at root    the root (after deletion)     search for data with key"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    for(int i =0;i<=20;i++){
        
        
        
        Node* start = b4.root;
        
        if(b4.root!=NULL) {
            int Key = b4.root->Dict.Key;
            cout<<i;cout.width(14);cout<<"["<<start->Dict.Key<<","<<start->Dict.Value<<"]";
          
            b4.root = b4.Delete(b4.root, *b4.root);
         
            if(b4.root!=NULL) {
               cout.width(14); cout<<"["<<b4.root->Dict.Key<<","<<b4.root->Dict.Value<<"]";
                Node* search =new Node();
                search = b4.Search(b4.root, Key);
                if(search !=NULL){
                    cout.width(18);cout<<"["<<search->Dict.Key<<","<<search->Dict.Value<<"]"<<endl;
                }
                else{
                  cout.width(24);cout<<"Nill"<<endl;
                }
            }
            else{
                cout.width(20);cout<<"Nill";
                cout.width(24);cout<<"Nill"<<endl;
            }
        }
        
        if(i ==10){
            
            ofstream *filekd3d = new ofstream;
            filekd3d->open("t7.dot");
            if(filekd3d->is_open())
            {
                b4.show(b4.root, filekd3d);
                filekd3d->close();
            }
            else
                cout<< "No file has been created!\n";
            
        }
        
        
        

    }
    
    
    
    //TestCase8
    cout<<"*******TestCase8*******"<<endl<<endl;
    cout<<"Data Inserted for TestCase8 into KD Tress is"<<endl<<endl;
    KDiementional kd4;
    int kd4_arr[20];
    kd4_arr[0] = 0;
    kd4_arr[1] = 500;
    int List3[100][100];
    //  kd4.root = kd4.insertInto(kd4.root, kd4_arr[0], 500-kd4_arr[0],0);
    List3[0][0] = kd4_arr[0];
    List3[0][1] = 500-kd4_arr[0];
    List3[0][2] = 0;
    //  kd4.root= kd4.insertInto(kd4.root, kd4_arr[1],500-kd4_arr[1], 1);
    List3[1][0] = kd4_arr[1];
    List3[1][1] = 500-kd4_arr[1];
    List3[1][2] = 1;
    for(int i =2;i<=19;i++){
        Key = (kd4_arr[i-2]+kd4_arr[i-1])/2;
        Value = i;
        //     kd4.root= kd4.insertInto(kd4.root, Key,500-Key, Value);
        kd4_arr[i] = Key;
        List3[i][0] = Key;
        List3[i][1] = 500-Key;
        List3[i][2] = Value;
        
        
    }
    //        cout<<"2D Tree"<<endl;
    //        for (int i=0; i<=19; i++) {
    //            cout<<"[";
    //            cout<<List3[i][0]<<" "<<List3[i][1]<<" "<<List3[i][2];
    //
    //            cout<<"]";
    //        }
    //        cout<<endl;
    
    
    KDNode lis[20];
    for(int i =1;i<=6;i++){
        kd4.root = kd4.insertInto(kd4.root, List3[i][0], List3[i][1], List3[i][2]);
        KDNode kd ;
        kd.Dict.XKey =List3[i][0];
        kd.Dict.YKey =List3[i][1];
        kd.Dict.Value=List3[i][2];
        lis[i] = kd;
        
        //cout<<"["<<kd.Dict.XKey<<","<<kd.Dict.YKey<<","<<kd.Dict.Value<<"]"<<endl;
    }
    
    for(i = 7;i<=12;i++){
        kd4.root = kd4.insertInto(kd4.root, List3[i-6][0], List3[i][1], List3[i][2]);
        KDNode kd ;
        kd.Dict.XKey =List3[i-6][0];
        kd.Dict.YKey =List3[i][1];
        kd.Dict.Value=List3[i][2];
        lis[i] = kd;
        //cout<<"["<<kd.Dict.XKey<<","<<kd.Dict.YKey<<","<<kd.Dict.Value<<"]"<<endl;
    }
    for(i = 13;i<=18;i++){
        kd4.root = kd4.insertInto(kd4.root, List3[i-6][0], List3[i-12][1], List3[i][2]);
        KDNode kd ;
        kd.Dict.XKey =List3[i-6][0];
        kd.Dict.YKey =List3[i-12][1];
        kd.Dict.Value=List3[i][2];
        lis[i] = kd;
        //  cout<<"["<<kd.Dict.XKey<<","<<kd.Dict.YKey<<","<<kd.Dict.Value<<"]"<<endl;
    }
    
    
    kd4.printInorder(kd4.root);
    cout<<endl<<endl;
    
    
    
    int i7 =1;
    while(kd4.root !=NULL){
        
        cout<<"Value of i is "<<i7<<endl;
        cout<<"The root before deletion of root node is:"<<endl;
        cout<<"["<<kd4.root->Dict.XKey<<" "<<kd4.root->Dict.YKey<<" "<<kd4.root->Dict.Value<<"]"<<endl<<endl;
        cout<<"Deleting the root node"<<endl;
        kd4.root = kd4.Kdelete(kd4.root, kd4.root);
        cout<<"The root after deletion of root node is:"<<endl;
        if(kd4.root !=NULL){
            cout<<"["<<kd4.root->Dict.XKey<<" "<<kd4.root->Dict.YKey<<" "<<kd4.root->Dict.Value<<"]"<<endl<<endl;}
        int  data1 = lis[i7].Dict.XKey;
        int data2 = lis[i7].Dict.YKey;
        int data3 = lis[i7].Dict.Value;
        
        
        bool flag = kd4.searchNode(kd4.root, data1, data2,data3);
        
        
        cout<<"Node to be searched is:"<<endl;
        cout<<"["<<data1<<" "<<data2<<" "<<data3<<"]"<<endl<<endl;
        
        if(flag== 1){
            cout<<"Node Found: "<<endl;
            cout<<"["<<data1<<" "<<data2<<" "<<data3<<"]"<<endl;
            
            
        }
        else{
            cout<<"The Node is not found"<<endl<<endl;
        }
        
        cout<<"**********************"<<endl;
        i7++;
        
        if(i7 == 7){
            ofstream *filekd3d = new ofstream;
            filekd3d->open("t8a.dot");
            if(filekd3d->is_open())
            {
                kd4.show(kd4.root, filekd3d);
                filekd3d->close();
            }
            else{
                cout<< "No file has been created!\n";}
            cout<<endl;
           cout<<"t8a.dot is generated"<<endl<<endl;
        
        }
        
        if(i7 == 13){
            ofstream *filekd3d = new ofstream;
            filekd3d->open("t8b.dot");
            if(filekd3d->is_open())
            {
                kd4.show(kd4.root, filekd3d);
                filekd3d->close();
            }
            else
                cout<< "No file has been created!\n";
            cout<<endl;
            cout<<"t8b.dot is generated"<<endl<<endl;

        }
        
    }
    
    return 0;
}
