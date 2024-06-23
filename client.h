#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

using namespace std;

class Client
{
private:
    string m_name;
    string m_address;
    string m_job;
    float m_income;

public:
    Client(string name, string address,string job, float income = 0) : m_name(name), m_address(address), m_job(job), m_income(income) {};

    //getters and setters
    void update(string name, string address,string job, float income);
    string getName() {return m_name;};
    string getaAddress() {return m_address;};
    string getJob() {return m_job;};
    float getIncome() {return m_income;};
    string GetInformation();
};

#endif
