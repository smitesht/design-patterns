#include <iostream>
#include <string>

using namespace std;

/*class LibraryUser
{
    public:
        virtual void borrowBook() = 0;
        virtual void returnBook() = 0;
        virtual void catelogBook() = 0;
        virtual void manageInventory() = 0;
        virtual ~LibraryUser() = default;
};

class Librarian : public LibraryUser
{
    public:
        void borrowBook() override{
            cout<<"Librarian borrow books"<<endl;
        }

        void returnBook() override {
            cout<<"Librarian Return books" <<endl;
        }

        void catelogBook() override{
            cout<<"Librarian manage catelog" <<endl;
        }

        void manageInventory() override {
            cout << "Librarian manage Inventory"<<endl;
        }
};

class Member : public LibraryUser{
    public:
        void borrowBook() override{
            cout<<"Member borrow books"<<endl;
        }

        void returnBook() override {
            cout<<"Member Return books" <<endl;
        }

        void catelogBook() override{
            // Member cannot maintain catelog
        }

        void manageInventory() override {
            // Member cannot manage inventory
        }
};*/

class Borrower{
    public:
        virtual void borrowBook() = 0;
        virtual void returnBook() = 0;
        virtual ~Borrower() = default;
};

class Cataloger{
    public:
        virtual void catalogBook() = 0;
        virtual ~Cataloger() = default;
};

class InventoryManager{
    public: 
        virtual void manageInventory() = 0;
        virtual ~InventoryManager() = default;
};

class Librarian : public Borrower, public Cataloger, public InventoryManager{
    public:
        void borrowBook() override{
            cout<<"Librarian borrow books"<<endl;
        }

        void returnBook() override {
            cout<<"Librarian Return books" <<endl;
        }

        void catalogBook() override{
            cout<<"Librarian manage catelog" <<endl;
        }

        void manageInventory() override {
            cout << "Librarian manage Inventory"<<endl;
        }
};

class Member : public Borrower{
    public:
        void borrowBook() override{
            cout<<"Member borrow books"<<endl;
        }

        void returnBook() override {
            cout<<"Member Return books" <<endl;
        }

};


int main()
{
    /*LibraryUser *user = new Librarian();

    user->borrowBook();
    user->manageInventory();

    LibraryUser *member = new Member();
    member->borrowBook();
    member->manageInventory(); // This methiod is not relevent for Member

    delete user;
    delete member;*/

    InventoryManager *inv_mgr = new Librarian();
    inv_mgr->manageInventory();
    delete inv_mgr;

    Borrower *user1 = new Librarian();
    user1->borrowBook();
    delete user1;

    Borrower *member = new Member();
    member->borrowBook();
    member->returnBook();
    delete member;

    Cataloger *cat = new Librarian();
    cat->catalogBook();
    delete cat;

    return 0;
}