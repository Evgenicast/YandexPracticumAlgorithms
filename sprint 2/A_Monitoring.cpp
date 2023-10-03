#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    ifstream f("input.txt");
    if(!f)
    {
        cout << "file not open";
        return 0;
    }

    int M, N, data;

    f >> M >> N;
    
    vector<vector<int>> mat(M);
    vector<vector<int>> transpon_mat(N);
    
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            f >> data;
            mat[i].push_back(data);
        }
    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            transpon_mat[i].push_back(mat[j][i]);
        }
    }

    for(const auto & i : transpon_mat)
    {
        for (const auto & j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
	return 0;
}
/*
Алла получила задание, связанное с мониторингом работы различных серверов. Требуется понять, сколько времени обрабатываются определённые запросы на конкретных серверах. 
Эту информацию нужно хранить в матрице, где номер столбца соответствуют идентификатору запроса, а номер строки — идентификатору сервера. Алла перепутала строки и столбцы местами. 
С каждым бывает. Помогите ей исправить баг.
Есть матрица размера m × n. Нужно написать функцию, которая её транспонирует.
Транспонированная матрица получается из исходной заменой строк на столбцы.

Формат ввода
В первой строке задано число n — количество строк матрицы.
Во второй строке задано m — число столбцов, m и n не превосходят 1000. В следующих n строках задана матрица. Числа в ней не превосходят по модулю 1000.

Формат вывода
Напечатайте транспонированную матрицу в том же формате, который задан во входных данных. Каждая строка матрицы выводится на отдельной строке, элементы разделяются пробелами.

Пример 1
Ввод			Вывод
4
3
1 2 3
0 2 6
7 4 1
2 7 0
				1 0 7 2
				2 2 4 7
				3 6 1 0
Пример 2
Ввод			Вывод
9
5
-7 -1 0 -4 -9
5 -1 2 2 9
3 1 -8 -1 -7
9 0 8 -8 -1
2 4 5 2 8
-7 10 0 -4 -8
-3 10 -7 10 3
1 6 -7 -5 9
-1 9 9 1 9
			-7 5 3 9 2 -7 -3 1 -1
			-1 -1 1 0 4 10 10 6 9
			0 2 -8 8 5 0 -7 -7 9
			-4 2 -1 -8 2 -4 10 -5 1
			-9 9 -7 -1 8 -8 3 9 9
*/