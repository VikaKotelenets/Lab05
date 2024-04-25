#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class ClassFormat {
    Lecture,
    Seminar,
    Lab,
    Online
};

class DailySchedule {
    private: 
    struct ClassInfo {
        int classNumber;
        string subject;
        string teacherSurname;
        ClassFormat format;
    };
     
     vector <ClassInfo> classes;

     public:

     void addClass(int classNumber, const string& subject, const string& teacherSurname, ClassFormat format) {
        classes.push_back({classNumber, subject, teacherSurname, format});
     }

     void deleteClass(int index) {
        if (index >= 0 && index < classes.size()) {
            classes.erase(classes.begin() + index);
        }
    }

    void displaySchedule() const {
        for (const auto& classInfo : classes) {
            std::string formatStr;
            switch (classInfo.format) {
                case ClassFormat::Lecture:
                    formatStr = "Lecture";
                    break;
                case ClassFormat::Seminar:
                    formatStr = "Seminar";
                    break;
                case ClassFormat::Lab:
                    formatStr = "Lab";
                    break;
                case ClassFormat::Online:
                    formatStr = "Online";
                    break;
            }

            cout << "Class " << classInfo.classNumber << ": " << classInfo.subject << endl;
            cout << "Teacher: " << classInfo.teacherSurname << endl;
            cout << "Format: " << formatStr << endl << endl;
        }
    }
};

int main() {
    DailySchedule schedule;

    schedule.addClass(1, "English", "Smith", ClassFormat::Lecture);
    schedule.addClass(2, "Physics", "Johnson", ClassFormat::Lab);
    schedule.addClass(3, "History", "Williams", ClassFormat::Seminar);

schedule.displaySchedule();

    return 0;
}
