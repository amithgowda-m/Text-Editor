#ifndef DOCUMENT_H
#define DOCUMENT_H

typedef struct Doc {
    int doc_id;
    char content[10000];
    struct Doc* next;
} Doc;

Doc* create_document(int id);
void add_document(Doc** head, Doc* doc);
Doc* find_document(Doc* head, int id);

#endif
