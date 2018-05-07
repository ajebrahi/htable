#include <stdio.h>
#include "ht_funcs.h"
#include<stdlib.h>
#include<string.h>
int main(int argvc, char *argv[]){

    FILE *file = NULL;
    int c;
    int freq[256] = {0};
    char *codes[256];
    int i;
    Node *head = NULL;
    file = fopen(argv[1], "r");

    while((c = getc(file)) != EOF){
        printf("The character is %c\n", c);
        freq[c]++;
    }

    head = build_linked(freq);
    /*while (cur != NULL && count < 5) {
        printf("Letter: %c\nFreqeuncy: %d\n", cur->letter, cur->frequency);
        cur = cur->next;
        count++;
    }*/
    head = build_tree(head);

    for(i = 0; i < 256; i++){
        codes[i] = (char *)malloc(sizeof(char));
        codes[i][0] = '-';
    }

    encode(codes, head, "");

    for(i = 0; i < 256; i++){
        if(codes[i][0] != '-'){
            printf("0x%x: %s\n", i, codes[i]);
        }
    }
    free_tree(head);
    for(i = 0; i < 256; i++){
        free(codes[i]);
    }
    fclose(file);
    return 0;
}
