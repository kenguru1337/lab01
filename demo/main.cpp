#include <student.hpp>
#include <fstream>

using nlohmann::json;


void print(const Student& student, std::ostream& os) {
    if (student.name.empty()){
        os << "| null\t|";
    } else {
        os << "| " << student.name << "\t|";
    }

    if (student.group.type() == typeid(std::nullptr_t)){
        os << "null|";
    } else if (student.group.type() == typeid(std::string)){
        if (std::any_cast<std::string>(student.group).length() == 1){
            os << " " << std::any_cast<std::string>(student.group) << "\t\t\t|";
        } else {
            os << " " << std::any_cast<std::string>(student.group) << "\t|";
        }
    } else {
        os << " " << std::any_cast<std::size_t>(student.group)
           << " group\t|";
    }

    if (student.avg.type() == typeid(std::nullptr_t)){
        os << "null\t|";
    } else if (student.avg.type() == typeid(std::string)){
        os << " " << std::any_cast<std::string>(student.avg) << "\t|";
    } else if (student.avg.type() == typeid(std::double_t)){
        os << " " << std::any_cast<std::double_t>(student.avg) << "\t|";
    } else {
        os << " " << std::any_cast<std::size_t>(student.avg) << "\t\t|";
    }

    if (student.debt.type() == typeid(std::nullptr_t)) {
        os << " null\t\t|" << std::endl;
    } else if (student.debt.type() == typeid(std::string)) {
        os << " " << std::any_cast<std::string>(student.debt) << "\t\t|" <<  std::endl;
    } else {
        os
                << " " << std::any_cast<std::vector<std::string> >(student.debt).size()
                << " items\t|" << std::endl;
    }
}

void print(const std::vector<Student>& students, std::ostream& os) {
    std::cout << "| name          | group     | avg   | debt      |" << std::endl;
    std::cout << "|---------------|-----------|-------|-----------|" << std::endl;
    for (auto const& student : students) {
        print(student, os);
        std::cout << "|---------------|-----------|-------|-----------|" << std::endl;
    }
}

int main() {
    std::string jsonPath;
    jsonPath = "/Users/pvelp/students.json";
//    if (argc < 1){
//        std::cout << "Не передали путь к файлу" << std::endl;
//    } else {
//        jsonPath = argv[0];
//    }
//...
    std::ifstream file{jsonPath};
    if (!file) {
        throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    std::vector<Student> students;
    for (auto const& item : data.at("items")) {
        Student student;
        from_json(item, student);
        students.push_back(student);
    }
    //...
    print(students, std::cout);
}