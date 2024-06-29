# Open Closed Principle (OCP)

The Open/Closed Principle states that software entities (classes, modules, functions, etc) should be open for extension but closed for modification. This means that the behavior of a module can be extended without modifying its source code.

## Why Need OCP:

- **Maintainability**: When new functionality is required, it can be added by extending existing code rather than modifying it. This minimized the risk of introducing new bugs into existing, stable code.

- **Scalability**: Systems adhering to OCP can grow and adapt to new requirements with less effort.

- **Flexibility**: By using abstractions, we can design systems that are flexible and can incorporate new functionality with minimal changes.

- **Reusability**: Classes that follow OCP can be more easily reused across different projects or components because they are designed to be extended rather than changed.

## Without OCP

```cpp
class Product
{
    public:
        double m_price;
        string m_name;

        Product(const string name, double price)
            :m_name(name), m_price(price)
            {}
};

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
};

int main()
{

    Product laptop("Dell Laptop", 1000);
    DiscountManager dm;

    cout<<"Original Price: "<<laptop.m_price<<endl;
    cout<<"Percent Discount Price: "<<dm.applyDiscount(laptop, DiscountType::PERCENTAGE)<<endl;
    cout<<"Fixed Discount Price: "<<dm.applyDiscount(laptop, DiscountType::FIXED)<<endl;

    return 0;
}
```

## With OCP

```cpp

class Product
{
    public:
        double m_price;
        string m_name;

        Product(const string name, double price)
            :m_name(name), m_price(price)
            {}
};

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

    PercentDiscount perDisc;
    FixedDiscount fixedDisc;
    SeasonDiscount seasDisc;

    cout<<"Original Price: "<<laptop.m_price<<endl;
    cout<<"Percent Discount Price: "<< perDisc.applyDiscount(laptop) <<endl;
    cout<<"Fixed Discount Price: "<< fixedDisc.applyDiscount (laptop) <<endl;
    cout<<"Seasoned Discount Price: "<< seasDisc.applyDiscount(laptop) <<endl;

    return 0;
}

```

## Benefits of OCP

- **Extendability**: Adding a new Discount type like SeasonedDiscount require only creating a new class that inherits from Discount and implement applyDiscount method. No changes to existing code are needed.

- **Maintaninability**: This existing discount classes remain unchanged, reducing the risk of introducing new bugs when adding new discount types.

- **Flexible** : Easy to accommodate new discount types without modification to the core logic.
