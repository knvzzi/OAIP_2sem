#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// Функция для генерации случайных чисел в заданном диапазоне
int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

// Функция для заполнения массива случайными числами
void fillArrayWithRandomNumbers(vector<int>& arr, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        int num = getRandomNumber(min, max);
        arr.push_back(num);
    }
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Функция для сортировки массива методом пузырька
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция для сортировки массива методом выбора
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    // Ввод размера массивов
    int size;
    cout << "Введите размер массивов: ";
    cin >> size;

    // Создание и заполнение массивов А и В случайными числами
    vector<int> arrA, arrB;
    fillArrayWithRandomNumbers(arrA, size, 0, 100);
    fillArrayWithRandomNumbers(arrB, size, 0, 100);

    // Формирование массива C, содержащего элементы массива А с четным значением и элементы массива В с нечетным значением
    vector<int> arrC;
    for (int num : arrA) {
        if (num % 2 == 0) {
            arrC.push_back(num);
        }
    }
    for (int num : arrB) {
        if (num % 2 != 0) {
            arrC.push_back(num);
        }
    }

    // Вывод исходных массивов
    cout << "Массив A: ";
    printArray(arrA);
    cout << "Массив B: ";
    printArray(arrB);

    // Сортировка массива C методом пузырька
    auto startBubbleSort = high_resolution_clock::now();
    bubbleSort(arrC);
    auto stopBubbleSort = high_resolution_clock::now();
    auto durationBubbleSort = duration_cast<microseconds>(stopBubbleSort - startBubbleSort);

    // Вывод отсортированного массива C
    cout << "Массив C (отсортированный пузырьком): ";
    printArray(arrC);

    // Сортировка массива C методом выбора
    auto startSelectionSort = high_resolution_clock::now();
    selectionSort(arrC);
    auto stopSelectionSort = high_resolution_clock::now();
    auto durationSelectionSort = duration_cast<microseconds>(stopSelectionSort - startSelectionSort);

    // Вывод отсортированного массива C
    cout << "Массив C (отсортированный выбором): ";
    printArray(arrC);

    // Вывод времени выполнения алгоритмов
    cout << "Время выполнения сортировки пузырьком: " << durationBubbleSort.count() << " микросекунд" << endl;
    cout << "Время выполнения сортировки выбором: " << durationSelectionSort.count() << " микросекунд" << endl;

    return 0;
}

