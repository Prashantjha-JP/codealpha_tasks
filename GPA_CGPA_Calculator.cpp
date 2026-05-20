#include <iostream>
using namespace std;

int main()
{
    int semesters;

    cout << "===== GPA & CGPA CALCULATOR =====" << endl;

    cout << "\nEnter Number of Semesters: ";
    cin >> semesters;

    float totalGPA = 0;

    for(int sem = 1; sem <= semesters; sem++){
    
        int subjects;

        string subjectName;

        float gradePoint;
        float creditHours;

        float totalCredits = 0;
        float totalGradePoints = 0;

        cout << "\n===== SEMESTER " << sem << " =====" << endl;

        cout << "Enter Number of Subjects: ";
        cin >> subjects;

        for(int i = 1; i <= subjects; i++){
        
            cout << "\n----- Subject " << i << " -----" << endl;

            cout << "Enter Subject Name: ";
            cin >> subjectName;

            cout << "Enter Grade Point: ";
            cin >> gradePoint;

            cout << "Enter Credit Hours: ";
            cin >> creditHours;

            totalGradePoints += gradePoint * creditHours;

            totalCredits += creditHours;

            cout << "\nSubject: " << subjectName << endl;
            cout << "Grade Point: " << gradePoint << endl;
            cout << "Credit Hours: " << creditHours << endl;
        }

        float gpa = totalGradePoints / totalCredits;

        cout << "\nSemester " << sem << " GPA: " << gpa << endl;

        totalGPA += gpa;
    }

    float cgpa = totalGPA / semesters;

    cout << "\n===== FINAL RESULT =====" << endl;

    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
