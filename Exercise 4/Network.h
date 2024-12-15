
#ifndef EX4_NETWORK_H
#define EX4_NETWORK_H
#include "Graph.h"



class Network {
private:
    Graph<std::string> allNetwork ;
    std::string output;
    bool checkLine(const std::string& line);
    void printNetwork();
public:
    explicit Network(int argc,char* listNetwork[]);
    void play();
    static int countWords(const std::string& str);

};


#endif //EX4_NETWORK_H
