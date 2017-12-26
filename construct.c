#include <stdlib.h>
#include "construct.h"

Node *genNode(int value, Node *left, Node *right)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = left;
  node->right = right;
  node->value = value;
  return node;
}

int findSupport(int seesaw[], int start, int end)
{
  if (end - start < 2)
    return -1;
  for (int support = start; support <= end; support++) {
    /* check if balanced */
    long long int leftTorque = 0;
    for (int left = start; left < support; left++)
      leftTorque += seesaw[left] * (support - left);
    long long int rightTorque = 0;
    for (int right = support + 1; right <= end; right++)
      rightTorque += seesaw[right] * (right - support);
    if (leftTorque == rightTorque)
      return support;
  }
  return -1;
}

Node *genList(int seesaw[], int N, int start, int end)
{
  if (end < start)
    return NULL;
  return(genNode(seesaw[end], 
		 genList(seesaw, N, start, end - 1),
		 NULL));
}
Node *genTree(int seesaw[], int N, int start, int end)
{
  if (end < start)
    return NULL;

  int balance = findSupport(seesaw, start, end); 
  if (balance == -1)
    return(genList(seesaw, N, start, end));
  else
    return(genNode(seesaw[balance], 
		   genTree(seesaw, N, start, balance - 1),
		   genTree(seesaw, N, balance + 1, end)));
		 
}

Node *ConstructTree(int seesaw[], int N)
{
  return(genTree(seesaw, N, 0, N - 1));
}
