#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex, bobot;
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
void addEdge(struct Graph* graph, int s, int d, int bobot){
    //add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
    newNode->bobot = bobot;
}

//print the Graph
void printGraph(struct Graph* graph){
    int v;
    for(v=0; v<graph->numVertices; v++){
        struct node* temp = graph->adjLists[v];
        printf("\n In Vertex %d\n= ", v);
        while(temp){
            printf("%d (%d) --> ", temp->vertex, temp->bobot);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int jv, je, vertexasal, vertextujuan, bobot, i;
    printf("=== Adjency List Graph Directed and Weighted ===\n");
    printf("--> Inputkan jumlah vertex : ");
    scanf("%d", &jv);
    printf("--> Inputkan jumlah edge : ");
    scanf("%d", &je);
    struct Graph* graph = createGraph(jv);
    printf("\n");

    // proses penambahan edge
    for(i=0;i<je;i++){
        printf("\n!! Penambahan Edge !!\n");
        printf("++ vertex asal : ");
        scanf("%d", &vertexasal);
        printf("++ vertex tujuan : ");
        scanf("%d", &vertextujuan);
        printf("++ bobot : ");
        scanf("%d", &bobot);
        addEdge(graph, vertexasal, vertextujuan, bobot);
    }
    printGraph(graph);

    return 0;
}
