#include <iostream>
#include <string>

using namespace std;

class Product
{
    public:
        double m_price;
        string m_name;

        Product(const string name, double price)
            :m_name(name), m_price(price)
            {}
};

/*
enum DiscountType{
    PERCENTAGE = 0,
    FIXED
};

class DiscountManager{

    public:
        double applyDiscount(Product &product, DiscountType discountType )
        {
            if(discountType == DiscountType::PERCENTAGE){
                return product.m_price - (product.m_price * 0.10);
            }
            else if(discountType == DiscountType::FIXED){
                return product.m_price - 10;
            }

            return product.m_price;
        }
};*/


class Discount
{
    public:
        virtual double applyDiscount(const Product &product) = 0;
        virtual ~Discount() = default;
};

class PercentDiscount : public Discount{
    public:
        double applyDiscount(const Product& product) override{
            return product.m_price - (product.m_price * 0.05);
        }
};

class FixedDiscount : public Discount{
    public:
        double applyDiscount(const Product& product) override{
            return product.m_price - 10;
        }
};

class SeasonDiscount : public Discount{
    public:
        double applyDiscount(const Product& product) override{
            return product.m_price - (product.m_price * 0.10);
        }
};


int main()
{

    Product laptop("Dell Laptop", 1000);
    
    /*DiscountManager dm;
    cout<<"Original Price: "<<laptop.m_price<<endl;
    cout<<"Percent Discount Price: "<<dm.applyDiscount(laptop, DiscountType::PERCENTAGE)<<endl;
    cout<<"Fixed Discount Price: "<<dm.applyDiscount(laptop, DiscountType::FIXED)<<endl;*/

    PercentDiscount perDisc;
    FixedDiscount fixedDisc;
    SeasonDiscount seasDisc;

    cout<<"Original Price: "<<laptop.m_price<<endl;
    cout<<"Percent Discount Price: "<< perDisc.applyDiscount(laptop) <<endl;
    cout<<"Fixed Discount Price: "<< fixedDisc.applyDiscount (laptop) <<endl; 
    cout<<"Seasoned Discount Price: "<< seasDisc.applyDiscount(laptop) <<endl;

    return 0;
}