
#include "Network.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

bool Network::checkLine(const std::string& line) {
    output="out.dat";
    std::istringstream check(line);
    std::string token;

    std::string l1, l2;
    int num;
    check>>l1>>l2>>num;
    if (l1.length() > 16 ||l1=="exit"||l2=="exit"|| l2.length() > 16 || num <= 0) {
        if (num <= 0){
            std::cout << "ERROR: node definition in <input> is invalid\n";
    }
        return false;
    }
    return true;
}
void Network::printNetwork(){
    std::ofstream file(output);
    if(!file.is_open()){
        std::cerr<<"ERROR: <"<<output<<"> does not exist or cannot be opened\n";
        exit(1);
    }
    allNetwork.printGraph(file);
}
Network::Network (int argc, char **listNetwork){
    for (int i = 1; i <argc; ++i) {
        if(listNetwork[i][0]=='-' && listNetwork[i][1]=='o'){
            output=(static_cast<std::string>(listNetwork[i]).erase(0,2));
            continue;
        }
        std::ifstream file(listNetwork[i]);
        if(!file.is_open()){
            std::cerr<<"ERROR: <"<<listNetwork[i]<<"> does not exist or cannot be opened\n";
            exit(1);
        }
        std::string line;
        while (std::getline(file,line )) {
            std::string word;
            if (checkLine(line) || countWords(line) ==3){
                std::stringstream line1(line);
                std::string from,to;
                int weight;
                line1>>from>>to>>weight;
                allNetwork.addEdge(from,to,weight);
            }else{
                std::cerr<<"ERROR: <"<<listNetwork[i]<<"> does not exist or cannot be opened\n";
                exit(1);
            }
        }
       file.close();
    }
    printNetwork();
}
void Network::play() {
    std::string user;
    while ((std::cin>>user) && user !="exit") {

        if (!allNetwork.isVertex(user)) {
            std::cout << user << " does not exist in the current network" << "\nUSAGE: <node> or ‘exit’ to terminate\n";
            continue;
        }
        std::vector<std::string> neighbors;
        neighbors = allNetwork.getConnectedNodes(user);
        if (neighbors.empty()) {
            std::cout << user << " : no outbound travel";
        }
        else {
            std::cout <<"\n"<< user << "\t";
            for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
                std::cout << *it;
                if (std::next(it) != neighbors.end()) {
                    std::cout << "\t";
                }
            }
            std::cout << std::endl;
        }
    }
}

int Network::countWords(const std::string& str) {
        std::istringstream iss(str);
        int wordCount = 0;
        std::string word;
        while (iss >> word) {
            ++wordCount;
        }
        return wordCount;
    }



