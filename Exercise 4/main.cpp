#include "Network.h"
int main(int argc, char* argv[]){
//    std::string line ="jjjjjj            jfhf              34";
//    std::istringstream check(line);
//    std::string token;
//
//    std::string l1, l2;
//    int num;
//    check>>l1>>l2>>num;
//    if (l1.size() > 16 ||l1=="exit"
//        ||l2=="exit"|| l2.size() > 16 || num <= 0|| (!check.eof()))
//        std::cout<<l1<<"  "<<l2<<"  "<<num;

    Network network(argc, argv);
    network.play();
//   Graph<char> graph;

//   graph.addVertex('A');
//   graph.addVertex('B');
//   graph.addVertex('C');
//   graph.addVertex('D');
//   graph.addVertex('E');

//   graph.addEdge('A', 'B', 1);
//   graph.addEdge('B', 'D', 2);
//   graph.addEdge('B', 'C', 6);
//   graph.addEdge('B', 'E', 3);
//   graph.addEdge('B', 'A', 4);
//   graph.addEdge('C', 'D', 5);
//   graph.addEdge('E', 'B', 6);
//   graph.addEdge('D', 'A', 6);

//  std::cout << "Graph:" << std::endl;
//   graph.printGraph(std::cout);


// graph.removeVertex('A');
// std::cout << "Graph after removing vertex A:" << std::endl;
// graph.printGraph(std::cout);

// std::cout << "Updating edge weight from 1 to 2 to 10:" << std::endl;
//   std::cout << "Weight of edge from 1 to 2: " << graph.getEdgeWeight('B', 'D') << std::endl;

// std::cout << "Neighbors of vertex 1: ";
// std::vector<char> neighbors = graph.getNeighbors('C');
//  for (const auto &neighbor : neighbors) {
//   std::cout << neighbor << " ";
//  }
//   std::cout << std::endl;

// std::cout << "Connected nodes to vertex : ";
// std::vector<char> connectedNodes = graph.getAdjacentSources('D');
//for (const auto &node : connectedNodes) {
//    std::cout << node << " ";
// }
//std::cout << std::endl;
//out<<"okkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
//   std::vector<char> connectedNodes1 = graph.getAdjacentSources(
//           'E');
//   for (const auto &node : connectedNodes1) {
//       std::cout << node << " ";
//   }
//   std::cout << std::endl;

//   return 0;
}
