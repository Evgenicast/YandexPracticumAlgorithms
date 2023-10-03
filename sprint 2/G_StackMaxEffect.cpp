#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template<typename T>
class StackMax
{
private:
    std::vector<T> items;
    std::vector<T> m_MaxVec;
public:

    void push(T item)
    {
        if(items.empty() || item > m_MaxVec.back())
        {
            m_MaxVec.push_back(item);
        }
        else
        {
            m_MaxVec.push_back(m_MaxVec.back());
        }
        items.push_back(item);
    }

    T pop()
    {
        if(items.empty())
        {
            std::cout << "error\n";
        }
        else
        {
            //m_Max = *std::max_element(items.cbegin(), items.cend());
            T lastItem = items.back();
            items.pop_back();
            m_MaxVec.pop_back();
            return lastItem;
        }
    }

    void get_max()
    {
        if(items.empty())
        {
            std::cout << "None\n";
        }
        else
        {
//            int max = items.front();
//            for (auto v : items)
//            {
//                if (v > max)
//                {
//                    max = v;
//                }
//            }
//            std::cout << *std::max_element(items.cbegin(), items.cend()) << "\n";
//            std::cout << m_Max << '\n';
            std::cout << m_MaxVec.back() << '\n';
        }
    }

    T peek()
    {
        return items.back();
    }

    int size()
    {
        return items.size();
    }

};

#include <fstream>


using namespace std;

int main()
{
    ifstream f("input.txt");
    if(!f)
    {
        cout << "Can'r open file";
        return 1;
    }

    int num;
    f >> num;
    std::string command;
    StackMax<int> stack;

    for (int i = 0; i < num; ++i)
    {
        f >> command;
        if (command == "get_max")
        {
            stack.get_max();
        }
        else if (command == "push")
        {
            int item;
            f >> item;
            stack.push(item);
        }
        else if (command == "pop")
        {
            stack.pop();
        }
    }

    return 0;
};