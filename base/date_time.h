#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include <string>
#include <boost/operators.hpp>

class TimeEpoch : public boost::less_than_comparable<TimeEpoch>
{
public:
	TimeEpoch(int64_t micro_second = 0);
	static TimeEpoch now();
	void addTime(int64_t micro_second);
	int64_t second();
	int64_t fraction(); //number after second
	int64_t toInt();
	struct tm toTM();
	void toTM(struct tm *tm); //thread safe
	std::string toStandardString(bool withMS = false);
public:
	static int64_t MsPerDay;
	static int64_t MsPerHour;
	static int64_t MsPerMinute;
	static int64_t MsPerSecond;
private:
	int64_t _ms; //micro second
};

inline bool operator<(TimeEpoch lhs, TimeEpoch rhs)
{
	return lhs.toInt() < rhs.toInt();
}
inline bool operator==(TimeEpoch lhs, TimeEpoch rhs)
{
	return lhs.toInt() == rhs.toInt();
}

class DateTime
{
public:
	DateTime(TimeEpoch timestamp);
	static DateTime now();
	int getDay();
	int getMonth();
	int getYear();
	int getHour();
	int getMinute();
	int getSecond();
	TimeEpoch toTimeEpoch();
	std::string toString();
	std::string toStandardString();//without micro second.
private:
	TimeEpoch _tp;
	struct tm _tm;
	std::string _str;
	std::string _sstr;
};



#endif
