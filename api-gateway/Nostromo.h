#pragma once
#define _CRT_SECURE_NO_DEPRECATE

#include <cpprest/http_listener.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>

#include <rxcpp/rx.hpp>
namespace Rx {
	using namespace rxcpp;
	using namespace rxcpp::sources;
	using namespace rxcpp::operators;
	using namespace rxcpp::util;
}
using namespace Rx;



// cpprest provides macros for all streams but std::clog in basic_types.h
#ifdef _UTF16_STRINGS
// On Windows, all strings are wide
#define uclog std::wclog
#else
// On POSIX platforms, all strings are narrow
#define uclog std::clog
#endif // endif _UTF16_STRINGS

using namespace std;
using namespace web::http::experimental::listener;
using namespace web::http;
using namespace web;


class Nostromo {

public:
	json::value get_health( ) { return health; };
	http_request get_request() { return  req; };
	Nostromo();
	void start_at(const web::uri url);

private:

	static	json::value health;
	static	http_request  req;


};