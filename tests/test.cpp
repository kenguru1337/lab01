// Copyright 2020 Your Name <your_email>

#include "student.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Meta, Test2){
    std::string jsonPath;
    jsonPath = "/Users/pvelp/students.json";
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> students;
    students = read_file(data);
    size_t val1 = data.at("_meta").at("count");
    size_t val2 = students.size();
    EXPECT_EQ(val1, val2);
}


TEST(Table, Test3){
    std::string tmp = R"(| name          | group     | avg   | debt      |
|---------------|-----------|-------|-----------|
| Ivanov Petr	| 1			| 4.25	| null		|
|---------------|-----------|-------|-----------|
| Sidorov Ivan	| 31 group	| 4		| C++		|
|---------------|-----------|-------|-----------|
| Pertov Nikita	| IU8-31	| 3.33	| 3 items	|
|---------------|-----------|-------|-----------|
)";

    std::string jsonPath = "/Users/pvelp/students.json";
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> students;
    students = read_file(data);
    std::stringstream os;
    print(students, os);
    EXPECT_EQ(tmp, os.str());
}
