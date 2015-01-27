int check_known(struct llnode *block){
    int count = 0;
    if(block->ul > -1){
            count++;
    }
    if(block->u > -1){
            count++;
    }
    if(block->ur > -1){
            count++;
    }
    if(block->r > -1){
            count++;
    }
    if(block->br > -1){
            count++;
    }
    if(block->b > -1){
            count++;
    }
    if(block->bl > -1){
            count++;
    }
    if(block->l > -1){
            count++;
    }

    return count;
}


int check_bomb(struct llnode *block){
    int count = 0;
    if(block->ul == -2){
            count++;
    }
    if(block->u == -2){
            count++;
    }
    if(block->ur == -2){
            count++;
    }
    if(block->r == -2){
            count++;
    }
    if(block->br == -2){
            count++;
    }
    if(block->b == -2){
            count++;
    }
    if(block->bl == -2){
            count++;
    }
    if(block->l == -2){
            count++;
    }

    return count;
}


