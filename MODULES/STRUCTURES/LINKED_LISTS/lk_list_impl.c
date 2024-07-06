#include "lk_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static int gbuffernum;

char **split_str_buffer(int size, char *str) {
  char **tmp;

  // ALLOCATIONS
  int bufferNum = strlen(str) / size;
  gbuffernum = bufferNum;
  tmp = (char **)malloc(size * sizeof(char *));
  for (int j = 0; j < size; j++) {
    *(tmp + j) = (char *)malloc((sizeof(char) * bufferNum + 1));
    *(*(tmp + j) + bufferNum) = '\0';
  }
  // COPYING
  for (int i = 0; i < size; i++) {
    for (int l = 0; l < bufferNum; l++) {
      *(*(tmp + i) + l) = *(str + bufferNum * i + l);
    }
  }
  return tmp;
}

char *custom_uid_hash(int mysize, char *mybody) {

  // DECLERATIONS
  int hashNum[6] = {0, 1, 2, 3, 4, 5};
  char *finalStr;
  finalStr = (char *)malloc(sizeof(char) * 27);
  srand(strlen(mybody));

  // BASIC ASSIGNEMENTS
  hashNum[0] = mysize;
  hashNum[5] = rand() % 50;

  // BODY TO HASH

  char **tmp0 = split_str_buffer(4, mybody);

  for (int i = 0; i < 4; i++) {
    for (int k = 0; *(*(tmp0 + i) + k) != '\0'; k++) {
      hashNum[1 + i] = hashNum[1 + i] % 21 + (int)*(*(tmp0 + i) + k) % 21;
    }
  }

  // NUM CONCATE

  for (int l = 0; l < 6; l++) {

    finalStr[l] = hashNum[l] + 22 + '0';
    finalStr[l + 6] = (((int)finalStr[l] + (int)finalStr[l % 3]) % 21) + '0';
    finalStr[l + 12] = (((int)finalStr[l] + (int)finalStr[l % 4]) % 21) + '0';
    finalStr[l + 18] = (((int)finalStr[l] + (int)finalStr[l % 5]) % 21) + '0';
    finalStr[24] = (((int)finalStr[l + 6] + (int)finalStr[l + 12]) % 21) + '0';
    finalStr[25] = (((int)finalStr[l + 18] + (int)finalStr[25 - l]) % 21) + '0';
  }
  finalStr[26] = '\0';

  // NUM TO STR

  // FREE D_POINTER TMP0
  for (int m = 0; m < 4; m++) {
    free(*(tmp0 + m));
  }
  free(tmp0);
  // RETURN POINTER
  return finalStr;
};

///////////////////////////////////////////////////////////////////////////

struct LinkedList *create_new_list(int size, char *body) {
  struct LinkedList *tmp =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp->size = size;
  tmp->body = body;
  tmp->uid = custom_uid_hash(tmp->size, tmp->body);
  tmp->next_Ptr = NULL;
  return tmp;
}

void print_struct_linked_list(struct LinkedList *list) {
  printf("\nThe Size is %d\nThe Body is %s\nThe UID is %s\nThe Next "
         "Address is %p \n",
         list->size, list->body, list->uid, list->next_Ptr);
}
//
void show_all_list(struct LinkedList *head) {
  struct LinkedList *tmp = head;
  while (tmp != NULL) {
    print_struct_linked_list(tmp);
    if (tmp->next_Ptr != NULL) {

#ifdef DEBUG
      printf("\nAddress : %p , PoiunterAddr: %p \n", tmp, tmp->next_Ptr);
#endif

      tmp = tmp->next_Ptr;

#ifdef DEBUG
      printf("Address : %p , PoiunterAddr: %p \n\n", tmp, tmp->next_Ptr);
#endif

    } else {
      printf("\nStopped execution after reaching the end of the list\nMarked "
             "by the existence of a null pointer\n\n");
      break;
    }
    sleep(1);
#ifdef DEBUG
    sleep(3);
#endif
  }
}

int add_node_tolist(struct LinkedList *head, struct LinkedList *node) {

#ifdef DEBUG
  printf("Adding Node %p To list with head %p \n", node, head);
#endif

  while (head->next_Ptr != NULL) {
    head = head->next_Ptr;
  }
  head->next_Ptr = node;
  node->uid = custom_uid_hash(node->size, node->body);
  return 0;
}

int update_node_inlist(char *uid, struct LinkedList *head, int size,
                       char *body) {
  int outp = 1;
  struct LinkedList *tmp = head;
  while (tmp->next_Ptr != NULL && tmp != NULL) {
    if (tmp->uid == uid) {
      tmp->size = size;
      tmp->body = body;
      tmp->uid = custom_uid_hash(tmp->size, tmp->body);
      outp = 0;
    }
    tmp = tmp->next_Ptr;
  }

  return outp;
}

int delete_node(int i, struct LinkedList *head) {
  int j = 0;
  int output = 2;
  struct LinkedList *tmp;
  printf("\nDeleting Node Number %d \n \n", i);

  if (head != NULL) {
    while (head->next_Ptr != NULL && j <= i) {
      tmp = head;
      head = head->next_Ptr;
      if (j == i && head->next_Ptr != NULL) {
        tmp->next_Ptr = head->next_Ptr;
        free(head);
        output = 0;
        break;
      }
      output = 1;
      j++;
    }
  }

  return output;
}

int inject_node_list(struct LinkedList *head, struct LinkedList *node,
                     int location) {
  int j = 0;
  int output = 2;
  struct LinkedList *tmp;
  printf("\nInjecting Node At Location  %d \n \n", location);

  if (head != NULL) {
    while (head->next_Ptr != NULL && j <= location) {
      tmp = head;
      head = head->next_Ptr;
      if (j == location) {
        tmp->next_Ptr = node;
        node->next_Ptr = head;
        if (node->uid == NULL) {
          node->uid = custom_uid_hash(node->size, node->body);
        }
        output = 0;
        break;
      }
      output = 1;
      j++;
    }
  }

  return output;
}