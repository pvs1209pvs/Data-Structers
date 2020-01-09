#include <stdlib.h>
#include <stdio.h>
#include "graph_array.h"
#include "list_con.h"

int main(){

  struct Vertex a, b, c, d, e;
  int nums[] = {0, 1, 2, 3, 4};

  a.ele = &nums[0];
  a.is_visisted = 0;

  b.ele = &nums[1];
  b.is_visisted = 0;

  c.ele = &nums[2];
  c.is_visisted = 0;

  d.ele = &nums[3];
  d.is_visisted = 0;

  e.ele = &nums[4];
  e.is_visisted = 0;

  struct Graph myGraph = *init_Graph(5);

  printf("%zu\n", myGraph.num_vertex);

  // left of the equal, 0 is going 1
  // right of the equal, nums[1] value of the vertex it's going to
  myGraph.adj_mat[0][1] = *init_vertex(&nums[1], 1);
  myGraph.adj_mat[0][2] = *init_vertex(&nums[2], 2);
  myGraph.adj_mat[0][0] = *init_vertex(NULL, 0);
  myGraph.adj_mat[0][3] = *init_vertex(NULL, 0);
  myGraph.adj_mat[0][4] = *init_vertex(NULL, 0);

  myGraph.adj_mat[1][0] = *init_vertex(&nums[0], 0);
  myGraph.adj_mat[1][3] = *init_vertex(&nums[3], 3);
  myGraph.adj_mat[1][4] = *init_vertex(&nums[4], 4);
  myGraph.adj_mat[1][1] = *init_vertex(NULL, 1);
  myGraph.adj_mat[1][2] = *init_vertex(NULL, 1);

  myGraph.adj_mat[2][0] = *init_vertex(&nums[0], 0);
  myGraph.adj_mat[2][4] = *init_vertex(&nums[4], 4);
  myGraph.adj_mat[2][1] = *init_vertex(NULL, 2);
  myGraph.adj_mat[2][2] = *init_vertex(NULL, 2);
  myGraph.adj_mat[2][3] = *init_vertex(NULL, 2);

  myGraph.adj_mat[3][3] = *init_vertex(&nums[3], 3);
  myGraph.adj_mat[3][0] = *init_vertex(NULL, 3);
  myGraph.adj_mat[3][1] = *init_vertex(NULL, 3);
  myGraph.adj_mat[3][2] = *init_vertex(NULL, 3);
  myGraph.adj_mat[3][4] = *init_vertex(NULL, 3);


  myGraph.adj_mat[4][1] = *init_vertex(&nums[1], 1);
  myGraph.adj_mat[4][2] = *init_vertex(&nums[2], 2);
  myGraph.adj_mat[4][0] = *init_vertex(NULL, 4);
  myGraph.adj_mat[4][3] = *init_vertex(NULL, 4);
  myGraph.adj_mat[4][4] = *init_vertex(NULL, 4);

  myGraph.degree[0] = 2;
  myGraph.degree[0] = 3;
  myGraph.degree[0] = 2;
  myGraph.degree[0] = 1;
  myGraph.degree[0] = 2;

  print_Graph(myGraph);

  dfs(myGraph, &myGraph.adj_mat[0][0]);
  //bfs(myGraph, &myGraph.adj_mat[0][0]);

  print_Graph(myGraph);



  return 0;
}

void bfs(struct Graph g, struct Vertex * v){

  con_list q;
  con_list_new(&q, sizeof(struct Vertex *), 5);

  con_list_add(&q, v);
  v->is_visisted = 1;
  printf("COOL %d \n", (v->id));

  while(con_list_getSize(&q)>0){
printf("yo %zu \n", con_list_getSize(&q));
    struct Vertex temp = *(struct Vertex *)con_list_get(&q, 0);

    con_list_dltIndx(&q, 0);
    // check if temp is  the goal




    for (size_t j = 0; j < g.num_vertex; j++) {
      if(g.adj_mat[temp.id][j].ele != NULL &&  g.adj_mat[temp.id][j].is_visisted == 0){
        struct Vertex * w = &g.adj_mat[temp.id][j];
        w->is_visisted = 1;
        con_list_add(&q, w);
      }
    }

  }

}

void dfs(struct Graph g, struct Vertex * v){
  v->is_visisted = 1;
  for (size_t j = 0; j < g.num_vertex; j++) {
    if(g.adj_mat[v->id][j].ele != NULL && g.adj_mat[v->id][j].is_visisted  == 0){
      dfs(g, &g.adj_mat[v->id][j]);
    }
  }

}

struct Vertex * init_vertex(void * element, int id){
  struct Vertex * v = malloc(sizeof(struct Vertex));
  v->ele = element;
  v->is_visisted = 0;
  v->id = id;
  return v;
}

struct Graph * init_Graph(size_t n){

  struct Graph * graph = malloc(sizeof(struct Graph));

  graph->num_vertex = n;

  graph->adj_mat = malloc(sizeof(struct Vertex*)*n);

  graph->degree = malloc(sizeof(size_t)*n);

  for (size_t i = 0; i < n; i++) {
    graph->adj_mat[i] = malloc(sizeof(struct Vertex)*n);
    for (size_t j = 0; j < n; j++) {
      struct Vertex * v = malloc(sizeof(struct Vertex));
      graph->adj_mat[i][j] = *v;
    }
    graph->degree[i] = 0;
  }

  return graph;

}


void add_vertex(struct Graph * graph, struct Vertex * v, int vertex_index){

}

void print_Graph(struct Graph graph){
  for (size_t i = 0; i < graph.num_vertex; i++) {
    for (size_t j = 0; j < graph.num_vertex; j++) {
      if(graph.adj_mat[i][j].ele == NULL) printf("%d,%d  ", 0, 0);
      else printf("%d,%d  ", *(int*)graph.adj_mat[i][j].ele, graph.adj_mat[i][j].is_visisted);
    }
    printf("\n");
  }
  printf("\n");
}
