#include <student.hpp>
#include <fstream>

using nlohmann::json;


void print(const Student& student, std::ostream& os) {
    //...
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