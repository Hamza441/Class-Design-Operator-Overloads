#include <cmath>
#include "time_span.h"
#include <iostream>

using namespace std;

TimeSpan::TimeSpan()
{
    hours_ =0;
    minutes_ = 0;
    seconds_ = 0;
}

TimeSpan::TimeSpan(float hr, float min, float sec)
{
    convert(hr, min, sec);  
}

TimeSpan::TimeSpan(float min, float sec)
{
    convert(0, min, sec); 
}

TimeSpan::TimeSpan(float sec)
{

    convert(0, 0, sec); 
   
}

int TimeSpan::hours() const
{
    return  hours_;
}

int TimeSpan::minutes() const
{
    return minutes_;
}

int TimeSpan::seconds()const
{
    return seconds_;
}

 void TimeSpan::set_time(int hr, int min, int sec)
{

          convert(hr, min, sec);
}
// converts  input to hours, minutes and seconds
void TimeSpan::convert(const float hr, const float min, const float sec)
{
    int all_seconds_ = (hr*3600) + (min * 60);
     
    if (sec < 0)
    {
        all_seconds_ += 60 - sec;
    }
    else
    {
        all_seconds_ += sec;
    }
        hours_ =  all_seconds_/3600;
        minutes_ = all_seconds_%3600/60;
        seconds_ = (all_seconds_%3600)%60;
}

 //operator overloading function
TimeSpan TimeSpan:: operator+(const TimeSpan& timspn_obj) const
{
   TimeSpan timespan;
   timespan.hours_ = hours_ + timspn_obj.hours_;
   timespan.minutes_ = minutes_ + timspn_obj.minutes_;
   timespan.seconds_ = seconds_ + timspn_obj.seconds_;
  
   if(timespan.seconds_ > 60){
       timespan.seconds_ -= 60;
       timespan.minutes_ += 1;
   }
   if(timespan.minutes_ > 60){
       timespan.minutes_ -= 60;
       timespan.hours_ += 1;
   }
  
   return timespan;
}

TimeSpan TimeSpan::operator-(const TimeSpan& obj) const
{
   TimeSpan timespan;
   timespan.hours_ = hours_ - obj.hours_;
   timespan.minutes_ = minutes_ - obj.minutes_;
   timespan.seconds_ = seconds_ - obj.seconds_;
  
   if(timespan.seconds_ < -60){
       timespan.seconds_ += 60;
       timespan.minutes_ -= 1;
   }
   if(timespan.minutes_ < -60){
       timespan.minutes_ += 60;
       timespan.hours_ -= 1;
   }
   return timespan;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& timspn_obj)
{
   hours_ = hours_ + timspn_obj.hours_;
   minutes_ = minutes_ + timspn_obj.minutes_;
   seconds_ = seconds_ + timspn_obj.seconds_;
  
   if(seconds_ > 60){
       seconds_ -= 60;
       minutes_ += 1;
   }
   if(minutes_ > 60){
       minutes_ -= 60;
       hours_ += 1;
   }
   return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& timspn_obj)
{
   hours_ = hours_ - timspn_obj.hours_;
   minutes_ = minutes_ - timspn_obj.minutes_;
   seconds_ = seconds_ - timspn_obj.seconds_;
  
   if(seconds_ < -60){
       seconds_ += 60;
       minutes_ -= 1;
   }
   if(minutes_ < -60){
       minutes_ += 60;
       hours_ -= 1;
   }
   return *this;
}

//Overloads for comparison
bool TimeSpan::operator==(const TimeSpan& timspn_obj) const
{
     return (hours_ == timspn_obj.hours_ && minutes_ == timspn_obj.minutes_ && timspn_obj.seconds_);
}

bool TimeSpan::operator!=(const TimeSpan& timspn_obj) const
{
     return !(hours_ == timspn_obj.hours_ && minutes_ == timspn_obj.minutes_ && seconds_ == timspn_obj.seconds_);
}

bool TimeSpan::operator<(const TimeSpan& timspn_obj) const
{
return (hours_ < timspn_obj.hours_ && minutes_ < timspn_obj.minutes_ < timspn_obj.seconds_);
} 

bool TimeSpan::operator<=(const TimeSpan& timspn_obj) const
{
    return (hours_ <= timspn_obj.hours_ && minutes_ <= timspn_obj.minutes_ <= timspn_obj.seconds_);
}

bool TimeSpan::operator>(const TimeSpan&  timspn_obj) const
{
    return (hours_ > timspn_obj.hours_ && minutes_ > timspn_obj.minutes_ > timspn_obj.seconds_);
}

bool TimeSpan::operator>=(const TimeSpan&  timspn_obj) const
{
    return (hours_ >= timspn_obj.hours_ && minutes_ >= timspn_obj.minutes_ >= timspn_obj.seconds_);
}


ostream& operator<<(ostream& stream, const TimeSpan& timspn_obj)
{
     stream << "Hours: "<<timspn_obj.hours()<<", Minutes: "<<timspn_obj.minutes()
     << ", Seconds: "<<timspn_obj.seconds();
     return stream;
}

istream& operator>>(istream& stream, TimeSpan& timspn_obj)
{
    float hr, min, sec;
    stream >> hr >> min >> sec;
    timspn_obj.set_time(hr,min,sec);
    return stream; 
}