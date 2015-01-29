void check_change(struct llnode *block,int check, int change){
        if (block->ul->state == check){
            block->ul->state = change;
        }
        if (block->u->state == check){
            block->u->state = change;
        }
        if (block->ur->state == check){
            block->ur->state = change;
        }
        if (block->r->state == check){
            block->r->state = change;
        }
        if (block->br->state == check){
            block->br->state = change;
        }
        if (block->b->state == check){
            block->b->state = change;
        }
        if (block->bl->state == check){
            block->bl->state = change;
        }
        if (block->l->state == check){
            block->l->state = change;
        }
}

int check_known(struct llnode *block){
    int count = 0;
    if(block->ul->state > -1){
            count++;
    }
    if(block->u->state > -1){
            count++;
    }
    if(block->ur->state > -1){
            count++;
    }
    if(block->r->state > -1){
            count++;
    }
    if(block->br->state > -1){
            count++;
    }
    if(block->b->state > -1){
            count++;
    }
    if(block->bl->state > -1){
            count++;
    }
    if(block->l->state > -1){
            count++;
    }

    return count;
}


int check_bomb(struct llnode *block){
    int count = 0;
    if(block->ul->state == -2){
            count++;
    }
    if(block->u->state == -2){
            count++;
    }
    if(block->ur->state == -2){
            count++;
    }
    if(block->r->state == -2){
            count++;
    }
    if(block->br->state == -2){
            count++;
    }
    if(block->b->state == -2){
            count++;
    }
    if(block->bl->state == -2){
            count++;
    }
    if(block->l->state == -2){
            count++;
    }

    return count;
}


struct llnode *mark_bomb(struct llnode *block){

    knownblocks = check_known(block);
    bombsaround = check_bomb(block);
    unknownblocks = 8 - knownblocks;

    cvalue = initial->state;

    if (cvalue != bombsaround)&&((cvalue-bombsaround) == unknownblocks){
        check_change(block, -1, -2);
    }
    return block;
};

struct llnode *mark_safe(struct llnode *block){

    bombsaround = check_bomb(block);

    cvalue = initial->state;

    if (cvalue == bombsaround){
        check_change(block,-1,-4);
    }
    return block;
};


struct llnode *mark_potential(struct llnode *block){

    knownblocks = check_known(block);
    bombsaround = check_bomb(block);
    unknownblocks = 8 - knownblocks;
    cvalue = initial->state;

    if (cvalue>bombsaround){
            check_change(block,-1,-3);
        }
    }
};

struct llnode *solve_block(struct llnode *block){

    mark_bomb(block);
    mark_safe(block);
    mark_potential(block);

    return block;

};

struct llnode *solve_potential
