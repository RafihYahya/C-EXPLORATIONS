#include "../../../UTILS/utils.h"
#include "../LINKED_LISTS/lk_lists.h"
#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void formatted_tree_print(struct TREE *tmp) {
  printf("\n." BOLD "->" BOLD " The " BOLD "Title" NORMAL
         " is" ANSI_COLOR_YELLOW BOLD "%s\n" NORMAL ANSI_COLOR_RESET "." BOLD
         "->" BOLD " The " BOLD "Body" NORMAL " is " ANSI_COLOR_CYAN BOLD
         "%s\n" ANSI_COLOR_RESET NORMAL "." BOLD "->" BOLD ""
         " The " BOLD "UID" NORMAL " is " ANSI_COLOR_MAGENTA BOLD
         "%s\n" ANSI_COLOR_RESET NORMAL "." BOLD "->" BOLD " The " BOLD
         "Left_ptr" NORMAL " "
         "address is " ANSI_COLOR_GREEN BOLD "%p\n" ANSI_COLOR_RESET NORMAL
         "." BOLD "->" BOLD " The " BOLD "Right_ptr" NORMAL
         " address is " ANSI_COLOR_GREEN BOLD "%p\n\n" ANSI_COLOR_RESET NORMAL
         "",
         tmp->title, tmp->body, tmp->uid, tmp->left_ptr, tmp->right_ptr);
}

struct TREE *create_new_tree(char *body, char *title) {

  struct TREE *rootPtr = (struct TREE *)malloc(sizeof(struct TREE));
  // SHORTHAND FOR STRUCT POINTER INITIALIZATION
  // SEARCH FOR DESIGNATED INITS
  if (rootPtr == NULL) {
    printf("Something Wrong Has Occured\nWe Couldn't Allocate"
           "the root node\n");
    exit(EXIT_FAILURE);
  }
  *rootPtr = (struct TREE){
      .body = body,
      .title = title,
  };
  rootPtr->uid = custom_uid_hash(strlen(rootPtr->title), body);

  return rootPtr;
}

void show_tree(struct TREE *root) {
  pthread_t thread1, thread2;

  struct TREE *tmp = root;
  // print struct loop
  if (tmp != NULL) {
    formatted_tree_print(tmp);
    show_tree(tmp->right_ptr);
    show_tree(tmp->left_ptr);
  }
}

int show_tree_node(int location, int direction, struct TREE *root,
                   int recFlag) {

  int locationCounter = location;
  int myreturn = 0;
  struct TREE *tmp = root;
  //
  if (location < 0 || (direction > 2 && direction < 0)) {
    printf("Please Enter Correct Args You Dumbass");
    return -1;
  }
  if (location == 0) {
    // printf("location is %d \n", location);
    if ((tmp->left_ptr == NULL && direction == 0) ||
        (tmp->right_ptr == NULL && direction == 1)) {
      return -1;
    }
    if (direction == 0) {
      tmp = tmp->left_ptr;
      formatted_tree_print(tmp);
      return 0;
    }
    if (direction == 1) {
      tmp = tmp->right_ptr;
      formatted_tree_print(tmp);
      return 0;
    }
  }
  locationCounter--;
  if (tmp->left_ptr != NULL) {
    myreturn = show_tree_node(locationCounter, direction, tmp->left_ptr, 1);
  }
  // printf("address of struct %p \n",root);
  if (tmp->right_ptr != NULL) {
    myreturn = show_tree_node(locationCounter, direction, tmp->right_ptr, 1);
  }
  /*
  if (myreturn != 0) {
    printf(ANSI_COLOR_RED BOLD
           "\nAN ERROR HAS OCCURED \n\n" ANSI_COLOR_RESET NORMAL);
  }
  */
  if (tmp->left_ptr == NULL && tmp->right_ptr == NULL) {
    myreturn = -1;
  }

  if (myreturn == -1 && recFlag == 0) {
    printf(ANSI_COLOR_YELLOW BOLD "CAN'T ACCESS DIRECTION, NULL PTR !!! " NORMAL
                                  "\n\n" ANSI_COLOR_RESET);
  }
  return myreturn;
}
int update_node_intree(struct TREE *node, struct TREE *tmp) {
  if (node == NULL) {
    return -1;
  }
  *node = (struct TREE){.body = tmp->body,
                        .color = tmp->color,
                        .doesHaveChild = tmp->doesHaveChild,
                        .left_ptr = tmp->left_ptr,
                        .right_ptr = tmp->right_ptr,
                        .title = tmp->title,
                        .uid = NULL};
  node->uid = custom_uid_hash(strlen(node->title), node->body);
  return 0;
}

