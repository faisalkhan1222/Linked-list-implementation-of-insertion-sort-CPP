
/*
 Linked list implementation of insertion-sort(C++)
 Author: FaisalKhan
 Dated: 2/14/16.
 */

#include <iostream>
#include <fstream>

using namespace std;

class ListNode {
    
    friend class LinkedList;
    int data;
    ListNode* next;

    
    //constructor to create the first node
    ListNode(int element){
        data = element;
        next = NULL;
    } //ListNode
    
    //constructor to create all the nodes except the first node
    ListNode(int element, ListNode* spot){
        //create a temp node to store the element
        ListNode* tempNode = new ListNode(element);
        //connect the temp node with the list
        tempNode -> next = spot -> next;
        spot -> next = tempNode;

    } //ListNode
    
    ~ListNode(){
        if (next != NULL)
        {
            delete next;
        }//if

    } //~ListNode
    
}; //ListNode


class LinkedList{
    
private:
    
    ListNode* listHead;
    
public:
    
    LinkedList(){
        
        listHead = new ListNode(-9999);
        listHead -> next = NULL;
    }
    
    //listInsert calls both of the constructors from class ListNode
    void listInsert(int input,ofstream &outfile){
        //find the correct spot for the incoming element
        ListNode* spot = findSpot(input);
        
        //check for duplicate data
        if(spot -> next != NULL  && spot -> next -> data == input){
            outfile << spot -> next -> data  << " is already in the list"<<endl;
            cout << spot -> next -> data  << " is already in the list"<<endl;
        }
        //insert the data into the list and print the list
        else
        {   ListNode* insertNode = new ListNode(input,spot);
            printList(outfile);
        }
        
    }//listInsert
    
    bool isEmpty(){
        return listHead -> next == NULL;
    }//isEmpty
    
    // Find the spot for an incoming data based on
    // its size so the list can stay sorted
    ListNode* findSpot(int data){
 
        ListNode* spot = listHead;
        
        while(spot -> next != NULL && spot->next->data < data){
            spot = spot -> next;
        }//while
        return spot;
    }//findspot

    //print the linked list elements to the console
    // and the output file
    void printList(ofstream &outfile){
        
        ListNode* traverseList = listHead;
        //traverse through the list and print the list
        while(traverseList -> next != NULL){
            outfile<< "(" <<traverseList -> data << "," << traverseList -> next -> data << ")" << "-->";
            cout<< "(" <<traverseList -> data << "," << traverseList -> next -> data << ")" << "-->";
            
            traverseList = traverseList -> next;
            
            if(traverseList -> next == NULL){
                outfile<<  "(" <<traverseList -> data << "," << "-1)" <<endl;
                cout<<  "(" <<traverseList -> data << "," << "-1)" <<endl;
            }//if
            
        }//while
        
    }//printList
    
    
    ~LinkedList(){
        
        if (listHead != NULL)
        {
            delete listHead;

        }
    }   //~LinkedList
    
};  //LinkedList class



int main(int argc, const char * argv[]) {
    
    //temperory variable to store the integer read from file
    int fileData;
    
    ifstream inputFile;
    
    ofstream outFile;
    
    //open the file provided an argument
    inputFile.open(argv[1]);
    
    //open the Outfile provided in the argument
    outFile.open(argv[2]);
    
    //check if an input file was provided as an argument
    if(!inputFile.is_open()){
        cout<<"An Input file must be provided as the first argument!"<<endl;
        cout<<"Terminating Program."<<endl;
        return -1;
    } //if
    
    //check if an output file was provided as an argument
    if(!outFile.is_open()){
        cout<<"An Output file must be provided as the second argument!"<<endl;
        cout<<"Terminating Program."<<endl;
        return -1;
    } //if
    
    cout<<endl;
    
    //create a new list object
    LinkedList* list = new LinkedList();
    
    cout <<"Contents of the Sorted Linked List" <<endl;
    cout<<endl;
    
    //keep on reading from file until there is no more data left to read
    while(inputFile >> fileData){
        cout << "Insert data " << fileData <<":  listHead --> ";
        list -> listInsert(fileData,outFile);
    } //while
    
    
    //close input file
    inputFile.close();
    
    //close output file
    outFile.close();
    
    delete list;
    
    cout<<endl;

    return 0;
}//main



