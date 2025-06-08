#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int id;
    float marks[3]; // marks for 3 subjects
    float average;
    char grade;

public:
    void input();
    void calculate();
    void display() const;
    void saveToFile(std::ofstream &out) const;
    void loadFromFile(std::ifstream &in);
};

#endif

