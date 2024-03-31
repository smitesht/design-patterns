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

class DBFactoryClass
{
public: 

    virtual IDatabase* CreateObject() = 0;
    virtual ~DBFactoryClass() {};
};

class MySQLFactoryClass : public DBFactoryClass
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

class SQLServerFactoryClass : public DBFactoryClass
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

class MongoDbFactoryClass : public DBFactoryClass
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

class Neo4jGraphDBFactoryClass : public DBFactoryClass
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
    DBFactoryClass* pFactory = nullptr;
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
