#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char alphabet;
    int frequency;
} SYMBOL;

typedef struct Node {
    SYMBOL symbol;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node** array;
    int size;
} MinHeap;

Node* createNode(char alphabet, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol.alphabet = alphabet;
    newNode->symbol.frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

MinHeap* createMinHeap(int size) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->array = (Node**)malloc(size * sizeof(Node*));
    minHeap->size = 0;
    return minHeap;
}

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->symbol.frequency < minHeap->array[smallest]->symbol.frequency) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->symbol.frequency < minHeap->array[smallest]->symbol.frequency) {
        smallest = right;
    }
    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i] = node;

    while (i && minHeap->array[i]->symbol.frequency < minHeap->array[(i - 1) / 2]->symbol.frequency) {
        swapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

MinHeap* buildMinHeap(SYMBOL symbols[], int n) {
    MinHeap* minHeap = createMinHeap(n);
    for (int i = 0; i < n; i++) {
        minHeap->array[i] = createNode(symbols[i].alphabet, symbols[i].frequency);
    }
    minHeap->size = n;
    for (int i = (n - 2) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
    return minHeap;
}

Node* buildHuffmanTree(SYMBOL symbols[], int n) {
    MinHeap* minHeap = buildMinHeap(symbols, n);

    while (minHeap->size != 1) {
        Node* left = extractMin(minHeap);
        Node* right = extractMin(minHeap);

        Node* top = createNode('$', left->symbol.frequency + right->symbol.frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    if (root->symbol.alphabet != '$') {  // Avoid printing internal nodes
        printf("%c ", root->symbol.alphabet);
    }
    inOrderTraversal(root->right);
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    SYMBOL symbols[n];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }
    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    Node* root = buildHuffmanTree(symbols, n);
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
