#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void error_reporting(int err) {
  //
  switch (err) {
  case 0:
    printf("\nOPERATION WAS SUCCEFFUL \n");
    break;
  case 1:
    printf("\nAN ERROR HAS OCCURED \n");
    break;
  case 2:
    printf("\nFUNCTION DIDNT EVEN EXECUTE \n");
    break;
  }
}
int show_help() {
  printf("\n This mini program can handle multiple data structures.\n For "
         "Exemple, Linked List, Binary Tree And Graphs\n With The intention of "
         "using them for the implementations,\n of many famous algorithms\n\n "
         "Version: 0.0.2\n\n");
  exit(EXIT_SUCCESS);
}

void memory_rest_arr(int a[10]) {
  clock_t btime = clock();
  uint64_t tmp = 0;
  uint64_t tmp2 = 0;
  for (int i = 0; i < 10; i++) {
    tmp = (((tmp - tmp) + (a[i] & 15)) << (4 * i)) + tmp;
    // printf("tmp is %lu \n ", (((15) << (4 * i)) & tmp) >> (4 * i));
    printf("tmp is %lu  .",
           (((unsigned long)(15) << (4 * i)) & tmp) >> (4 * i));
    printf("tmp is %b \n ",
           (((unsigned long)(15) << (4 * i)) & tmp) >> (4 * i));
    tmp2 = (((unsigned long)(15) << (4 * i)) & tmp) >> (4 * i);
  }

  // printf("\ntmp is %p \n", tmp);
  // printf("tmp is %lu \n ", tmp);
  clock_t etime = clock();

  // printf("time taken  is %.3g ms \n ",((double)(etime - btime) /
  // CLOCKS_PER_SEC) * 1000);
  printf("time taken  is %.3g μs, \n ",
         ((double)(etime - btime) / CLOCKS_PER_SEC) * 1000 * 1000);
}
void memory_rest_arr2() {

  clock_t btime = clock();
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++) {

    // printf("tmp is %lu \n ", (((15) << (4 * i)) & tmp) >> (4 * i));
    printf("tmp is %d \n \n", a[i]);
  }

  clock_t etime = clock();

  printf("time taken  is %.3g ms \n ",
         ((double)(etime - btime) / CLOCKS_PER_SEC) * 1000);
  printf("\n\ntime taken  is %.3g μs, \n\n ",
         ((double)(etime - btime) / CLOCKS_PER_SEC) * 1000 * 1000);
}

