#include "linkedList.h"
#include<sstream>


using namespace std;
int size=0; //Counts the amount of elements in the list


Node *Linkedlist::getHead() const {  //return the head of the list
    return head;
}

void Linkedlist::insert(int element) { //Puts the next member into the array
    Node* t=new Node(element);
    if(isEmpty()) {
        head = t;
        tail=t;
        index=t;
    }
    else {
            tail->setNext(t);
            tail=t;
            index=tail;
        }
}



bool Linkedlist::isEmpty() {//check if the list is empty
    return index == nullptr;
}

int Linkedlist::getelement() {//return the "factorial number"
    return index->getFactorial();
}


Node* Linkedlist::getCursor() {//return the address of cursor
    if(index == nullptr) return nullptr;
    return index;
}

Linkedlist::~Linkedlist() {//Destructor
    Node* t =head;
    while(t != nullptr){
        Node* next=t->getNext();
        delete t;
        t=next;
    }
    head=tail=index= nullptr;
}


//The function receives a change from the user in its full representation, converts the integers separated by a comma to an array, and in each of the following situations, the system issues an Invalid permutation.n error message and does not save the transformation.
//The sequence of numbers contains numbers outside the n-1 range
// The sequence is not unique – that is, there exists a number that appears more than once.
// The new consideration is not one legal action away from the last consideration enterd in the case of the first consideration entry,
//She will not check the conditions

void AddPermutation(const int max,const int n,Linkedlist* fullarr) {
    if (size >= max) { // check if the size of list > maximum
        cerr << "Full calculator.\n";  //if the size in link list > from the max
        return;
    }
    string line, token;
    int perm[n];
    int i = 0;
    cin >> line;
    stringstream s(line);
    while (getline(s, token, ',')) {  // insert the input from the user to array because the input sprite by ,
        perm[i] = stoi(token);

        if (perm[i] > n || perm[i] < 1) {  // check the condition
            cerr << "Invalid permutation.\n";
            return;
        }
        i++;
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (j != k && perm[j] == perm[k]) {  // check if the number exist in the linklist
                cerr << "Invalid permutation.\n";
                return;
            }
        }
    }
    int num = arrtofactorial(perm, n);  //change the arr to number in  factorial
    if (fullarr->isEmpty()) {
        fullarr->insert(num);
        printall(fullarr->getCursor(), n);
        size++;
        return;
    }
    string spermtocheck = factorialtoarr(fullarr->getelement(), n); // change the factorial to string of numbers that exist in arr
    int *arrtocheck = stringpermtoarr(n, spermtocheck);
    if (arrtocheck == nullptr)return;
    if (checkaction(arrtocheck, n, num)) { //check if the one action of permotision id o.k
        fullarr->insert(num);
        printall(fullarr->getCursor(), n);  // print the permotion
        size++;
        delete arrtocheck;
        return;
    }
    delete arrtocheck;
    cerr << "Invalid permutation.\n";
}


//The function receives from the user a number representing a transformation in the base of a factorial and in each
//From the following situations, the function prints an error message:
//Invalid or already exists factorial representation.n
//- The number is not in the valid number range 0-n!
//- The number already exists in the sequence of permutations recorded so far.
//- The consideration represented by this number is not one legal action away from the last consideration entered.


void AddFactorial(const int max,const int n,Linkedlist* fullarr) {
    if (size >= max) { // check if the size of list < maximum
        cerr << "Full calculator.\n"; //if the size in link list > from the max
        return;

    }
    int num;
    cin >> num;
    int N = factorial(n);
    if (num < 0 || num > (N - 1)) {  //check the condition (look on the condition of this function)
        cerr << "Invalid or already exists factorial representation.\n";
        return;
    }
    if(fullarr->isEmpty()){
        fullarr->insert(num);
        printall(fullarr->getCursor(),n);
        size++;
        return;
    }
        Node *t = fullarr->getHead();
        while (t != nullptr) {
            if (t->getFactorial() == num) { //check if the factorial exist in linked list
                cerr << "Invalid or already exists factorial representation.\n";
                return;
            }
            t = t->getNext();
        }
        string spermtocheck = factorialtoarr(fullarr->getelement(), n); // change the factorial to string arr
        int *arrtocheck = stringpermtoarr(n, spermtocheck); // change the string array to int array
        if (arrtocheck == nullptr)return;
        if (checkaction(arrtocheck, n, num)) { // Checks if the number (factorial) is one action away
            fullarr->insert(num);
            printall(fullarr->getCursor(), n);  // // print the permotion
            size++;
            delete arrtocheck;
            return;
        }
    delete arrtocheck;
    cerr << "Invalid or already exists factorial representation.\n";
    }



bool checkaction(int * arrtocheck,int n,int num) {   //Checks whether the push to the top action on the new permutation is one action away from the previous permutation
    for (int k = 3; k <= n; k++) {
        if (pushtothetposucess(arrtocheck, n, k - 1) == num) { // check if push the top correct
            return true;
        }
    }
    return false;
}


