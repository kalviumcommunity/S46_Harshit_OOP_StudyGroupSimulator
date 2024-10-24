#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
private:
    string name;
    string role;
    static int totalMembers;

public:

    Member() : name(""), role("") {
        totalMembers++;
    }

    Member(string memberName, string memberRole) : name(memberName), role(memberRole) {
        totalMembers++;
    }

    static int getTotalMembers() {
        return totalMembers;
    }

    // Mutator to set member details
    void setMemberDetails(string memberName, string memberRole) {
        this->name = memberName;
        this->role = memberRole;
    }

    // Accessor for member name
    string getName() const {
        return name;
    }

    // Accessorfor member role
    string getRole() const {
        return role;
    }

    // Mutator for member name
    void setName(const string& memberName) {
        name = memberName;
    }

    // Mutator for member role
    void setRole(const string& memberRole) {
        role = memberRole;
    }

    void displayMemberInfo() const {
        cout << "Name: " << name << ", Role: " << role << endl;
    }
};

int Member::totalMembers = 0;

class StudyGroup {
private:
    string groupName;
    string groupTopic;
    vector<Member*> members;
    static int totalGroups;

public:

    StudyGroup(string name, string topic) : groupName(name), groupTopic(topic) {
        totalGroups++;
    }

    static int getTotalGroups() {
        return totalGroups;
    }

    // Mutator for group name
    void setGroupName(const string& name) {
        groupName = name;
    }

    // Accessor for group name
    string getGroupName() const {
        return groupName;
    }

    // Mutator for group topic
    void setGroupTopic(const string& topic) {
        groupTopic = topic;
    }

    // Accessor for group topic
    string getGroupTopic() const {
        return groupTopic;
    }

    void addMember(Member* newMember) {
        members.push_back(newMember);
    }

    void displayGroupInfo() const {
        cout << "Study Group: " << groupName << endl;
        cout << "Topic: " << groupTopic << endl;
        cout << "Members:" << endl;
        for (const auto& member : members) {
            member->displayMemberInfo();
        }
    }

    void deleteMembers() {
        for (auto& member : members) {
            delete member;
        }
    }
};

int StudyGroup::totalGroups = 0;

int main() {
    StudyGroup* cppStudyGroup = new StudyGroup("C++ Enthusiasts", "Advanced C++ Programming");

    vector<Member*> members;
    string names[] = {"Aman Jain", "Priya", "Kalvian", "Ajay"};
    string roles[] = {"Student", "Tutor", "Student", "Tutor"};

    for (int i = 0; i < 4; i++) {
        Member* newMember = new Member(names[i], roles[i]);
        members.push_back(newMember);
        cppStudyGroup->addMember(newMember);
    }

    cppStudyGroup->displayGroupInfo();

    cout << "Total members: " << Member::getTotalMembers() << endl;
    cout << "Total study groups: " << StudyGroup::getTotalGroups() << endl;

    for (auto member : members) {
        delete member;
    }
    delete cppStudyGroup;

    return 0;
}
