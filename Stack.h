#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

typedef struct stackNode		// implemented as Linked List. Linked List node is stackNode.
{
	TreeNode *p_data;
	stackNode *link;
};

typedef struct stack			// to maintain the Linked List.
{
	stackNode *root;
	stackNode *top;
	int nodecount;
};

stackNode* createNode(TreeNode *node)	// create Linked List node i.e. stackNode
{
	stackNode *tempnode = (stackNode*)malloc(sizeof(stackNode));
	tempnode->p_data = node;
	tempnode->link = NULL;
	return tempnode;
}

bool isEmpty(stack *stk)
{
	if (stk->nodecount == 0)
		return true;
	else
		return false;
}

void push(stack *stk, TreeNode *node)
{
	stackNode *tempnode = createNode(node);
	if (stk->nodecount == 0)
	{
		stk->root = tempnode;
		stk->top = tempnode;
		stk->nodecount++;
	}
	else
	{
		stackNode *temp = stk->root;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = tempnode;
		stk->top = tempnode;
		stk->nodecount++;
	}
}

void pop(stack *stk)
{
	if (isEmpty(stk))
		return;
	else
	{
		if (stk->nodecount == 1)
		{
			free(stk->top);
			stk->nodecount--;
		}
		else
		{
			stackNode *curr = stk->root;
			stackNode *next = curr->link;
			while (next->link != NULL)
			{
				curr = curr->link;
				next = next->link;
			}

			stk->top = curr;
			free(next);
			curr->link = NULL;
			stk->nodecount--;
		}
	}
}

TreeNode* peek(stack *stk)
{
	return stk->top->p_data;
}

stack* createStack()
{
	stack *stk = (stack*)malloc(sizeof(stack));

	if (stk)
	{
		stk->root = NULL;
		stk->top = NULL;
		stk->nodecount = 0;
		return stk;
	}
	else
		return NULL;
}

void disposeStack(stack *stk)
{
	if (stk != NULL)
		free(stk);
}