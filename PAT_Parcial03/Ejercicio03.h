#pragma once

#ifndef TIMEMAP_H
#define TIMEMAP_H

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class TimeMap
{
private:
    struct Pair {
        int timestamp;
        std::string value;
    };

    std::unordered_map<std::string, std::vector<Pair>> map;

public:
    TimeMap();

    void set(const std::string& key, const std::string& value, int timestamp);

    std::string get(const std::string& key, int timestamp);

    ~TimeMap();
};

#endif



