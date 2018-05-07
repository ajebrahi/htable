#include "ht_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *insert_sorted(Node *head, Node *cur){

/*    Node *prev = head;
    Node *cur = NULL;

    if(prev == NULL){
        head = new;
        return;
    }
    while(prev->next != NULL){
        cur = prev->next;
        if((new->frequency < cur->frequency) || 
           (new->frequency==cur->frequency && new->letter < cur->letter)){
            prev->next = new;
            new->next = cur;
            return;
        }
        if(cur->next == NULL){
            cur->next = new;
        }
        prev = prev->next;
    }
}*/

    Node *prev, *next;
    if(head == NULL){
        free(head);
        cur->next = NULL;
        return cur;
    }
    prev = head;
    next = head->next;
    while((next != NULL && cur->frequency > next->frequency) || 
         (next != NULL && (cur->frequency == next->frequency) && (cur->letter > next->letter))){
        prev = prev->next;
        next = next->next;
    }
    prev->next = cur;
    cur->next = next;
    return head;
}


/*
    int pos = 0;
    Node *temp = head;
    while(temp != NULL){
        if(temp->frequency > new->frequency ||
           (new->frequency==temp->frequency && new->letter > temp->letter)){
            break;
        }
        temp = temp->next;
        pos++;
    }
    head = add_at_pos(head, new, pos);
}

Node *add_at_pos(Node *head, Node *new, int pos){
    int initial = 0;
    Node *iterate = head;

    if(iterate->frequency == 0){
        return new;
    }
    
    while(initial != pos){
        iterate = iterate->next;
        initial++;
    }
    new->next = iterate->next;
    iterate->next = new;
    return head;
}
Node *insert_head(Node *head, Node *new){
    new->next = head;
    return new;
}

int comp(Node *a, Node *b){

    if(a == NULL || b == NULL){
        return 0;
    }
    if(a->frequency < b->frequency){
        return -1;
    }
    if(a->frequency == b->frequency && a->letter < b->letter){
        return -1;
    } 
    else{ return 1;}
}
*/
Node *build_linked(int arr[]){
    Node *new;
    int i;
    Node *head = NULL;;

    for (i = 0; i < 256; i++) {
        if (arr[i] > 0) {
            new = (Node *)malloc(sizeof(Node));
            new->letter = i;
            new->frequency = arr[i];
            head = insert_sorted(head, new);
        }
    }

/*
    for(i = 0; i < 256; i++){
        if(arr[i] != 0){
            if(head->letter < 0){
                head->letter = i;
                head->frequency = arr[i];
                head->next = NULL;
            }
            else{
                new->letter = i;
                new->frequency = arr[i];
                new->next = NULL;
                head = insert_sorted(head, new);
            }
        }
    }*/
    return head;
}

Node *build_tree(Node *head){
    Node *prev = head;
    Node *cur = NULL;
    Node *new;

    if(prev == NULL){
        return head;
    }
    cur = prev->next;
    printf("head letter: %c with frequency %d\n", prev->letter, prev->frequency);
    printf("next letter: %c with frequency %d\n", cur->letter, cur->frequency);
    while(prev != NULL && prev->next != NULL){
        /*cur = prev->next;*/
/*?*/
        new = (Node *)malloc(sizeof(Node));
        new->left = (Node *)malloc(sizeof(Node));
        new->right = (Node *)malloc(sizeof(Node));

        new->left->frequency = prev->frequency;
        new->left->letter = prev->letter;
        new->right->frequency = cur->frequency;
        new->right->letter = cur->letter;
        new->next = NULL;
        new->frequency = prev->frequency + cur->frequency;
        new->letter = -1;
        head = cur->next;
        head = insert_sorted(head, new);
        prev = head;
    }
    return head;
    /*insert_sorted(head, prev);*/
}

Node *build_tree(Node *head){
    Node *first = NULL, *second = NULL, *new = NULL;
    if (head == NULL) {
        return head;
    }
    first = head;
    second = head->next;
    while (first != NULL && second != NULL) {

    }
}

void free_tree(Node *root){

    if(root == NULL){
        free(root);
        return;
    }
    if(root->left != NULL){
        free_tree(root->left);
    }
    if(root->right != NULL){
        free_tree(root->right);
    }
}

void encode(char *arr[], Node *root, char *code){

    char *left_path;
    char *right_path;

    if(root == NULL){ 
        return;
    }

    left_path = (char *)malloc(sizeof(char)*strlen(code)+1);
    right_path = (char *)malloc(sizeof(char)*strlen(code)+1);
    strcpy(left_path, code);
    strcat(left_path, "0");
    strcpy(right_path, code);
    strcat(right_path, "1");

    if(root->left == NULL && root->right == NULL){
printf("letter %d\n", root->letter);
        arr[root->letter] = realloc(arr[root->letter], sizeof(char) * strlen(code)+1);
        strcpy(arr[root->letter], code);
    }
    if(root != NULL && root->left != NULL){
    encode(arr, root->left, left_path);}
    if(root != NULL && root->right != NULL){
    encode(arr, root->right, right_path);}

    free(left_path);
    free(right_path);

}

