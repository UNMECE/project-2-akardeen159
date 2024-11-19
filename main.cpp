#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
class Student {
protected:
    std::string fName;
    std::string lName;
    float gpa;
    int gradYear;
    std::string gradSem;
    int enrollYear;
    std::string enrollSem;
    std::string progType;

public:
    Student()
        : fName(""), lName(""), gpa(0.0), gradYear(0),
          gradSem(""), enrollYear(0), enrollSem(""), progType("Undergrad") {}

    virtual ~Student() {}

    void setName(const std::string &first, const std::string &last) {
        fName = first;
        lName = last;
    }

    void setGPA(float grade) { gpa = grade; }

    void setGrad(int year, const std::string &semester) {
        gradYear = year;
        gradSem = semester;
    }

    void setEnroll(int year, const std::string &semester) {
        enrollYear = year;
        enrollSem = semester;
    }

    void setProg(const std::string &type) { progType = type; }

    virtual std::string getInfo() const {
        std::string info = "Name: " + fName + " " + lName +
                           ", GPA: " + std::to_string(gpa).substr(0, 4) + 
                           ", Graduation: " + gradSem + " " + std::to_string(gradYear) +
                           ", Enrollment: " + enrollSem + " " + std::to_string(enrollYear) +
                           ", Program: " + progType;
        return info;
    }
};
class ArtStudent : public Student {
private:
    std::string artFocus;

public:
    ArtStudent() : Student(), artFocus("Art Studio") {}

    void setFocus(const std::string &focus) { artFocus = focus; }

    std::string getInfo() const override {
        return Student::getInfo() + ", Art Focus: " + artFocus;
    }
};
class PhysicsStudent : public Student {
private:
    std::string conc;

public:
    PhysicsStudent() : Student(), conc("Biophysics") {}

    void setConc(const std::string &concentration) { conc = concentration; }

    std::string getInfo() const override {
        return Student::getInfo() + ", Concentration: " + conc;
    }
};
int main() {
    std::vector<ArtStudent *> artStudents;
    std::vector<PhysicsStudent *> physicsStudents;

    ArtStudent *art1 = new ArtStudent();
    art1->setName("Johnathan", "Fort");
    art1->setGPA(3.85);
    art1->setGrad(2025, "Spring");
    art1->setEnroll(2021, "Fall");
    art1->setFocus("Art Studio");
    artStudents.push_back(art1);

    ArtStudent *art2 = new ArtStudent();
    art2->setName("james", "Smith");
    art2->setGPA(3.50);
    art2->setGrad(2026, "Fall");
    art2->setEnroll(2022, "Spring");
    art2->setFocus("Art History");
    artStudents.push_back(art2);

    ArtStudent *art3 = new ArtStudent();
    art3->setName("Johnson", "Feild");
    art3->setGPA(3.25);
    art3->setGrad(2025, "Spring");
    art3->setEnroll(2021, "Fall");
    art3->setFocus("Art Education");
    artStudents.push_back(art3);

    ArtStudent *art4 = new ArtStudent();
    art4->setName("Van", "Gogh");
    art4->setGPA(4.00);
    art4->setGrad(2027, "Fall");
    art4->setEnroll(2023, "Spring");
    art4->setFocus("Art Studio");
    artStudents.push_back(art4);

    ArtStudent *art5 = new ArtStudent();
    art5->setName("Frida", "Kahlo");
    art5->setGPA(3.75);
    art5->setGrad(2026, "Spring");
    art5->setEnroll(2022, "Fall");
    art5->setFocus("Art History");
    artStudents.push_back(art5);

    PhysicsStudent *phys1 = new PhysicsStudent();
    phys1->setName("Robert", "Woah");
    phys1->setGPA(2.85);
    phys1->setGrad(2025, "Winter");
    phys1->setEnroll(2021, "Spring");
    phys1->setConc("Biophysics");
    physicsStudents.push_back(phys1);

    PhysicsStudent *phys2 = new PhysicsStudent();
    phys2->setName("Sophia", "Many");
    phys2->setGPA(3.10);
    phys2->setGrad(2026, "Summer");
    phys2->setEnroll(2022, "Fall");
    phys2->setConc("Earth and Planetary Sciences");
    physicsStudents.push_back(phys2);

    PhysicsStudent *phys3 = new PhysicsStudent();
    phys3->setName("James", "Taylor");
    phys3->setGPA(3.60);
    phys3->setGrad(2027, "Spring");
    phys3->setEnroll(2023, "Spring");
    phys3->setConc("Biophysics");
    physicsStudents.push_back(phys3);

    PhysicsStudent *phys4 = new PhysicsStudent();
    phys4->setName("Albert", "Einstein");
    phys4->setGPA(4.00);
    phys4->setGrad(2026, "Winter");
    phys4->setEnroll(2022, "Spring");
    phys4->setConc("Earth and Planetary Sciences");
    physicsStudents.push_back(phys4);

    PhysicsStudent *phys5 = new PhysicsStudent();
    phys5->setName("Isaac", "Newton");
    phys5->setGPA(4.00);
    phys5->setGrad(2028, "Fall");
    phys5->setEnroll(2024, "Fall");
    phys5->setConc("Biophysics");
    physicsStudents.push_back(phys5);

    std::ofstream outFile("student_info.dat", std::ios::out);
    if (outFile.is_open()) {
        for (const auto &student : artStudents) {
            outFile << student->getInfo() << std::endl;
        }
        for (const auto &student : physicsStudents) {
            outFile << student->getInfo() << std::endl;
        }
        outFile.close();
    }

    for (auto &student : artStudents) delete student;
    for (auto &student : physicsStudents) delete student;

    return 0;
}

