#include <iostream>
#include <fstream>
#include "CVects.h"
#include "CAngls.h"

int main() {
        
    setlocale(LC_ALL, "RUS");
    srand(static_cast<unsigned>(time(nullptr)));
    
    std::ifstream vectsFile("inputV.txt");
    if (!vectsFile) {
        std::cerr << "������ ����� ��� ��������" << std::endl;
        return 1;
    }

    CVects v1(3);
    v1.readFromFile(vectsFile);
    std::cout << "������� v1 (�� �����):\n" << v1 << std::endl;
    vectsFile.close();

    ++v1;
    std::cout << "���������� ���-�� ��������: \n" << v1 << std::endl;

    v1--;
    std::cout << "���������� ���-�� ��������: \n" << v1 << std::endl;

    std::ifstream anglsFile("inputA.txt");
    if (!anglsFile) {
        std::cerr << "������ ����� ��� �����" << std::endl;
        return 1;
    }

     CAngls a1(3);
     a1.readFromFile(anglsFile);
     std::cout << "���� v1 (�� �����):\n" << a1 << std::endl;
     anglsFile.close();

     CVects vmoved = v1 + a1;
     std::cout << "�������� �������� (CVects + CAngls): \n" << vmoved << std::endl;

     CVects vmoved1 = a1 + v1;
     std::cout << "�������� �������� (CAngls + CVects): \n" << vmoved1 << std::endl;

     return 0;
}
    
    
    
    /*
    // ������������ CVects
    CVects v1(3);
    v1.generateRandom();
    std::cout << "������� v1:\n" << v1 << std::endl;

    CVects v2 = v1;
    std::cout << "������� v2 (����� v1):\n" << v2 << std::endl;

    ++v1;
    std::cout << "����� ++v1:\n" << v1 << std::endl;

    v1--;
    std::cout << "����� v1--:\n" << v1 << std::endl;

    // ������������ CAngls
    CAngls a1(3);
    a1.generateRandom();
    std::cout << "���� �� v1:\n" << a1 << std::endl;

    CAngls a2 = a1;
    std::cout << "���� v2 (����� ����� v1):\n" << a2 << std::endl;

    ++a1;
    std::cout << "����� ++a1:\n" << a1 << std::endl;

    a1--;
    std::cout << "����� a1--:\n" << a1 << std::endl;

    // ������������ ����������
    CVects v3 = v1 + a1;
    std::cout << "v1 + a1:\n" << v3 << std::endl;

    CVects v4 = a1 + v1;
    std::cout << "a1 + v1:\n" << v4 << std::endl;

    CAngls a3 = v1 - v2;
    std::cout << "v1 - v2:\n" << a3 << std::endl;

    return 0;
}
*/