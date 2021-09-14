#include <student.hpp>
#include <fstream>

using nlohmann::json;


void print(const Student& student, std::ostream& os) {
    //... ??
    if (student.name.empty()){
        os << "null";
    } else {
        os << student.name;
    }

    if (student.avg.type() == typeid(std::nullptr_t)){
        os << "null";
    } else if (student.avg.type() == typeid(std::string)){
        os << std::any_cast<std::string>(student.avg);
    } else if (student.avg.type() == typeid(std::double_t)){
        os << std::any_cast<std::double_t>(student.avg);
    } else {
        os << std::any_cast<std::size_t>(student.avg);
    }

    if (student.group.type() == typeid(std::nullptr_t)){
        os << "null";
    } else if (student.group.type() == typeid(std::string)){
        os << std::any_cast<std::string>(student.group);
    } else {
        os << std::any_cast<std::size_t>(student.group)
        << " group";
    }

    if (student.debt.type() == typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type() == typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
                << std::any_cast<std::vector<std::string> >(student.debt).size()
                << " items";
    }
}

void print(const std::vector<Student>& students, std::ostream& os) {

    //...
    for (auto const& student : students) {
        print(student, os);
    }
}

int main(int argc, char* argv[]) {
    std::string jsonPath;
    if (argc < 1){
        std::cout << "Не передали путь к файлу" << std::endl;
    } else {
        jsonPath = argv[1];
    }
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