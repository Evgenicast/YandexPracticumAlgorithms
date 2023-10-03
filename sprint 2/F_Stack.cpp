#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

template<typename T>
class StackMax
{
private:
    std::vector<T> items;

public:
    StackMax() = default;

    void push(T item)
    {
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
            T lastItem = items.back();
            items.pop_back();
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
            int max = items.front();
            for (auto v : items)
            {
                if (v > max)
                {
                    max = v;
                }
            }
            std::cout << max << "\n";
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
}
