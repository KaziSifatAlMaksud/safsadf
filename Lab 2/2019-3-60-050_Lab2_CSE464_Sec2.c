/*
Create two files, keys.txt and find.txt,
with random integers. Create a binary search tree containing the integers in keys.txt.
Report the runtime elapsed to create the binary search tree. Now, search the integers of find.txt
in the binary search tree. Report the runtime elapsed for searching all the keys
in the binary search tree.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *right_child;
    struct node *left_child;
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x)
        return root;
    else if(x>root->data)
        return search(root->right_child, x);
    else
        return search(root->left_child,x);
}


struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL)
        return find_minimum(root->left_child);
    return root;
}

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{

    if(root==NULL)
        return new_node(x);
    else if(x>root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child,x);
    return root;
}

struct node* delete(struct node *root, int x)
{

    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {

        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}


int main()
{
    clock_t start = clock();
    struct node *root;
    FILE *fptr, *findptr;

    fptr = fopen("key.txt", "w");

    if (fptr == NULL){
        printf("Error!");
        exit(1);
    }
    int root_random = rand()%100;
    /*printf("%d\n\n",root_random);*/
    root = new_node(root_random);
    for(int i = 0;i<100;i++){
        int num_input;
        num_input = rand()%100;
        putw(num_input, fptr);
    }
    fclose(fptr);
    fptr = fopen("key.txt", "r");
    printf("\n ======Read the Value from Key.txt file====== \n");
    for (int num = getw(fptr); num != EOF; num = getw(fptr)) {
        printf("%d\n", num);
        insert(root, num);
    }
    fclose(fptr);
    inorder(root);

     findptr = fopen("Find.txt", "w");

    if (fptr == NULL){
        printf("Error!");
        exit(1);
    }

    for(int i = 0;i<100;i++){
        int find_input;
        find_input = rand()%100;
        putw(find_input, findptr);
    }
    fclose(findptr);
    findptr = fopen("Find.txt", "r");
    printf("\n ===== Read the Value from Find.txt file ======\n");
    for (int num1 = getw(findptr); num1 != EOF; num1 = getw(findptr)) {
            printf("%d\n", num1);
            struct node* result = search(root, num1);
                if (result == NULL) {
                    printf("\n Value not found in the binary search tree\n");
                } else {
                    printf("Value found in the binary search tree\n");
                }

    }
    fclose(findptr);
    clock_t end = clock();
    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n ===== Time elapsed to create binary search tree =====\n");
    printf("Time elapsed: %f seconds\n", time);
    return 0;
}
