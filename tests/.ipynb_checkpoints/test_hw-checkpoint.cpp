// If you change anything in this file, your changes will be ignored
// in your homework submission.
// // Chekout TEST_F functions bellow to learn what is being tested.
// #include <cmath>
// #include <ctime>
// #include <fstream>
// #include <gtest/gtest.h>
// #include <iostream>
// #include <math.h>
// #include <string>

// // in order to access private members, we have to defeat the safety
// // mechanisms. This is acceptable for unit testing, but not much
// // else. It is also not portable because it is not supported by the
// // C++ spec, and therefore might not work with all compilers.
// #define private public
// #include "../code/Edge.h"
// #include "../code/Graph.h"
// #include "../code/Node.h"

// using namespace std;

// class test_Graph : public ::testing::Test {
// protected:
//   // This function runs only once before any TEST_F function
//   static void SetUpTestCase() {
//     std::ofstream outgrade("./total_grade.txt");
//     if (outgrade.is_open()) {
//       outgrade.clear();
//       outgrade << (int)0;
//       outgrade.close();
//     }
//   }

//   // This function runs after all TEST_F functions have been executed
//   static void TearDownTestCase() {
//     std::ofstream outgrade("./total_grade.txt");
//     if (outgrade.is_open()) {
//       outgrade.clear();
//       outgrade << (int)std::ceil(100 * total_grade / max_grade);
//       outgrade.close();
//       std::cout << "Total Grade is : "
//                 << (int)std::ceil(100 * total_grade / max_grade) << std::endl;
//     }
//   }

//   void add_points_to_grade(double points) {
//     if (!::testing::Test::HasFailure()) {
//       total_grade += points;
//     }
//   }

//   // this function runs before every TEST_F function
//   void SetUp() override {}

//   // this function runs after every TEST_F function
//   void TearDown() override {
//     std::ofstream outgrade("./total_grade.txt");
//     if (outgrade.is_open()) {
//       outgrade.clear();
//       outgrade << (int)std::ceil(100 * total_grade / max_grade);
//       outgrade.close();
//     }
//   }

//   static double total_grade;
//   static double max_grade;
// };

// double test_Graph::total_grade = 0;
// double test_Graph::max_grade = 144;

// // forward declaration of helpers. read and learn from them!
// Graph* buildGraphToClear();
// Graph* mkgraph();
// Node* find(Graph* graph, string label);

// // Unit Tests

// TEST_F(test_Graph, Graph_EdgeSetType) {
//   Node* a(new Node("a"));
//   Node* b(new Node("b"));
//   Edge* ab(new Edge(a, b));
//   ab->type = CROSS_EDGE;
//   ab->setType(FORWARD_EDGE);
//   ASSERT_EQ(ab->type, FORWARD_EDGE);
//   add_points_to_grade(5);
//   ab->setType(UNDISCOVERED_EDGE);
//   ASSERT_EQ(ab->type, UNDISCOVERED_EDGE);
//   add_points_to_grade(5);
// }

// TEST_F(test_Graph, Graph_ClearNode) {
//   Node* n(new Node("some node"));
//   Node* p(new Node("some other node"));
//   n->color = BLACK;
//   n->discovery_time = 42;
//   n->completion_time = 108;
//   n->rank = 23;
//   n->predecessor = p;
//   n->clear();
//   ASSERT_EQ(n->color, WHITE);
//   add_points_to_grade(2);
//   ASSERT_EQ(n->discovery_time, -1);
//   add_points_to_grade(2);
//   ASSERT_EQ(n->completion_time, -1);
//   add_points_to_grade(2);
//   ASSERT_EQ(n->rank, -1);
//   add_points_to_grade(2);
//   ASSERT_FALSE(n->predecessor);
//   add_points_to_grade(2);
// }

// TEST_F(test_Graph, Graph_ClearGraph) {
//   // HINT: implement 'Node::clear' and 'Edge::setType', and then use
//   // them to implement 'Graph::clear'.
//   Graph* g = buildGraphToClear();
//   g->clear();
//   ASSERT_EQ(g->clock, 0);
//   add_points_to_grade(1);

