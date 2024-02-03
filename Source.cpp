#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int* arr, int size) {            // ���������� ������� ���������� ������� �� 1 �� 50
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50 + 1;      // +1, ����� ���� �� 50 ������������
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void findPairs(int* arr, int size, int targetSum) {             // ����� � ����� ��� ��������� � �������� ������
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == targetSum) {
                std::cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << targetSum << std::endl;
            }
        }
    }
}

int main() {
    srand(time(nullptr));                        // �������������� ��������� ��������� ����� ��������� ���������

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* dynamicArray = new int[size];             // �������� ������ ��� ������������ ������
    fillArray(dynamicArray, size);

    std::cout << "Generated array: ";
    printArray(dynamicArray, size);

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    findPairs(dynamicArray, size, targetSum);   // �������� ��������� �� ������������ ������, ���-�� ��������� � ��������� ������������� �����
    delete[] dynamicArray;     //  ����������� ������           

    return 0;
}