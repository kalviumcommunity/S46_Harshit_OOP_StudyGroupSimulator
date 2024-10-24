#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
private:
    // Private data members (abstraction)
    string name;
    string role;

    static int totalMembers;

public:

    // Default constructor
    Member() : name(""), role("") {
        totalMembers++;
    }

    // Parameterized constructor
    Member(string memberName, string memberRole) : name(memberName), role(memberRole) {
        totalMembers++;
    }

    static int getTotalMembers() {
        return totalMembers;
    }

    void setMemberDetails(string memberName, string memberRole) {
        this->name = memberName;
        this->role = memberRole;
    }

    string getName() const {
        return this->name;
    }

    string getRole() const {
        return this->role;
    }

    void setName(const string& memberName) {
        this->name = memberName;
    }

    void setRole(const string& memberRole) {
        this->role = memberRole;
    }

    // Function to display member info (demonstrates abstraction as only relevant information is exposed)
    void displayMemberInfo() const {
        cout << "Name: " << this->name << ", Role: " << this->role << endl;
    }
};

int Member::totalMembers = 0;

class StudyGroup {
private:
    // Private data members for group name and topic (abstraction)
    string groupName;
    string groupTopic;

    // A list of pointers to members, hidden from external access
    vector<Member*> members;

    static int totalGroups;

public:

    // Parameterized constructor
    StudyGroup(string name, string topic) : groupName(name), groupTopic(topic) {
        totalGroups++;
    }

    static int getTotalGroups() {
        return totalGroups;
    }

    void setGroupName(const string& name) {
        this->groupName = name;
    }

    string getGroupName() const {
        return this->groupName;
    }

    void setGroupTopic(const string& topic) {
        this->groupTopic = topic;
    }

    string getGroupTopic() const {
        return this->groupTopic;
    }

    void addMember(Member* newMember) {
        this->members.push_back(newMember);
    }

    // Function to display group info (abstraction as only necessary info is exposed)
    void displayGroupInfo() const {
        cout << "Study Group: " << this->groupName << endl;
        cout << "Topic: " << this->groupTopic << endl;
        cout << "Members:" << endl;
        for (const auto& member : members) {
            member->displayMemberInfo();
        }
    }

    ~StudyGroup() {
        // Destructor to clean up dynamically allocated members
        for (auto member : members) {
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

    delete cppStudyGroup;

    return 0;
}
