#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Member {
private:
    string name;
    string role;

public:
    Member(string memberName, string memberRole) : name(memberName), role(memberRole) {}

    void displayMemberInfo() {
        cout << "Name: " << name << ", Role: " << role << endl;
    }

    string getRole() {
        return role;
    }
};

class StudyGroup {
private:
    string groupName;
    string groupTopic;
    vector<Member> members;

public:
    StudyGroup(string name, string topic) : groupName(name), groupTopic(topic) {}

    void addMember(Member newMember) {
        members.push_back(newMember);
    }

    void displayGroupInfo() {
        cout << "Study Group: " << groupName << endl;
        cout << "Topic: " << groupTopic << endl;
        cout << "Members:" << endl;
        for (auto &member : members) {
            member.displayMemberInfo();
        }
    }
};

int main() {
    StudyGroup cppStudyGroup("C++ Enthusiasts", "Advanced C++ Programming");

    Member aaryan("Aaryan", "Student");
    Member priya("Priya", "Tutor");

    cppStudyGroup.addMember(aaryan);
    cppStudyGroup.addMember(priya);

    cppStudyGroup.displayGroupInfo();

    return 0;
}
