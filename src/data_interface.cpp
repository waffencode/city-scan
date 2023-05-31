#include <curl/curl.h>
#include <iostream>
#include <fstream>

#include "data_interface.h"

void data_interface::request(std::string url)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    
    if (curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        std::string data;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        
        res = curl_easy_perform(curl);
        write_callback(data);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    } 
    else 
    {
        std::cerr << "curl_easy_init() failed." << std::endl;
    }
}

size_t data_interface::write_data(char *ptr, size_t size, size_t nmemb, std::string* data)
{
    *data = ptr;
    return nmemb;
}

void data_interface::write_callback(std::string data)
{
    _db->add_raw_data(data);
}

std::vector<std::string> data_interface::read_link()
{
    std::vector<std::string> links;
    std::string link;
    std::ifstream file;
    file.open("links.txt", std::ifstream::in);

    while (file >> link) 
    {
        links.push_back(link);
    }
    
    file.close();
    
    return links;
}

void data_interface::request_all()
{
    std::vector<std::string> links = read_link();

    for (const auto& link : links)
    {
        request(link);       
    }
}