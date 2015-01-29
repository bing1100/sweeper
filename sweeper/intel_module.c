//optimizations: create solutions as a simple list can free up memory

#include <stdlib.h>
#include <assert.h>

// The decision tree is used to record patterns and the solution to the pattern.

//  The s_tree variable determines whether or not the current decision tree is a solution tree
//  The node_value represents the value the node is or should be changed to depending on if the current
//   tree is a solution tree or not
//  The deep value represents how deep the current tree is which the algorithm can use to determine which
//   block the corresponding node represents
//  The branch represents one line of decisions that use the current decision
//  The nextbranch represents another line of decisions that use the current decision

struct decisiontree {
    int s_tree;
    int node_value;
    int deep;
    struct decisiontree *branch;
    struct decisiontree *nextbranch;
};


// Do not use this if s_tree is true
struct decisiontree *cons_nextbranch(int node_value, int deep, struct decisiontree *initial){

    assert(initial != NULL && initial->s_tree == 0);

    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    initial->nextbranch = new;

    new->branch


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



