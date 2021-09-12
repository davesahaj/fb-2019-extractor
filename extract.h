#ifndef EXTRACT_H
#define EXTRACT_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

struct Person
{
private:
    std::string phnumber{""};
    std::string fbid{""};
    std::string fname{""};
    std::string lname{""};
    std::string gender{""};
    std::string city{""};
    std::string hometown{""};
    std::string rel_status{""};
    std::string occupation{""};

public:
    void setNumber(std::string data);
    void setFname(std::string data);
    void setFbid(std::string data);
    void setHometown(std::string data);
    void setLname(std::string data);
    void setGender(std::string data);
    void setCity(std::string data);
    void setRelationship(std::string data);
    void setWork(std::string data);

    std::string getNumber();
    std::string getFname();
    std::string getLname();
    std::string getHometown();
    std::string getFbid();
    std::string getGender();
    std::string getCity();
    std::string getRelationship();
    std::string getWork();
};

class FB
{
private:
    std::vector<Person> people;

    std::string phnumber{""};
    std::string fname{""};
    std::string lname{""};
    std::string gender{""};
    std::string city{""};
    std::string rel_status{""};
    std::string occupation{""};

    bool compareDetails(std::string a, std::string b);
    Person makePerson(std::string line);
    std::vector<Person> search();
    void displayPeople(std::vector<Person> people);

public:
    void initialize(std::string path);
};

#endif