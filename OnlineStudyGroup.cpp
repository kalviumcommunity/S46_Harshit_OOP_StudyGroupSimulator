#include <iostream>
#include <string>
#include <vector>
#include <memory>

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

    // Pure virtual function for description
    virtual string getDescription() const = 0;

    // Hook for additional behavior
    virtual void additionalBehavior() const {}
};

// Concrete Member: Student
class Student : public Member {
public:
    Student(string name) : Member(name, "Student") {}

    string getDescription() const override {
        return "I am a student and I love to learn!";
    }
};

// Concrete Member: Tutor
class Tutor : public Member {
public:
    Tutor(string name) : Member(name, "Tutor") {}

    string getDescription() const override {
        return "I am a tutor and I love to teach!";
    }
};

// MemberManager: Open for extension through polymorphism
class MemberManager {
private:
    vector<shared_ptr<Member>> members;

public:
    void addMember(shared_ptr<Member> newMember) {
        members.push_back(newMember);
    }

    void displayMembers() const {
        for (const auto& member : members) {
            member->displayMemberInfo();
            cout << "Description: " << member->getDescription() << endl;
            member->additionalBehavior(); // Dynamic behavior hook
        }
    }
};

// StudyGroup: Open for extension via derived classes
class StudyGroup {
private:
    string groupName;
    string groupTopic;
    MemberManager memberManager; // Delegation to MemberManager

public:
    StudyGroup(string name, string topic) : groupName(name), groupTopic(topic) {}

    virtual ~StudyGroup() = default;

    void addMember(shared_ptr<Member> newMember) {
        memberManager.addMember(newMember);
    }

    virtual void displayGroupInfo() const {
        cout << "Study Group: " << groupName << endl;
        cout << "Topic: " << groupTopic << endl;
        cout << "Members:" << endl;
        memberManager.displayMembers();
    }
};

// OnlineStudyGroup: Extended behavior without modifying StudyGroup
class OnlineStudyGroup : public StudyGroup {
public:
    OnlineStudyGroup(string name, string topic) : StudyGroup(name, topic) {}

    void startSession() const {
        cout << "Starting an online session for the group!" << endl;
    }

    void displayGroupInfo() const override {
        StudyGroup::displayGroupInfo();
        cout << "This group is conducted online!" << endl;
    }
};

// New Member Type: Guest
class Guest : public Member {
public:
    Guest(string name) : Member(name, "Guest") {}

    string getDescription() const override {
        return "I am a guest, observing the session!";
    }

    void additionalBehavior() const override {
        cout << "Note: Guest has limited access to materials." << endl;
    }
};

int main() {
    // Creating an online study group
    shared_ptr<OnlineStudyGroup> cppStudyGroup = make_shared<OnlineStudyGroup>("C++ Enthusiasts", "Advanced C++ Programming");

    // Adding members
    cppStudyGroup->addMember(make_shared<Student>("Aman Jain"));
    cppStudyGroup->addMember(make_shared<Tutor>("Priya"));
    cppStudyGroup->addMember(make_shared<Student>("Kalvian"));
    cppStudyGroup->addMember(make_shared<Guest>("Observer"));

    // Display group info and start session
    cppStudyGroup->displayGroupInfo();
    cppStudyGroup->startSession();

    return 0;
}
