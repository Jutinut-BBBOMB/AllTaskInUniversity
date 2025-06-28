///นายจุติณัฏฐ์ รัตนะมงคลกุล 6609650228

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_EXPAND 30 

typedef struct {
    char node;
    int cost;
} Edge;

typedef struct {
    char name;
    Edge neighbors[MAX_NODES];
    int neighbor_count;
} Node;

typedef struct {
    char nodes[MAX_NODES];
    int top;
} Stack;

Node graph[MAX_NODES];
int node_count = 0;
int expand_count = 0;


void addNode(char name) {
    graph[node_count].name = name;
    graph[node_count].neighbor_count = 0;
    node_count++;
}


void addEdge(char from, char to, int cost) {
    for (int i = 0; i < node_count; i++) {
        if (graph[i].name == from) {
            int idx = graph[i].neighbor_count;
            graph[i].neighbors[idx].node = to;
            graph[i].neighbors[idx].cost = cost;
            graph[i].neighbor_count++;
        }
    }
}


int getNodeIndex(char name) {
    for (int i = 0; i < node_count; i++) {
        if (graph[i].name == name) return i;
    }
    return -1;
}


void sortNeighbors(Node *node) {
    for (int i = 0; i < node->neighbor_count - 1; i++) {
        for (int j = i + 1; j < node->neighbor_count; j++) {
            if (node->neighbors[i].node > node->neighbors[j].node) {
                Edge temp = node->neighbors[i];
                node->neighbors[i] = node->neighbors[j];
                node->neighbors[j] = temp;
            }
        }
    }
}


void push(Stack *s, char node) {
    s->nodes[++(s->top)] = node;
}

char pop(Stack *s) {
    return s->nodes[(s->top)--];
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}


void DFS(char start, char goal) {
    Stack s;
    s.top = -1;
    int visited[MAX_NODES] = {0};

    push(&s, start);

    while (!isStackEmpty(&s)) {
        if (expand_count > MAX_EXPAND) {
            printf(" Expand more than %d times\n", MAX_EXPAND);
            return;
        }

        char current = pop(&s);
        int index = getNodeIndex(current);

        if (visited[index]) continue;
        visited[index] = 1;
        expand_count++;

        printf("%c -> ", current);
        if (current == goal) {
            printf("Goal!\n");
            return;
        }

        sortNeighbors(&graph[index]); 
        for (int i = graph[index].neighbor_count - 1; i >= 0; i--) {
            if (!visited[getNodeIndex(graph[index].neighbors[i].node)]) {
                push(&s, graph[index].neighbors[i].node);
            }
        }
    }
    printf("No Solution\n");
}

int main() {

    addNode('S'); addNode('A'); addNode('B'); addNode('G'); addNode('D'); addNode('E'); addNode('F');
    
    addEdge('S', 'B', 2); addEdge('S', 'A', 3);

    addEdge('A', 'G', 3);

    addEdge('B', 'A', 4); addEdge('B', 'D', 4);

    addEdge('G', 'D', 4); addEdge('G', 'E', 5);

    addEdge('D', 'F', 5);
    
    addEdge('E', 'F', 5);

    printf("Depth-First Search Path: ");
    DFS('S', 'F');

    return 0;
}
