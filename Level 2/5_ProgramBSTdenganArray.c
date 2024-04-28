#include <stdlib.h>
#include <stdio.h>

struct bst{
    int data;
    struct bst * right, * left;
};
typedef struct bst node;

void insert(node ** tree, int val){
    node *temp = NULL;

    if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data){
        insert(&(*tree)->left, val);
        }else if(val > (*tree)->data){
            insert(&(*tree)->right, val);
        }
}

void print_preorder(node * tree){
    if (tree){
        printf("\t|| %d || ", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(node * tree){
    if (tree){
        print_inorder(tree->left);
        printf("\t|| %d || ",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree){
    if (tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("\t|| %d || ",tree->data);
    }
}

void printlevelorder(struct node * tree){
    int h = height(tree);
    int i;
    for (i=1; i<=h; i++){
        printcurrentlevel(tree, i);
    }
}

void printcurrentlevel(node * tree, int level){
    if(tree == NULL){
        return;
    }
    if(level == 1){
        printf("\t|| %d || ", tree->data);
    }else if(level > 1){
        printcurrentlevel(tree->left, level-1);
        printcurrentlevel(tree->right, level-1);
    }
}

int height(node * tree){
    if(tree == NULL){
        return 0;
    }else{
        int lheight = height(tree->left);
        int rheight = height(tree->right);

        if (lheight > rheight){
            return (lheight + 1);
        }else{
            return (rheight + 1);
        }
    }
}

/*void deltree(node * tree){
    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}*/

node* search(node ** tree, int val){
    if(!(*tree)){
        return;
    }
    printf(" %d  ", (*tree)->data);
    if(val < (*tree)->data){
        search(&((*tree)->left), val);
    }else if(val > (*tree)->data){
        search(&((*tree)->right), val);
    }else if(val == (*tree)->data){
        return *tree;
    }
}

void main(){
    node * root;
    node * tmp;
    int val[30] = {7131, 4785, 8820, 654, 2306, 3029, 6587, 5371, 2069, 7816, 8119, 3096, 6909, 697, 3764, 3756, 6115, 8477, 9594, 8856, 3741, 8500, 8693, 1090, 7461, 3007, 1162, 6303, 6279, 3310};
    int  i,j;
    root = NULL;

    printf(">>>> PROGRAM BINARY SEARCH TREE DENGAN PENYIMPANAN ARRAY <<<<\n\n");

    /*Inserting nodes into tree */
    for(i=0; i<29; i++){
        insert(&root, val[i]);
    }
    /* Printing nodes of tree */
    printf("========================================================================================================================\n");
    printf("Pre Order Display\n");
    print_preorder(root);
    printf("\n========================================================================================================================\n");
    printf("\nIn Order Display\n");
    print_inorder(root);
    printf("\n========================================================================================================================\n");
    printf("\nPost Order Display\n");
    print_postorder(root);
    printf("\n========================================================================================================================\n");
    printf("\nLevel Order Display\n");
    printlevelorder(root);
    printf("\n========================================================================================================================\n");

    /* Search node into tree */
    printf(">>> SEARCH NODE <<<<\n");
    printf("\n-----> SEARCHING 8820 <-----\n");
    printf("Simpul node =");
    tmp = search(&root, 8820);
    if (tmp){
        printf("\nSearched node = %d\n", tmp->data);
    }else{
        printf("Data Not Found in tree.\n");
    }

    printf("\n========================================================================================================================\n");
    printf("-----> SEARCHING 8477 <-----\n");
    printf("Simpul node = ");
    tmp = search(&root, 8477);
    if (tmp){
        printf("\nSearched node = %d\n", tmp->data);
    }else{
        printf("Data Not Found in tree.\n");
    }

    printf("\n========================================================================================================================\n");
    printf("-----> SEARCHING 6279 <-----\n");
    printf("Simpul node = ");
    tmp = search(&root, 6279);
    if (tmp){
        printf("\nSearched node = %d\n", tmp->data);
    }else{
        printf("Data Not Found in tree.\n");
    }
    printf("\n========================================================================================================================");
}

