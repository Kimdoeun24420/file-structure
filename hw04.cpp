#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class IOBuffer {
public:
    virtual int Pack(fstream& file) const = 0;
    virtual int Unpack(fstream& file) = 0;
};

class Student : public IOBuffer {
private:
    int id;
    string name;
    string address;
    string firstCourseDate;
    int creditHours;

public:
    // Constructor, getters, setters, and other methods

    // Pack the object into the file
int Pack(fstream& file) const {
    int packedSize = 0;
    packedSize += file.write(reinterpret_cast<const char*>(&id), sizeof(id)).rdstate();
    packedSize += file.write(name.c_str(), sizeof(char) * name.size()).rdstate();
    packedSize += file.write(address.c_str(), sizeof(char) * address.size()).rdstate();
    packedSize += file.write(firstCourseDate.c_str(), sizeof(char) * firstCourseDate.size()).rdstate();
    packedSize += file.write(reinterpret_cast<const char*>(&creditHours), sizeof(creditHours)).rdstate();
    return packedSize;
}

int Unpack(fstream& file) {
    int unpackedSize = 0;
    unpackedSize += file.read(reinterpret_cast<char*>(&id), sizeof(id)).rdstate();
    char buffer[100];
    unpackedSize += file.read(buffer, sizeof(char) * 100).rdstate();
    name = buffer;
    unpackedSize += file.read(buffer, sizeof(char) * 100).rdstate();
    address = buffer;
    unpackedSize += file.read(buffer, sizeof(char) * 100).rdstate();
    firstCourseDate = buffer;
    unpackedSize += file.read(reinterpret_cast<char*>(&creditHours), sizeof(creditHours)).rdstate();
    return unpackedSize;
}
};

class CourseRegistration : public IOBuffer {
private:
    int courseID;
    int studentID;
    int creditHours;
    char grade;

public:
    // Constructor, getters, setters, and other methods

    // Pack the object into the file
    int Pack(fstream& file) const {
    int packedSize = 0;
    packedSize += file.write(reinterpret_cast<const char*>(&courseID), sizeof(courseID)).rdstate();
    packedSize += file.write(reinterpret_cast<const char*>(&studentID), sizeof(studentID)).rdstate();
    packedSize += file.write(reinterpret_cast<const char*>(&creditHours), sizeof(creditHours)).rdstate();
    packedSize += file.write(reinterpret_cast<const char*>(&grade), sizeof(grade)).rdstate();
    return packedSize;
}

    int Unpack(fstream& file) {
    int unpackedSize = 0;
    unpackedSize += file.read(reinterpret_cast<char*>(&courseID), sizeof(courseID)).rdstate();
    unpackedSize += file.read(reinterpret_cast<char*>(&studentID), sizeof(studentID)).rdstate();
    unpackedSize += file.read(reinterpret_cast<char*>(&creditHours), sizeof(creditHours)).rdstate();
    unpackedSize += file.read(reinterpret_cast<char*>(&grade), sizeof(grade)).rdstate();
    return unpackedSize;
}
};

int main() {
    // Example usage
    // BufferFile and other operations here

    return 0;
}
