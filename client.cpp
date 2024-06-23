#ifndef CLIENT_CPP
#define CLIENT_CPP

#include "client.h"
#include <sstream>

string Client::GetInformation()
{
    stringstream stt;
    stt << "Cliente: " << m_name << "\nProfissao: " << m_job << "\nSalario: " << m_income << "\n";

    return stt.str();
}

void Client::update(string name, string address,string job, float income) {
    m_name = name;
    m_address = address;
    m_job = job;
    m_income = income;
}


#endif // CLIENT_CPP
