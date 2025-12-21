#include "document.h"
#include <stdlib.h>
#include <string.h>

Doc* create_document(int id) {
    Doc* d = (Doc*)malloc(sizeof(Doc));
    d->doc_id = id;
    d->content[0] = '\0';
    d->next = NULL;
    return d;
}

void add_document(Doc** head, Doc* doc) {
    doc->next = *head;
    *head = doc;
}

Doc* find_document(Doc* head, int id) {
    while (head) {
        if (head->doc_id == id)
            return head;
        head = head->next;
    }
    return NULL;
}
