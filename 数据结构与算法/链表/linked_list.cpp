#include <iostream>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct DNode {
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;

LNode *head = NULL;

void insertHead(int key) {
    LNode *newNode = new LNode;
    newNode->data = key;
    newNode->next = head;

    head = newNode;
}

void ListInsert(LinkList head, int key) {
    LNode *newNode = new LNode;
    newNode->data = key;
    newNode->next = head->next;
    head->next = newNode;
}

bool ListInsert(DLinkList pHead, int key) {
    DNode* newNode = new DNode;
    newNode->data = key;

    newNode->next = pHead->next;
    newNode->prior = pHead;

    if(pHead->next != NULL) {
        pHead->next->prior = newNode;
    }
    pHead->next = newNode;
    return true;
}

void insertLast(int key) {
    struct LNode *newNode = new LNode;
    newNode->data = key;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct LNode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void ListInsertLast(int key) {
    LNode *newNode = new LNode;
    newNode->data = key;
    newNode->next = NULL;

    LNode *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    head->data = head->data + 1;
}



bool deleteNode(struct LNode **head, int key) {
    struct LNode *temp;
    if((*head)->data == key) {
        temp = *head;
        *head = (*head)->next;
        delete temp;
        return true;
    } else {
        struct LNode *prev = *head;
        while(prev->next != NULL) {
            if(prev->next->data == key) {
                temp = prev->next;
                prev->next = temp->next;
                delete temp;
                return true;
            }
            prev = prev->next;
        }
        return false;
    }
}

bool deleteNodee(LNode **head, int key) {
    LNode *temp;
    LNode *prev = *head;
    while(prev->next != NULL) {
        if(temp->next->data == key) {
            temp = prev->next;
            prev->next = temp->next;
            delete temp;
            return true;
        }
        prev = prev->next;
    }
    return false;
}

struct LNode* searchNode(struct LNode *head, int key) {
    struct LNode *temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    DNode* head = new DNode();
    head->data = NULL;
    head->prior = NULL;
    head->next = NULL;
}