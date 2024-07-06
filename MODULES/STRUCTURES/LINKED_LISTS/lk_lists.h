

#define INTCHAR 22

struct LinkedList {
  int size;
  char *uid;
  char *body;
  struct LinkedList *next_Ptr;
};

// Functions

char *custom_uid_hash(int mysize, char *mybody);

struct LinkedList *create_new_list(int size, char *body);

void show_all_list(struct LinkedList *head);
void print_struct_linked_list(struct LinkedList *p);

int add_node_tolist(struct LinkedList *head, struct LinkedList *node);
int inject_node_list(struct LinkedList *head, struct LinkedList *node,
                     int location);
int update_node_inlist(char *uid, struct LinkedList *head, int size,
                       char *body);

int delete_node(int i, struct LinkedList *head);
int delete_all_lst(struct LinkedList *head);

int find_node_inlist(char *uid, struct LinkedList *head);
