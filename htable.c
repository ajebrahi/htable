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

    if(file == NULL){
        printf("usage\n");
        return 0;
    }

    while((c = getc(file)) != EOF){
        freq[c]++;
    }

    head = build_linked(freq);
    head = build_tree(head);

    for(i = 0; i < 256; i++){
        codes[i] = (char *)malloc(sizeof(char));
        strcpy(codes[i], "-");
    }
    encode(codes, head, (char *)malloc(sizeof(char)));

    for(i = 0; i < 256; i++){
        if(codes[i][0] != '-'){
            printf("0x%02x: %s\n", i, codes[i]);
        }
    }
    free_tree(head);
    for(i = 0; i < 256; i++){
        free(codes[i]);
    }
    fclose(file);
    return 0;
}
