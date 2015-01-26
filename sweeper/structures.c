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
# and these values are utilised to generate the 30 by 16 grid.

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


