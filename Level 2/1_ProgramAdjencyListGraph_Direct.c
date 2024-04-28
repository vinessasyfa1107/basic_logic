#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph{
    int numVertices;
    struct node** adjLists;
};

//create a node
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
};

//create a graph
struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    int i;
    for(i=0; i < vertices; i++){
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// add edge
void addEdge(struct Graph* graph, int s, int d){
    //add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}

//print the Graph
void printGraph(struct Graph* graph){
    int v;
    for(v=0; v<graph->numVertices; v++){
        struct node* temp = graph->adjLists[v];
        printf("\n In Vertex %d\n= ", v);
        while(temp){
            printf("%d --> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int jv, je, vertexasal, vertextujuan, i;
    printf("=== Adjency List Graph Berarah ===\n");
    printf("--> Input jumlah vertex : ");
    scanf("%d", &jv);
    printf("--> Input jumlah edge : ");
    scanf("%d", &je);
    struct Graph* graph = createGraph(jv);
    printf("\n");

    //Penambahan Edge
    for(i=0;i<je;i++){
        printf("\n-- Penambahan Edge --\n");
        printf("++ vertex asal : ");
        scanf("%d", &vertexasal);
        printf("++ vertex tujuan : ");
        scanf("%d", &vertextujuan);
        addEdge(graph, vertexasal, vertextujuan);
    }
    printGraph(graph);

    return 0;
}
