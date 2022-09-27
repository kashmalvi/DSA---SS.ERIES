//**********************************************************
//************IMPLEMENTATION OF K-QUEUE*************
//**********************************************************
class NQueue{
public:
    // Initialize your data structure.
    int s; //s is the size of array
    int n; //n queues to be implemented
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freespot;
    NQueue(int n, int s){
        // Write your code here.
        this->s=s;    //s is the size of array
        this->n=n;    //n queues to be implemented
        //creating an array 'front' with size 'n' ie no. of queues to be implemented
        front=new int[n];
        rear=new int[n];
        //initialising the front and rear array with -1
        for(int i=0;i<n;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        //creating an array 'next' with size same as that of the original array, this tells us the next free slot thats available
        
        next=new int[s];
        //initialising the next array
        for(int i=0; i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1; //initialising the last value of next array as -1.
        arr=new int[s]; //creating an array of size s
        freespot=0; //freespot indicates the index where the value can be stored
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
        if(freespot==-1){
            return false;
        }
        //finding the first free index
        int index=freespot;
        //update the freespot
        freespot=next[index];
        //check whether the first element
        if(front[m-1]==-1){
            front[m-1]=index;
        }
        else{
            //link the new element to the previous element
            next[rear[m-1]]=index;
        }
        
        //update -next
        next[index]=-1;
        
        //push element
        arr[index]=x; 
        rear[m-1]=index;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        if(front[m-1]==-1){
            return -1;
        }
        
        //find index to pop
        int index=front[m-1];
        //front ko aage badhao
        front[m-1]=next[index];
        //free slots ko manage karo
        next[index]=freespot;
        freespot=index;
        return arr[index] ;
    }
};

//tc - O(1)
//sc - O(n+s)
