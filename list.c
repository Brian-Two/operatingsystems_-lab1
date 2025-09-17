// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
  return mylist;
}

void list_free(list_t *l) {
  if (l == NULL) {
    return;
  }
  node_t *curr = l->head;
  while (curr != NULL) {
    node_t *next = curr->next;
    free(curr);
    curr = next;
  }
  l->head = NULL;
}

void list_print(list_t *l) {
  if (l == NULL) {
    printf("(null)\n");
    return;
  }
  node_t *curr = l->head;
  while (curr != NULL) {
    printf("%d->", curr->value);
    curr = curr->next;
  }
  printf("NULL\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 10024);
  char tbuf[20];

	buf[0] = '\0';
	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {
  if (l == NULL) {
    return 0;
  }
  int count = 0;
  node_t *curr = l->head;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  if (l == NULL) {
    return;
  }
  node_t *new_node = getNode(value);
  if (l->head == NULL) {
    l->head = new_node;
    return;
  }
  node_t *curr = l->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}
void list_add_to_front(list_t *l, elem value) {
     node_t *cur_node = (node_t *) getNode(value);

     /* Insert to front */
     node_t *head = l->head;  // get head of list

     cur_node->next = head;
     l->head = cur_node;
}

node_t * getNode(elem value) {
  node_t *mynode;

  mynode = (node_t *) malloc(sizeof(node_t));
  mynode->value = value;
  mynode->next = NULL;

  return mynode;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (l == NULL) {
    return;
  }
  int length = list_length(l);
  if (index < 1 || index > length + 1) {
    return; // out of range: do nothing
  }
  if (index == 1) {
    list_add_to_front(l, value);
    return;
  }
  int pos = 1;
  node_t *prev = l->head;
  while (prev != NULL && pos < index - 1) {
    prev = prev->next;
    pos++;
  }
  if (prev == NULL) {
    return;
  }
  node_t *new_node = getNode(value);
  new_node->next = prev->next;
  prev->next = new_node;
}

elem list_remove_from_back(list_t *l) {
  if (l == NULL || l->head == NULL) {
    return -1;
  }
  if (l->head->next == NULL) {
    elem val = l->head->value;
    free(l->head);
    l->head = NULL;
    return val;
  }
  node_t *prev = l->head;
  node_t *curr = l->head->next;
  while (curr->next != NULL) {
    prev = curr;
    curr = curr->next;
  }
  elem val = curr->value;
  prev->next = NULL;
  free(curr);
  return val;
}

elem list_remove_from_front(list_t *l) {
  if (l == NULL || l->head == NULL) {
    return -1;
  }
  node_t *to_remove = l->head;
  elem val = to_remove->value;
  l->head = to_remove->next;
  free(to_remove);
  return val;
}

elem list_remove_at_index(list_t *l, int index) {
  if (l == NULL || index <= 0 || l->head == NULL) {
    return -1;
  }
  int length = list_length(l);
  if (index > length) {
    return -1;
  }
  if (index == 1) {
    return list_remove_from_front(l);
  }
  node_t *prev = l->head;
  int pos = 1;
  while (prev != NULL && pos < index - 1) {
    prev = prev->next;
    pos++;
  }
  if (prev == NULL || prev->next == NULL) {
    return -1;
  }
  node_t *to_remove = prev->next;
  elem val = to_remove->value;
  prev->next = to_remove->next;
  free(to_remove);
  return val;
}

bool list_is_in(list_t *l, elem value) {
  if (l == NULL) {
    return false;
  }
  node_t *curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}
elem list_get_elem_at(list_t *l, int index) {
  if (l == NULL || index <= 0) {
    return -1;
  }
  int pos = 1;
  node_t *curr = l->head;
  while (curr != NULL && pos < index) {
    curr = curr->next;
    pos++;
  }
  if (curr == NULL) {
    return -1;
  }
  return curr->value;
}
int list_get_index_of(list_t *l, elem value) {
  if (l == NULL) {
    return -1;
  }
  int pos = 1;
  node_t *curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) {
      return pos;
    }
    curr = curr->next;
    pos++;
  }
  return -1;
}

