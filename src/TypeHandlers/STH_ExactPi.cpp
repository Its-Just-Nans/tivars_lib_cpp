/*
 * Part of tivars_lib_cpp
 * (C) 2015-2018 Adrien "Adriweb" Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#include "TypeHandlers.h"
#include "../utils.h"
#include <regex>

namespace tivars
{

    data_t STH_ExactPi::makeDataFromString(const std::string& str, const options_t& options)
    {
        (void)options;

        throw std::runtime_error("Unimplemented");

        if (str.empty() || !is_numeric(str))
        {
            throw std::invalid_argument("Invalid input string. Needs to be a valid Exact Real Pi");
        }
    }

    std::string STH_ExactPi::makeStringFromData(const data_t& data, const options_t& options)
    {
        if (data.size() != 9)
        {
            throw std::invalid_argument("Invalid data array. Needs to contain 9 bytes");
        }

        return multiple(stoi(STH_FP::makeStringFromData(data, options)), "π");
    }

}
