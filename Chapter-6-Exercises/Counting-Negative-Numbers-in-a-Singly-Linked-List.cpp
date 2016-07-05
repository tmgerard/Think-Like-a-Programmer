/*
*   Problem: Counting Negative Numbers in a Singly Linked List
*
*   Write a recursive function that is given a singly linked list where the data
*   type is integer. The function returns the count of negative numbers in the
*   list.
*/

#include <iostream>

struct exListNode
{
    int data;
    exListNode* next;
};

typedef exListNode* listPtr;

int countNegative(listPtr head);

int main()
{
    listPtr numbers;

    exListNode* node1 = new exListNode;
    node1->data = -1;

    exListNode* node2 = new exListNode;
    node1->data = -1;

    exListNode* node3 = new exListNode;
    node1->data = -1;

    exListNode* node4 = new exListNode;
    node1->data = 1;

    numbers = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    node1 = node2 = node3 = node4 = NULL;

    int negativeCount = countNegative(numbers);

    std::cout << "Count = " << negativeCount << std::endl;

    return 0;
}

int countNegative(listPtr head)
{
    if (head == NULL) return 0;
    int listCount = countNegative(head->next);
    if (head->data < 0) listCount++;
    return listCount;
}
