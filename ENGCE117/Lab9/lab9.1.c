#include <iostream>
#include <fstream>
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

    void DelNode() {
        if (*now != NULL) {
            studentNode *temp = *now;
            *now = (*now)->next;
            delete temp;
            printf("Deleted successfully!\n");
        }
    }

    void GoFirst() { now = &start; }
    
    void GoNext() {
        if (*now != NULL) now = &((*now)->next);
    }

    void ShowAll() {
        studentNode *temp = start;
        while (temp != NULL) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }

    int FindNode(char n[]) {
        studentNode **temp = &start;
        while (*temp != NULL) {
            if (strcmp((*temp)->name, n) == 0) {
                now = temp;
                return 1;
            }
            temp = &((*temp)->next);
        }
        return 0;
    }

    void EditNode(char n[], int a, char s, float g) {
        if (*now != NULL) {
            strcpy((*now)->name, n);
            (*now)->age = a;
            (*now)->sex = s;
            (*now)->gpa = g;
        }
    }

    studentNode* getStart() { return start; }
};

void AddData(LinkedList *l) {
    char n[20], s; int a; float g;
    printf("Enter Name, Age, Sex, GPA: ");
    scanf("%s %d %c %f", n, &a, &s, &g);
    l->InsNode(n, a, s, g);
}

void EditData(LinkedList *l) {
    char n[20], newN[20], s; int a; float g;
    printf("Enter name to edit: ");
    scanf("%s", n);
    if (l->FindNode(n)) {
        printf("Enter NEW Name, Age, Sex, GPA: ");
        scanf("%s %d %c %f", newN, &a, &s, &g);
        l->EditNode(newN, a, s, g);
    } else {
        printf("Not found!\n");
    }
}

void FindData(LinkedList *l) {
    char n[20];
    printf("Enter name to find: ");
    scanf("%s", n);
    if (l->FindNode(n)) {
        printf("Found! Data: ");
        l->GoFirst();
        l->FindNode(n);
    }
}

void writefile(LinkedList *l) {
    ofstream out("student.txt");
    studentNode *temp = l->getStart();
    while (temp != NULL) {
        out << temp->name << " " << temp->age << " " << temp->sex << " " << temp->gpa << endl;
        temp = temp->next;
    }
    out.close();
}

void readfile(LinkedList *l) {
    ifstream in("student.txt");
    char n[20], s; int a; float g;
    while (in >> n >> a >> s >> g) {
        l->InsNode(n, a, s, g);
    }
    in.close();
}

int main() {
    LinkedList listA;
    int menu;

    readfile(&listA); 

    do {
        printf("\n--- Menu (1)Add (2)Edit (3)Delete (4)Find (5)Show (0)Exit : ");
        scanf("%d", &menu);

        switch(menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: listA.DelNode(); break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
    } while (menu != 0);

    writefile(&listA);
    return 0;
}