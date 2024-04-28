#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* newNode(){
    struct node* node;
    int place;

    node = malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    printf("--Please input the node: ");
    scanf("%d", &node->data);

    printf("Is there any left child from %d (choose 0 = no or 1 = yes)?: ", node->data);
    scanf("%d", &place);
    if(place == 1){
        node->left = newNode();
    }
    printf("\n");
    printf("Is there any right child from %d (choose 0 = no or 1 = yes)?: ", node->data);
    scanf("%d", &place);
    if(place == 1){
        node->right = newNode();
    }

    return node;
}

//Diurut dari PostOrder karna from bottom to up//
void printpostorder(struct node* node){
    if(node == NULL)
        return;

    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d", node->data);
}

void printinorder(struct node* node){
    if(node == NULL)
        return;
    printinorder(node->left);
    printf("%d", node->data);
    printinorder(node->right);
}

void printpreorder(struct node* node){
    if(node == NULL)
        return;
    printf("%d", node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}

void printlevelorder(struct node* root){
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        printcurrentlevel(root, i);
    }
}

void printcurrentlevel(struct node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        printf("%d", root->data);
    }else if(level > 1){
        printcurrentlevel(root->left, level-1);
        printcurrentlevel(root->right, level-1);
    }
}

int height(struct node* node){
    if(node == NULL){
        return 0;
    }else{
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight){
            return (lheight + 1);
        }else{
            return (rheight + 1);
        }
    }
}

int main(){
    int choose;
    struct node* root = newNode();
    printf("\n");

    while(1){
    printf("\n*** All nodes have been input ***");
    printf("\nWhat would you do?");
    printf("\n1.Pre-Order Operation");
    printf("\n2.In-Order Operation");
    printf("\n3.Post-Order Operation");
    printf("\n4.Level Traversal");
    printf("\n5.Exit");
    printf("\nEnter --> ");
    scanf("%d", &choose);

        switch(choose){
        case 1:
        printf("\n\n--> Displaying Pre-order Operation\n");
        printpreorder(root);
        break;
        case 2:
        printf("\n--> Displaying In-order Operation\n");
        printinorder(root);
        break;
        case 3:
        printf("\n--> Displaying Post-order Operation\n");
        printpostorder(root);
        break;
        case 4:
        printf("\n--> Displaying Level Traversal Operation\n");
        printlevelorder(root);
        break;
        case 5:
        exit(1);
        break;
        default:
        printf("Please press any key!");

        continue;
        getchar();
        }
    }
    return 0;
}

