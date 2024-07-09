struct GRAPH {
    char *title;
    char *body;
    char *uid;
    //
    unsigned int numConnections;
    struct GRAPH **ptrArray;
};

static struct GRAPH **globalGraphAccess;


void print_full_graph(struct GRAPH **globalGraphAccess);