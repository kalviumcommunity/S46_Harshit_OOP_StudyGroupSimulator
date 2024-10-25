#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract base class
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

    Member(string memberName) : name(memberName), role("Unknown") {
        totalMembers++;
    }

    virtual ~Member() {
        // Virtual destructor to cleanup derived classes
        totalMembers--;
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

    virtual void displayMemberInfo() const {
        cout << "Name: " << this->name << ", Role: " << this->role << endl;
    }

    // Pure virtual function (abstract method)
    virtual string getDescription() const = 0; // Makes Member an abstract class
};

int Member::totalMembers = 0;

// Derived class for Students
class Student : public Member {
public:
    Student(string name) : Member(name, "Student") {}

    // Override pure virtual function
    string getDescription() const override {
        return "I am a student and I love to learn!";
    }
};

// Derived class for Tutors
class Tutor : public Member {
public:
    Tutor(string name) : Member(name, "Tutor") {}

    // Override pure virtual function
    string getDescription() const override {
        return "I am a tutor and I love to teach!";
    }
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
            cout << "Description: " << member->getDescription() << endl; // Call virtual function
        }
    }

    ~StudyGroup() {
        for (auto member : members) {
            delete member;
        }
        totalGroups--;
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
    
    vector<Member*> members;
    members.push_back(new Student("Aman Jain"));   
    members.push_back(new Tutor("Priya"));         
    members.push_back(new Student("Kalvian"));    
    members.push_back(new Tutor("Ajay"));        
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
