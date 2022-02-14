#include "ClientData.h"
#include "Missions.h"

using namespace std;
using json = nlohmann::json;


ClientData::ClientData(json* gameData) : m_URL("https://127.0.0.1:2999/liveclientdata/allgamedata"), m_curl(curl_easy_init())
{
    m_gameData = gameData;

    //setting curl options
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_URL, m_URL.c_str()); //setting url
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4); // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_TIMEOUT_MS, 101); // time out after 101 ms
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_WRITEFUNCTION, &ClientData::callback); // Hook up data handling function.
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_WRITEDATA, &m_httpData);
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_VERBOSE, 0L); //debugging purposes
    curl_easy_setopt(m_curl, CURLoption::CURLOPT_SSL_VERIFYPEER, 0L); //avoid ssl errors
}

ClientData::~ClientData()
{
    curl_easy_cleanup(m_curl);
}


std::size_t ClientData::callback(const char* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}


bool ClientData::uptadeGamedata()
{
    // Response information.
    long httpCode(0);
    m_httpData.clear();

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(m_curl);
    curl_easy_getinfo(m_curl, CURLINFO::CURLINFO_RESPONSE_CODE, &httpCode);


    if (httpCode == 200 || httpCode == 0)
    {
        //fill the json object passed in argument with the new data
        if (m_httpData != "")
        {
            if (m_httpData.substr(26, 5) == "error") //test if there is an error in the received data
            { 
                cout << "The data received include an error." << endl;
                return false;
            }
            else
            {
                try
                {
                    *m_gameData = json::parse(m_httpData);
                    return true;
                }
                catch (const char* msg) 
                {
                    cout << "Unable to parse the data received by the API :" << endl;
                    cout << msg << endl;
                    return false;
                }
            }
        }
        else
        {
            cout << "no http data was received." << endl;
            return false;
        }
    }
    else
    {
        cout << "Couldn't GET from " << m_URL << " - exiting" << endl;
        return false;
    }
}