/*
 * Part of tivars_lib_cpp
 * (C) 2015-2018 Adrien "Adriweb" Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#include "TypeHandlers.h"
#include <cstring>

namespace tivars
{
    data_t TH_TempEqu::makeDataFromString(const std::string& str, const options_t& options)
    {
        (void)str;
        (void)options;

        throw std::runtime_error("Unimplemented");
    }

    std::string TH_TempEqu::makeStringFromData(const data_t& data, const options_t& options)
    {
        (void)options;

        size_t dataSize = data.size();
        if (dataSize < 6)
        {
            throw std::invalid_argument("Invalid data array. Needs to contain at least 6 bytes (size fields)");
        }

        uint8_t type = data[0];
        std::string typeStr = (type == 5 ? "prgm" : "");

        uint8_t namelen = data[1];
        if (namelen < 1 || namelen > 8 || namelen > dataSize-4) { // for the other fields
            throw std::invalid_argument("Invalid data array. namelen field impossible or inconsistent with actual data");
        }

        std::string name(namelen, '\0');
        memcpy(&name[0], &data[2], namelen);

        uint16_t offset = (uint16_t) ((data[2 + namelen] & 0xFF) + ((data[2 + namelen + 1] & 0xFF) << 8));

        data_t tokens(data.begin()+4+namelen-2, data.end()); // we take 2 bytes more at the beginning to overwrite them with length
        tokens[0] = (uchar) ((tokens.size()-2) & 0xFF);
        tokens[1] = (uchar) (((tokens.size()-2) >> 8) & 0xFF);
        std::string detokenized = TH_Tokenized::makeStringFromData(tokens);

        return typeStr + name + ":" + std::to_string(offset) + ":" + detokenized;
    }

}
