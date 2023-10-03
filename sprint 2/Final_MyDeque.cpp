#include <vector>
#include <iostream>
#include <exception>
#include <optional>

// ID 90765484

/*
-- ЗАДАЧА --

Нужно реализовать структуру данных Дек, используя кольцевой буфер.

-- МЕТОДЫ --

push_back(x), push_front(x), pop_back(), pop_front() должны иметь константную асимптотику.

-- ПРИНЦИП РАБОТЫ --

Изначальная реализация предполагала использовать std::deque в качестве базового контейнера, но, поскольку
размер дека должен быть ограничен и задается пользователем (не известен на этапе компиляции), то подходит вариант применения динамического массива,
в данном случае, std::vector.

Требуемая заданием константная асимптотика методов добавления в начало, конец и удаления (начало, конец) достигается
путем применения доступа к элементам по индексам. В данном случае предпочтение отдается методу at() у std::vector. Асимптотика О(1);
Данная реализация помогает при отладке. Даже при написании данного несложного кода были глупые ошибки, которые
как раз и помог обнаружить этот метод. Не нужно гадать после запуска, что вызвало Undefined Behaviour;

Пользовательский класс, служащий контейнером данных, должен быть шаблонным, чтобы уметь работать с разными типами элементов.
Поэтому класс MyDeque является шаблонным. Поля класса int m_Head, m_Tail, m_Size отвечают соответственно за доступ к элементам по индексу (начало, конец)
и размер в соответствии с состоянием объекта на данный момент.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --

PushFront(T item). Добавление элемента в начало Дека происходит по индексу m_Head. Далее, индекс инкрементируется. При добавлении элемента
используется метод деления по модулю, который а) автоматизирует процесс проверки выхода за границы массива в случае достижения последнего элемента (относительно m_MaxSize) и
б) возвращает индекс на начальную позицию, реализуя таким образом "кольцевой буфер".

PushBack(T item). Добавление элемента в конец Дека происходит по индексу m_Tail. Поскольку индексация зависит от размера Дека, то предварительно
нужно вычесть 1 (т.е. m_Tail - 1) и прибавить размер. (Еще одно причина для константности). Далее, индекс декрементируется. "Кольцевой буфер"
достигается таким же способом, как и при добавлении в начало (см. выше), только в обратном порядке. Если индекс достигает начала Дека, он возвращается на его
конечную позицию.

Добавление элементов в заполненный Дек (m_Size == m_MaxSize) вызывает ошибку "error"; Переменная m_Size инкрементируется или декрементируется в зависимости от вызываемого метода.

PopBack(). Данная реализация не предполагает фактического удаления элемента из конца Дека. В поток вывода записывается элемент по индексу m_Tail.
Сам индекс декрементируется.

PopFront(). Данная реализация не предполагает фактического удаления элемента из начала Дека. В поток вывода записывается элемент по индексу m_Head.
Сам индекс инкрементируется.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --

Добавление и извлечение по индексам == О(1).Выполнение n комманд == O(n).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --

Выделение памяти при создании объекта == О(n).
*/


template<typename T>
class MyDeque
{
private:

    std::vector<T> m_Data;
    int m_Head = 0;
    int m_Tail = 0;
    int m_Size = 0;

public:

    MyDeque<T>(const std::size_t & max_size)
    : m_Data(max_size, 0){}

    bool PushBack(T item)
    {
        if(m_Size == m_Data.size())
        {            
            return false;
        }
        else
        {
            m_Tail = (m_Tail - 1 + m_Data.size()) % m_Data.size();

            try
            {
                m_Data.at(m_Tail) = item;
            }
            catch (const std::exception & e)
            {
                std::cerr << "Exception: " << e.what() << std::endl;
                return false;
            }
        }

        ++m_Size;
        return true;
    }

    bool PushFront(T item)
    {
        if(m_Size == m_Data.size())
        {
            return false;
        }
        else
        {
            try
            {
                m_Data.at(m_Head) = item;
            }
            catch (std::exception const & e)
            {
                std::cerr << "Exception: " << e.what() << std::endl;
                return false;
            }

            m_Head = (m_Head + 1) % m_Data.size();
            ++m_Size;
        }
		
        return true;
    }

    std::optional<int> PopBack()
    {
        if(m_Size == 0)
        {
            return {};
        }

        int curr_tail = m_Tail;
        m_Tail = (m_Tail + 1) % m_Data.size();
        --m_Size;

        return  m_Data.at(curr_tail);
    }

    std::optional<int> PopFront()
    {
        if(m_Size == 0)
        {
            return{};
        }

        m_Head = (m_Head - 1 + m_Data.size()) % m_Data.size();
        --m_Size;

        return m_Data.at(m_Head);
    }
};

using namespace std;

int main()
{
    ifstream f("input.txt");
    if(!f)
    {
        cout << "File not open";
        return 0;
    }

    size_t comand_count, size;

    f >> comand_count >> size;
    std::string command;
    MyDeque<int> deque(size);

    for (int i = 0; i < comand_count; ++i)
    {
        f >> command;
        if (command == "push_back")
        {
            int value;
            f >> value;

            if (deque.PushBack(value))
            {
                continue;
            }
            else
            {
                 std::cout << "error\n";
            }
        }
        else if (command == "push_front")
        {
            int value;
            f >> value;
            if (deque.PushFront(value))
            {
                continue;
            }
            else
            {
                 std::cout << "error\n";
            }
        }
        else if (command == "pop_front")
        {
            auto val = deque.PopFront();
            if (!val)
            {
                cout << "error\n";
            }
            else
            {
                cout << *val << endl;
            }            
        }
        else if (command == "pop_back")
        {
            auto val = deque.PopBack();
            if (!val)
            {
                cout << "error\n";
            }
            else
            {
                cout << *val << endl;
            }
        }
    }
    return 0;
}