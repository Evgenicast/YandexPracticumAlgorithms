#include <list>
#include <iostream>
#include <string>
#include <fstream>

template<typename T>
class Queue
{
private:

    std::list<T> m_QueueList;
    //typename std::list<T>::iterator it;

public:

    void Size()
    {
        std::cout << GetSize() << "\n";
    }

    void Put(T x)
    {
        //it = m_QueueList.begin();
        m_QueueList.push_front( x);
        //++it;

    }

    void Get()
    {
        if(GetSize() == 0)
        {
            std::cout << "error\n" ;
        }
        else
        {
            std::cout << m_QueueList.back() << "\n";
            m_QueueList.pop_back();
           // --it;
        }
    }

    size_t GetSize()
    {
        return m_QueueList.size();
    }
};

using namespace std;

int main()
{
    ifstream f("input.txt");
    if(!f)
    {
        cout << "File not open";
        return 1;
    }

    int num_command;
    f >> num_command;
    std::string command;
    Queue<int> queue;

    for (int i = 0; i < num_command; ++i)
    {
        f >> command;
        if (command == "size")
        {
            queue.Size();
        }
        else if (command == "put")
        {
            int item;
            f >> item;
            queue.Put(item);
        }
        else if(command == "get")
        {
            queue.Get();
        }
    }

    return 0;
}
