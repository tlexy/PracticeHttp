#include "date_time.h"
#include <boost/lexical_cast.hpp>

uint32_t TimeEpoch::MsPerDay = 24*60*60*1000000;
uint32_t TimeEpoch::MsPerHour = 60*60*1000000;
uint32_t TimeEpoch::MsPerMinute = 60*1000000;
uint32_t TimeEpoch::MsPerSecond = 1000000;

TimeEpoch::TimeEpoch(uint64_t micro)
	:_ms(micro)
{
}

TimeEpoch TimeEpoch::now()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return TimeEpoch(MsPerSecond * tv.tv_sec + tv.tv_usec);
}

uint64_t TimeEpoch::second()
{
	return _ms / MsPerSecond;
}

uint64_t TimeEpoch::fraction()
{
	return _ms % MsPerSecond;
}

void TimeEpoch::addTime(uint64_t micro)
{
	_ms += micro;
}

uint64_t TimeEpoch::toInt()
{
	return _ms;
}

struct tm TimeEpoch::toTM()
{
	time_t time = _ms / MsPerSecond;
	struct tm *tm_ = gmtime(&time);
	return *tm_;
}

void TimeEpoch::toTM(struct tm *tm)
{
	time_t time = _ms / MsPerSecond;
	struct tm *tm_ = gmtime_r(&time, tm);
}

std::string TimeEpoch::toStandardString(bool withMS)
{
	struct tm tm_;
	toTM(&tm_);

	std::string str;
	str += boost::lexical_cast<std::string>(tm_.tm_hour);
	str.append(":");
	str += boost::lexical_cast<std::string>(tm_.tm_min);
	str.append(":");
	str += boost::lexical_cast<std::string>(tm_.tm_sec);
	if (withMS)
	{
		str.append("::");
		str += boost::lexical_cast<std::string>(fraction());
	}
	return str;
}

///////////////////////////////////////////////////////////

DateTime::DateTime(TimeEpoch timestamp)
	:_tp(timestamp)
{
	_tp.toTM(&_tm);

	_str += boost::lexical_cast<std::string>(_tm.tm_year + 1900);
	_str.append("-");
	_str += boost::lexical_cast<std::string>(_tm.tm_mon + 1);
	_str.append("-");
	_str += boost::lexical_cast<std::string>(_tm.tm_mday);
	_str.append("T");
	_str += boost::lexical_cast<std::string>(_tm.tm_hour);
	_str.append(":");
	_str += boost::lexical_cast<std::string>(_tm.tm_min);
	_str.append(":");
	_str += boost::lexical_cast<std::string>(_tm.tm_sec);

	_sstr = _str;
	_sstr.append("::");
	_sstr += boost::lexical_cast<std::string>(_tp.fraction());
}

DateTime DateTime::now()
{
	TimeEpoch te = TimeEpoch::now();
	return DateTime(te);
}

int DateTime::getDay()
{
	return _tm.tm_mday;
}

int DateTime::getMonth()
{
	return _tm.tm_mon + 1;
}

int DateTime::getYear()
{
	return _tm.tm_year + 1900;
}

int DateTime::getHour()
{
	return _tm.tm_hour;
}

int DateTime::getMinute()
{
	return _tm.tm_min;
}

int DateTime::getSecond()
{
	return _tm.tm_sec;
}

TimeEpoch DateTime::toTimeEpoch()
{
	return _tp;
}

std::string DateTime::toString()
{
	return _sstr;	
}

std::string DateTime::toStandardString()
{
	return _str;
}











