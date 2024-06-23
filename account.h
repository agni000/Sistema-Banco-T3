#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP

#include "client.h"

class ContaCorrente
{
protected:
    //attributes
    Client *m_client;
    std::string m_name;
    float m_balance;
    std::string m_description;

public:
    //constructors and destructor
    ContaCorrente(Client *client, float balance = 0) : m_client(client), m_balance(balance) {
        m_name = m_client->getName();
        m_description = "Conta corrente";
    };
    //getters and setters
    void UpdateClient(Client *client) { m_client = client;}
    std::string getDescription() { return m_description;};
    bool Deposit(float value);
    bool operator +=(float value) { return Deposit(value); };
    bool Withdraw(float value);
    bool operator -=(float value) { return Withdraw(value); };
    bool Transfer(ContaCorrente &account, float value);

    //transfer all
    bool operator >> (ContaCorrente &account);
    string GetClientInfo() {
        if (m_client) {
            return m_name;
        } else {
            return "Cliente não associado";
        }
    }

    virtual string getAllInfo();
};

class ContaEspecial : public ContaCorrente
{
protected:
    float m_limit;

public:
    //constructors and destructor
    ContaEspecial(Client *client, float balance = 0, float limit = 0) : ContaCorrente(client, balance), m_limit(limit) {
        m_description = "Conta especial";
    };

    //getters and setters
    bool Withdraw(float value);
    bool Transfer(ContaCorrente &account, float value);
};

class ContaMaster : public ContaCorrente
{
protected:
    float m_limit;
    float m_bitcoin;
public:
    //constructor
    ContaMaster(Client *client, float balance = 0, float limit = 0, float bitcoin = 0) : ContaCorrente(client, balance), m_limit(limit), m_bitcoin(bitcoin) {
        m_description = "Conta Master";
    };
};

#endif
