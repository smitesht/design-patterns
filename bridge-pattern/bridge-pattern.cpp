#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Implementor
struct IPaymentGateway
{
    virtual string process(double amount) = 0;
    virtual ~IPaymentGateway() {}
};

struct INetBankingPayment : public IPaymentGateway {
    virtual ~INetBankingPayment() {}
};

class HDFCBakPayment : public INetBankingPayment {
public:
    string process(double amount) override {
        string transactionId = "HDFC00001";
        cout<< "HDFC Net Banking Payment : " << std::to_string(amount) << endl;
        return transactionId;
    }

    ~HDFCBakPayment(){}
};


struct ICreditDebitCardPayment : public IPaymentGateway {
    virtual ~ICreditDebitCardPayment() {}
};


class ICICIBankCreditCardPayment : public ICreditDebitCardPayment {
private:
    // string credit_card_number
public:
    string process(double amount) override {        
        string transactionId = "ICICICC00001";
        cout << "ICICI Bank Credit Card Payment :" << std::to_string(amount) << endl;
        return transactionId;
    }

    ~ICICIBankCreditCardPayment() {}
};

class PayPalGateway : public IPaymentGateway {
public:
    string process(double amount) override {        
        string transactionId = "PAYPAL00001";
        cout << "PayPal Payment : " << std::to_string(amount) << endl;
        return transactionId;
    }

    ~PayPalGateway() {}
};

struct UPIPayment : public IPaymentGateway {
    virtual ~UPIPayment() {}
};

class BharatPayUPI : public UPIPayment {
public:
    string process(double amount) override {        
        string transactionId = "BHARAT00001";
        cout << "Bharat UPI Payment : " << std::to_string(amount) << endl;
        return transactionId;
    }

    ~BharatPayUPI() {}
};

class PhonePePayUPI : public UPIPayment {
public:
    string process(double amount) override {       
        string transactionId = "PHONEPAY00001";
        cout << "PhonePe UPI Payment : " << std::to_string(amount)<<endl;
        return transactionId;
    }

    ~PhonePePayUPI() {}
};

// Abstraction
class PaymentProcessor {
protected:
    shared_ptr<IPaymentGateway> _paymentGateway;

public:
    PaymentProcessor(shared_ptr<IPaymentGateway> paymentGateway)
        :_paymentGateway(paymentGateway)
    {}
    
    virtual void processPayment(double amount) {
        string transactionID = _paymentGateway->process(amount);
        cout << "Transaction ID: " << transactionID << endl;
    }
    virtual ~PaymentProcessor(){}
};

class HDFCBakPaymentProcessor : public PaymentProcessor {
public:
    HDFCBakPaymentProcessor(shared_ptr<IPaymentGateway> paymentGateway)
        :PaymentProcessor(paymentGateway)
    {}

    void processPayment(double amount) override {
        PaymentProcessor::processPayment(amount);
    }
};

class ICICIBankCreditCardPaymentProcessor : public PaymentProcessor {
public:
    ICICIBankCreditCardPaymentProcessor(shared_ptr<IPaymentGateway> paymentGateway)
        :PaymentProcessor(paymentGateway)
    {}

    void processPayment(double amount) override {
        PaymentProcessor::processPayment(amount);
    }
};

class PayPalPaymentProcessor : public PaymentProcessor {
public:
    PayPalPaymentProcessor(shared_ptr<IPaymentGateway> paymentGateway)
        :PaymentProcessor(paymentGateway)
    {}

    void processPayment(double amount) override {
        PaymentProcessor::processPayment(amount);
    }
};

class BharatPayPaymentProcessor : public PaymentProcessor {
public:
    BharatPayPaymentProcessor(shared_ptr<IPaymentGateway> paymentGateway)
        :PaymentProcessor(paymentGateway)
    {}

    void processPayment(double amount) override {
        PaymentProcessor::processPayment(amount);
    }
};

int main()
{
    shared_ptr<IPaymentGateway> hdfcNetBankingPayGway = make_shared<HDFCBakPayment>();
    shared_ptr<IPaymentGateway> iciciCCPayGway = make_shared<ICICIBankCreditCardPayment>();
    shared_ptr<IPaymentGateway> paypalPayGway = make_shared<PayPalGateway>();
    shared_ptr<IPaymentGateway> bharatUPIPayGway = make_shared<BharatPayUPI>();

    shared_ptr<PaymentProcessor> paymentProcessor = make_shared<HDFCBakPaymentProcessor>(hdfcNetBankingPayGway);
    paymentProcessor->processPayment(200);

    paymentProcessor = make_shared<ICICIBankCreditCardPaymentProcessor>(iciciCCPayGway);
    paymentProcessor->processPayment(150);

    paymentProcessor = make_shared<PayPalPaymentProcessor>(paypalPayGway);
    paymentProcessor->processPayment(499);

    paymentProcessor = make_shared<BharatPayPaymentProcessor>(bharatUPIPayGway);
    paymentProcessor->processPayment(1100);

}