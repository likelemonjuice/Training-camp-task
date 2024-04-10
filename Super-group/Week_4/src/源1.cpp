#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>

Status BST_init(BinarySortTreePtr bst) {
    if (bst == NULL) return failed;
    bst->root = NULL;
    return succeed;
}

Status BST_insert(BinarySortTreePtr bst, ElemType value) {
    if (bst == NULL) return failed;
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    if (node == NULL) return failed;
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    if (bst->root == NULL) {
        bst->root = node;
    }
    else {
        NodePtr current = bst->root;
        NodePtr parent = NULL;
        while (current != NULL) {
            parent = current;
            if (value < current->value) {
                current = current->left;
            }
            else if (value > current->value) {
                current = current->right;
            }
            else {
                free(node); // Value already exists in the tree
                return failed;
            }
        }
        if (value < parent->value) {
            parent->left = node;
        }
        else {
            parent->right = node;
        }
    }
    return succeed;
}

Status BST_delete(BinarySortTreePtr bst, ElemType value) {
    if (bst == NULL || bst->root == NULL) return failed;
    NodePtr parent = NULL;
    NodePtr current = bst->root;
    while (current != NULL && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    if (current == NULL) return failed; // Value not found

    // Case 1: Node to be deleted has no children
    if (current->left == NULL && current->right == NULL) {
        if (current != bst->root) {
            if (parent->left == current) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else {
            bst->root = NULL;
        }
        free(current);
    }
    // Case 2: Node to be deleted has one child
    else if (current->right == NULL) {
        if (current != bst->root) {
            if (parent->left == current) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
        }
        else {
            bst->root = current->left;
        }
        free(current);
    }
    else if (current->left == NULL) {
        if (current != bst->root) {
            if (parent->left == current) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
        }
        else {
            bst->root = current->right;
        }
        free(current);
    }
    // Case 3: Node to be deleted has two children
    else {
        NodePtr successor = current->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        ElemType temp = current->value;
        current->value = successor->value;
        successor->value = temp;
        return BST_delete(bst, temp);
    }
    return succeed;
}

Status BST_search(BinarySortTreePtr bst, ElemType value) {
    if (bst == NULL || bst->root == NULL) return failed;
    NodePtr current = bst->root;
    while (current != NULL) {
        if (value == current->value) {
            if (value == current->value) {
                return succeed;
            }
            else if (value < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return failed;
    }

    // Recursive preorder traversal
    Status BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        visit(bst->root);
        if (bst->root->left != NULL) BST_preorderR(bst->root->left, visit);
        if (bst->root->right != NULL) BST_preorderR(bst->root->right, visit);
        return succeed;
    }

    // Recursive inorder traversal
    Status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        if (bst->root->left != NULL) BST_inorderR(bst->root->left, visit);
        visit(bst->root);
        if (bst->root->right != NULL) BST_inorderR(bst->root->right, visit);
        return succeed;
    }

    // Recursive postorder traversal
    Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        if (bst->root->left != NULL) BST_postorderR(bst->root->left, visit);
        if (bst->root->right != NULL) BST_postorderR(bst->root->right, visit);
        visit(bst->root);
        return succeed;
    }

    // Non-recursive preorder traversal
    Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        // TODO: Implement non-recursive preorder traversal
    }

    // Non-recursive inorder traversal
    Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        // TODO: Implement non-recursive inorder traversal
    }

    // Non-recursive postorder traversal
    Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        // TODO: Implement non-recursive postorder traversal
    }

    // Level order traversal
    Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        // TODO: Implement level order traversal
    }

#include <stdio.h>

    void visit(NodePtr node) {
        printf("%d ", node->value);
    }

    int main() {
        BinarySortTreePtr bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
        if (bst == NULL) {
            printf("Memory allocation failed\n");
            return -1;
        }
        BST_init(bst);
        BST_insert(bst, 5);
        BST_insert(bst, 3);
        BST_insert(bst, 8);
        BST_insert(bst, 1);
        BST_insert(bst, 4);
        BST_insert(bst, 7);
        BST_insert(bst, 9);

        printf("Inorder traversal: ");
        BST_inorderR(bst, visit);
        printf("\n");

        printf("Preorder traversal: ");
        BST_preorderR(bst, visit);
        printf("\n");

        printf("Postorder traversal: ");
        BST_postorderR(bst, visit);
        printf("\n");

        // Uncomment the following lines to test the level order traversal
        // BST_levelOrder(bst, visit);

        return 0;
    }
#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    Status BST_init(BinarySortTreePtr bst) {
        if (bst == NULL) return failed;
        bst->root = NULL;
        return succeed;
    }

    
    // Non-recursive preorder traversal
    Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        NodePtr current = bst->root;
        NodePtr stack[100];
        int top = -1;
        while (current != NULL || top != -1) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->left;
            }
            current = stack[top--];
            visit(current);
            current = current->right;
        }
        return succeed;
    }

    // Non-recursive inorder traversal
    Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        NodePtr current = bst->root;
        NodePtr stack[100];
        int top = -1;
        while (current != NULL || top != -1) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->left;
            }
            current = stack[top--];
            visit(current);
            current = current->right;
        }
        return succeed;
    }

    // Non-recursive postorder traversal
    Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        NodePtr current = bst->root;
        NodePtr stack[100];
        int top = -1;
        bool visitedRight = false;
        while (current != NULL || top != -1) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->left;
            }
            current = stack[top--];
            if (current->right == NULL || visitedRight) {
                visit(current);
                visitedRight = false;
            }
            else {
                stack[++top] = current;
                current = current->right;
            }
        }
        return succeed;
    }

    // Level order traversal
    Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        NodePtr queue[100];
        int front = 0, rear = 0;
        queue[rear++] = bst->root;
        while (front != rear) {
            NodePtr current = queue[
                NodePtr current = queue[front++];
                visit(current);
                if (current->left != NULL) queue[rear++] = current->left;
                if (current->right != NULL) queue[rear++] = current->right;
        }
        return succeed;
    }

    // Recursive inorder traversal
    Status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        if (bst->root->left != NULL) BST_inorderR(bst->root->left, visit);
        visit(bst->root);
        if (bst->root->right != NULL) BST_inorderR(bst->root->right, visit);
        return succeed;
    }

    // Recursive postorder traversal
    Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
        if (bst == NULL || visit == NULL) return failed;
        if (bst->root->left != NULL) BST_postorderR(bst->root->left, visit);
        if (bst->root->right != NULL) BST_postorderR(bst->root->right, visit);
        visit(bst->root);
        return succeed;
    }

    // Main function for testing
    int main() {
        BinarySortTreePtr bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
        if (bst == NULL) {
            printf("Memory allocation failed\n");
            return -1;
        }
        BST_init(bst);
        BST_insert(bst, 5);
        BST_insert(bst, 3);
        BST_insert(bst, 8);
        BST_insert(bst, 1);
        BST_insert(bst, 4);
        BST_insert(bst, 7);
        BST_insert(bst, 9);

        printf("Inorder traversal (Recursive): ");
        BST_inorderR(bst, visit);
        printf("\n");

        printf("Preorder traversal (Iterative): ");
        BST_preorderI(bst, visit);
        printf("\n");

        printf("Postorder traversal (Iterative): ");
        BST_postorderI(bst, visit);
        printf("\n");

        printf("Level order traversal: ");
        BST_levelOrder(bst, visit);
        printf("\n");

        return 0;
    }
