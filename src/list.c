#include "ajn/list.h"
#include <string.h>

AJN_List *AJN_List_Create(size_t item_size)
{
    AJN_List *list = malloc(sizeof(AJN_List));

    list->item_size = item_size;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void AJN_List_Free(AJN_List *list)
{
    AJN_ListItem *item = list->head, *next;
    while (item != NULL) {
        next = item->next;
        if (item->value != NULL) {
            free(item->value);
        }
        free(item);
        item = next;
    }
}

void AJN_List_Append(AJN_List *list, void *src)
{
    AJN_ListItem *item = malloc(sizeof(AJN_ListItem));
    item->value = malloc(list->item_size);
    memcpy(item->value, src, list->item_size);

    if (list->head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        item->next = list->tail;
        list->tail = item;
    }
}

void AJN_List_AppendPtr(AJN_List *list, void *ptr)
{
    AJN_ListItem *item = malloc(sizeof(AJN_ListItem));
    item->value = ptr;

    if (list->head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        item->next = list->tail;
        list->tail = item;
    }
}

void AJN_List_Prepend(AJN_List *list, void *src)
{
    AJN_ListItem *item = malloc(sizeof(AJN_ListItem));
    item->value = malloc(list->item_size);
    memcpy(item->value, src, list->item_size);

    if (list->head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        item->next = list->head;
        list->head = item;
    }
}

void AJN_List_PrependPtr(AJN_List *list, void *ptr)
{
    AJN_ListItem *item = malloc(sizeof(AJN_ListItem));
    item->value = ptr;

    if (list->head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        item->next = list->head;
        list->head = item;
    }
}

void AJN_List_Insert(AJN_List *list, int index, void *src)
{
    if (index < 0 || index > list->size) {
        return;
    }

    AJN_ListItem *prev = list->head;
    for (int i = 0; i < list->size; ++i) {
        prev = prev->next;
    }

    AJN_ListItem *item = malloc(sizeof(AJN_ListItem));
    item->value = malloc(list->item_size);
    item->next = prev->next;
    prev->next = item;

    memcpy(item->value, src, list->item_size);
}

void AJN_List_InsertPtr(AJN_List *list, int index, void *ptr)
{
    if (index < 0 || index > list->size) {
        return;
    }

    AJN_ListItem *prev = list->head;
    for (int i = 0; i < list->size; ++i) {
        prev = prev->next;
    }

    AJN_ListItem *item = malloc(sizeof(AJN_ListItem));
    item->value = ptr;
    item->next = prev->next;
    prev->next = item;
}

void AJN_List_Get(AJN_List *list, int index, void *dst)
{
    AJN_ListItem *item = list->head;
    for (int i = 0; i < index; ++i) {
        item = item->next;
        if (item == NULL) {
            return;
        }
    }
    memcpy(dst, item->value, list->item_size);
}

void *AJN_List_At(AJN_List *list, int index)
{
    AJN_ListItem *item = list->head;
    for (int i = 0; i < index; ++i) {
        item = item->next;
        if (item == NULL) {
            return NULL;
        }
    }
    return item->value;
}

void AJN_List_Remove(AJN_List *list, int index)
{
    AJN_ListItem *prev = NULL, *item = list->head;
    for (int i = 0; i < index; ++i) {
        prev = item;
        item = item->next;
    }

    prev->next = item->next;
    if (item->value != NULL) {
        free(item->value);
    }
    free(item);
}

