#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <string>
using namespace std;

class VendingBank
{
    private:
        int id_;
        double penny_;
        double nickel_;
        double dime_;
        double quarter_;
        double overall_entered_coins;
        double overall_vending_bank_money;
    
    public:
        //constructors
        VendingBank(); 
        VendingBank(int id); 
        VendingBank(int id, double overall_vendingBank_money_, double penn, double nick, double dime, double quarter);

        //getters and setters
        int get_id()const;
        double get_penny() const;
        double get_nickel()const;
        double get_dime()const;
        double get_quarter()const;

        //functions
        bool set_id(int id);
        bool set_overall_entered_coins( double penny, double nickel, double dim, double quarter);
        bool calculate_coins( double penny, double nickel, double dim, double quarter);
        bool RejectEnteredCoins(double penny, double nickel, double dim, double quarter);
        
        //operator overloading function
        VendingBank operator+(const VendingBank& vending) const;
        VendingBank& operator+=(const VendingBank& vending);
        VendingBank operator-(const VendingBank& vending) const;
        VendingBank& operator-=(const VendingBank& vending);

        //Overloads for comparison
        bool operator==(VendingBank& vending) const;
        bool operator!=(VendingBank& vending) const;
       
       friend ostream& operator<<(ostream& stream, const VendingBank& bank);
};

#endif