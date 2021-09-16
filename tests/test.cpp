// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
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
    for (auto const& item : data.at("items")) {
        Student student;
        from_json(item, student);
        students.push_back(student);
    }
    size_t val1 = data.at("_meta").at("count");
    size_t val2 = students.size();
    EXPECT_EQ(val1, val2);
}
