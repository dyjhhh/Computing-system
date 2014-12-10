#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mp12.h"


/* delete_tree - given the root of a tree, frees the tree structure from memory
 * INPUTS: curNode - a pointer to a node who must have its subtree and self freed
 * OUTPUTS: none
 * RETURNS: none
 */
void delete_tree(node * curNode)
{
    // YOUR CODE HERE

 if (curNode == NULL) {
 return;
 }
if(CurNode->left)   
    delete_tree(curNode->left);
    if(CurNode->right)  
        delete_tree(curNode->right);
    delete curNode;

}

/* create_postfix_tree - given an expression string creates an expression tree
 * INPUTS: exp_str - a string containing the postfix expression
 * OUTPUTS: Allocates nodes and creates a tree
 * RETURNS: A pointer to the root of the tree
 */
node * create_postfix_tree(char * exp_str)
{
    // YOUR CODE HERE
     int max=0;
        int i=0;
 
    struct node *newnode = (node*)malloc(sizeof(node));
 
    while(exp_str[i]!='\0'){
        max = max +1;
 
    }
 
    for(i=0; i<max; i++){
        if(exp_str[i] != ' '){
                if(exp_str[i]<='9' || exp_str>='0'){
                        stackPush(myStack, exp_str[i]);
                }
                else{
                        stackPop(myStack);
                        newnode->item = exp_str[i];
                        newnode->left = exp_str[i-2];
                        newnode->right = exp_str[i-1];
                        stackPush(myStack, newnode);
                }
    }
 
}

/* evaluate_postfix - given an expression tree recursively evaluates it
 * INPUTS: curNode - a pointer to a node that must have its left and right subtrees evaluated
 * OUTPUTS: none
 * RETURNS: The value of the evaluated expression
 */
int evaluate_postfix(node * curNode)
{
    // YOUR CODE HERE
   
   int node, left, right;
 
 
   // Check if its a leaf
   if (curNode -> right == NULL && curNode -> left == NULL)
 
      {
 
        // Convert Char to Ints
        right = curNode -> right -> item - '0';
        left = curNode -> left -> item - '0';
 
 
        // Evaluate the expression if its a leaf and return the computation
        switch (curNode -> item)
 
              {
                case '+':
                  node = right + left;
                  break;
 
                case '-':
                  node = right - left;
                  break;
 
                case '*':
                  node = right * left;
                  break;
 
                case '/':
                  node = right / left;
                  break;
 
                default:
                  break;
              }
 
      }
 
    else
 
        {
          //Find a leaf if you didnt find one
          evaluate_postfix(curNode -> right);
          evaluate_postfix(curNode -> left);
 
        }
 
    return node;
 
}
/* postfix - given an expression string prints the solution
 *           the solution is just a number (i.e. printf("%d\n", solution); )
 * INPUTS: exp_str - a string containing the postfix expression
 * OUTPUTS: prints the solution to the expression
 * RETURNS: none
 */
void postfix(char * exp_str)
{
    // YOUR CODE HERE
        node * create_postfix_tree(char * exp_str)
        int evaluate_postfix(node * curNode)
        cout << node << endl;
        void delete_tree(node * curNode)

}

/* infix - given an infix expression prints the solution
 *         must convert to a postfix expression and call postfix()
 * INPUTS: exp_str - a string containing the infix expression
 * OUTPUTS: prints the solution to the expression
 * RETURNS: none
 */
void infix(char * exp_str)
{
    // CHALLENGE CODE HERE
}

/* stackInit - initializes a stack structure
 * INPUTS: myStack - pointer to stack structure
 * OUTPUTS: sets top to -1
 * RETURNS: none
 */
void stackInit(stack * myStack)
{
	myStack->top = -1;
}

/* stackPush - pushes an element onto the stack
 * INPUTS: myStack - a pointer to stack structure
 *         element - the node pointer element
 * OUTPUTS: none
 * RETURNS: none
 */
void stackPush(stack * myStack, node * element)
{
	if (myStack->top >= (MAXSIZE - 1))
	{
		printf("Can't push onto stack: stack is full\n");
		return;
	}
	myStack->contents[++myStack->top] = element;
}

/* stackPop - pops an element off the stack
 * INPUTS: myStack - a pointer to stack structure
 * OUTPUTS: none
 * RETURNS: the node pointer element popped off the stack
 */
node * stackPop(stack * myStack)
{
	if(myStack->top < 0)
	{
		printf("Can't pop off stack: stack is empty\n");
		return NULL;
	}
	return myStack->contents[myStack->top--];
}