//   for (auto it = g->nodes.begin(); it != g->nodes.end(); ++it) {
//     Node* n(*it);
//     ASSERT_EQ(n->color, WHITE);
//     add_points_to_grade(1);
//     ASSERT_FALSE(n->predecessor);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->discovery_time, -1);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->completion_time, -1);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->rank, -1);
//     add_points_to_grade(1);
//   }
//   for (auto it = g->edges.begin(); it != g->edges.end(); ++it) {
//     Edge* e(*it);
//     ASSERT_EQ(e->type, UNDISCOVERED_EDGE);
//     add_points_to_grade(0.5);
//   }
// }

// TEST_F(test_Graph, Graph_SetNodeColor) {
//   {
//     Node* n(new Node("some node"));
//     n->color = BLACK;
//     n->discovery_time = 10;
//     n->completion_time = 11;
//     n->setColor(WHITE, 18); // The 18 should be ignored
//     ASSERT_EQ(n->color, WHITE);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->discovery_time, -1);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->completion_time, -1);
//     add_points_to_grade(1);
//   }
//   {
//     Node* n(new Node("some node"));
//     n->color = WHITE;
//     n->discovery_time = -1;
//     n->completion_time = -1;
//     n->setColor(GRAY, 18);
//     ASSERT_EQ(n->color, GRAY);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->discovery_time, 18);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->completion_time, -1);
//     add_points_to_grade(1);
//   }
//   {
//     Node* n(new Node("some node"));
//     n->color = GRAY;
//     n->discovery_time = 10;
//     n->completion_time = -1;
//     n->setColor(BLACK, 18);
//     ASSERT_EQ(n->color, BLACK);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->discovery_time, 10);
//     add_points_to_grade(1);
//     ASSERT_EQ(n->completion_time, 18);
//     add_points_to_grade(1);
//   }
// }

// TEST_F(test_Graph, Graph_NodeGetDiscoInfo) {
//   Node* n(new Node("some node"));
//   n->color = GRAY;
//   n->discovery_time = 10;
//   n->completion_time = 18;
//   n->rank = 4;
//   int c, dt, ct, r;
//   n->getDiscoveryInformation(c, dt, ct, r);
//   ASSERT_EQ(c, GRAY);
//   add_points_to_grade(2);
//   ASSERT_EQ(dt, 10);
//   add_points_to_grade(2);
//   ASSERT_EQ(ct, 18);
//   add_points_to_grade(2);
//   ASSERT_EQ(r, 4);
//   add_points_to_grade(2);
// }

// TEST_F(test_Graph, Graph_TestIfNodeIsSpanningTreeAncestor) {
//   Node* a(new Node("a"));
//   Node* b(new Node("b"));
//   Node* c(new Node("c"));
//   Node* e(new Node("e"));
//   a->predecessor = NULL;
//   b->predecessor = a;
//   c->predecessor = a;
//   e->predecessor = c;

//   ASSERT_EQ(a->isAncestor(c), false);
//   add_points_to_grade(2);
//   ASSERT_EQ(c->isAncestor(a), true);
//   add_points_to_grade(2);
//   ASSERT_EQ(e->isAncestor(a), true);
//   add_points_to_grade(2);
//   ASSERT_EQ(e->isAncestor(b), false);
//   add_points_to_grade(2);
// }

// TEST_F(test_Graph, Graph_SetSpanningTreePredecessor) {
//   Node* a(new Node("a"));
//   Node* c(new Node("c"));
//   Node* e(new Node("e"));
//   c->setPredecessor(a);
//   e->setPredecessor(c);

//   ASSERT_EQ(c->predecessor, a);
//   add_points_to_grade(5);
//   ASSERT_EQ(e->predecessor, c);
//   add_points_to_grade(5);
// }

