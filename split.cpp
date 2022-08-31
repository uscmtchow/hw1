/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>

/* Add a prototype for a helper function here if you need */
Node*& helper(Node*& in, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
    /* Add code here */
    // WRITE YOUR CODE HERE
    Node* random = helper(in, odds, evens);

    // if odd
    if (random->value % 2 == 1) {
        random->next = odds;
        odds = random;
    }
    // if even
    else {
        random->next = evens;
        evens = random;
    }

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE
Node*& helper(Node*& in, Node*& odds, Node*& evens) {
    Node* temp;
    if (in->next == nullptr) {
        return in;
    }
    else {
        temp = helper(in->next, odds, evens);
    }

    // if odd
    if (temp->value % 2 == 1) {
        temp->next = odds;
        odds = temp;
        return in;
    }
    // if even
    else {
        temp->next = evens;
        evens = temp;
        return in;
    }
}
