# llnode represents one of the squares in the 16 by 30 grid

# a llnode = null is a block that does not exist

# item can have value
# -1 = unknown block
# -2 = block contains a bomb
# and 0 to 8 depending on how many bombs are surrounding it

# Each one of the blocks surrounding the llnode block is represented by letters
# u = up, l = left, r = right, b = back
# *This is a doubly linked list so that if we start a llnode x and x has b llnode y
#  then the u of llnode y is x

# int hg (horizontal grid) and vg (vertical grid) represent where the llnode is on the 30 by 16 grid
# and these values are utilised to generate the 30 by 16 grid. (top and left is zero and increases)

struct llnode {
    int hg;
    int vg;
    int state;
    struct llnode *ul;
    struct llnode *u;
    struct llnode *ur;
    struct llnode *r;
    struct llnode *br;
    struct llnode *b;
    struct llnode *bl;
    struct llnode *l;
}

# The algorithm to construct a new 30 by 16 grid (30 horizontal, 16 vertical)
# is by starting from the top left corner we build down first and we go back to
# the top and shift one to the right and go down again.

# In this algorithm we require one constructor that constructs downward
# and one constructor that constructs to the right


# this is the constructor function that constructs down

struct llnode *cons_down(int bottom, struct llnode *initial){

    # Create memory for new llnode block
    struct llnode *new = malloc(sizeof(struct llnode));

    # Sets hg and vg values for new block, block is right below initial block
    #  so that hg is constant while vg increases by 1
    new->hg = initial->hg;
    new->vg = initial->vg + 1;

    # Set the state of the current block to be unknown
    new->state = -1;

    # Set the initial block to be above the new block
    new->u = initial;
    # and vice versa (set the new block to be right under the initial block
    initial->b = new;

    # this if statment initializes block values for blocks on the left if the block is
    #  not part of the first column it also initializes the right block values for the
    #  block to the left
    if(initial->l != NULL){

        # Sets all the blocks to the left of the block since the block is not on the
        #  leftmose edge
        new->ul = new->u->l;
        new->l = new->u->bl;
        new->bl = new->l->b; /* This considers if the block is on the bottom row*/

        # Since there are blocks to the left of the current block, we can set the right
        #  side values for the blocks to the left of the block
        new->l->ur = new->u;
        new->l->r = new;
        new->l->br = new->b;
    }
    # Since the block is on the leftmost side of the grid, set all values for the leftside
    #  to be NULL (this considers the testcase of the bottom left block)
    else {
        new->l = new->bl = new->ul = NULL;
    }

    # these values are only updated if blocks to the right exist so that
    #  only when blocks to the left of these blocks are defined are these values
    #  filled
    new->ur = NULL;
    new->r = NULL;
    new->br = NULL;

    # this value are only updated if blocks below this block exist so that
    #  only when the block below this current block is defined is this value filled
    new->b = NULL;


    return new;
};

#this is the constructor function that constructs right (only applies to the top row)

struct llnode *cons_right(struct llnode *initial){

    # Create memory for new llnode block
    struct llnode *new = malloc(sizeof(struct llnode));

    # Set hg and vg ints for the new block, the block is shifted over to the right by 1
    #  and does not change vertically
    new->hg = initial->hg + 1;
    new->vg = initial->vg;

    # Set the initial state of the block to be unknown
    new->item = -1;

    # Sets the initial block to be on the left of the new block
    new->l = initial;
    # and vice versa (set the new block to be to the right of the initial block)
    initial->r = new;

    # Sets the bottom left value to the new block
    new->bl = new->l->b;

    # Set the bottom value to be NULL
    #  only set to not NULL if the block below the current block is defined first
    new->b = NULL;

    # Set all the r value to be NULL
    #  only set to not NULL if the blocks to the right is defined first
    new->r  = NULL;
    new->br = NULL;

    # Since the block is on the top row, all of the upper values are NULL
    new->ul = NULL;
    new->u = NULL;
    new->ur =NULL;
    return new;
};

# this is the function that creates a hs by vs grid where each grid member is a llnode stucture and is connected

void cons_grid(int hs, int vs, struct llnode *initial){

    # Set both tempvs and temphs pointer to be the initial block
    #  The tempvs variable represents the llnode which a new llnode will be constructed under
    #  The temphs variable represents the llnode which a new llnode will be constructed to the right
    struct llnode *tempvs = initial;
    struct llnode *temphs = initial;

    # Both for loops start at 1 since the initial block exists
    for(int a=1;a<hs;a++){
        for(int d=1;d<vs;d++){
            tempvs = cons_down(tempvs);
        }
        temphs=cons_right(temphs);
        tempvs=temphs;
    }
}

# We must create destructor functions now, the destructor functions will use the logic as the constructor
