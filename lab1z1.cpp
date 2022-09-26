// lab1z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <thread>
#include <cmath>
#include <vector>
#include <numeric> 
#include <iomanip>
#include <cstdio>

#include <iostream>
#include <ctime> // в ней функция time
#include <random>

using namespace std;

// с 4 потоками ~  994142228124135936
// с 1 потоком ~   994142228124135936
static const long long ELEMENTS = 10000000000;  // количество элементов
static const int THREADS_NUMBER = 1;
unsigned long long result = 0;

/*
int row_sum(int n)
{
    int sum = 0;
    for (int i = 0; i <= ELEMENTS; i++)
        sum += i;
    return sum;
}
*/

void row_sum_threading(const int thread_number, unsigned long long n)
{
    //const int n_elements = (MATRIX_SIZE * MATRIX_SIZE);
    const long long n_operations = n / THREADS_NUMBER;
    const int rest_operations = n % THREADS_NUMBER;

    unsigned long long start_op, end_op;

    if (thread_number == 0) {
        // First thread does more job
        start_op = n_operations * thread_number;
        end_op = (n_operations * (thread_number + 1)) + rest_operations;
    }
    else {
        start_op = n_operations * thread_number + rest_operations+1;
        end_op = (n_operations * (thread_number + 1)) + rest_operations;
    }
    long long r = 0;
    for (unsigned long long op = start_op; op <= end_op; ++op) {
        
        
            
            r += op;
        
        
    }
    result += r;
    cout << "result: " << r << "\t";
}

void multithreading_execution(int r, int els) {
    double start = clock();
    std::thread threads[THREADS_NUMBER];

    for (int i = 0; i < THREADS_NUMBER; ++i) {
        //std::cout << "Starting thread " << i << std::endl;
        threads[i] = std::thread(row_sum_threading, i, std::ref(els));
    }

    //std::cout << "Calculating...." << std::endl;

    for (int i = 0; i < THREADS_NUMBER; ++i) {
        //std::cout << "Joining thread " << i << std::endl;
        threads[i].join();
    }
    cout << "res: " << result << "\t";
    printf("\nResult time: %.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
}



int main()
{
    cout << "THREADS_NUMBER = " << THREADS_NUMBER << endl;
    cout << "ELEMENTS = " << ELEMENTS << endl;  
    printf("\n");
   // int resnum = res();
    multithreading_execution(NULL, ELEMENTS);

}
