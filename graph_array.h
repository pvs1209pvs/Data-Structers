#include<stdlib.h>

struct Vertex{
  void * ele;
  int is_visisted;
  int id;
};

struct Graph{
  size_t num_vertex;
  struct Vertex ** adj_mat;
  size_t * degree; // degree of each vertex
};

struct Vertex * init_vertex(void * element, int id);

struct Graph * init_Graph(size_t n_v);

void add_vertex(struct Graph * graph, struct Vertex * v, int vertex_index);

void dfs(struct Graph g, struct Vertex * v);

void bfs(struct Graph g, struct Vertex * v);

void print_Graph(struct Graph graph);