// TEST_F(test_Graph, Graph_DepthFirstSeartchNoTrarget) {
//   Graph* g = mkgraph();
//   g->clear();
//   ASSERT_EQ(g->clock, 0);
//   add_points_to_grade(2);
//   Node* a = find(g, "a");
//   ASSERT_TRUE(a); // sanity check my find function, "a" shouldn't be null
//   add_points_to_grade(2);
//   g->dfs(a);
//   ASSERT_GT(g->clock, 0); // clock should increment beyond zero
//   add_points_to_grade(2);
//   ASSERT_EQ(a->color, BLACK); // start node should be fully explored
//   add_points_to_grade(2);
//   ASSERT_EQ(a->discovery_time, 0); // start node discovered at t=0
//   add_points_to_grade(2);
//   ASSERT_EQ(a->completion_time, 13); // should finish at exactly t=13
//   add_points_to_grade(2);
//   int c, dt, ft, r;
//   for (auto it = g->nodes.begin(); it != g->nodes.end(); ++it) {
//     Node* n(*it);
//     ASSERT_TRUE(n);
//     n->getDiscoveryInformation(c, dt, ft, r);
//     ASSERT_EQ(c, BLACK); // all nodes should be fully explored
//     add_points_to_grade(0.25);
//     ASSERT_GE(dt, 0); // discovered between 0 and 6 inclusive;
//     add_points_to_grade(0.25);
//     ASSERT_LE(dt, 6);
//     add_points_to_grade(0.25);
//     ASSERT_GE(ft, 7); // finish time between 7 and 13 inclusive
//     add_points_to_grade(0.25);
//     ASSERT_LE(ft, 13);
//     add_points_to_grade(0.5);
//   }
//   Node* f = find(g, "f");
//   Node* d = find(g, "d");
//   ASSERT_EQ(f->predecessor, d);
//   add_points_to_grade(1);
// }

// TEST_F(test_Graph, Graph_DepthFirstSeartchEdgeTypes) {
//   Graph* g = mkgraph();
//   g->clear();
//   ASSERT_EQ(g->clock, 0);
//   add_points_to_grade(1);
//   Node* a = find(g, "a");
//   ASSERT_TRUE(a); // sanity check my find function
//   add_points_to_grade(1);
//   g->dfs(a); // run the DFS

//   // declare vars to count number of each kind of edge
//   int numFwd = 0;
//   int numTree = 0;
//   int numBack = 0;
//   int numCross = 0;
//   for (auto it = g->edges.begin(); it != g->edges.end(); ++it) {
//     Edge* e(*it);
//     ASSERT_TRUE(e);
//     add_points_to_grade(1);
//     if (e->getType() == FORWARD_EDGE) {
//       numFwd++;
//     } else if (e->getType() == TREE_EDGE) {
//       numTree++;
//     } else if (e->getType() == BACK_EDGE) {
//       numBack++;
//     } else if (e->getType() == CROSS_EDGE) {
//       numCross++;
//     }
//   }

//   // The classification of edges depends on traversal order & can't be
//   // predicted at write-time, so test sums and inequalities instead.
//   ASSERT_EQ(numTree + numFwd + numBack + numCross, 12);
//   add_points_to_grade(1);
//   ASSERT_GE(numTree, 6);
//   add_points_to_grade(1);
//   ASSERT_GT(numFwd, 0);
//   add_points_to_grade(1);
//   ASSERT_GT(numBack, 0);
//   add_points_to_grade(1);
//   ASSERT_EQ(numCross, 0);
//   add_points_to_grade(1);
// }

// TEST_F(test_Graph, Graph_BreadthFirstSearch) {
//   Graph* graph = mkgraph();
//   graph->clear();
//   Node* a = find(graph, "a");
//   Node* b = find(graph, "b");
//   Node* c = find(graph, "c");
//   Node* d = find(graph, "d");
//   Node* e = find(graph, "e");
//   Node* f = find(graph, "f");
//   Node* g = find(graph, "g");
//   int color, dt, ft, rank;

//   graph->bfs(a);
//   a->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 0);
//   add_points_to_grade(2);
//   b->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 1);
//   add_points_to_grade(2);
//   c->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 1);
//   add_points_to_grade(2);
//   e->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 1);
//   add_points_to_grade(2);
//   d->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 2);
//   add_points_to_grade(2);
//   g->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 2);
//   add_points_to_grade(2);
//   f->getDiscoveryInformation(color, dt, ft, rank);
//   ASSERT_EQ(rank, 3);
//   add_points_to_grade(2);
// }

