#include <iostream>
#include <string>

using namespace std;

class Member {
private:
    string name;
    string role;

public:
    Member() : name(""), role("") {}

    Member(string memberName, string memberRole) {
        this->name = memberName;
        this->role = memberRole;
    }

    void setMemberDetails(string memberName, string memberRole) {
        this->name = memberName;
        this->role = memberRole;
    }

    void displayMemberInfo() const {
        cout << "Name: " << name << ", Role: " << role << endl;
    }

    string getRole() const {
        return role;
    }
};

class StudyGroup {
private:
    string groupName;
    string groupTopic;
    Member* members[10];
    int memberCount;

public:
    StudyGroup(string name, string topic) : groupName(name), groupTopic(topic), memberCount(0) {}

    void addMember(Member* newMember) {
        if (memberCount < 10) {
            members[memberCount] = newMember;
            memberCount++;
        } else {
            cout << "Member array is full!" << endl;
        }
    }

    void displayGroupInfo() const {
        cout << "Study Group: " << groupName << endl;
        cout << "Topic: " << groupTopic << endl;
        cout << "Members:" << endl;
        for (int i = 0; i < memberCount; i++) {
            members[i]->displayMemberInfo();
        }
    }
};

int main() {
    StudyGroup* cppStudyGroup = new StudyGroup("C++ Enthusiasts", "Advanced C++ Programming");

    Member* aman = new Member("Aman Jain", "Student");
    Member* priya = new Member("Priya", "Tutor");
    Member* kalvian = new Member("Kalvian", "Student");
    Member* ajay = new Member("Ajay", "Tutor");

    cppStudyGroup->addMember(aman);
    cppStudyGroup->addMember(priya);
    cppStudyGroup->addMember(kalvian);
    cppStudyGroup->addMember(ajay);

    cppStudyGroup->displayGroupInfo();

    delete aman;
    delete priya;
    delete kalvian;
    delete ajay;

    delete cppStudyGroup;

    return 0;
}
