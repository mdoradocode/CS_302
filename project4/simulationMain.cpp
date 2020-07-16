//Michael Dorado, April 2020, CS 302
//This program takes in data on customer arrival and transactions times and simulates what a bank line wait times would be. it employs the use of events, nodes, node queues, and priority node Queus
#include <iostream>
#include "nodeQueue.h"
#include "nodeQueue.cpp"
#include "Node.h"
#include "Node.cpp"
#include "event.h"
#include "event.cpp"
#include "pQueue.h"
#include "pQueue.cpp"
#include <fstream>

using namespace std;

void processDepart(float &timeWaited, int &teller, int currTime, event<int> *newEvent, pQueue<int, event<int>> &eventQueue, nodeQueue<int, Node<int>> &bankLine);
void processArrival(float &timeWaited, int &teller, int currTime, event<int> *newEvent, pQueue<int, event<int>> &eventQueue, nodeQueue<int,Node<int>> &bankLine);



int main(){
    //Variable Declaraction
    pQueue<int, event<int>> eventQueue;
    nodeQueue<int, Node<int>> bankLine;
    int tempTrans, tempArrive, currTime;
    float averageWait;
    float sizeOfQueue = 0;
    int teller = 1;
    float timeWaited = 0;
    ifstream file;
    //File I/O
    file.open("data.txt");

    //Filling up the event queue so it may be messed with
    while(!file.eof())
    {  
        file >> tempArrive;
        file >> tempTrans;
        eventQueue.push(tempArrive,tempTrans,0);
        sizeOfQueue++;
    }

    file.close();

    //This portion will create and modify the queues
    while(!eventQueue.IsEmpty())
    {
        event<int> *newEvent = eventQueue.peek();
        currTime = newEvent -> getTime();
        if(newEvent -> getType() == 0)
        {
            cout << "Processing Arrival Event at: " << currTime << endl;
            processArrival(timeWaited, teller, currTime, newEvent, eventQueue, bankLine);
            teller = 0;
        }
        else
        {
            cout << "Processing Departure Event at: " << currTime << endl;
            processDepart(timeWaited, teller, currTime, newEvent, eventQueue, bankLine);
        }
    }
    averageWait = (timeWaited/sizeOfQueue);
    cout << "Amount of People Processed: " << sizeOfQueue << endl << "Average Wait Time: " << averageWait << endl;

} 

void processArrival(float &timeWaited, int &teller, int currTime, event<int> *newEvent, pQueue<int, event<int>> &eventQueue, nodeQueue<int,Node<int>> &bankLine)
{ 
    int tempTime, tempLength;
    tempTime = newEvent -> getTime();
    tempLength = newEvent -> getLength();
    eventQueue.pop();
    if(bankLine.IsEmpty() && teller == 1){
        int depart = currTime + tempLength;
        eventQueue.push(depart, 0, 1);
        timeWaited += (depart-newEvent ->getTime()-newEvent ->getLength());
        teller = 0;
    } 
    else{
        bankLine.push(tempTime, tempLength);
    }
}

void processDepart(float &timeWaited, int &teller, int currTime, event<int> *newEvent, pQueue<int, event<int>> &eventQueue, nodeQueue<int, Node<int>> &bankLine)
{   
    eventQueue.pop();
    if(!bankLine.IsEmpty())
    {
        int tempTime, tempLength;
        Node<int> *tempEvent = bankLine.peek();
        tempTime = tempEvent -> getArrive();
        tempLength = tempEvent -> getTransaction();
        bankLine.pop();
        int depart = currTime + tempLength;
        eventQueue.push(depart, 0, 1);
        timeWaited+=(depart - tempTime - tempLength);
    }
    else
    {
        teller = 1;
    }
}