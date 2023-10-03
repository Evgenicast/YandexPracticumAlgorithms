#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class MyQueueSized
{
private:
    vector<T> m_Queue;
    int m_Size = 0;
    int m_MaxSize = 0;
    int m_Head = 0;
    int m_Tail = 0;

public:

    MyQueueSized(int max_size)
    : m_Queue(max_size), m_MaxSize(max_size) {}

    void push(T item)
    {
        if (m_Size == m_MaxSize)
        {
            cout << "error\n";
        }
        else
        {
            m_Queue[m_Tail] = item;
            ++m_Tail; ++m_Size;

            if(m_Tail == m_MaxSize)
            {
                m_Tail = 0;
            }
        }
    }

    void Pop()
    {
        if(isEmpty())
        {
            cout << "None\n";
        }
        else
        {
            cout << m_Queue[m_Head] << "\n";
            //m_Queue.pop_back();
            ++m_Head;
            --m_Size;
            if (m_Head == m_MaxSize)
            {
                m_Head = 0;
            }
        }
    }

    void Peek()
    {
        if(isEmpty())
        {
            cout << "None\n";
        }
        else
        {
            cout << m_Queue[m_Head] << "\n";
        }
    }

    bool isEmpty()
    {
        return m_Size == 0;
    }

    void size()
    {
        cout << m_Size << "\n";
    }
    };
    
    int main()
	{
    ifstream f("input.txt");
    if(!f)
    {
        cout << "File not open";
        return 1;
    }

    int num, num_command;
    f >> num_command >> num;
    //f.get();
    string command;
    MyQueueSized<int> queue(num);

    for (int i = 0; i < num_command; ++i)
    {
        f >> command;
        if (command == "size")
        {
            queue.size();
        }
        else if (command == "push")
        {
            int item;
            f >> item;
            queue.push(item);
        }
        else if (command == "pop")
        {
            queue.Pop();
        }
        else if (command == "peek")
        {
            queue.Peek();
        }
    }
    return 0;
}
