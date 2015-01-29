

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

    value

};
