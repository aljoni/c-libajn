#pragma once

#include <stdlib.h>

/**
 * Linked-list implementation.
 *
 * @author Alex Nicholson
 */

typedef struct AJN_ListItem
{
    void *value;
    struct AJN_ListItem *next;
} AJN_ListItem;

typedef struct AJN_List
{
    size_t item_size;
    int size;
    struct AJN_ListItem *head;
    struct AJN_ListItem *tail;
} AJN_List;

extern AJN_List *AJN_List_Create(size_t item_size);

extern void AJN_List_Free(AJN_List *list);

extern void AJN_List_Append(AJN_List *list, void *src);

extern void AJN_List_AppendPtr(AJN_List *list, void *ptr);

extern void AJN_List_Prepend(AJN_List *list, void *src);

extern void AJN_List_PrependPtr(AJN_List *list, void *ptr);

extern void AJN_List_Get(AJN_List *list, int index, void *dst);

extern void *AJN_List_At(AJN_List *list, int index);

