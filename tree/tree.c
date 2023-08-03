#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int value) {
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void drawTree(TreeNode *root, int x, int y, int xOffset) {
  if (root != NULL) {
    // Draw the current node
    char nodeValue[8];
    snprintf(nodeValue, sizeof(nodeValue), "%d", root->value);
    DrawText(nodeValue, x, y, 20, BLACK);

    // Calculate the position for the left and right children
    int yOffset = 60;
    drawTree(root->left, x - xOffset, y + yOffset, xOffset / 2);
    drawTree(root->right, x + xOffset, y + yOffset, xOffset / 2);

    // Draw lines to connect the current node to its children
    if (root->left != NULL)
      DrawLine(x + 8, y + 8, x - xOffset + 8, y + yOffset - 12, BLACK);
    if (root->right != NULL)
      DrawLine(x + 8, y + 8, x + xOffset + 8, y + yOffset - 12, BLACK);
  }
}

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Binary Tree Visualization");
  SetTargetFPS(60);

  // Create a sample binary tree
  TreeNode *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the tree starting from the root node
    drawTree(root, screenWidth / 2, 100, 200);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
