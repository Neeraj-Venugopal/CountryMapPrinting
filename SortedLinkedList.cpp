/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortedLinkedList.cpp
 * Author: Neeraj
 * 
 * Created on March 12, 2018, 11:15 AM
 */

#include "SortedLinkedList.h"
#include <string>
#include <algorithm>
#include "Node.h"

// Constructor
SortedLinkedList::SortedLinkedList()
{
   //cout << endl;
    head = nullptr;
}

// Inserting the node to correct postion in the list.
// Sorts based on the latitude in ascending order.
void SortedLinkedList::insert(Node* node)
{
    bool flag = false;
    
    Node* temp = new Node();
    temp->next = head;
    
    Node* prev = new Node();
    prev = temp;    

    if(head == NULL || temp->next->get_row() >= node->get_row())
    {
        //cout << "Neeraj" << endl;
        flag = true;
        node->next = head;
        head = node;
        
    }
    
    while( temp->next && flag == false)
    {
        if(node->get_row() <= temp->get_row())
        {        
            if(temp->next == head)
            {
                head = node;
                node->next = temp;
                flag = true;
                break;
            }
            else
            {              
                prev->next = node;
                node->next = temp;
                flag = true;
                break;
            }
            
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    
    if ( flag == false)
    {
       
        prev = head;
        while(prev->next)
        {
            prev = prev->next;
        }
        prev->next = node;
        node->next = NULL;
    }    
    
}

// Operator Overloading for the Purpose of printing
ostream& operator << (ostream& outs, const SortedLinkedList& list)
{
    Node *temp = list.head;
    int count = 0;
    int row = 0; 
    int col = 0;
    string name = "";
    string state = "";   
    
    string printMatrix[50][120];
    for(int i = 0; i < 50; i++)
        for(int j = 0; j < 120; j++)
            printMatrix[i][j] = ' ';
    
    while(temp->next)
    { 
        row = temp->get_row();
        col = temp->get_col();
        name = temp->get_name();
        state = temp->get_state();

        if( name.length() > 1)
        {
           printMatrix[row][col] = "*" + name + " " + state;
        }
        else
            printMatrix[row][col] = '#';
        
        temp = temp->next;
    }
  
    row = temp->get_row();
    col = temp->get_col();
    name = temp->get_name();
    state = temp->get_state();

    if( name.length() > 1)
    {
        printMatrix[row][col] = "*" + name + " " + state;
    }
    else
        printMatrix[row][col] = '#';
    
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 120; j++)
        {
            cout << printMatrix[i][j];
        }
        cout << endl;
    }   
    return outs;    
}