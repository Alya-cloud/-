#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int* arr, int size) {            // Заполнение массива случайными числами от 1 до 50
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50 + 1;      // +1, чтобы было до 50 включительно
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void findPairs(int* arr, int size, int targetSum) {             // Поиск и вывод пар элементов с заданной суммой
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == targetSum) {
                std::cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << targetSum << std::endl;
            }
        }
    }
}

int main() {
    srand(time(nullptr));                        // Инициализирует генератор случайных чисел начальным значением

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* dynamicArray = new int[size];             // Выделяет память под динамический массив
    fillArray(dynamicArray, size);

    std::cout << "Generated array: ";
    printArray(dynamicArray, size);

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    findPairs(dynamicArray, size, targetSum);   // Передает указатель на динамический массив, кол-во элементов и введенную пользователем сумму
    delete[] dynamicArray;     //  Освобождает память           

    return 0;
}