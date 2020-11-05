#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>
#include <regex>
#include <map>

int calculateSize(std::ifstream&);
void controller();
void firstEx();
void additionFirstEx();
void secondEx();
void additionSecondEx();
void thirdEx();
void additionThirdEx();
void additionThirdEx2();
void additionThirdEx3();
void fourEx();
void additionFourEx();
void fifth();
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    controller();
    return 0;
}



void controller() {
    int choice;
    std::cout << "Enter the exercice\n";
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 1: {
        firstEx();
        break;
    }
    case 2: {
        additionFirstEx();
        break;
    }
    case 4: {
        secondEx();
        break;
    }
    case 5: {
        additionSecondEx();
        break;
    }
    case 6: {
        thirdEx();
        break;
    }
    case 7: {
        additionThirdEx();
        break;
    }
    case 8: {
        additionThirdEx2();
        break;
    }
    case 9: {
        additionThirdEx3();
        break;
    }
    case 10: {
        fourEx();
        break;
    }
    case 11: {
        additionFourEx();
        break;
    }
    case 12: {
        fifth();
        break;
    }
    default:
        break;
    }
}
int calculateSize(std::ifstream& someFile) {
    someFile.seekg(0, std::ios::end);
    int tmp  = someFile.tellg();
    someFile.seekg(0, std::ios::beg);
    return tmp;
}
void firstEx() {
    int length;
    char* buffer;
    char separators[]{'.','!',';'};
    int separatorsLenght = 3;
    std::ifstream ist("Shakespeare_WintersTale.txt");
    if (!ist.is_open()) {
        std::cout<< "Opens error\n";
        return;
    }

    length = calculateSize(ist);

    buffer = new char[length];
    ist.read(buffer, length);
    ist.close();
    
    for (int index = 0,start = 0, end; buffer[index] != 0; ++index) {
        if (buffer[index] == '?') {
            end = index + 1;
            while (start != end) {

                std::cout<< buffer[start];
                start++;
            }
            start++;
            std::cout<< '\n';
        }
        for (int separatorIndex = 0; separatorIndex < separatorsLenght; ++separatorIndex) {
            if (separators[separatorIndex] == buffer[index]) {
                start = index + 1;
            }
        }
        
    }
    delete[] buffer;
}
void additionFirstEx() {
    int length;
    char* buffer;
    char separators[]{ '.','?',';' };
    int separatorsLenght = 3;
    std::ifstream ist("text.txt");
    std::ofstream os("text2.txt");
   
    if (!ist.is_open() || !os.is_open()) {
        std::cout<< "Opens error\n";
        return;
    }

    length = calculateSize(ist);

    buffer = new char[length];
    ist.read(buffer, length);
    ist.close();
    
    for (int index = 0, start = 0, end; buffer[index] != 0; ++index) {
        if (buffer[index] == '!') {
            end = index + 1;
            while (start != end) {

                os << buffer[start];
                start++;
            }
            start++;
            std::cout<< '\n';
        }
        for (int separatorIndex = 0; separatorIndex < separatorsLenght; ++separatorIndex) {
            if (separators[separatorIndex] == buffer[index]) {
                start = index + 1;
            }
        }

    }
    delete[] buffer;
}
void secondEx() {
    {
        std::ofstream os("z3.dat", std::ios::binary);
        if (!os.is_open()) {
            std::cout << "Opens error\n";
            return;
        }
        const int intsArrSize = 10, charsArrSize = 5;
        double doubleNum1 = 36.14, doubleNum2 = 0.3543;
        int intsArr[intsArrSize];
        char charsArr[charsArrSize];
        for (int index = 0; index < intsArrSize; ++index)
            intsArr[index] = index;
        for (int index = 0; index < charsArrSize; ++index) {
            charsArr[index] = 70 + index;
        }
        os.write((char*)&doubleNum1, sizeof(doubleNum1));
        os.write((char*)&doubleNum2, sizeof(doubleNum2));

        for (int index = 0; index < intsArrSize; ++index)
            os.write((char*)&intsArr[index], sizeof(intsArr[index]));

        for (int index = 0; index < charsArrSize; ++index)
            os.write((char*)&charsArr[index], sizeof(charsArr[index]));

        os.close();

        {
            std::ifstream ist("z3.dat", std::ios::binary);
            if (!ist.is_open()) {
                std::cout << "Opens error\n";
            }
            ist.seekg(0, std::ios::end);
            int lenght = ist.tellg();
            std::cout << lenght << '\n';
            ist.close();

            std::ofstream os("z3.dat", std::ios::binary | std::ios::app);
            if (!os.is_open()) {
                std::cout << "Opens error\n";
            }
            os.write((char*)&lenght, sizeof(lenght));
            os.close();
        }
    }
}
void additionSecondEx() {
    std::ofstream os("z3.dat", std::ios::binary);
    std::ifstream ist("Shakespeare_WintersTale.txt", std::ios::binary );
    if (!(os.is_open())&&ist.is_open()) {
        std::cout<< "Opens error\n";
        return;
    }
    int bufSize;
    char* buf;

    ist.seekg(0,  std::ios::end);
    bufSize = ist.tellg();
    ist.seekg(0, std::ios::beg);
    buf = new char[bufSize];
    ist.read(buf, bufSize);
    
    os.write((char*)buf, sizeof(char) * bufSize);

    os.close();
}
void thirdEx() {
    const int arrSize = 10;
    int arr[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = index;
    }
    std::ofstream ofs("z3_3.txt", std::ios::binary );
    if (!ofs.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    ofs.write((char*)arr, sizeof(arr));
    
    ofs.close();

    int newNum;
    int numIndex;
    std::cout<< "Enter the number and its index\n";
    std::cin >> newNum >> numIndex;

    std::fstream fst("z3_3.txt", std::ios::binary  | std::ios::in | std::ios::out);
    if (!fst.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    fst.seekg(0,  std::ios::end);
    int lenght = fst.tellg();
    std::cout<< "The file size ist: " << lenght << "bytes\n";
    int possition = numIndex * sizeof(int);

    std::cout<< "Position of the edited element: " << possition << '\n';
    fst.seekp(possition, std::ios::beg);
    fst.write((char*)&newNum, sizeof(int));
    fst.seekg(0);
    fst.read((char*)&arr, sizeof(arr));
    for (int index = 0; index < arrSize; ++index)
    {
        std::cout<< arr[index] << " ";
    }
   
}
void additionThirdEx() {
    int arrSize;
    std::cout<< "Enter the size of array\n";
    std::cin >> arrSize;
    int* arr = new int[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = index;
    }
    std::ofstream ofs("z3_3.txt", std::ios::binary );
    if (!ofs.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    ofs.write((char*)arr, sizeof(arr) * arrSize);

    ofs.close();

    int newNum;
    int numIndex;
      std::fstream fst("z3_3.txt", std::ios::binary  | std::ios::in | std::ios::out);
      std::cout<< "Enter the number and its index\n";
      std::cin >> newNum >> numIndex;

  
    if (!fst.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    fst.seekg(0,  std::ios::end);
    int lenght = fst.tellg();
    std::cout<< "The file size ist: " << lenght << "bytes\n";
    int possition = numIndex * sizeof(int);

    std::cout<< "Position of the edited element: " << possition << '\n';
    fst.seekp(possition, std::ios::beg);
    fst.write((char*)&newNum, sizeof(int));
    fst.seekp(0);


    fst.read((char*)arr, sizeof(arr) * arrSize);
    for (int index = 0; index < arrSize; ++index)
    {
        std::cout<< arr[index] << " ";
    }

}
void additionThirdEx2() {
    int arrSize;
    std::cout<< "Enter the size of array\n";
    std::cin >> arrSize;
    int** arr = new int*[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = new int[arrSize];
    }
    for (int index = 0; index < arrSize; ++index) {
        for (int index2 = 0; index2 < arrSize; ++index2) {
            arr[index][index2] = index2 + index * arrSize;
            std::cout<< arr[index][index2] << " ";
        }
        std::cout<< "\n";
    }
    std::ofstream ofs("z3_3.txt", std::ios::binary );
    if (!ofs.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    //ofs.write((char*)arr, sizeof(arr));
    for(int index = 0; index < arrSize; ++index)
        ofs.write((char*)arr[index], sizeof(arr) * arrSize);

    ofs.close();

    int newNum;
    int numIndex;
    int numIndex2;
    std::cout<< "Enter the number and its index1 && index2\n";
    std::cin >> newNum >> numIndex >> numIndex2;

    std::fstream fst("z3_3.txt", std::ios::binary  | std::ios::in | std::ios::out);
    if (!fst.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    fst.seekg(0,  std::ios::end);
    int lenght = fst.tellg();
    std::cout<< "The file size ist: " << lenght << "bytes\n";
    int possition = (numIndex * arrSize * sizeof(int)) + numIndex2 * sizeof(int) ;

    std::cout<< "Position of the edited element: " << possition << '\n';
    fst.seekp(possition, std::ios::beg);
    fst.write((char*)&newNum, sizeof(int));
    fst.seekg(0);
    for (int index = 0; index < arrSize; ++index)
        fst.read((char*)arr[index], sizeof(arr) * arrSize);

    for (int index = 0; index < arrSize; ++index) {
        for (int index2 = 0; index2 < arrSize; ++index2) {
            std::cout<< arr[index][index2] << " ";
        }
        std::cout<< "\n";
    }

}
void additionThirdEx3() {
    const int arrSize = 10;
    int arr[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = index;
    }
    for (int index = 0; index < arrSize; ++index) {
        std::cout<< arr[index] << " ";
        
    }
    std::ofstream ofs("z3_3.txt", std::ios::binary );
    if (!ofs.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    for (int index = 0; index < arrSize; ++index)
        ofs.write((char*)&arr[index], sizeof(int));

    ofs.close();

    int newNum;
    int numIndex;
    int numIndex2;
    std::cout<< "Enter the index you want to delete\n";
    std::cin >> numIndex;

    std::fstream fst("z3_3.txt", std::ios::binary  | std::ios::in | std::ios::out);
    if (!fst.is_open()) {
        std::cout<< "An error has occurred\n";
        return;
    }
    fst.seekg(0,  std::ios::end);
    int lenght = fst.tellg();
    std::cout<< "The file size ist: " << lenght << "bytes\n";
    int possition = (numIndex * sizeof(int));
    int tmp[arrSize - 1];
    
    fst.seekp(possition, std::ios::beg);
    for (int index = numIndex + 1 ; index < arrSize; ++index) {
        fst.write((char*)&arr[index], sizeof(int));
    }
    fst.seekg(0);
    fst.read((char*)arr, sizeof(arr));

    for (int index = 0; index < arrSize-1; ++index) {
        std::cout<< arr[index] << " ";
    }
    fst.close();
}
void fourEx() {
    std::ifstream firstFile;
    std::ifstream secondFile;
    
    firstFile.open("first.dat");
    secondFile.open("second.txt");

    if (!(firstFile.is_open() && secondFile.is_open())) {
        std::cout<< "The error was occure\n";
            return;
    }
    char* firstBuf;
    char* secondBuf;
    int firstBufSize = 0;
    int secondBufSize = 0;

    firstBufSize = calculateSize(firstFile);
    secondBufSize = calculateSize(secondFile);

    if (firstBufSize != secondBufSize) {
        std::cout<< "Files have different sizes\n";
        return;
    }
    firstBuf = new char[firstBufSize];
    secondBuf = new char[secondBufSize];
   
    firstFile.read((char*)firstBuf, sizeof(int) * firstBufSize);
    secondFile.read((char*)secondBuf, sizeof(int) * secondBufSize);

    for (int index = 0; index < firstBufSize && index < secondBufSize; ++index)
    {
        if (firstBuf[index] != secondBuf[index]) {
            std::cout<< "Files have different content\n";
            return;
        }
    }
    std::cout<< "Files are absolutely identical\n";
}
void additionFourEx() {
    std::ifstream firstFile;
    std::ifstream secondFile;

    firstFile.open("first.txt");
    secondFile.open("second.txt");

    if (!(firstFile.is_open() && secondFile.is_open())) {
        std::cout<< "The error was occure\n";
        return;
    }
    char* firstBuf;
    char* secondBuf;
    int firstBufSize = 0;
    int secondBufSize = 0;
    bool isEquals = true;

    firstBufSize = calculateSize(firstFile);
    secondBufSize = calculateSize(secondFile);

    if (firstBufSize != secondBufSize) {
        std::cout<< "Files have different sizes and content\n";
        isEquals = false;
    }
    firstBuf = new char[firstBufSize];
    secondBuf = new char[secondBufSize];

    firstFile.read((char*)firstBuf, sizeof(int) * firstBufSize);
    secondFile.read((char*)secondBuf, sizeof(int) * secondBufSize);
    if (isEquals) {
        for (int index = 0; index < firstBufSize && index < secondBufSize; ++index)
        {
            if (firstBuf[index] != secondBuf[index]) {
                std::cout<< "Files have different content\n";
                isEquals = false;

            }
        }
        if (isEquals) 
            std::cout<< "Files are absolutely identical\n";
    }
    bool isContainFirst, isContainSecond;
    for (int index = 0, index2, index3; index < firstBufSize && index < secondBufSize; ++index) {
        isContainFirst = true, isContainSecond = true;
        for (index2 = 0, index3 = index; index2 < firstBufSize && index2 < secondBufSize; ++index2, ++index3) {
            if (isContainFirst && firstBuf[index3] != secondBuf[index2]) {
                isContainFirst = false;
                if (!isContainFirst && !isContainSecond) {
                    break;
                }
            }
            if (isContainSecond && secondBuf[index3] != firstBuf[index2]) {
                isContainSecond = false;
                if (!isContainFirst && !isContainSecond) {
                    break;
                }
            }
            
        }
        if (isContainFirst|| isContainSecond) {
            std::cout<< "One file ist part of another one\n";
            break;
        }
    }
}
void fifth() {
    std::ifstream ist("dates.txt", std::ios::binary);
    if (!(ist.is_open())) {
        std::cout << "The error has occure\n";
        return;
    }
    std::tr1::regex rx("\\d{2}.{1}\\d{2}.{1}\\d{4}");

    char* buf;

    int bufSize;

    std::map<std::string, int> data;
    std::string key = "";

    bufSize = calculateSize(ist);

    buf = new char[bufSize];

    ist.read(buf, bufSize);
    ist.close();

    buf[bufSize] = '\0';
    int maxSize = 0;
    for (int index = 0, start = index; index <= bufSize; ++index) {
        if ((buf[index] == ' ' || buf[index] == '\r' || buf[index] == '\0') && key != "") {
            if (index - start > maxSize) {
                maxSize = index - start - 1;
            }
            start = index;
            ++data[key];
            key = "";

            continue;
        }
        if (buf[index] != '\n')
            key += buf[index];
    }
    std::map<string, int>::iterator it = data.begin();
    for (; it != data.end(); ++it) {
        cout << it->first << "\t->" << it->second << "\n";
    }

    cout << "Words with the biggest size\n\r";
    for (int index = 0, start = index; index <= bufSize; ++index) {
        if (buf[index] == ' ' || buf[index] == '\n' || buf[index] == '\r' || buf[index] == '\0') {
            if (index - start - 1 == maxSize) {
                cout << key << endl;
            }
            start = index;
            key = "";
            continue;
        }
        key += buf[index];
    }
}
