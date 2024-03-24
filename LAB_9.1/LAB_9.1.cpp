#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <locale>

using namespace std;

struct Student {
    string surname;
    int course;
    string specialty;
    double physics_grade;
    double math_grade;
    double programming_grade;
};

void inputStudentData(Student& student, int number) {
    cout << "Prizvyshche studenta " << number << ": ";
    cin >> student.surname;
    cout << "Otsinka z fizyky: ";
    cin >> student.physics_grade;
    cout << "Otsinka z matematyky: ";
    cin >> student.math_grade;
    cout << "Otsinka z prohramuvannya: ";
    cin >> student.programming_grade;
}

void inputCourseAndSpecialty(vector<Student>& students) {
    int course;
    string specialty;
    cout << "Kurs: ";
    cin >> course;
    cout << "Spetsialnist: ";
    cin >> specialty;
    for (auto& student : students) {
        student.course = course;
        student.specialty = specialty; // Присвоюємо спеціальність для кожного студента
    }
}

void inputStudentsData(vector<Student>& students) {
    for (int i = 0; i < 5; ++i) {
        Student new_student;
        inputStudentData(new_student, i + 1);
        students.push_back(new_student);
    }
    inputCourseAndSpecialty(students); // Введення курсу і спеціальності одного разу
}

void printStudentsTable(const vector<Student>& students) {
    cout << setw(5) << "№" << setw(15) << "Prizvyshche" << setw(7) << "Kurs" << setw(15) << "Spetsialnist"
        << setw(10) << "  Fizyka" << setw(10) << "    Matematyka" << setw(15) << "     Prohramuvannya" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        cout << setw(5) << i + 1 << setw(15) << students[i].surname << setw(7) << students[i].course
            << setw(15) << students[i].specialty << setw(10) << students[i].physics_grade
            << setw(10) << students[i].math_grade << setw(15) << students[i].programming_grade << endl;
    }
}

int countStudentsWithoutThrees(const vector<Student>& students) {
    int count = 0;
    for (const auto& student : students) {
        if (student.physics_grade >= 4 && student.math_grade >= 4 && student.programming_grade >= 4) {
            ++count;
        }
    }
    return count;
}

double calculatePercentageOfStudentsWithAverageBelowFour(const vector<Student>& students) {
    int total_students = students.size();
    int count = 0;
    for (const auto& student : students) {
        double average = (student.physics_grade + student.math_grade + student.programming_grade) / 3.0;
        if (average < 4) {
            ++count;
        }
    }
    return (count * 100.0) / total_students;
}

int main() {
    setlocale(LC_ALL, "ukr");
    vector<Student> students;
    inputStudentsData(students);
    cout << "\nTablytsya studentiv:\n";
    printStudentsTable(students);

    int without_threes = countStudentsWithoutThrees(students);
    cout << "\nKilkist studentiv bez triyok: " << without_threes << endl;

    double percentage_below_four = calculatePercentageOfStudentsWithAverageBelowFour(students);
    cout << "Protsent studentiv z serednim balom menshe 4: " << fixed << setprecision(2) << percentage_below_four << "%" << endl;

    return 0;
}
