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

    // Overloaded constructor to initialize only the member's name
    Member(string memberName) : name(memberName), role("Unknown") {
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

    void startSession() const {
        cout << "Starting an online session for group: " << getGroupName() << endl;
        cout << "Topic: " << getGroupTopic() << endl;
        cout << "All members have been notified to join the session." << endl;
    }
};

int main() {
    OnlineStudyGroup* cppStudyGroup = new OnlineStudyGroup("C++ Enthusiasts", "Advanced C++ Programming");
    
    // Use constructor overloading to create members with different initialization
    vector<Member*> members;
    members.push_back(new Member("Aman Jain", "Student")); // Using parameterized constructor
    members.push_back(new Member("Priya")); // Using overloaded constructor, role set to "Unknown"
    members.push_back(new Tutor("Kalvian")); // Using Tutor constructor
    members.push_back(new Member("Ajay", "Tutor")); // Using parameterized constructor

    for (Member* newMember : members) {
        cppStudyGroup->addMember(newMember);
    }

    cppStudyGroup->displayGroupInfo(); 
    cppStudyGroup->startSession();

    cout << "Total members: " << Member::getTotalMembers() << endl; 
    cout << "Total study groups: " << StudyGroup::getTotalGroups() << endl; 

    delete cppStudyGroup;

    return 0;
}
