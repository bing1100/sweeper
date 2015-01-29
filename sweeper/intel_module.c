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

    new->branch = NULL;
    new->nextbranch = NULL;
    new->s_tree = 0;
    new->deep = deep + 1;
    new->node_value = node_value;

    return new;
};

struct decisiontree *cons_solution(int node_value, int deep, struct decisiontree *initial){

    assert(initial != NULL && initial->s_tree == 1);

    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    initial->branch = new;

    new->branch = NULL;
    new->nextbranch = NULL;
    new->s_tree = 1;
    new->deep = deep + 1;
    new->node_value = node_value;

    return new;
};

struct decisiontree *cons_branch(int node_value, int deep, struct decisiontree *initial){

    assert(initial != NULL && initial->s_tree == 0);

    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    initial->branch = new;

    new->branch = NULL;
    new->nextbranch = NULL;
    new->s_tree = 0;
    new->deep = deep + 1;
    new->node_value = node_value;

    return new;
};

void free_decisiontree(struct decisiontree *initial){
    if(initial != NULL){
        struct decisiontree *tempbranch = initial->branch;
        struct decisiontree *tempnextbranch = initial->nextbranch;
        free(initial);
        free_decisiontree(tempbranch);
        free_decisiontree(tempnextbranch);
    }
}


