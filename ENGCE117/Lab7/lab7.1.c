#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct LinkedList {
    struct studentNode *start;
    struct studentNode *now;
};

void initList(struct LinkedList *list) {
    list->start = NULL;
    list->now = NULL;
}

void InsNode(struct LinkedList *list, char n[], int a, char s, float g) {

    struct studentNode *newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    if (newNode == NULL) return;

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    struct studentNode **pp = &(list->start);

    while (*pp != NULL)
        pp = &((*pp)->next);

    *pp = newNode;
}

void DelNode(struct LinkedList *list) {

    if (list->start == NULL)
        return;

    struct studentNode *removeNode = list->start;
    list->start = removeNode->next;
    free(removeNode);
}

void GoNext(struct LinkedList *list) {

    if (list->now == NULL)
        list->now = list->start;
    else
        list->now = list->now->next;
}

int main() {

    struct LinkedList listA, listB;
    struct LinkedList *listC;

    initList(&listA);
    initList(&listB);

    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);

    GoNext(&listA);
    GoNext(&listA);

    printf("%s %d %c %.2f\n",
           listA.now->name,
           listA.now->age,
           listA.now->sex,
           listA.now->gpa);

    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);

    DelNode(&listB);

    printf("%s %s\n",
           listB.start->next->name,
           listB.start->name);

    listC = &listA;

    printf("%s %d %c %.2f\n",
           listC->start->name,
           listC->start->age,
           listC->start->sex,
           listC->start->gpa);

    listC = &listB;

    printf("%s %s\n",
           listC->start->next->name,
           listC->start->name);

    return 0;
}