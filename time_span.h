#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <string>
using namespace std;
class TimeSpan
{
    private:
        int hours_;
        int minutes_;
        int seconds_;
    
    public:
        //Constructors
       // TimeSpan();
        TimeSpan(float hr, float min, float sec);
        TimeSpan(float min, float sec);
        TimeSpan(float sec);
         TimeSpan();

        
        //Getters and setters
        int hours() const;
        int minutes() const;
        int seconds() const;
        void set_time(int hr, int min, int sec);

        void convert(const float hr, const float min, const float sec);
        //Overloads for arithmetic operations
        
        TimeSpan operator-(const TimeSpan& timspn_obj) const;
        TimeSpan& operator-=(const TimeSpan& timspn_obj);
        TimeSpan operator+(const TimeSpan& timspn_obj) const;
        TimeSpan& operator+=(const TimeSpan& timspn_obj);

         //Overloads for comparison
         bool operator==(const TimeSpan& timspn_obj) const;
         bool operator!=(const TimeSpan& timspn_obj) const;
         bool operator<(const TimeSpan& timspn_obj) const;
         bool operator<=(const TimeSpan& timspn_obj) const;
         bool operator>(const TimeSpan&  timspn_obj) const;
         bool operator>=(const TimeSpan& timspn_obj) const;

        friend ostream& operator<<(ostream& stream, const TimeSpan& rat);
        friend istream& operator>>(istream& stream, TimeSpan& rat);
};      

#endif