
//1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его 
//   размер. Вызвать эту функцию из main.
// 
//2. Задать целочисленный массив, состоящий из элементов 0 и 1. например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
//   написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. выводить на экран массив до изменений
//   и после.
// 
//3. Задать пустой целочисленный массив размером 8. написать функцию, которая с помощью цикла заполнит его
//   значениями 1 4 7 10 13 16 19 22. вывести массив на экран.
// 
//4. * написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, 
//   или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.
// 
//5. ** написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть
//   истину если в массиве есть место,в котором сумма левой и правой части массива равны. примеры: 
//   checkbalance([1, 1, 1, || 2, 1]) → true, checkbalance ([2, 1, 1, 2, 1]) → false, checkbalance
//   ([10, || 1, 2, 3, 4]) → true. абстрактная граница показана символами ||, эти символы в массив не входят.

void arrayPrint(int *inputArray, int arraySize);
void arrayPrint(double* inputArray, int arraySize);
void arrayChange(int* arrPtr, int n);
void arrayInit(int* inputArray, int size);
void moveRight(int* inputArray, int size);
void moveLeft(int* inputArray, int size);
void moveArray(int* inputArray, int size, int shift);
bool checkArrayBalance(int* inputArray, int size);


#include <iostream>

int main()
{
    // Task 1
    const int doubleArraySize = 5;
    double doubleArray[doubleArraySize] = { 5.1, 6.2, 8.3, 1.9, 2.4 };

    std::cout << "Task 1:\n";
    arrayPrint(doubleArray, doubleArraySize);
    std::cout << "\n";

    
    // Task 2
    const int arraySize1 = 10;
    int arr[arraySize1] = { 1, 0, 0, 1, 0, 1, 1, 1, 0, 0 };

    const int arraySize2 = 12;
    int arr2[arraySize2] = { 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1 };

    std::cout << "Task 2: \n";
    arrayPrint(arr2, arraySize2);
    arrayChange(arr2, arraySize2);
    arrayPrint(arr2, arraySize2);
   
    //Task 3
    int intArray[8];

    std::cout << "\nTask 3:\n";
    arrayInit(intArray, 8);
    arrayPrint(intArray, 8);

    //Task 4
    const int arrSize = 8;
    int arrayMove[arrSize] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    std::cout << "\nTask 4:\n";
    arrayPrint(arrayMove, arrSize);
    moveArray(arrayMove, arrSize, -2);
    arrayPrint(arrayMove, arrSize);
    moveArray(arrayMove, arrSize, 4);
    arrayPrint(arrayMove, arrSize);

    //Task 5
    const int balanceArraySize = 5;
    int balanceArray[balanceArraySize] = { 4, 2, 1, 1, 6 };

    std::cout << "\nTask 5:\n";
    if (checkArrayBalance(balanceArray, balanceArraySize)) std::cout << "True\n";
    else std::cout << "False\n";


}

void arrayPrint(int *inputArray, int arraySize) 
{
    
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << inputArray[i] << "  ";
    }
    std::cout << "\n";
}

void arrayPrint(double *inputArray, int arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << inputArray[i] << "  ";
    }
    std::cout << "\n";
}




void arrayChange(int *inputArray,int arraySize)
{
    
    for (int i=0; i < arraySize; i++)
    {
        if (inputArray[i] == 0) inputArray[i] = 1;
        else if (inputArray[i] == 1) inputArray[i] = 0;
        else
        {
            std::cout << "Incorrect input, some elements could not be changed.\n";
        }
        
    }
}




void arrayInit(int* inputArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        inputArray[i] = 1 + i * 3;
    }
}




void moveArray(int* inputArray, int size, int shift)
{
    if (shift > 0)
    {
        for (int i = 0; i < shift; i++)
        {
            moveRight(inputArray, size);
        }
    }
    else if (shift < 0)
    {
        shift = abs(shift);
        for (int i = 0; i < shift; i++)
        {
            moveLeft(inputArray, size);
        }
    }
}

void moveRight(int* inputArray, int size)
{
    int memory = inputArray[size - 1];

    for (int i = size - 1; i > 0; i--)
    {
        inputArray[i] = inputArray[i - 1];
    }

    inputArray[0] = memory;
    
}

void moveLeft(int* inputArray, int size)
{
    int memory = inputArray[0];

    for (int i = 0; i < size; i++)
    {
        inputArray[i] = inputArray[i + 1];
    }

    inputArray[size - 1] = memory;
}





bool checkArrayBalance(int* inputArray, int size)
{
    int* ptr = nullptr;
    int leftSum, rightSum;
    for (int i = 0; i < size; i++)
    {
        leftSum = 0;
        rightSum = 0;
        ptr = &inputArray[i];

        for (int j = 0; j <= i; j++)
        {
            leftSum += inputArray[j];
        }

        for (int k = i + 1; k < size; k++)
        {
            rightSum += inputArray[k];
        }

        if (leftSum == rightSum) return true;
    }

    return false;
}