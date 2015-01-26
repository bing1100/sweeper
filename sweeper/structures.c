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
    int item;
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

struct llnode *cons_down(int ivg,int ihg,struct llnode *initial,int b, struct llnode *r){
    struct llnode *new = malloc(sizeof(struct llnode));
    new->hg = r->hg;
    new->vg = r->vg + 1;
    new->item = -1;
    new->u = r;
    r->b = new;
    new->ur = NULL;
    new->r = NULL;
    new->br = NULL;
    new->b = NULL;
    if(r->left != NULL){
        new->l = r->bl;
        new->bl = r->bl->b;
        new->ul = r->u;

        r->bl->r = new;
        r->bl->br = new->b;
        r->bl->ur = r;
    }
    else {
        new->l = new->bl = new->ul = NULL;
    }
    return new;
};

#this is the constructor function that constructs right

struct llnode *cons_right(int ivg,int ihg,struct llnode *initial, struct llnode *r){
    struct llnode *new = malloc(sizeof(struct llnode));
    new->hg = r->hg;
    new->vg = r->vg + 1;
    new->item = -1;
    new->l = r;
    r->r = new;
    new->bl = r->b;
    new->b = NULL;
    new->r  = NULL;
    new->br = NULL;
    new->ul = NULL;
    new->u = NULL;
    new->ur =NULL;
    return new;
};

void cons_grid(int hs, int vs){

}
