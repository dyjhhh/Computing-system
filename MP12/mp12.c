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
 deleteTree(curNode->getRight());
 deleteTree(curNode->getLeft());
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
    int length = strlen(exp_str);
        stack *exp_str_stack = (stack *) malloc(sizeof(stack));
        int idx;
        node *temp;
 
        stackInit(exp_str_stack);
 
        for (idx = 0; idx < length; idx++) {
                if (exp_str[idx] == ' ') continue;
 
                if (exp_str[idx] >= 48 && exp_str[idx] <= 57) {
                        temp = (node *)malloc(sizeof(node));
                        temp->item = exp_str[idx];
                        temp->left = NULL;
                        temp->right = NULL;
                        stackPush(exp_str_stack, temp);
                }
               
                else {
                        if (exp_str[idx] == '*' ||
                        exp_str[idx] == '+' ||
                        exp_str[idx] == '-' ||
                        exp_str[idx] == '/') {
 
                        temp = (node *)malloc(sizeof(node));
                        temp->item = exp_str[idx];
                        temp->right = stackPop(exp_str_stack);
                        temp->left = stackPop(exp_str_stack);
                        stackPush(exp_str_stack, temp);
                        }
                }
        }
 
        node *root = stackPop(exp_str_stack);
        free(exp_str_stack);
        return root;
 
}

/* evaluate_postfix - given an expression tree recursively evaluates it
 * INPUTS: curNode - a pointer to a node that must have its left and right subtrees evaluated
 * OUTPUTS: none
 * RETURNS: The value of the evaluated expression
 */
int evaluate_postfix(node * curNode)
{
    // YOUR CODE HERE
if (curNode->left == NULL && curNode->right == NULL) {
                return curNode->item-48;
        }
 
        switch (curNode->item) {
                case '+': return evaluate_postfix(curNode->left) + evaluate_postfix(curNode->right);
                case '-': return evaluate_postfix(curNode->left) - evaluate_postfix(curNode->right);
                case '*': return evaluate_postfix(curNode->left) * evaluate_postfix(curNode->right);
                case '/': return evaluate_postfix(curNode->left) / evaluate_postfix(curNode->right);
        }
 
        return 0;
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
