#pragma once
#include "Nostromo.h"


Nostromo::Nostromo()
{
};


namespace {


	void respond(const http_request& request, const status_code& status, const json::value& response) {

		json::value resp;
		resp[U("status")] = json::value::string(U("running"));
		resp[U("version")] = json::value::string(U("1.0"));

		request.reply(status_codes::OK, resp);
		request.reply(status, resp);
	};



	void handle_get(http_request req) {
		auto http_get_vars = uri::split_query(req.request_uri().query());

		auto found_name = http_get_vars.find(U("request"));

		if (found_name == end(http_get_vars)) {
			auto err = U("Request received with get var \"request\" omitted from query.");
			uclog << err << endl;
			respond(req, status_codes::BadRequest, json::value::string(err));
			return;
		}

		auto request_name = found_name->second;
		uclog << U("Received request: ") << request_name << endl;
		respond(req, status_codes::OK, json::value::string(U("Request received for: ") + request_name));
	}

	// implement rest of http methods later
	// ...

	void handle_post(http_request req) {

		json::value resp;
		resp[U("status")] = json::value::string(U("running"));
		resp[U("version")] = json::value::string(U("1.0"));

		req.reply(status_codes::OK, resp);
	}



}

void Nostromo::start_at(const web::uri url) {

	// Synchronously bind the listener to all nics.
	
	// Handle incoming requests.
	http_listener listener(url);
	listener.support(methods::GET, handle_get);
	listener.support(methods::POST, handle_post);
	
	try
	{
		listener
			.open()
			.then([&listener]() {uclog << "Listening " << endl; })
			.wait();

		while (true);
	}
	catch (exception const & e)
	{
		uclog << e.what() << endl;
	}
}