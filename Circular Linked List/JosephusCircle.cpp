/*There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and k-th person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive. */

#include<iostream>
#include<list>
using namespace std;

int josephusCircle(int n, int k){
    list<int>l; //creates a doubly linked list using stl container//
    for(int i=0;i<n;i++)
        l.push_back(i); //pushes i to the end of the doubly linked list//
    auto it = l.begin(); 
    while(l.size()>1){
        for(int i=1;i<k;i++){
            it++;
            if(it==l.end()){
              //if iterator reaches the end,then we change it to begin of the list//
                it = l.begin();
            }
        }
        it = l.erase(it);
        if(it==l.end()){
           //if iterator reaches the end,then we change it to begin of the list//
                it = l.begin();
            }
    }
    return l.front(); //returns front element of the list//
}