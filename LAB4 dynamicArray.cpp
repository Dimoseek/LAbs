#include "dynamicArray.h"
#include <cassert>
#include <algorithm>

DynamicArray createDynamicArrayWithCapacity(size_t capacity)
{
    DynamicArray<int> arr(capacity);
    return arr;
}

DynamicArray createDynamicArray()
{
    return createDynamicArrayWithCapacity(4); // По умолчанию вместимость равна 4
}

void addElementToArray(DynamicArray<int>& arr, int element)
{
    if (arr.size() == arr.getCapacity())
    {
        size_t newCapacity = (arr.getCapacity() == 0) ? 1 : arr.getCapacity() * 2;
        DynamicArray<int> newArr(newCapacity);

        std::copy(arr.begin(), arr.end(), newArr.begin());
        arr = std::move(newArr);
    }
    arr.add(element);
}

int getElementAtIndex(const DynamicArray<int>& arr, size_t index)
{
    assert(index < arr.size());
    return arr[index];
}

std::span<int> getCurrentSpan(DynamicArray<int>& arr)
{
    return std::span<int>(arr.begin(), arr.size());
}

void freeDynamicArray(DynamicArray<int>& arr)
{
    // Освобождение ресурсов осуществляется автоматически при выходе из области видимости объекта DynamicArray
    // Нет необходимости явно удалять и обнулять указатели
}
