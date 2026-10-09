#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

int myAbs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

long myAbsLong(long x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// задачи - методы

int sumLastNums(int x) {
    x = myAbs(x);
    int lastSum = x % 10;
    int lastLastSum = (x / 10) % 10;
    return lastSum + lastLastSum;
}

bool isPositive(int x) {
    return x > 0;
}

bool isUpperCase(char x) {
    return (x >= 'A' && x <= 'Z');
}

bool isDivisor(int x, int y) {
    if (x == 0 || y == 0) return false;
    return (x % y == 0) || (y % x == 0);
}

int lastNumSum(int x, int y) {
    return (x % 10) + (y % 10);
}

// задачи 2 - условия

double safeDiv(int x, int y) {
    if (y == 0) {
        return 0.0;
    }
    return (double)x / y;
}

std::string makeDecision(int x, int y) {
    if (x > y) {
        return std::to_string(x) + " > " + std::to_string(y);
    }
    else if (x < y) {
        return std::to_string(x) + " < " + std::to_string(y);
    }
    else {
        return std::to_string(x) + " == " + std::to_string(y);
    }
}

bool sum3(int x, int y, int z) {
    if (x + y == z) {
        return true;
    }
    else if (x + z == y) {
        return true;
    }
    else if (z + y == x) {
        return true;
    }
    else {
        return false;
    }
}

std::string age(int x) {
    if (x % 100 >= 11 && x % 100 <= 14) {
        return std::to_string(x) + " лет";
    }
    else if (x % 10 == 1) {
        return std::to_string(x) + " год";
    }
    else if (x % 10 == 2 || x % 10 == 3 || x % 10 == 4) {
        return std::to_string(x) + " года";
    }
    else {
        return std::to_string(x) + " лет";
    }
}

void printDays(int x) {
    switch (x) {
        case 1: std::cout << "Понедельник ";
        case 2: std::cout << "Вторник ";
        case 3: std::cout << "Среда ";
        case 4: std::cout << "Четверг ";
        case 5: std::cout << "Пятница ";
        case 6: std::cout << "Суббота ";
        case 7: std::cout << "Воскресенье ";
            break;
        default: std::cout << "Это не день недели ";
    }
}

// задачи 3 - циклы

std::string reverseListNums(int x) {
    std::string result = "";
    for (int i = x; i >= 0; i--) {
        result += std::to_string(i);
        if (i > 0) {
            result += " ";
        }
    }
    return result;
}

int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}

bool equalNum(long x) {
    x = myAbsLong((long)x);
    int lastDigit = x % 10;
    x = x / 10;
    while (x > 0) {
        int currentDigit = x % 10;
        if (currentDigit != lastDigit) {
            return false;
        }
        x = x / 10;
    }
    return true;
}

void leftTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void guessGame() {
    std::srand(std::time(0));
    int secret = std::rand() % 10;
    int attempt = 0;
    int userNum = -1;

    do {
        std::cout << "Введите число от 0 до 9: ";
        if (!(std::cin >> userNum) || userNum < 0 || userNum > 9) {
            std::cout << "Нужно ввести число от 0 до 9!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(10000, '\n');
        attempt++;

        if (userNum == secret) {
            std::cout << "Вы угадали! Число " << secret << " было отгадано за " << attempt << " попыток\n";
        } else {
            std::cout << "Вы не угадали, ";
        }
    } while (userNum != secret);
}

// задачи 4 - массивы

int findLast(int arr[], int size, int x) {
    int lastIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

int* add(int arr[], int size, int x, int pos) {
    if (pos < 0) {
        pos = 0;
    }
    else if (pos > size) {
        pos = size;
    }
    int* result = new int[size + 1];
    for (int i = 0; i < pos; i++) {
        result[i] = arr[i];
    }
    result[pos] = x;
    for (int i = pos; i < size; i++) {
        result[i + 1] = arr[i];
    }
    return result;
}

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int* concat(int arr1[], int size1, int arr2[], int size2) {
    int* result = new int[size1 + size2];
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
    return result;
}

int* deleteNegative(int arr[], int size, int& resultSize) {
    int* result = new int[size];
    resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            result[resultSize] = arr[i];
            resultSize++;
        }
    }
    return result;
}

