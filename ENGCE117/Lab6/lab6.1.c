#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

struct studentNode* AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa);

void InsertNode(struct studentNode *now,
                char name[], int age, char sex, float gpa);

void DelNode(struct studentNode **now);
void GoBack(struct studentNode **now);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start = NULL;
    struct studentNode *now = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsertNode(now, "three", 18, 'M', 3.33);
    ShowAll(start);

    InsertNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);

    GoBack(&now);

    DelNode(&now);
    ShowAll(start);

    DelNode(&now);
    ShowAll(start);

    DelNode(&now);
    ShowAll(start);

    return 0;
}

/* ---------- Functions ---------- */

struct studentNode* AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa) {

    struct studentNode *newNode, *walk;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        walk = *start;
        while (walk->next != NULL) {
            walk = walk->next;
        }
        walk->next = newNode;
        newNode->back = walk;
    }

    return newNode;
}

void InsertNode(struct studentNode *now,
                char name[], int age, char sex, float gpa) {

    struct studentNode *newNode;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = now;
    newNode->back = now->back;

    if (now->back != NULL) {
        now->back->next = newNode;
    }
    now->back = newNode;
}

void GoBack(struct studentNode **now) {
    if ((*now)->back != NULL) {
        *now = (*now)->back;
    }
}

void DelNode(struct studentNode **now) {
    struct studentNode *temp = *now;

    if (temp->next != NULL) {
        *now = temp->next;
        temp->next->back = temp->back;
    } else {
        *now = temp->back;
    }

    if (temp->back != NULL) {
        temp->back->next = temp->next;
    }

    free(temp);
}

void ShowAll(struct studentNode *walk) {
    printf("List : ");
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}