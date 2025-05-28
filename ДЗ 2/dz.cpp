#include <iostream>
#include <fstream>
#include "CVects.h"
#include "CAngls.h"

int main() {
        
    setlocale(LC_ALL, "RUS");
    srand(static_cast<unsigned>(time(nullptr)));
    
    std::ifstream vectsFile("inputV.txt");
    if (!vectsFile) {
        std::cerr << "Ошибка файла для векторов" << std::endl;
        return 1;
    }

    CVects v1(3);
    v1.readFromFile(vectsFile);
    std::cout << "Вектора v1 (из файла):\n" << v1 << std::endl;
    vectsFile.close();

    ++v1;
    std::cout << "Увеличение кол-ва векторов: \n" << v1 << std::endl;

    v1--;
    std::cout << "Уменьшение кол-ва векторов: \n" << v1 << std::endl;

    std::ifstream anglsFile("inputA.txt");
    if (!anglsFile) {
        std::cerr << "Ошибка файла для углов" << std::endl;
        return 1;
    }

     CAngls a1(3);
     a1.readFromFile(anglsFile);
     std::cout << "Углы v1 (из файла):\n" << a1 << std::endl;
     anglsFile.close();

     CVects vmoved = v1 + a1;
     std::cout << "Вращение векторов (CVects + CAngls): \n" << vmoved << std::endl;

     CVects vmoved1 = a1 + v1;
     std::cout << "Вращение векторов (CAngls + CVects): \n" << vmoved1 << std::endl;

     return 0;
}
    
    
    
    /*
    // Тестирование CVects
    CVects v1(3);
    v1.generateRandom();
    std::cout << "Вектора v1:\n" << v1 << std::endl;

    CVects v2 = v1;
    std::cout << "Вектора v2 (копия v1):\n" << v2 << std::endl;

    ++v1;
    std::cout << "После ++v1:\n" << v1 << std::endl;

    v1--;
    std::cout << "После v1--:\n" << v1 << std::endl;

    // Тестирование CAngls
    CAngls a1(3);
    a1.generateRandom();
    std::cout << "Углы от v1:\n" << a1 << std::endl;

    CAngls a2 = a1;
    std::cout << "Углы v2 (копия углов v1):\n" << a2 << std::endl;

    ++a1;
    std::cout << "После ++a1:\n" << a1 << std::endl;

    a1--;
    std::cout << "После a1--:\n" << a1 << std::endl;

    // Тестирование операторов
    CVects v3 = v1 + a1;
    std::cout << "v1 + a1:\n" << v3 << std::endl;

    CVects v4 = a1 + v1;
    std::cout << "a1 + v1:\n" << v4 << std::endl;

    CAngls a3 = v1 - v2;
    std::cout << "v1 - v2:\n" << a3 << std::endl;

    return 0;
}
*/