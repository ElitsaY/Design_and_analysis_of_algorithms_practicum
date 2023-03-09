#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_VAL = 100;

struct Student
{
    int id;
    string name;

    Student(){}
    Student(int id, const string &name) : id(id), name(name) {}
};

void countSortLists(vector <Student> &students)
{
    vector <list <Student>> id2Students(MAX_VAL + 1);

    for (const Student &s : students)
    {
        id2Students[s.id].emplace_back(move(s));
    }

    int ptr = 0;
    for (int id = 0; id <= MAX_VAL; id++)
    {
        for (const Student &s : id2Students[id])
        {
            students[ptr] = move(s);
            ptr++;
        }
    }
}

void countSortPrefixes(vector <Student> &students)
{
    vector <int> pref(MAX_VAL + 1, 0);
    vector <int> idCnt(MAX_VAL + 1, 0);
    vector <int> placedIdCnt(MAX_VAL + 1, 0);

    for (const Student &s : students)
    {
        idCnt[s.id]++;
    }

    pref[0] = idCnt[0];
    for (int id = 1; id <= MAX_VAL; id++)
    {
        pref[id] = pref[id - 1] + idCnt[id];
    }

    vector <Student> newStudents(students.size());
    for (const Student &s : students)
    {
        int cntBefore = placedIdCnt[s.id];
        if (s.id != 0) cntBefore += pref[s.id - 1];

        newStudents[cntBefore] = move(s);
        placedIdCnt[s.id]++;
    }

    students = move(newStudents);
}

int main()
{
    int n;
    cin >> n;

    vector <Student> students;
    students.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int id;
        string name;

        cin >> id >> name;
        students.emplace_back(id, name);
    }

    //countSortLists(students);
    countSortPrefixes(students);

    cout << '\n';
    for (const Student &s : students)
    {
        cout << s.id << " " << s.name << '\n';
    }
}
/*
4
3 tri
1 edno
2 dve_1
2 dve_2
*/
