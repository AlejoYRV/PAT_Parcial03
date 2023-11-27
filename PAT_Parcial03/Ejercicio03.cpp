#include "Ejercicio03.h"

TimeMap::TimeMap() {}

void TimeMap::set(const std::string& key, const std::string& value, int timestamp)
{
    map[key].push_back({ timestamp, value });
}

std::string TimeMap::get(const std::string& key, int timestamp)
{
    if (map.find(key) == map.end())
        return "";

    const auto& values = map[key];

    int t = values.size();
    int m = 0;
    int b = 0;

    if (values[b].timestamp > timestamp)
        return "";

    if (values[t - 1].timestamp <= timestamp)
        return values[t - 1].value;

    while (b < t) {
        m = (t + b) >> 1;

        if (values[m].timestamp == timestamp)
            return values[m].value;

        if (values[m].timestamp < timestamp)
            b = m + 1;
        else
            t = m;
    }

    return values[m].value;
}

TimeMap::~TimeMap()
{
    map.clear();
}