struct TREE *find_tree_node_parent(struct TREE *root, struct TREE *node) {
  struct TREE *tmp = root;
  struct TREE *out = NULL;
  if (out != NULL) {
    return out;
  }
  if (tmp != NULL) {
    if (tmp->left_ptr == node || tmp->right_ptr == node) {
      out = tmp;
    } else {
      if (tmp->left_ptr != NULL) {
        find_tree_node_parent(tmp->left_ptr, node);
      }
      if (tmp->right_ptr != NULL) {
        find_tree_node_parent(tmp->right_ptr, node);
      }
    }
  }
  return out;
}

int delete_tree_node(struct TREE *root, struct TREE *toDeleteNode,
                     int deleteALLBranch) {
  struct TREE *tmp;
  unsigned short int l = 2;
  tmp = find_tree_node_parent(root, toDeleteNode);
  if (tmp->left_ptr == toDeleteNode) {
    l = 0;
  }
  if (tmp->right_ptr == toDeleteNode) {
    l = 1;
  }
  if (deleteALLBranch == 0) {
    // TODO FIND A WAY TO STITCH REMAINING NODE
    if (l == 0) {
      tmp->left_ptr = toDeleteNode->left_ptr;
    }
    if (l == 1) {
      tmp->right_ptr = toDeleteNode->left_ptr;
    }
    return 0;
  } else {
    // TODO FREE ALL BRANCH RECURSIVLY
    switch (l) {
    case 0:
      tmp->left_ptr = NULL;
      break;
    case 1:
      tmp->right_ptr = NULL;
      break;
    case 2:
      printf("An ERROR HAS OCCURED \n");
      break;
    }

    return 0;
  }
}

int estimated_tree_size(struct TREE *root, int acc) {
  // TODO CHECK
  int tmp = acc;
  if (root->left_ptr != NULL) {
    tmp = estimated_tree_size(root->left_ptr, tmp + 1);
  }
  if (root->right_ptr != NULL) {
    tmp = estimated_tree_size(root->right_ptr, tmp);
  }
  return tmp;
}
//
static int output2 = 0;
int last_nodes_tree(struct TREE *root, struct TREE **nodeList) {
  if (root->left_ptr == NULL && root->right_ptr == NULL) {
    if (*nodeList == NULL) {
    }
    *(nodeList + output2 ) = root;
    printf("Miaw %s\n",(**(nodeList + output2 )).title);
    output2++;
  }
  if (root->left_ptr != NULL) {
    output2 = last_nodes_tree(root->left_ptr, nodeList);
  }
  if (root->right_ptr != NULL) {
    output2 = last_nodes_tree(root->right_ptr, nodeList);
  }
  return output2;
}

/*
void last_nodes_tree(struct TREE *root, struct TREE **nodeList) {
  if (root->left_ptr == NULL && root->right_ptr == NULL) {

    for (int i = 0; i < 10; i++) {
      if (tmp[i] == NULL) {
        tmp[i] = root;
        break;
      }
    }
    //*nodeList = root;
  }
  if (root->left_ptr != NULL) {
    last_nodes_tree(root->left_ptr, nodeList);
  }
  if (root->right_ptr != NULL) {
    last_nodes_tree(root->right_ptr, nodeList);
  }
} */

//
int inject_tree_node(struct TREE *root, struct TREE *node,
                     short int withBranch) {
  // TODO CHECK

  int size = estimated_tree_size(root, 0);
  struct TREE **p = malloc(sizeof(struct TREE *) * size);
  if (p != NULL) {
    last_nodes_tree(root, p);
    if (*p != NULL) {
      if (withBranch == 0) {
        node->left_ptr = NULL;
        node->right_ptr = NULL;
      }
      (*p)->left_ptr = node;
    } else {
      return 2;
    }
  } else {
    return 1;
  }
  return 0;
}