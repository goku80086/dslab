#include<bits/stdc++.h>
using namespace std;
class CircularQueue{

    private :
    int *arr;
    int front,rear,size,cap1;

    public:
    CircularQueue(int cap){
        cap1=cap;
        arr=new int[cap1];
        front=-1;
        rear=-1;
        size=0;
    }

    bool isfull(){
        return size==cap1;
    }

    bool isempty(){
        return size==0;
    }

    void enqueue(int value){
        if(isfull())
        {
            cout<<"Queue is full";
            return ;
        }
        if(front==-1)
        front =0;

        rear=(rear+1)%cap1;

        arr[rear]=value;
        size++;
    }

    int dequeue(){
        if(isempty()){
            cout<<"Queue is empty";
            return -1;
        }
        int val=arr[front];
    front=(front+1)%cap1;
    size--;
    return val;

    }
    int peek(){
    if(isempty())
    return -1;
    else
    return arr[front];
    }
     void display(){
        if(isempty()) {
            cout<<"Underflow"<<endl;
            return;
        }

        int i=front;
        for (int j=0;j<size;j++) {
            cout<<arr[i]<<" ";
            i=(i+1)%cap1;
        }
        cout << endl;
    }

};
int main(){
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();

    return 0;
}