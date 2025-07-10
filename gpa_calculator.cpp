#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cctype>
using namespace std;

// Grade to Grade Point Mapping
int getGradePointFromGrade(char grade) {
    switch (toupper(grade)) {
        case 'S': return 10;
        case 'A': return 9;
        case 'B': return 8;
        case 'C': return 7;
        case 'D': return 6;
        case 'E': return 5;
        case 'F': return 0;
        default: return -1;
    }
}

int main() {
    int totalSubjects;
    cout << " Enter number of subjects (1 to 15): ";
    cin >> totalSubjects;

    if (totalSubjects < 1 || totalSubjects > 15) {
        cout << " Invalid subject count. Please enter between 1 and 15.\n";
        return 1;
    }

    float midterm, termend, internal, attendance;
    float totalWeightedGPA = 0.0;
    int credits, totalCredits = 0;
    string subjectName;
    char grade;

    cout << " Note: Subjects with 0 credit will be skipped from GPA calculation.\n";

    for (int i = 1; i <= totalSubjects; ++i) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush input
        cout << "\n Subject " << i << ":\n";

        cout << "Enter subject name: ";
        getline(cin, subjectName);

        cout << "Midterm marks (out of 50): ";
        cin >> midterm;
        while (midterm < 0 || midterm > 50) {
            cout << " Enter valid marks (0-50): ";
            cin >> midterm;
        }

        cout << "Term-end marks (out of 100): ";
        cin >> termend;
        while (termend < 0 || termend > 100) {
            cout << " Enter valid marks (0-100): ";
            cin >> termend;
        }

        cout << "Internal marks (out of 35): ";
        cin >> internal;
        while (internal < 0 || internal > 35) {
            cout << " Enter valid marks (0-35): ";
            cin >> internal;
        }

        cout << "Attendance marks (out of 5): ";
        cin >> attendance;
        while (attendance < 0 || attendance > 5) {
            cout << " Enter valid marks (0-5): ";
            cin >> attendance;
        }

        cout << "Credits: ";
        cin >> credits;
        while (credits < 0) {
            cout << " Credits can't be negative. Re-enter: ";
            cin >> credits;
        }

        if (credits == 0) {
            cout << " Subject not counted (0 credit).\n";
            continue;
        }

        cout << "Enter Grade (S/A/B/C/D/E/F): ";
        cin >> grade;
        int gradePoint = getGradePointFromGrade(grade);

        while (gradePoint == -1) {
            cout << " Invalid grade. Please enter again (S/A/B/C/D/E/F): ";
            cin >> grade;
            gradePoint = getGradePointFromGrade(grade);
        }

        // Marks just for reference
        float midtermWeighted = midterm * 0.60f;
        float termendWeighted = termend * 0.30f;
        float finalMarks = midtermWeighted + termendWeighted + internal + attendance;
        finalMarks = round(finalMarks);

        // GPA calculation
        totalWeightedGPA += gradePoint * credits;
        totalCredits += credits;

        // Display subject summary
        cout << fixed << setprecision(2);
        cout << "➡ Final Marks: " << finalMarks << " / 100.00\n"; //"There might be a difference of 1 mark due to the rounding off of decimal-point values."<<endl;
        cout << " → Grade Point: " << gradePoint << "\n";
    }

    // Final GPA and Percentage
    cout << "\n=========== FINAL RESULT ===========\n";
    cout << fixed << setprecision(2);

    if (totalCredits > 0) {
        float finalGPA = totalWeightedGPA / totalCredits;
        float percentage = finalGPA * 10;

        cout << "GPA = Σ(Credit * Grade Point) ÷ Σ(Credits)\n";
        cout << " Final GPA: " << finalGPA << endl;
        cout << " Final Percentage: " << percentage << "%" << endl;
    } else {
        cout << " GPA can't be calculated (all 0-credit subjects).\n";
    }

    cout << "=====================================\n";
    return 0;
}
