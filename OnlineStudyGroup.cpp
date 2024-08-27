#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Member {
private:
    string name;
    string role;

public:
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
    vector<Member> members;

public:
    StudyGroup(string name, string topic) {
        this->groupName = name;
        this->groupTopic = topic;
    }

    void addMember(const Member& newMember) {
        members.push_back(newMember);
    }

    void displayGroupInfo() const {
        cout << "Study Group: " << groupName << endl;
        cout << "Topic: " << groupTopic << endl;
        cout << "Members:" << endl;
        for (const auto &member : members) {
            member.displayMemberInfo();
        }
    }
};

int main() {
    StudyGroup cppStudyGroup("C++ Enthusiasts", "Advanced C++ Programming");

    Member aman("Aman", "Student");
    Member priya("Priya", "Tutor");

    aman.setMemberDetails("Aman Jain", "Student");

    cppStudyGroup.addMember(aman);
    cppStudyGroup.addMember(priya);

    cppStudyGroup.displayGroupInfo();

    return 0;
}
