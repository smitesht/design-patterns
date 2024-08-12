# Dependency Inversion Principle (DIP)

Dependency Inversion Principle state that high-level modules should not depend on low-level modules. Both should depend on abstractions like interface. Additionally, abstraction should not depend on details, details should depend on abstractions.

## Why Need DIP:

- **Decoupling**: DIP promotes decoupling of components. making the system more modular and easier to maintain.
- **Flexibility**: It allows for easy swapping of implementations without affecting the high-level module.
- **Testability**: By depending on abstractions, high-level modules can be easily tested using mock implementations.
- **Maintaninability**: Changes in low-level modules do not impact high-level modules, leading to a more maintainable system.
- **Reusability**: Promotes reusability of high-level modules across different projects by relying on abstract interfaces.

## Without DIP

In this approach, NotificationSender directly depends on EmailSender or SmsSender rather than abstraction. This creates a problem when we want to change or add a new sender.

```cpp

class EmailSender{

    public:
        void sendEmail(const string &message){
            cout<<"Sending email: "<< message << endl;
        }
};

class SmsSender{
    public:
        void sendSms(const string& message){
            cout<<"Sending SMS: "<<message<<endl;
        }
};

class NotificationService{

    private:
        EmailSender *m_emailSender;
        SmsSender *m_smsSender;

    public:

        NotificationService(EmailSender* emailSender, SmsSender* smsSender)
           :m_emailSender(emailSender), m_smsSender(smsSender)
        { }

        void send(const string message){
            m_emailSender->sendEmail(message);
            m_smsSender->sendSms(message);
        }
};


int main()
{
    EmailSender emailSender;
    SmsSender smsSender;

    NotificationService service(&emailSender, &smsSender);
    service.send("Hello Client");

    return 0;
}

```

## With DIP

In this example, NotificationService depends on the abstraction (interface ) rather than details (concrete class)

```cpp

class NotificationSender
{
    public:
        virtual void send(string& message) = 0;
        virtual ~NotificationSender() = default;
};

class EmailSender : public NotificationSender{

    public:
        void send(string &message) override{
            cout<< "Sending Email: "<<message <<endl;
        }
};

class SmsSender : public NotificationSender{

    public:
        void send(string &message) override{
            cout<< "Sending SMS: "<<message<<endl;
        }
};

class NotificationService{

    private:
        vector<shared_ptr<NotificationSender>> m_list;

    public:

        void addSender(NotificationSender *sender){

            shared_ptr<NotificationSender> s{sender};

            m_list.push_back(s);
        }

        void send(string msg){

            for(auto p: m_list){
                p->send(msg);
            }
        }

};

int main()
{
    NotificationSender *emailSender = new  EmailSender();
    NotificationSender *smsSender = new SmsSender();

    NotificationService service;
    service.addSender(emailSender);
    service.addSender(smsSender);

    service.send("Hello Client");

    return 0;
}

```
