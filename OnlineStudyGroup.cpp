#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class
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

    void displayMemberInfo() const {
        cout << "Name: " << this->name << ", Role: " << this->role << endl;
    }
};

int Member::totalMembers = 0;

// Derived class for Students
class Student : public Member {
public:
    // Constructor for Student
    Student(string name) : Member(name, "Student") {}
};

// Derived class for Tutors
class Tutor : public Member {
public:
    // Constructor for Tutor
    Tutor(string name) : Member(name, "Tutor") {}
};

// Base class
class StudyGroup {
private:
    // Private data members for group name and topic (abstraction)
    string groupName;
    string groupTopic;

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

// Derived class for Online Study Groups
class OnlineStudyGroup : public StudyGroup {
public:
    OnlineStudyGroup(string name, string topic) : StudyGroup(name, topic) {}

    // functionality to start an online session
    void startSession() const {
        cout << "Starting an online session for group: " << getGroupName() << endl;
        cout << "Topic: " << getGroupTopic() << endl;
        cout << "All members have been notified to join the session." << endl;
    }
};

int main() {
    OnlineStudyGroup* cppStudyGroup = new OnlineStudyGroup("C++ Enthusiasts", "Advanced C++ Programming");

    vector<Member*> members;
    string names[] = {"Aman Jain", "Priya", "Kalvian", "Ajay"};
    string roles[] = {"Student", "Tutor", "Student", "Tutor"};

    for (int i = 0; i < 4; i++) {
        Member* newMember = new Member(names[i], roles[i]);
        members.push_back(newMember);
        cppStudyGroup->addMember(newMember);
    }

    cppStudyGroup->displayGroupInfo();
    cppStudyGroup->startSession(); // Start the online session

    cout << "Total members: " << Member::getTotalMembers() << endl;
    cout << "Total study groups: " << StudyGroup::getTotalGroups() << endl;

    //clean up
    delete cppStudyGroup;

    return 0;
}