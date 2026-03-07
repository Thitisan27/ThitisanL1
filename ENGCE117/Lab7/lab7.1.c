#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkedList {
protected:
    studentNode *start;   
    studentNode **now;    

public:
    LinkedList() {
        start = NULL;
        now = &start;
    }
    void InsNode(const char n[], int a, char s, float g) {
        studentNode *newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = NULL;

        studentNode **temp = &start;
        while (*temp != NULL) {
            temp = &((*temp)->next);
        }
        *temp = newNode;
    }
    void GoNext() {
        if (*now != NULL && (*now)->next != NULL) {
            now = &((*now)->next);
        }
    }
    void DelNode() {
        if (*now != NULL) {
            studentNode *temp = *now;
            *now = (*now)->next;
            delete temp;
        }
    }
    virtual void ShowNode() {
        if (*now != NULL) {
            printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }
};

class NewList : public LinkedList {
public:
    // ฟังก์ชันกลับไปเริ่มที่โหนดแรก
    void GoFirst() {
        now = &start;
    }
    virtual void ShowNode() {
        if (*now != NULL) {
            printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext(); 
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.GoNext();
    listB.ShowNode();

    listC = &listA;
    listC->ShowNode(); 

    listC = &listB;
    listC->ShowNode(); 

    return 0;
}