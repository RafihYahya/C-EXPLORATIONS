struct GRAPH {
  char *title;
  char *body;
  char *uid;
  //
  unsigned int numTotalConnections;
  unsigned int numOutgoingConnections;
  struct GRAPH **ptrOutgoing;
  struct GRAPH **ptrIncoming;
  static struct GRAPH **globalGraphAccess;
};
static struct GRAPH **globalAllGraphAccess;


//MACRO
#define FUNC_WRAPPER(...) \
__VA_ARGS__ 


struct GRAPH *create_graph(char* title,char *body);
struct GRAPH *add_node_toGraph(struct GRAPH *target, struct GRAPH *node);
struct GRAPH delete_node_fromGraph(struct GRAPH *target, struct GRAPH *node);
struct GRAPH *find_node_inGraph(struct GRAPH *target, char *uid);
struct GRAPH *find_node_in_globalGraph(struct GRAPH **globalGraphAccess,
                                       char *uid);
void free_all_graphAllocations();
void traverse_all_nodes_inGraph(struct GRAPH **globalGraphAccess,
                                void (*fun)(struct GRAPH *node));
void print_full_graph(struct GRAPH **globalGraphAccess);

// SPECIAL
struct GRAPH **find_close_loops_graph(struct GRAPH **globalGraphAccess);
struct GRAPH *merge_all_distinctGraphs(struct GRAPH **loops);
struct GRAPH **find_graph_orphans(struct GRAPH **globalGraphAccess);
struct GRAPH **find_nodeGraph_nConnections(unsigned int num,
                                           struct GRAPH **globalGraphAccess,
                                           unsigned short int total);