#include <iostream>
#include "split.h"

int main() {

    Node* odds = nullptr;
    Node* evens = nullptr;

    //generate list
    Node* fifth = new Node(5, nullptr);
    Node* fourth = new Node(4, fifth);
    Node* third = new Node(3, fourth);
    Node* second = new Node(2, third);
    Node* first = new Node(1, second);

    split(first, odds, evens);

    //print odds
    Node* tempNode = odds;
    std::cout << "odds: " << std::endl;
    while (tempNode != nullptr) {
        std::cout << tempNode->value << " ";
        tempNode = tempNode->next;
    }

    std::cout << std::endl;

    //print evens
    tempNode = evens;
    std::cout << "evens: " << std::endl;
    while (tempNode != nullptr) {
        std::cout << tempNode->value << " ";
        tempNode = tempNode->next;
    }

    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    // delete odds->next;
    // delete odds;
    // // delete evens->next;
    // delete evens;

    return 0;
}
