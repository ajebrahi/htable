#include <stdio.h>
#include "ht_funcs.h"
#include<stdlib.h>
#include<string.h>
int main(int argvc, char *argv[]){

    FILE *file = NULL;
    char c;
    int freq[256];
    char *codes[256];
    int i;
    Node *head = NULL;

    file = fopen(argv[1], "r");

    for(i = 0; i < 256; i++){
        freq[i] = 0;
    }

    while((c = getc(file)) != EOF){
        freq[(unsigned)c]++;
    }

    head = build_linked(freq);
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