void show_sizes() {
  //
  struct TREE *p;
  char s[] = {"\x1b[31m"
              "HELLO WORLD "
              "\x1b[0m"};
  uint64_t x = 1;
  for (int t = 0; t < 6; t++) {
    x = x << 2;
    x++;
  }
  x = x + (x << 12);
  x = (uint64_t)&s[0];

  printf("SIZE OF char    %lu  in bytes \n", sizeof(char));
  printf("SIZE OF double  %lu  in bytes \n", sizeof(double));
  printf("SIZE OF long    %lu  in bytes \n", sizeof(long));
  printf("SIZE OF ulong   %lu  in bytes \n", sizeof(unsigned long));
  printf("SIZE OF unint   %lu  in bytes \n", sizeof(uint64_t));
  printf("SIZE OF ull     %lu  in bytes \n", sizeof(unsigned long long));
  printf("SIZE OF int     %lu  in bytes \n", sizeof(int));
  printf("SIZE OF uint    %lu  in bytes \n", sizeof(unsigned int));
  printf("SIZE OF sint    %lu  in bytes \n", sizeof(short int));
  printf("SIZE OF rootptr %lu  in bytes \n\n\n", sizeof(p));

  printf("SIZE OF char    %lu \n", sizeof(char) * 8);
  printf("SIZE OF double  %lu  in bytes \n", sizeof(double) * 8);
  printf("SIZE OF long    %lu  in bytes \n", sizeof(long) * 8);
  printf("SIZE OF ulong   %lu  in bytes \n", sizeof(unsigned long) * 8);
  printf("SIZE OF unint   %lu  in bytes \n", sizeof(uint64_t) * 8);
  printf("SIZE OF ull     %lu  in bytes \n", sizeof(unsigned long long) * 8);
  printf("SIZE OF int     %lu \n", sizeof(int) * 8);
  printf("SIZE OF uint    %lu \n", sizeof(unsigned int) * 8);
  printf("SIZE OF sint    %lu \n", sizeof(short int) * 8);
  printf("SIZE OF rootptr %lu \n \n \n", sizeof(p) * 8);

  printf("value of p pure is %p \n", p);
  printf("value of p pure is %p \n", &p);
  printf("value of x pure is %p \n", x);
  printf("value of x pure is %x \n", x);
  printf("value of x pure is %lu \n", x);
  printf("value of x pure is %s \n\n", &(x));
  printf("value of x pure is %b \n\n", &(x));

  printf("value of s from x is  %s \n \n", x);
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[10] = {0, 2, 2, 3, 7, 5, 6, 7, 12, 9};
  memory_rest_arr(b);
  // memory_rest_arr2();
  int i = '0';
  printf("\n\n'0' in decimals is %d \n", i);
  // fflush(stdout);
  write(1, &i, sizeof(int));
  write(1, "\n", 2);
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {

  int err;
  int err2;
  int esSize = 0;
  if (argc == 2) {
    if (strcmp(argv[1], "--help") == 0) {
      show_help();
    }
    if (strcmp(argv[1], "--info") == 0) {
      show_sizes();
    }
  }

  char *tree_body = " Meine Leebne Deine miaw";
  char *tree_title = " Meine Leebne";
  char *tree_body1 = " Meine Leebne Deine miaw1";
  char *tree_title1 = " Meine Leebne1";
  char *tree_body2 = " Meine Leebne Deine miaw2";
  char *tree_title2 = " Meine Leebne2";
  char *tree_body3 =" Meine Leebne Deine miaw3";
  char *tree_title3 = " Meine Leebne3";
  char *tree_body4 = " Meine Leebne Deine miaw4";
  char *tree_title4 = " Meine Leebne4";
  char *tree_body5 = " Meine Leebne Deine miaw5";
  char *tree_title5 = " Meine Leebne5";
  char *tree_body6 = " Meine Leebne Deine miaw6";
  char *tree_title6 = " Meine Leebne6";

  struct TREE *root = create_new_tree(tree_body, tree_title);
  struct TREE *node1 = create_new_tree(tree_body1, tree_title1);
  struct TREE *node2 = create_new_tree(tree_body2, tree_title2);
  struct TREE *node3 = create_new_tree(tree_body3, tree_title3);
  struct TREE *node4 = create_new_tree(tree_body4, tree_title4);
  struct TREE *node5 = create_new_tree(tree_body5, tree_title5);
  struct TREE *node6 = create_new_tree(tree_body6, tree_title6);
  //
  root->left_ptr = node1;
  root->right_ptr = node2;

  node1->left_ptr = node3;
  node1->right_ptr = node4;

  node2->left_ptr = node5;
  node2->right_ptr = node6;

  node3->left_ptr = NULL;
  node3->right_ptr = NULL;

  node4->left_ptr = NULL;
  node4->right_ptr = NULL;

  node5->left_ptr = NULL;
  node5->right_ptr = NULL;

  node6->left_ptr = NULL;
  node6->right_ptr = NULL;


  //
  //
  //
  show_tree(root);
  esSize = estimated_tree_size(root, 0);
  printf(""BOLD"\n=> Level Size of Root TREE Is "ANSI_COLOR_RED"%d"ANSI_COLOR_RESET". \n"NORMAL"",esSize);
  err = show_tree_node(0, 1, root, 0);
  err = show_tree_node(2, 1, root, 0);

  //
  // struct TREE *tmp001 = find_tree_node_parent(root, node2);
  // printf("tnp001 addres is %p \n", tmp001);
  // printf("node2  addres is %p \n", node2);

#ifdef LINKED
#ifndef DUMMY

  char *body = "This is The main List The hOriozn of the future";
  char *body1 = "LAMA la biodiversitast auf dem lange behalden2";
  char *body2 = "For The Freedom We fight in these forgotten land";
  // DUMMY FIRST
  struct LinkedList *tmp2 =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp2->size = 77;
  tmp2->body = body1;
  tmp2->next_Ptr = NULL;
  tmp2->uid = custom_uid_hash(tmp2->size, tmp2->body);

  // DUMMY SECOND
  struct LinkedList *tmp =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp->size = 3;
  tmp->body = body;
  tmp->next_Ptr = tmp2;
  struct LinkedList *tmp6 =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp6->size = 3;
  tmp6->body = "SIX 6";
  tmp6->next_Ptr = NULL;

  struct LinkedList *tmp5 =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp5->size = 3;
  tmp5->body = "FIVE 5";
  tmp5->next_Ptr = NULL;
  struct LinkedList *tmp4 =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp4->size = 3;
  tmp4->body = "FOUR";
  tmp4->next_Ptr = NULL;

  struct LinkedList *tmp3 =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  tmp3->size = 3;
  tmp3->body = body2;
  tmp3->next_Ptr = tmp4;

//
#endif

  printf("\n\nHello And Welcome To My Mini PROGRAM \n");

  //
  struct LinkedList *p = create_new_list(50, body);
  err = add_node_tolist(p, tmp);
  error_reporting(err);
  //
  if (err == 0) {
    printf("\nSECOND NODE \n \n");
    print_struct_linked_list(p->next_Ptr);
  }

#ifdef DEBUG
  printf("ADDRESS OF DANG P is : %p\n", p);
  printf("VALUE OF ADDRESS OF DANG P is : %p\n", p->next_Ptr);
  struct LinkedList *dg_ptr = p->next_Ptr;
  printf("VALUE OF ADDRESS OF DANG P is : %d\n", dg_ptr->size);
#endif
  //
  // err2 = delete_node(0, p);
  //
  print_struct_linked_list(p->next_Ptr);
  error_reporting(err2);
#ifdef DEBUG
  sleep(2);
  printf("\ntmp : %p , tmp->ptr : %p \n", tmp, tmp->next_Ptr);
#endif
  err = add_node_tolist(p, tmp5);

#ifdef DEBUG
  printf("\ntmp : %p , tmp->ptr : %p \n", tmp, tmp->next_Ptr);
  printf("ADDRESS OF DANG P is : %p\n", p);
  printf("VALUE OF ADDRESS OF DANG P is : %p\n", p->next_Ptr);
  printf("VALUE OF ADDRESS OF DANG P is : %d\n", dg_ptr->size);
  // dg_ptr->size = 3;
  // printf("VALUE OF ADDRESS OF DANG P is : %d\n", dg_ptr->size);
  sleep(5);
#endif

  show_all_list(p);
  //
  printf("\n Injecting A Node At Location 1\n");
  inject_node_list(p, tmp4, 1);
  inject_node_list(p, tmp6, 1);

  //
  show_all_list(p);
#endif
  return err;
}