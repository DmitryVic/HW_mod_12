#include <iostream>
#include <cassert>
#include <string>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN  // Уменьшает количество включаемых заголовков Windows
#include <windows.h>        // Используется для настройки консоли
#endif
using namespace std;


bool IsKPeriodic(const std::string& str, int K){
    unsigned int strSize = str.size();
    if ( K <= 0 || strSize == 0 || strSize%K != 0 || K > strSize)     // строка не кратна K - false
        return false;                                               
    if (K == strSize)                                               // если кратность равна длине строки, то по логике она кратна
        return true;                                                // если нет, то поменять K => strSize в условии выше
    
    string box;
    for (size_t i = 0; i < K; i++)
    {
        box += str[i];                                              // box - первая кратная часть, для последующей проверки остальных частей
    }
    for (size_t i = K; i < strSize; i++)                            // сравнение начинаю с К, так как все сравниваю с box
    {                                                               // скорость O(n)
        if (str[i] != box[i%K])
            return false;
    }
    return true;
}


int main(int argc, char const *argv[]) {
    
    // Универсальная настройка локали
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Настройки для Windows
    // исправляет не коректную запись в string русских символов в консоле
    // распространяет локализацию на весь проект 
    #ifdef _WIN32
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
    #endif
    
    // Для Linux/Mac
    // был ли определен SET_GLOBAL_LOCALE_LINUX ? да (в cmake) или нет (в cmake)
    #ifdef SET_GLOBAL_LOCALE_LINUX
        std::locale::global(std::locale("ru_RU.UTF-8"));
    #endif
    
    int i = 0;
    //1
    (IsKPeriodic("ababab", 2)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 2
    (IsKPeriodic("abcabcabc", 3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 3 (любая строка кратна 1)
    (IsKPeriodic("aaaaaa", 1)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 4
    (!IsKPeriodic("abcd", 2)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 5 длина 7 не делится на 3 
    (!IsKPeriodic("xyzxyzx", 3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 6 (по условию K>0, а строка пустая — false)
    (!IsKPeriodic("", 5)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 7
    (!IsKPeriodic("ab", 3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 8
    (IsKPeriodic("abaaba", 3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 9
    (!IsKPeriodic("abaabb", 3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    //10 Размер строки = кратности, по логике это является кратным 
    (IsKPeriodic("aba", 3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 11
    (!IsKPeriodic("aa", 4)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 12 K = 0
    (!IsKPeriodic("aba", 0)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 13 K = -3
    (!IsKPeriodic("aaba", -3)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    // 14 K = -10
    (!IsKPeriodic("aaaaa", -10)) ? cout << "Тест №" << ++i << " \x1B[32mпройден\033[0m\t\t" << endl : cout << "Тест №" << ++i << " \x1B[31mпровален\033[0m\t\t" << endl;
    return 0;
}