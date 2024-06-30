# Interface Segregation Principle (ISP)

The interface segregation principle state that no client should be forced to depend on methods it does not use. Instead of creating large general purpose interfaces, create smaller, more specific interfaces so that clients uses the methods which are relevent to them.

## Why Need ISP

- **Client Simplicity**: Clients should not be burdened with methods they don't need, making the code easier to understand and use.
- **Maintanability**: Changes in the interface impact fewer clients, reducing the risk of introducing bugs and making the codebase easier to maintain.
- **Flexible**: Smaller, more focused interfaces allow for more flexible and moduler designs, enabling clients to use only the functionality they need.
- **Separation Of Concerns**: It encourages a clear separation of concerns, ensuring that interfaces are cohesive and focused on specific tasks.

## Without ISP

```cpp

class LibraryUser
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
};

int main()
{
    LibraryUser *user = new Librarian();

    user->borrowBook();
    user->manageInventory();

    LibraryUser *member = new Member();
    member->borrowBook();
    member->manageInventory(); // This methiod is not relevent for Member

    delete user;
    delete member;

    return 0;
}

```

## With ISP

```cpp
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
```
