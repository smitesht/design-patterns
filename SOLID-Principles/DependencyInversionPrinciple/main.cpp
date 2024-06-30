#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*
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
};*/


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

    //NotificationService service(&emailSender, &smsSender);

   //service.send("Hello Client");

    NotificationService service;
    service.addSender(emailSender);
    service.addSender(smsSender);

    service.send("Hello Client");
   
    return 0;
}