// ввод данных с клавиатуры под массивы
int inputArray(int arr[], int maxSize) {
    int n;
    std::cout << "Сколько элементов? (от 1 до " << maxSize << "): ";
    if (!(std::cin >> n) || n < 1 || n > maxSize) {
        std::cout << "Нужно ввести число от 1 до " << maxSize << "!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -1;
    }
    std::cin.ignore(10000, '\n');

    for (int i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = ";
        if (!(std::cin >> arr[i])) {
            std::cout << "Нужно ввести число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return -1;
        }
    }
    std::cin.ignore(10000, '\n');
    return n;
}


int main() {
    int n = 0;
    std::cout << std::boolalpha;
    do {
        // ===== МЕНЮ =====
        std::cout << "\n";
        std::cout << "                     МЕНЮ ЗАДАЧ                       \n";
        std::cout << "  Задачи 1. Методы:\n";
        std::cout << "   1  - Сумма последних двух цифр числа\n";
        std::cout << "   2  - Проверка числа на положительность\n";
        std::cout << "   3  - Проверка символа на заглавную букву\n";
        std::cout << "   4  - Проверка, делятся ли числа нацело\n";
        std::cout << "   5  - Многократный вызов (сложение 5 чисел)\n";
        std::cout << "  Задачи 2. Условия:\n";
        std::cout << "   6  - Безопасное деление (защита от деления на 0)\n";
        std::cout << "   7  - Строка сравнения (>, <, ==)\n";
        std::cout << "   8  - Тройная сумма (сумма двух = третьему)\n";
        std::cout << "   9  - Возраст (год/года/лет)\n";
        std::cout << "  10  - Вывод дней недели с заданного дня\n";
        std::cout << "  Задачи 3. Циклы:\n";
        std::cout << "  11  - Числа наоборот (от x до 0)\n";
        std::cout << "  12  - Возведение числа в степень\n";
        std::cout << "  13  - Проверка, все ли цифры одинаковы\n";
        std::cout << "  14  - Левый треугольник из звёздочек\n";
        std::cout << "  15  - Игра \"Угадайка\" (число от 0 до 9)\n";
        std::cout << "  Задачи 4. Массивы:\n";
        std::cout << "  16  - Поиск последнего вхождения числа в массиве\n";
        std::cout << "  17  - Добавление элемента в массив\n";
        std::cout << "  18  - Реверс массива (переворот на месте)\n";
        std::cout << "  19  - Объединение двух массивов\n";
        std::cout << "  20  - Удаление отрицательных чисел из массива\n";
        std::cout << "------------------------------------------------------\n";
        std::cout << "   0  - Выход из программы\n";
        std::cout << "======================================================\n";

        std::cout << "Введите номер операции: ";
        if (!(std::cin >> n)) {
            std::cout << "Ошибка! Нужно ввести число.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            n = -1;
            continue;
        }
        std::cin.ignore(10000, '\n');

        switch (n) {
            case 1: {
                int number = 0;
                std::cout << "Введите число для сложения последних двух цифр: ";
                if (std::cin >> number) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << sumLastNums(number) << "\n";
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 2: {
                int number = 0;
                std::cout << "Введите число для проверки на положительность: ";
                if (std::cin >> number) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << isPositive(number) << "\n";
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 3: {
                char character;
                std::cout << "Введите букву для проверки на капс: ";
                std::cin >> character;
                if (std::cin.peek() == '\n') {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << isUpperCase(character) << "\n";
                } else {
                    std::cout << "Нужно ввести один символ!" << std::endl;
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 4: {
                int x = 0, y = 0;
                std::cout << "Введите числа для проверки делителей через пробел: ";
                if ((std::cin >> x) && (std::cin >> y)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << isDivisor(x, y) << "\n";
                } else {
                    std::cout << "Нужно ввести числа!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 5: {
                int x = 0, y = 0, w = 0, q = 0, e = 0;
                std::cout << "Введите 5 чисел для сложения через пробел: ";
                if ((std::cin >> x) && (std::cin >> y) && (std::cin >> w) && (std::cin >> q) && (std::cin >> e)) {
                    std::cin.ignore(10000, '\n');
                    int res = lastNumSum(x, y);
                    res = lastNumSum(res, w);
                    res = lastNumSum(res, q);
                    res = lastNumSum(res, e);
                    std::cout << "Результат: " << res << "\n";
                } else {
                    std::cout << "Нужно ввести числа!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 6: {
                int x = 0, y = 0;
                std::cout << "Введите 2 числа через пробел: ";
                if ((std::cin >> x) && (std::cin >> y)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << safeDiv(x, y) << "\n";
                } else {
                    std::cout << "Нужно ввести числа!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 7: {
                int x = 0, y = 0;
                std::cout << "Введите 2 числа для сравнения: ";
                if ((std::cin >> x) && (std::cin >> y)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << makeDecision(x, y) << "\n";
                } else {
                    std::cout << "Нужно ввести числа!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 8: {
                int x = 0, y = 0, z = 0;
                std::cout << "Введите 3 числа через пробел: ";
                if ((std::cin >> x) && (std::cin >> y) && (std::cin >> z)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << sum3(x, y, z) << "\n";
                } else {
                    std::cout << "Нужно ввести числа!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 9: {
                int x = 0;
                std::cout << "Введите возраст: ";
                if (std::cin >> x) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << age(x) << "\n";
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 10: {
                int x = 0;
                std::cout << "Введите день недели (1-7): ";
                if ((std::cin >> x) && (x >= 1) && (x <= 7)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: \n";
                    printDays(x);
                    std::cout << "\n";
                } else {
                    std::cout << "Нужно ввести число от 1 до 7!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 11: {
                int x = 0;
                std::cout << "Введите число: ";
                if ((std::cin >> x) && (x >= 0)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << reverseListNums(x) << "\n";
                } else {
                    std::cout << "Нужно ввести неотрицательное число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 12: {
                int x = 0, y = 0;
                std::cout << "Введите 2 числа, где 1 - само число, 2 - степень: ";
                if ((std::cin >> x) && (std::cin >> y) && (y >= 0)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << pow(x, y) << "\n";
                } else {
                    std::cout << "Нужно ввести числа (степень >= 0)!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 13: {
                long x = 0;
                std::cout << "Введите число: ";
                if (std::cin >> x) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: " << equalNum(x) << "\n";
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 14: {
                int x = 0;
                std::cout << "Введите число для вывода треугольника: ";
                if ((std::cin >> x) && (x > 0)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Результат: \n";
                    leftTriangle(x);
                } else {
                    std::cout << "Нужно ввести положительное число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 15: {
                guessGame();
                break;
            }
            case 16: {
                int arr[100];
                int size = inputArray(arr, 100);
                if (size == -1) break;

                int x = 0;
                std::cout << "Введите x: ";
                if (std::cin >> x) {
                    std::cin.ignore(10000, '\n');
                    std::cout << "Последнее вхождение: " << findLast(arr, size, x) << "\n";
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 17: {
                int arr[100];
                int size = inputArray(arr, 100);
                if (size == -1) break;

                int x = 0, pos = 0;
                std::cout << "Введите число для вставки: ";
                if (!(std::cin >> x)) {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                std::cin.ignore(10000, '\n');

                std::cout << "Введите позицию (0-" << size << "): ";
                if (!(std::cin >> pos) || pos < 0 || pos > size) {
                    std::cout << "Позиция должна быть от 0 до " << size << "!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                std::cin.ignore(10000, '\n');

                int* res = add(arr, size, x, pos);
                std::cout << "Результат: \n";
                for (int i = 0; i < size + 1; i++) std::cout << res[i] << " ";
                std::cout << "\n";
                delete[] res;
                break;
            }
            case 18: {
                int arr[100];
                int size = inputArray(arr, 100);
                if (size == -1) break;

                reverse(arr, size);
                std::cout << "Перевернутый: ";
                for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
                std::cout << "\n";
                break;
            }
            case 19: {
                int arr1[100], arr2[100];
                std::cout << "Первый массив: \n";
                int size1 = inputArray(arr1, 100);
                if (size1 == -1) break;

                std::cout << "Второй массив: \n";
                int size2 = inputArray(arr2, 100);
                if (size2 == -1) break;

                int* res = concat(arr1, size1, arr2, size2);
                std::cout << "Результат: \n";
                for (int i = 0; i < size1 + size2; i++) {
                    std::cout << res[i] << " ";
                }
                std::cout << "\n";
                delete[] res;
                break;
            }
            case 20: {
                int arr[100];
                int size = inputArray(arr, 100);
                if (size == -1) {
                    break;
                }

                int resultSize = 0;
                int* res = deleteNegative(arr, size, resultSize);
                std::cout << "Результат: \n";
                for (int i = 0; i < resultSize; i++) {
                    std::cout << res[i] << " ";
                }
                std::cout << "\n";
                delete[] res;
                break;
            }
            case 0: {
                std::cout << "Выход из программы\n";
                break;
            }
            default: {
                std::cout << "Такой операции нет. Введите число от 0 до 20.\n";
                break;
            }
        }
    } while (n != 0);
    return 0;
}
