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