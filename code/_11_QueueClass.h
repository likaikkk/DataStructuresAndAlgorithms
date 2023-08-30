template<class T>
class Queue
{
public:
    void Clear;                     //clear the queue
    bool EnQueue(const T item);     //add element item to the end of the queue
    bool DeQueue(T& item);          //take out the first element of the queue and delete it
    bool IsEmpty();                 //check if the queue is empty
    bool IsFull();                  //check if the queue is full
    bool GetFront(T& item);         //read the front element without deleting
};


