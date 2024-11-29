#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract base class for Members
class Member {
private:
    string name;
    string role;

public:
    Member(string memberName, string memberRole) : name(memberName), role(memberRole) {}

    virtual ~Member() = default;

    string getName() const { return name; }
    string getRole() const { return role; }

    virtual void displayMemberInfo() const {
        cout << "Name: " << name << ", Role: " << role << endl;
    }

    // Pure virtual function
    virtual string getDescription() const = 0;
};

// Student class
class Student : public Member {
public:
    Student(string name) : Member(name, "Student") {}

    string getDescription() const override {
        return "I am a student and I love to learn!";
    }
};

// Tutor class
class Tutor : public Member {
public:
    Tutor(string name) : Member(name, "Tutor") {}

    string getDescription() const override {
        return "I am a tutor and I love to teach!";
    }
};

// Class to manage Study Group Members
class MemberManager {
private:
    vector<Member*> members;

public:
    ~MemberManager() {
        for (auto member : members) {
            delete member;
        }
    }

    void addMember(Member* newMember) {
        members.push_back(newMember);
    }

    void displayMembers() const {
        for (const auto& member : members) {
            member->displayMemberInfo();
            cout << "Description: " << member->getDescription() << endl;
        }
    }
};

// StudyGroup class
class StudyGroup {
private:
    string groupName;
    string groupTopic;
    MemberManager memberManager; // Delegation to MemberManager

public:
    StudyGroup(string name, string topic) : groupName(name), groupTopic(topic) {}

    void addMember(Member* newMember) {
        memberManager.addMember(newMember);
    }

    void displayGroupInfo() const {
        cout << "Study Group: " << groupName << endl;
        cout << "Topic: " << groupTopic << endl;
        cout << "Members:" << endl;
        memberManager.displayMembers();
    }
};

// OnlineStudyGroup class for conducting sessions
class OnlineStudyGroup : public StudyGroup {
public:
    OnlineStudyGroup(string name, string topic) : StudyGroup(name, topic) {}

    void startSession() const {
        cout << "Starting an online session for group: " << endl;
    }
};

int main() {
    OnlineStudyGroup* cppStudyGroup = new OnlineStudyGroup("C++ Enthusiasts", "Advanced C++ Programming");

    cppStudyGroup->addMember(new Student("Aman Jain"));
    cppStudyGroup->addMember(new Tutor("Priya"));
    cppStudyGroup->addMember(new Student("Kalvian"));
    cppStudyGroup->addMember(new Tutor("Ajay"));

    cppStudyGroup->displayGroupInfo();
    cppStudyGroup->startSession();

    delete cppStudyGroup;

    return 0;
}
