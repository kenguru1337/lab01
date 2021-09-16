// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_
#include <iostream>
#include <any>
#include <nlohmann/json.hpp>
#include <string>


using nlohmann::json;

struct Student{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

auto get_name(const json& j) -> std::string;

auto get_debt(const json& j) -> std::any;

auto get_avg(const json& j) -> std::any;

auto get_group(const json& j) -> std::any;

void from_json(const json& j, Student& s);



#endif // INCLUDE_STUDENT_HPP_
