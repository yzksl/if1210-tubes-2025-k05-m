#include "../header/LinkedList.h"
#include "../header/Boolean.h"
#include <stdlib.h>
#include <string.h>

/* REALISASI FUNGSI DAN PROSEDUR */
void CreateLL(LinkedList *l) {
    l->head = NULL;
    l->size = 0;
}

LinkedListNode* CreateLLNode(int id, char name[50]) {
    // Allocate memory for node
    LinkedListNode* node;
    node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    // Set values for node
    node->id = id;
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}

void PutNodeInLastLL(LinkedList* l, LinkedListNode* NodeAdress) {
    if (l->size == 0) {
        l->head = NodeAdress;
    }
    else {
        LinkedListNode* prevnode = getLLNodeByIdx(l, l->size - 1);
        prevnode->next = NodeAdress;
    }
    l->size += 1;    
}

void PutNodeInIdxLL(LinkedList* l, LinkedListNode* NodeAddress, int idx) {
    if (idx == 0) {
        NodeAddress->next = l->head;
        l->head = NodeAddress;
    } else if (idx < l->size && idx > 0) {
        LinkedListNode* prevnode = getLLNodeByIdx(l, idx - 1);
        LinkedListNode* afternode = getLLNodeById(l, idx);
        prevnode->next = NodeAddress;
        NodeAddress->next = afternode;
        l->size += 1;
    } else if (idx == l->size) {
        putNodeInLastLL(l, NodeAddress);
    } else {
        printf("POSISI INVALID\n");
    }
}

LinkedListNode* getLLNodeById(const LinkedList* l, int id) {
    if (l->size == 0) {
        printf("LIST KOSONG\n");
        return NULL;
    } else {
        LinkedListNode* temp = l->head;
        for (int i = 0; i < l->size; ++i) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL; // tidak ditemukan node dengan id tersebut
}

LinkedListNode* getLLNodeByIdx(const LinkedList* l, int idx) {
    if (idx > 0 && idx < l->size) {
        LinkedListNode* temp = l->head;
        for (int i = 0; i < idx; ++i) {
            temp = temp->next;
        }
        return temp;
    } else if (idx == 0) {
        return l->head;
    } else {
        printf("POSISI INVALID\n");
        return NULL;
    }
}

LinkedListNode* getLLNodeByName(const LinkedList* l, char name[50]) {
    if (l->size == 0) {
        printf("LIST KOSONG\n");
        return NULL;
    } else {
        LinkedListNode* temp = l->head;
        for (int i = 0; i < l->size; ++i) {
            if (strcmp(temp->name, name) == 0) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL; // tidak ditemukan node dengan nama tersebut
}

boolean isLLEmpty(LinkedList l) {
    return (!l.size);
}

// boolean isLLNodeEmpty(LinkedListNode node) {
//     return (!(node.id && ));
// }

void FreeLL(LinkedList* l) {
    LinkedListNode* current = l->head;
    // get address of next node, free current, update current to next node, repeat
    while (current != NULL) {
        LinkedListNode* next = current->next;
        free(current);
        current = next;
    }
    l->head = NULL;
    l->size = 0;
}

void FreeNodeLL(LinkedList* l, LinkedListNode* node) {
    // if node is head
    if (l->head == node) {
        l->head = node->next;
        free(node);
        l->size -= 1;
        return;
    }

    // else, node not head
    // find node before node to delete
    LinkedListNode* temp = l->head;
    while(temp != NULL && temp->next != node) {
        temp = temp->next;
    }
    // if found, then free, otherwise do nothing
    if (temp != NULL) {
        temp->next = node->next;
        free(node);
        l->size -= 1;
    }
}