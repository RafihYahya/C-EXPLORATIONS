

enum RGBCOLOR { RED, BLUE, GREEN };

struct TREE {
  char *title;
  char *body;
  char *uid;
  enum RGBCOLOR color;

  int doesHaveChild;
  struct TREE *left_ptr;
  struct TREE *right_ptr;
};

// STARTING
/*
 *------------------------------
 * FUNCTION : CREATE NEW TREE
 *------------------------------
 * create the root node of the tree defined by @struct TREE
 *
 * @char *body: dynamically allocated string pointer, serve as node body.
 * @char *title: dynamically allocated string pointer, serve as node title.
 *
 * return @int
 */
struct TREE *create_new_tree(char *body, char *title);

// DISPLAY

/*
 * FUNCTION : Display Tree
 * Recursively Display each node attributes.
 *
 * @struct TREE *root: dynamically allocated struct pointer to the root node
 *
 * return @int
 */

void formatted_tree_print(struct TREE *tmp);
void show_tree(struct TREE *root);

int show_tree_node(int location, int direction, struct TREE *root, int recFlag);

// COMMON OPERATIONS

int update_node_intree(struct TREE *node, struct TREE *tmp);
struct TREE *last_nodes_tree(struct TREE *root, struct TREE *nodeList);
struct TREE *find_tree_node_parent(struct TREE *root, struct TREE *node);
int estimated_tree_size(struct TREE *root,int acc);
int delete_tree_node(struct TREE *root, struct TREE *toDeleteNode,
                     int deleteALLBranch);
int inject_tree_node(struct TREE *root, struct TREE *node,short int withBranch);
int inject_tree_node_withLocation(struct TREE *root, struct TREE *node,short int location);

int swap_tree_node(struct TREE *firstNode, struct TREE *secondNode,
                   int swapFullBranches);
int free_tree_node(struct TREE *node,int freeALLBranch);


// SPECIAL OPERATIONS
int reorder_tree_based_onRGB(struct TREE *root);


