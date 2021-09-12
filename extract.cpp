#include <iostream>
#include <cwctype>
#include <fstream>
#include "extract.h"

void Person::setNumber(std::string data)
{
    this->phnumber = data;
}
void Person::setFname(std::string data)
{
    this->fname = data;
}
void Person::setLname(std::string data)
{
    this->lname = data;
}
void Person::setGender(std::string data)
{
    this->gender = data;
}
void Person::setCity(std::string data)
{
    this->city = data;
}
void Person::setRelationship(std::string data)
{
    this->rel_status = data;
}
void Person::setFbid(std::string data)
{
    this->fbid = data;
}
void Person::setHometown(std::string data)
{
    this->hometown = data;
}

std::string Person::getNumber()
{
    return this->phnumber;
}
std::string Person::getFname()
{
    return this->fname;
}
std::string Person::getLname()
{
    return this->lname;
}
std::string Person::getGender()
{
    return this->gender;
}
std::string Person::getCity()
{
    return this->city;
}
std::string Person::getRelationship()
{
    return this->rel_status;
}
std::string Person::getWork()
{
    return this->occupation;
}
std::string Person::getHometown()
{
    return this->hometown;
}
std::string Person::getFbid()
{
    return this->fbid;
}

Person FB::makePerson(std::string line)
{
    Person person;

    std::string tmp{};
    std::string data[9]{};

    int column{};

    for (auto &letter : line)
    {
        if (column == 9)
            break;

        if (letter != ':')
            data[column] += tolower(letter);

        else
            column++;
    }
    person.setNumber(data[0]);
    person.setFbid(data[1]);
    person.setFname(data[2]);
    person.setLname(data[3]);
    person.setGender(data[4]);
    person.setCity(data[5]);
    person.setHometown(data[6]);
    person.setRelationship(data[7]);
    person.setCity((data[8] + " " + person.getCity()));

    return person;
}

bool FB::compareDetails(std::string a, std::string b)
{

    if (a == "" || b == "")
        return 0;

    size_t found = a.find(b);
    if (found == std::string::npos)
        return 1;

    return 0;
}
std::vector<Person> FB::search()
{
    std::vector<Person> tmp{};

    for (auto &person : people)
    {
        bool flag{};
        if (phnumber != "" && compareDetails(person.getNumber(), phnumber))
            flag = 0;
        if (fname != "" && compareDetails(person.getFname(), fname))
            flag = 0;
        if (lname != "" && compareDetails(person.getLname(), lname))
            flag = 0;
        if (gender != "" && !(person.getGender() == gender))
            flag = 0;
        if (city != "" && compareDetails(person.getCity(), city))
            flag = 0;
        if (rel_status != "" && !(person.getRelationship() == rel_status))
            flag = 0;
        if (occupation != "" && compareDetails(person.getWork(), occupation))
            flag = 0;

        if (flag)
            tmp.push_back(person);
    }

    return tmp;
}

void displayPeople(std::vector<Person> people)
{
    if (!people.size())
    {
        std::cout << " No records found\n";
        return;
    }

    system("clear");
    for (auto &person : people)
    {

        std::cout << person.getFname() << " " << person.getLname();

        if (person.getRelationship() != "" && person.getGender() != "")
            std::cout << " is a " << person.getRelationship() << " " << person.getGender();

        else if (person.getRelationship() != "" && person.getGender() == "")
            std::cout << " is " << person.getRelationship();

        else if (person.getRelationship() == "" && person.getGender() != "")
            std::cout << " is a " << person.getGender();

        if (person.getCity().size() > 2)
            std::cout << " living in " << person.getCity();

        if (person.getWork() != "")
            std::cout << " working as a " << person.getWork();

        std::cout << " with phone number: " << person.getNumber();

        std::cout << std::endl
                  << std::endl;
    }
}

void FB::initialize(std::string path)
{
    std::ifstream infile(path);

    if (!infile.is_open())
    {
        std::cout << "Cannot open file, check filename or path again\nExiting now\n";
        return;
    }

    for (std::string line; getline(infile, line);)
        people.push_back(makePerson(line));

    infile.close();

    do
    {
        std::string ch;

        system("clear");
        std::cout << "Would you like to search the records (Y/N): ";
        std::cin >> ch;

        if (ch == "n" || ch == "N")
            break;

        search();

    } while (1);
}
