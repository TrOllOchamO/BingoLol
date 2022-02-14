#pragma once
#define CURL_STATICLIB

#include <iostream>
#include <iomanip>

#include "curl/curl.h"
#include "nlohmann/json.hpp"

class ClientData
{
public:
	ClientData(nlohmann::json* gameData);
	~ClientData();
	bool uptadeGamedata(); //request game data, parse it and store it into gameData
	static std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out); //the CURLOPT_WRITEFUNCTION for curl

protected:
	const std::string m_URL;
	CURL* m_curl;
	std::string m_httpData;
	nlohmann::json *m_gameData;
};

