/*typedef struct linkedNode{

    char letter;
    int frequency;
    struct linkedNode *next;

} linkedNode;
*/
typedef struct Node{

    int letter;
    int frequency;
    struct Node *next;
    struct Node *left;
    struct Node *right;

} Node;
/*
Node *make_linked(int freq[]);

Node *add_to_head(Node* head, Node *new);
*/
Node *insert_sorted(Node *head, Node *new);
Node *build_linked(int arr[]);
/*
void swap_nodes(Node *a, Node *b);

Node *insert_sort(Node *head, char c, int freq);
void sort_linked(Node *head);

void insert_sorted(Node **head, Node *new);
void sort_linked(Node **head);
*/
Node *build_tree(Node *head);

/*Node *rmv_from_linked(Node *head);*/
void encode(char *arr[], Node *root, char *code);
void free_tree(Node *root);
Node *add_at_pos(Node *head, Node *new, int pos);
void print_tree(Node *head);
void elements_in_list(Node *head);