// TEST_F(test_Graph, Graph_BreadthFirstSearchWithTarget) {
//   int color, dt, ft, rank;
//   {
//     Graph* graph = mkgraph();
//     graph->clear();
//     Node* c = find(graph, "c");
//     Node* f = find(graph, "f");
//     graph->bfs(c, f);
//     f->getDiscoveryInformation(color, dt, ft, rank);
//     ASSERT_EQ(rank, 2);
//     add_points_to_grade(5);
//   }
//   {
//     Graph* graph = mkgraph();
//     graph->clear();
//     Node* b = find(graph, "b");
//     Node* c = find(graph, "c");
//     graph->bfs(c, b);
//     b->getDiscoveryInformation(color, dt, ft, rank);
//     ASSERT_EQ(rank, 3); // rank is 3 if graph is directed
//     add_points_to_grade(5);
//   }
//   {
//     Graph* graph = mkgraph();
//     graph->setDirected(false);
//     graph->clear();
//     Node* b = find(graph, "b");
//     Node* c = find(graph, "c");
//     graph->bfs(c, b);
//     b->getDiscoveryInformation(color, dt, ft, rank);
//     ASSERT_EQ(rank, 1); // rank is 1 if graph is undirected
//     add_points_to_grade(5);
//   }
// }

// // ---------------------------------------------------------------- Helpers ---

// Graph* buildGraphToClear() {
//   // make a Graph with wonky metadata. it is intended test clear().
//   Graph* g(new Graph());
//   g->clock = 42;

//   Node* a(new Node("a"));
//   a->color = GRAY;
//   a->discovery_time = 1;
//   a->completion_time = 4;
//   a->rank = 0;
//   Node* b(new Node("b"));
//   b->color = BLACK;
//   b->discovery_time = 2;
//   b->completion_time = 5;
//   b->rank = 1;
//   Node* c(new Node("c"));
//   c->color = WHITE;
//   c->discovery_time = 3;
//   c->completion_time = 6;
//   c->rank = -1;

//   Edge* ab(new Edge(a, b));
//   ab->type = TREE_EDGE;
//   Edge* bc(new Edge(b, c));
//   bc->type = CROSS_EDGE;
//   Edge* ac(new Edge(a, c));
//   bc->type = BACK_EDGE;

//   a->predecessor = NULL;
//   b->predecessor = a;
//   c->predecessor = b;

//   g->addNode(a);
//   g->addNode(b);
//   g->addNode(c);
//   g->addEdge(ab);
//   g->addEdge(bc);
//   g->addEdge(ac);

//   return g;
// }

// Graph* mkgraph() {
//   Graph* ret(new Graph());
//   Node* a(new Node("a"));
//   Node* b(new Node("b"));
//   Node* c(new Node("c"));
//   Node* d(new Node("d"));
//   Node* e(new Node("e"));
//   Node* f(new Node("f"));
//   Node* g(new Node("g"));

//   Edge* ab(new Edge(a, b));
//   Edge* ac(new Edge(a, c));
//   Edge* bc(new Edge(b, c));
//   Edge* ae(new Edge(a, e));
//   Edge* ce(new Edge(c, e));
//   Edge* cd(new Edge(c, d));
//   Edge* dg(new Edge(d, g));
//   Edge* eg(new Edge(e, g));
//   Edge* df(new Edge(d, f));
//   Edge* fb(new Edge(f, b));
//   // if graph is undirected, these could cause trouble. see that it doesn't
//   Edge* gd(new Edge(g, d));
//   Edge* ge(new Edge(g, e));

//   ret->addNode(a);
//   ret->addNode(b);
//   ret->addNode(c);
//   ret->addNode(d);
//   ret->addNode(e);
//   ret->addNode(f);
//   ret->addNode(g);

//   ret->addEdge(ab);
//   ret->addEdge(ac);
//   ret->addEdge(bc);
//   ret->addEdge(ae);
//   ret->addEdge(ce);
//   ret->addEdge(cd);
//   ret->addEdge(dg);
//   ret->addEdge(eg);
//   ret->addEdge(df);
//   ret->addEdge(fb);
//   ret->addEdge(gd);
//   ret->addEdge(ge);

//   ret->setDirected(true);

//   return ret;
// }

// Node* find(Graph* graph, string label) {
//   for (auto it = graph->nodes.begin(); it != graph->nodes.end(); ++it) {
//     Node* n = *it;
//     if (n->data == label) {
//       return n;
//     }
//   }
//   return NULL;
// }
