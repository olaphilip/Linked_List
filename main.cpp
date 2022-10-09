/*
Olasunkanmi Ajiromoke
P-Queue
Linked List
To compile this project, you need a file named input.txt 
that takes all the enqueue and dequeue input
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node 
{
public:
    string fName;
    int number;
    int classNum;
    Node* next;
};

//store the head of the linked list
Node* head = new Node();

void enqueue(string fName, int number, int classNum)
{
    Node* student = new Node();
    student->fName = fName;
    student->number = number;
    student->classNum = classNum;
    
    //enqueue at the beginning
    if (head == NULL){
        student->next = head;
        head = student;
    }
    
    //insert anywhere else
    else{
        Node* st = head;
        while(st->next != NULL){
            st = st->next;
        }
        student->next = st->next;
        st->next = student;
    }
    cout << "Enqueue successful\n";
}

void dequeue (Node** head_ref)
{
    Node* current = *head_ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

void print()
{
    Node* p = head;
    if (p == NULL) {
        cout << "Queue empty";
    }
    else{
        while (p != NULL) {
            cout << p->fName << " " << p->number << ", " << p->classNum << endl;
            p = p->next;
        }
    }
}

int main()
{
    Node* head = NULL;
    
    std::ifstream infile("input.txt");
    if (infile.is_open()) {
        std::string read;
        while (infile >> read){
            if (read[0] = '+') {
                try{
                    std::string fName, number, classNum;
            
                infile >> fName >> number >> classNum;
                
                int num = std::stoi(number);
                int cNum = std::stoi(classNum);
            
                enqueue(fName, num, cNum);
                print();
                }
                catch (const std::invalid_argument& ia){
                    std::cerr << "Invalid argument: " << ia.what() << '\n';
                }
            }
            else {
                dequeue(&head);
            }
        }
        infile.close();
        return 0;
    }
    
    else{
        std::cout << "file does not exist";
        return 0;
    }
}
