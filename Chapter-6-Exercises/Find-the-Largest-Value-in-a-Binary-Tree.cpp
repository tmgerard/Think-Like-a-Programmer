/*
*   Problem: Find the largest value in a binary tree
*
*   Write a function that, when given a binary tree where each node holds an integer,
*   returns the largest integer in the tree.
*/

#include <iostream>

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;
};

typedef treeNode* treePtr;

int maxValue(treePtr root);

int main()
{

}

int maxValue(treePtr root)
{
    if (root = NULL) return 0;
    if (root->right == NULL && root->left == NULL)
    {
        return root->data;
    }
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
    int maxNum = root->data;
    if (leftMax > maxNum) maxNum = leftMax;
    if (rightMax > maxNum) maxNum = rightMax;
    return maxNum;
}
