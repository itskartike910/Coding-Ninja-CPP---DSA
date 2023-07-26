
template <typename T> // Generalised using templates
// Queue using array;
class Queue
{
    T *arr;         // to store arr
    int nextIndex;  // to store next index
    int firstIndex; // to store the first index
    int size;       // to store the size
    int capacity;   // to store the capacity it can hold
    public:
    Queue(int s)
    { // Constructor to initialize values
        arr = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    { // Returns number of elements present
        return size;
    }

    bool isEmpty()
    { // To check if queue is empty or not
        return size == 0;
    }

    void enqueue(T element)
    { // Function for insertion
        if (size == capacity)
        { // To check if the queue is already full
            cout << "Queue Full ! " << endl;
            return;
        }
        arr[nextIndex] = element;               // Otherwise added a new element
        nextIndex = (nextIndex + 1) % capacity; // in cyclic way
        if (firstIndex == -1)
        { // Suppose if queue was empty
            firstIndex = 0;
        }
        size++; // Finally, incremented the size
    }

    T front()
    { // To return the element at front position
        if (isEmpty())
        { // To check if the queue was initially empty
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        return arr[firstIndex]; // otherwise returned the element
    }

    T dequeue()
    { // Function for deletion
        if (isEmpty())
        { // To check if the queue was empty
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        T ans = arr[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--; // Decrementing the size by 1
        if (size == 0)
        {                    // If queue becomes empty after deletion, then
            firstIndex = -1; // resetting the original parameters
            nextIndex = 0;
        }
        return ans;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!" << endl;
        }
        else if (nextIndex >= firstIndex)
        {
            for (int i = firstIndex; i < nextIndex; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (nextIndex < firstIndex)
        {
            for (int i = firstIndex; i < capacity; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i < nextIndex; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Queue using array, dynamically, queue never full;

template <typename T>
class QueueUsingArray
{
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s)
    {
        arr = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {                                     // When size becomes full
            T *newData = new T[2 * capacity]; // we simply doubled the
            // capacity
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            { // Now copied the Elements to new one
                newData[j] = arr[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            { // Overcoming the initial
                // cyclic insertion by copying
                // the elements linearly
                newData[j] = arr[i];
                j++;
            }
            delete[] arr;
            arr = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2; // Updated here as well
            // cout << "Queue Full ! " << endl;
            //  return;
        }
        arr[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        return arr[firstIndex];
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        T ans = arr[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!" << endl;
        }
        else if (nextIndex >= firstIndex)
        {
            for (int i = firstIndex; i < nextIndex; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (nextIndex < firstIndex)
        {
            for (int i = firstIndex; i < capacity; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i < nextIndex; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};