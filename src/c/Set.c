#include "Set.h"
#include "StructsInHospital.h"
#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createSet(Set* s, const int capacity) {
    if (capacity < 1) {
        printf("ERROR: KAPASITAS INVALID\n");
        return;
    }

    // allocate memory for the array
    char** newBuffer = (char**) malloc(capacity * sizeof(char*));
    if (newBuffer == NULL) {
        printf("ERROR: GAGAL ALOKASI MEMORI\n");
        return;
    }
    s->buffer = newBuffer;

    // initialize all elements (pointers to chars) to null
    for (int i = 0; i < capacity; ++i) {
        s->buffer[i] = NULL;
    }
    s->capacity = capacity;
    s->nEff = 0;
}

void freeSet(Set* s) {
    // free elements
    for (int i = 0; i < s->nEff; ++i) {
        free(s->buffer[i]);
        s->buffer[i] = NULL;
    }
    // free buffer
    free(s->buffer);
    s->buffer = NULL;

    s->nEff = 0;
    s->capacity = 0;
}

void addToSet(Set *s, const char* val) {
    if (isSetFull(s)) {
        printf("ERROR: SET PENUH\n");
        return;
    } else if (idxIsValInSet(s, val) != -1) {
        printf("ERROR: TERDAPAT VAL DALAM SET\n");
        return;
    }
    // allocate memory for the string
    s->buffer[s->nEff] = (char*) malloc(STR_MAX_SIZE * sizeof(char));
    strcpy(s->buffer[s->nEff], val);
    s->nEff += 1;
}

void removeFromSet(Set* s, const char* val) {
    int valAtIdx = idxIsValInSet(s, val);
    if (valAtIdx == -1) {
        return;
    }
    free(s->buffer[valAtIdx]);
    // rata kiri kan
    for (int i = valAtIdx; i < s->nEff - 1; ++i) {// nEff - 1 karena di indeks nEff - 1 tidak dapat strcpy dari nEff
        s->buffer[i] = s->buffer[i + 1]; // shift pointers
    }
    s->buffer[s->nEff - 1] = NULL;
    s->nEff -= 1;
}

int idxIsValInSet(const Set* s, const char* val) {
    for (int i = 0; i < s->nEff; ++i) {
        if (strcmp(s->buffer[i], val) == 0) {
            return i;
        }
    }
    return -1;
}

boolean isSetEmpty(const Set* s) {
    return s->nEff == 0;
}

boolean isSetFull(const Set* s) {
    return s->nEff == s->capacity;
}

void expandSet(Set* s, const int num) {
    if (num <= 0) {
        printf("INVALID NUM\n");
        return;
    }

    char** newBuffer = realloc(s->buffer, (s->capacity + num)*sizeof(char*));
    if (newBuffer == NULL) {
        printf("ERROR: GAGAL REALOKASI MEMORI\n");
        return;
    }
    // init pointers to null
    for (int i = s->capacity; i < s->capacity + num; ++i) {
        newBuffer[i] = NULL;
    }
    s->buffer = newBuffer;
    s->capacity += num;
}

void shrinkSet(Set* s, const int num) {
    if (num <= 0 || s->capacity < num || s->nEff > s->capacity - num) {
        printf("ERROR: NUM INVALID\n");
        return;
    }

    char** newBuffer = realloc(s->buffer, (s->capacity - num)*sizeof(char*));
    if (newBuffer == NULL) {
        printf("ERROR: GAGAL REALOKASI MEMORI\n");
        return;
    }
    s->buffer = newBuffer;
    s->capacity -= num;
}

void compressSet(Set* s) {
    if (s->nEff == 0) {
        printf("ERROR: LIST KOSONG\n");
        return;
    }

    char** newBuffer = realloc(s->buffer, (s->nEff)*sizeof(char*));
    if (newBuffer == NULL) {
        printf("ERROR: GAGAL REALOKASI MEMORI\n");
        return;
    }
    s->buffer = newBuffer;
    s->capacity = s->nEff;
}