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


//from http://www.drdobbs.com/web-development/restful-web-services-a-tutorial/240169069
//Addressing Resources
//
//REST requires each resource to have at least one URI.A RESTful service uses a directory hierarchy like human readable URIs to address its resources.
//The job of a URI is to identify a resource or a collection of resources.The actual operation is determined by an HTTP verb.
//The URI should not say anything about the operation or action.This enables us to call the same URI with different HTTP verbs to perform different operations.
//
//Suppose we have a database of persons and we wish to expose it to the outer world through a service.A resource person can be addressed like this:
//
//http://MyService/Persons/1
//
//This URL has following format : Protocol://ServiceName/ResourceType/ResourceID
//
//Here are some important recommendations for well - structured URIs :
//
//Use plural nouns for naming your resources.
//Avoid using spaces as they create confusion.Use an _(underscore) or –(hyphen) instead.
//A URI is case insensitive.I use camel case in my URIs for better clarity.You can use all lower - case URIs.
//You can have your own conventions, but stay consistent throughout the service.Make sure your clients are aware of this convention.
//It becomes easier for your clients to construct the URIs programmatically if they are aware of the resource hierarchy and the URI convention you follow.
//A cool URI never changes; so give some thought before deciding on the URIs for your service.
//If you need to change the location of a resource, do not discard the old URI.If a request comes for the old URI, use status code 300 and redirect the client to the new location.
//Avoid verbs for your resource names until your resource is actually an operation or a process.Verbs are more suitable for the names of operations.
//For example, a RESTful service should not have the URIs http ://MyService/FetcthPerson/1 or http://MyService/DeletePerson?id=1.

class Nostromo {

public:
	http_request get_request() { return  req; };
	Nostromo();
	void start_at(const web::uri url);

private:
		http_request  req;


};