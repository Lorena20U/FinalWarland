int ocupado[64];
int saltar = 0;
int cambiar = 0;
int tam = 0;
int test2 = 0;
struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  delay(10);
  return newNode;
}

// Create a graph
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    tam++;
    graph->adjLists[i] = NULL;
    ocupado[i] = 0;
    delay(10);
  return graph;
}

// Add edge
void addEdge(struct Graph* graph) {
  // Add edge from s to d
  for(int i=0;i<8;i++){
    for(int xu=0;xu<7;xu++){
      test2++;
      //
  struct node* newNode = createNode(i+8*(xu+1));
  newNode->next = graph->adjLists[i+xu*8];
  graph->adjLists[i+xu*8] = newNode;
  //
  newNode = createNode(i+xu*8);
  newNode->next = graph->adjLists[i+8*(xu+1)];
  graph->adjLists[i+8*(xu+1)] = newNode;
  //
  newNode = createNode(i*8+xu+1);
  newNode->next = graph->adjLists[i*8+xu];
  graph->adjLists[i*8+xu] = newNode;
  //
  newNode = createNode(i*8+xu);
  newNode->next = graph->adjLists[i*8+xu+1];
  graph->adjLists[i*8+xu+1] = newNode;
  delay(10);}}}
void SearchGraph(struct Graph* graph, int pos, int comp, int mov, bool jump2, bool jump) {
    cambiar = -1;
    struct node* temp = graph->adjLists[pos];
    struct node* temp2;
    while (temp) {
      delay(10);
     if (temp->vertex == comp){
      if (ocupado[comp] == 1){
        if(jump == false){SearchGraph(graph, comp, (comp+mov), mov, false, true);} 
        else{return;}}
     else{
      if (jump2 == false){
      if (jump == false){
      ocupado[pos] = 0;
      ocupado[comp] = 1;}
      else{
        ocupado[pos-mov] = 0;
        ocupado[comp] = 1;   
      }
      cambiar = comp;}  
      if(jump == true){saltar = 1;}return;}}
      temp = temp->next;
      delay(10);}return;}
