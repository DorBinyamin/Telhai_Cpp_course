#include <iomanip>
#include "Plain.h"

Plain::Plain(unsigned int** graph,unsigned int size):Graph(graph),Size(size){}//constructor

// Copy constructor
Plain::Plain(const Plain& other) : Size(other.Size) {
    Graph = new unsigned int*[Size];
    for (unsigned int i = 0; i < Size; ++i) {
        Graph[i] = new unsigned int[Size];
        for (unsigned int j = 0; j < Size; ++j) {
            Graph[i][j] = other.Graph[i][j];
        }
    }
}

Plain& Plain:: operator=(const Plain& other) {
    if (this != &other) {
        // Deallocate current resources
        for (unsigned int i = 0; i < Size; ++i) {
            delete[] Graph[i];
        }
        delete[] Graph;
        // Copy new resources
        Size = other.Size;
        Graph = new unsigned int*[Size];
        for (unsigned int i = 0; i < Size; ++i) {
            Graph[i] = new unsigned int[Size];
            for (unsigned int j = 0; j < Size; ++j) {
                Graph[i][j] = other.Graph[i][j];
            }
        }
    }
    return *this;
}

Plain::~Plain() {
    for (unsigned int i = 0; i < Size; ++i) {
        delete[] Graph[i];
    }
    delete[] Graph;
}

void Plain::Printplain(Linkedlist<Plain_Horse> *linkedlisthorses, Intersection **intersectionarr, int time) {
    int numofhorses = count(linkedlisthorses),r;
    for (int i = 0; i < time; i++) {
        Node<Plain_Horse> *horses = linkedlisthorses->getHead();
        for (int j = 0; j < numofhorses; j++) {
            int numberRoute = intersectionarr[horses->type->getLocation() - 1]->getSizeofpaths();
            r = horses->type->calculate(numberRoute); //calculate if the horse move or not (calculate for type of horses in run time)
            if (r == 0) {
                horses = horses->next;
                continue;
            }
            int temp = 0;
            Node<Path> *p = intersectionarr[horses->type->getLocation() - 1]->getPaths()->getHead();
            while (temp < r - 1) {
                p = p->next;
                temp++;
            }
            double numberofnewlevel= *p->type + horses->type->getC(); //updating the trail level
            p->type->setTransitionLevel(numberofnewlevel);
            horses->type->setLocation(p->type->getTo());
            horses = horses->next;
        }
        }
    Printlevel_of_paths(intersectionarr);
    PrintHorses(linkedlisthorses);
}

void Plain::PrintHorses(Linkedlist<Plain_Horse> *linkedlisthorses) const{ //this function print all the horses
    unsigned int location = 0;
    while (location < Size) {
        Node<Plain_Horse> *horse = linkedlisthorses->getHead();
        string str;
        str+=to_string(location+1)+":" ;
        while (horse != nullptr){
            if(horse->type->getLocation() == static_cast<int>((location+1))){
                str+=horse->type->getName()+",";
            }
            horse=horse->next;
        }
        if(str.back() == ',')str.erase(str.size() - 1);  //this if for the print and remove the last ","
        cout<<str<<endl;
        location++;
    }
}



void Plain::Printlevel_of_paths(Intersection** intersectionarr){ //this function print all level of path like matrix;
    for (unsigned int k = 0; k < this->Size; k++) {
        Node<Path> *path = intersectionarr[k]->getPaths()->getHead();
        for (unsigned int j = 0; j < this->Size; j++) {
            if (Graph[k][j] == 0 || path->type->getTransitionLevel()==0) {
                if(j==Size -1)//This if for the print
                    cout <<"0";
                else cout<<"0"<< ' ';
            } else {
                if( j==Size -1){//This if for the print
                    cout<<std::fixed<<std::setprecision(2)<< path->type->getTransitionLevel() ;
                }
                else {
                    cout<<std::fixed<<std::setprecision(2) << path->type->getTransitionLevel()<<' ';
                }
                path = path->next;
            }
        }
        cout << endl;
    }
}

int Plain::count(Linkedlist<Plain_Horse> *linkedlisthorses) { //This function count the size of Horses
    Node<Plain_Horse>* t= linkedlisthorses->getHead();
    int count = 0;
    while(t != nullptr){
        count++;
        t =  t->next;
    }
    return count;
}