#define MAXSIZE 100

/* A tree node that makes up the expression tree
   item - the item (operand or value) for this node
   left - pointer to left node
   right - pointer to right node
*/
struct node {
	char item;
	node * left;
	node * right;
};

/* Creates an expression tree and parses it to evaluate the postfix expression */
void postfix(char * exp_str);

/* Given a postfix expression, creates the expression tree and returns
 * a pointer to the root of the tree */
node * create_postfix_tree(char * exp_str);

/* Given a pointer to the root of a tree, recursively delete the tree freeing memory */
void delete_tree(node * curNode);

/* A recursive function that evaluates the expression tree */
int evaluate_postfix(node * curNode);

/* A stack structure. Contains contents and an index to the top element */
struct stack {
	node * contents[MAXSIZE];
    int top;
};

/* Initializes the stack structure to be used */
void stackInit(stack * myStack);

/* Pushes an element onto the stack */
void stackPush(stack * myStack, node * element);

/* Pops an element off the stack */
node * stackPop(stack * myStack);

/* Converts an infix expression to a postfix expression, creates an expression tree,
   and parses it to evaluate the expression */
void infix(char * exp_str);

