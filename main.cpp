#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"

int main() {
    std::vector<Student> students;
    int choice;
    
    do {
        std::cout << "\n1. Add Student\n2. Display All\n3. Save to File\n4. Load from File\n5. Exit\nChoose: ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline
        
        if (choice == 1) {
            Student s;
            s.input();
            students.push_back(s);
        } else if (choice == 2) {
            for (const auto &s : students) {
                s.display();
            }
        } else if (choice == 3) {
            std::ofstream out("students.txt");
            for (const auto &s : students) {
                s.saveToFile(out);
            }
            out.close();
            std::cout << "Saved to students.txt\n";
        } else if (choice == 4) {
            std::ifstream in("students.txt");
            students.clear();
            while (in.peek() != EOF) {
                Student s;
                s.loadFromFile(in);
                students.push_back(s);
            }
            in.close();
            std::cout << "Loaded from students.txt\n";
        }
    } while (choice != 5);

    return 0;
}

