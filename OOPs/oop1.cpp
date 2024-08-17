#include <bits/stdc++.h>
using namespace std;
class Teacher
{
    double salary;

public:
    string name;
    string subj;
    string dept;
    Teacher(Teacher &ogObj)
    {
        this->name = ogObj.name;
        this->dept = ogObj.dept;
        this->subj = ogObj.subj;
        this->setSalary(ogObj.salary);
    }
    Teacher(string name, string sub, string dept, double salary)
    {
        this->dept = dept;
        this->name = name;
        this->subj = sub;
        this->setSalary(salary);
    }

    // setters
    void setSalary(double s)
    {
        salary = s;
    }
    // getter
    double getsalary()
    {
        return salary;
    }
    void getInfor()
    {
        cout << "Name : " << this->name << endl;
        cout << "Department : " << this->dept << endl;
    }
};

int main()
{
    Teacher t1("Pranav", "C++", "Comps", 25000);
    Teacher t2(t1);

    t2.getInfor();
    t2.name = "Neha";

    t2.getInfor();

    t1.getInfor();
    return 0;
}