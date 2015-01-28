//optimizations: create solutions as a simple list can free up memory

#include <stdlib.h>

// The head structure, the head holds all of the different starting variations in a list
//  branch represents a certain decision tree with corresponding values and a solution
//  tree attached to the end of the decision tree (so each decision tree is 18 long)
//  nextbranch represents the next head that is connected to a branch of possiblities
struct head {
    int s_tree;
    int value;
    int deep;
    struct decisiontree *branch;
    struct head *nextbranch;
};

// The decisiontree is the main structure to record the nodes with a 3 by 3 square
//  s_tree signifies 1 if the corresponding tree data is part of the solution and 0
//   of the tree data is part of the recording
//  node_value represents the value of the specific node (depends on value of deep) or
//   represents the true value that the specific node (depends on deep)
//   should be changed into if s_tree is true
//  deep represents how deep into the tree the specific node is and since the algorithm
//   is fixed a certain value for deep always corresponds to a specific node relative to
//   the center node in the 3 by 3
//  rest represents the rest of the tree
struct decisiontree {
    int s_tree;
    int node_value;
    int deep;
    struct head *rest;
};

struct decisiontree *cons_tree(int level,int node_value,struct head *initial,int s_tree, int deep){
    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    initial->nextbranch = new;
    new->s_tree = s_tree;
    new->node_value = node_value;
    new->deep = initial->deep + 1;
    new->rest = NULL;
    return new;
};


void free_decisiontree(struct decisiontree *initial){
    while (initial != NULL){
        struct decisiontree *temp = initial->rest;
        free(initial);
        initial = temp;
    }
}

struct head *cons_head(struct head *initial){
    struct head *newhead = malloc(sizeof(struct head));

    initial->nextbranch = newhead;
    newhead->branch = NULL;
    newhead->nextbranch = NULL;

    return newhead;
};

void free_head(struct head *initial){
    while (initial != NULL){
        struct head *temp = initial->nextbranch;
        free_decisiontree(initial->branch);
        free(initial);
        initial = temp;
    }
}

struct decisiontree *add_tree(int level,struct head *initial,int initial_node_value){

    struct head *newhead = cons_head(initial);

    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    newhead->nextbranch = NULL;
    initial->nextbranch = newhead;
    newhead->branch = new;

    new->deep = 0;

    new->node_value = initial_node_value;

    new->s_tree = 0;

    new->rest = NULL;

    return new;
};

struct decisiontree *add_solution(struct decisiontree *lastnode, int block_value){
    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    lastnode->rest = new;

    new->deep = 0;

    new->node_value = block_value;

    new->s_tree = 1;

    new->rest = NULL;

    return new;

};



