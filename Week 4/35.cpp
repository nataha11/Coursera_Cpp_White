#include <iostream>

using namespace std;

struct Specialization {
    string sp;
    explicit Specialization(const string& new_sp) {
        sp = new_sp;
    }
};

struct Course {
    string c;
    explicit Course(const string& new_c) {
        c = new_c;
    }
};

struct Week {
    string wk;
    explicit Week(const string& new_wk) {
        wk = new_wk;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& New_sp, const Course& New_c, const Week& New_wk) {
        specialization = New_sp.sp;
        course = New_c.c;
        week = New_wk.wk;
    }
};

int main() {

    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

//incorrect calls:

/*    LectureTitle title("C++", "White belt", "4th");

    LectureTitle title(string("C++"), string("White belt"), string("4th"));

    LectureTitle title = {"C++", "White belt", "4th"};

    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

    LectureTitle title(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );

    LectureTitle title(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );*/


    cout << title.specialization << title.course << title.week << endl;

    return 0;
}