#include "student.h"
#include <iostream>
#include <fstream>

void Student::input() {
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter student ID: ";
    std::cin >> id;
    for (int i = 0; i < 3; i++) {
        std::cout << "Enter marks for subject " << (i+1) << ": ";
        std::cin >> marks[i];
    }
    std::cin.ignore(); // clear buffer
    calculate();
}

void Student::calculate() {
    average = (marks[0] + marks[1] + marks[2]) / 3.0;
    if (average >= 75) grade = 'A';
    else if (average >= 60) grade = 'B';
    else if (average >= 50) grade = 'C';
    else if (average >= 35) grade = 'D';
    else grade = 'F';
}

void Student::display() const {
    std::cout << "Name: " << name << "\nID: " << id
              << "\nAverage: " << average << "\nGrade: " << grade << "\n\n";
}

void Student::saveToFile(std::ofstream &out) const {
    out << name << "\n" << id << "\n"
        << marks[0] << " " << marks[1] << " " << marks[2] << "\n";
}

void Student::loadFromFile(std::ifstream &in) {
    std::getline(in, name);
    in >> id >> marks[0] >> marks[1] >> marks[2];
    in.ignore(); // move to next line
    calculate();
}