//The function takes an integer representing the number of the member we want to perform the operation on. and "pushes" the number in the index to the beginning. In any of the following situations, the program prints an Invalid operation or permutation already exists.
//- The resulting number is not within the valid operating range 3 until n.
//- The consideration received after running this operation, already exists in the list of permutations.
void PushtotheTop(const int n,const int max,Linkedlist* fullarr) {
    if (size >= max) { // check if size of link list < max
        cerr << "Full calculator.\n";
        return;
    }
    int numpushtop; // The index that we want push to top
    cin >> numpushtop;
    if (fullarr->isEmpty()) {
        cerr << "Empty calculator.\n";
        return;
    }
    if (numpushtop < 3 || numpushtop > n) { //check if the index not in the range
        cerr << "Invalid operation or permutation already exists.\n";
        return;
    }
    string peromation = factorialtoarr(fullarr->getelement(), n); //change the factorial to string arr
    int *arrperm = stringpermtoarr(n, peromation); // change the string array to int array
    if (arrperm == nullptr)return;
    int factorialinchack=pushtothetposucess(arrperm,n,numpushtop-1); // puse to the top the index to first
    Node* t=fullarr->getHead();
    while (t != nullptr) {
    if(t->getFactorial() == factorialinchack) { //check if the number(factorial) after the action  exist in link list
        delete arrperm;
        return;
    }
    t = t->getNext();
    }
    fullarr->insert(factorialinchack); //append the factorial to link list
    printall(fullarr->getCursor(),n);  // print the permotion
    size++;
    delete arrperm;
}


 //The function will print to the user a menu that allows selecting the print format
 //]1[ Full print
 //]2[ Print factorial values only
 //]3[ Prints only permutation values
 //- Every time you enter a book outside this range, the function prints an error message
 //Invalid print option
void print(Linkedlist* fullarr,const int n ) {
        cout << "[1] : full print " << "\n" << "[2] : factorial print \n" << "[3] : premutation print \n";
        int num;
        cin >> num;
        if (num < 1 || num > 3) {
            cerr << "Invalid print option.\n";
        }
        Node *t = fullarr->getHead();
        switch (num) { // chack the number from the user in the range
            case 1:
                while (t != nullptr) {
                    printall(t, n);
                    t = t->getNext();
                }
                break;
            case 2:
                while (t != nullptr) {
                    cout << t->getFactorial() << endl; //print the number (factorial)
                    t = t->getNext();
                }
                break;
            case 3:
                while (t != nullptr) {
                    printperm(t, n);
                    t = t->getNext();
                }
                break;
            default:
                break;
            }
        }


int arrtofactorial(const int *arr, const int n) {  // change the array to number (factorial)
        int newarr[n];
        int sum = 0, N = n - 1;
        for (int i = 0; i < n; i++) {
            int count = 0; //Counts how many numbers to our right are smaller than the number in the current index
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j])
                    count++;
            }
            newarr[i] = count;
        }
        for (int i = 0; i < n; i++) {
            sum += newarr[i] * factorial(N--); //Sum up all the numbers in the double-indexed array at the rally that corresponds to them
        }
        return sum;
    }


int factorial(int n) {  //return the number in factorial
     int res=1;
     for(int i=2;i <= n;i++) {
         res *= i;
     }
     return res;
    }


string factorialtoarr(int num,const int n) {   //change the number(factorial) to string that container the Permutation
        int arr[n], j = n - 1, basearr[n],N=n; //base array is for the base case number 0
        int endarr[n]; //the last array
        stringstream  perm; //for the save the Permutation
        if (num == 0) {
            for (int i = 0; i < n; i++) { // this loop creator thr base array(factorial 0)
                perm<<i+1;
                if(i<n-1)
                    perm<<','; //append , for print
            }
            return perm.str(); //change rhe stringstream to string
        }
        for (int i = 0; i < n; i++) { //creat the base array( factorial 0)
            basearr[i]=i+1;
        }
        for (int i = 1; i <= n; i++, j--) {  // this loop calculate the number in all call in array
            arr[j] = num % i;
            num = num / i;
        }

        for(int i=0;i<n;i++){ //this loop creat the last arr
            endarr[i]=basearr[arr[i]];
            slice(N--,arr[i],basearr);  //slice arr for the calculate the original number
        }

        for(int i=0;i<n;i++){
            perm<<endarr[i];
            if(i<n-1)
                perm<<','; //append , for print
        }

        return perm.str(); //return the string of Permutation
    }



void printall(Node* t,const int n){  //print the Permutation + factorial
        int num=t->getFactorial();
        string perm = factorialtoarr(t->getFactorial(),n);
        cout <<"[ " << perm <<" ]"<<"\t"<<num<<endl;
    }




void printperm(Node* t,const int n){  // print only the Permutation
    string perm = factorialtoarr(t->getFactorial(),n);
    cout <<"[ " << perm <<" ]"<<"\t"<<endl;
}


void slice(int n,int remove,int arr[]){  // "slice" the array and removes the index she received
    for (int i = remove; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    }



//Changes the permutation string to an array of int (the array is dynamically assigned)
int* stringpermtoarr(const int n,std::string &perm){
        int i=0;
        string arr;
        int *arrofperm =new int[n];
        stringstream sperm(perm);
        while(getline(sperm,arr,',')) { //change the string with "," to array of int
            arrofperm[i] = stoi(arr);
            i++;
        }
        if(i > n){ //check if the index not "out of range"
            delete [] arrofperm;
            return  nullptr;
        }
        return arrofperm; //return the array of int
    }


//The function takes an array and index and pushes the number that appears in the inx at the beginning of the array and moves all other elements to the right if successful,
// returns the factorial value of the permutation
int pushtothetposucess(const int* arrperm , const int n,int move ){
    int demiarr[n],i=0,j=1;
    demiarr[0]=arrperm[move];
    for(;i<move;i++,j++){
        demiarr[j]=arrperm[i];
    }
    i++;
    for(;i<n;i++,j++){
        demiarr[j]=arrperm[i];
    }
    int numfactorial = arrtofactorial(demiarr,n);
    return numfactorial;

}


