#include <iostream>
#include <string>

using namespace std;


struct IDatabase
{
    virtual string GetConnectionString() = 0;
    virtual ~IDatabase() {}
};

class MySQLDatabse : public IDatabase
{
public:

    string GetConnectionString()
    {
        return "MySQL DB ConnectionString";
    }

    ~MySQLDatabse() {}

};

class SQLServerDatabse : public IDatabase
{
public:
    string GetConnectionString()
    {
        return "SQLServer DB ConnectionString";
    }

    ~SQLServerDatabse() {}
};

class MongoDB : public IDatabase
{
public:
    string GetConnectionString()
    {
        return "MongoDB ConnectionString";
    }

    ~MongoDB() {}
};

class Neo4jGraphDB : public IDatabase
{
public:
    string GetConnectionString()
    {
        return "Neo4jGraph DB ConnectionString";
    }
    ~Neo4jGraphDB() {}
};

class FactoryClass
{
public: 

    virtual IDatabase* CreateObject() = 0;
    virtual ~FactoryClass() {};
};

class MySQLFactoryClass : public FactoryClass
{

public:
    IDatabase* CreateObject()
    {
        return new MySQLDatabse();
    }

    ~MySQLFactoryClass()
    {
        
    }
};

class SQLServerFactoryClass : public FactoryClass
{
public:
    IDatabase* CreateObject()
    {
        return new SQLServerDatabse();
    }

    ~SQLServerFactoryClass()
    {

    }
};

class MongoDbFactoryClass : public FactoryClass
{
public:
    IDatabase* CreateObject()
    {
        return new MongoDB();
    }

    ~MongoDbFactoryClass()
    {

    }
};

class Neo4jGraphDBFactoryClass : public FactoryClass
{
public:
    IDatabase* CreateObject()
    {
        return new Neo4jGraphDB();
    }

    ~Neo4jGraphDBFactoryClass()
    {

    }
};

int main()
{
    FactoryClass* pFactory = nullptr;
    IDatabase* pDB;

    pFactory = new MySQLFactoryClass();
    pDB = pFactory->CreateObject();
    cout << pDB->GetConnectionString() << endl;

    pFactory = new Neo4jGraphDBFactoryClass();
    pDB = pFactory->CreateObject();
    cout << pDB->GetConnectionString() << endl;

    pFactory = new MongoDbFactoryClass();
    pDB = pFactory->CreateObject();
    cout << pDB->GetConnectionString() << endl;

    delete pDB;
    delete pFactory;
}