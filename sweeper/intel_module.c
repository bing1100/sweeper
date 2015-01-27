//optimizations: create solutions as a simple list can free up memory

#include <stdlib.h>

struct head {
    struct decisiontree *branch;
    struct head *nextbranch;
};

struct decisiontree {
    int s_tree_avail;
    int level;
    int node_value;
    struct decisiontree *rest;
    struct decisiontree *solution;
}

struct decisiontree *cons_tree(int level,int node_value,struct decisiontree *initial){
    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    initial->rest = new;
    new->level = level;
    new->s_tree_avail = 0;
    new->node_value = node_value;
    new->rest = NULL;
    new->solution = NULL;
    return new;
};

struct decisiontree *cons_solution(int level,int node_value,struct decisiontree *initial){
    struct decisiontree *new = malloc(sizeof(struct decisiontree));

    initial->solution = new;
    new->level = level;
    new->s_tree_avail = 1;
    new->node_value = node_value;
    new->rest = NULL;
    new->solution = NULL;
    return new;
};

struct decisiontree *add_decision(int level,struct llnode *initial){



};



