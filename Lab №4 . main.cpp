#include "dynamicArray.h"
#include <iostream>

void test1()
{
    // Тест инициализации DynamicArray с указанной емкостью
    DynamicArray<int> arr(10);
    assert(arr.getCapacity() == 10);
}

void test2()
{
    // Тест добавления элементов в DynamicArray и проверки размера
    DynamicArray<int> arr;
    assert(arr.size() == 0);
    arr.add(5);
    assert(arr.size() == 1);
}

void test3()
{
    // Тест динамического изменения размера DynamicArray
    DynamicArray<int> arr(1);
    arr.add(5);
    assert(arr.getCapacity() == 1);
    arr.add(10);
    assert(arr.getCapacity() == 2);
    arr.add(20);
    assert(arr.getCapacity() == 4);
}

void test4()
{
    // Тест доступа к элементам с использованием оператора подсчета
    DynamicArray<int> arr;
    arr.add(5);
    int el = arr[0];
    assert(el == 5);
}

int main()
{
    // Запуск тестов
    test1();
    test2();
    test3();
    test4();

    // Итерация через DynamicArray с использованием foreach
    DynamicArray<int> arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);

    for (const int& element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
