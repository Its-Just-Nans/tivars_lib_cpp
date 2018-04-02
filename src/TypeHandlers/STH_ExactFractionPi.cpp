/*
 * Part of tivars_lib_cpp
 * (C) 2015-2018 Adrien "Adriweb" Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#include "TypeHandlers.h"
#include "../utils.h"
#include <regex>

using namespace std;

namespace tivars
{

    data_t STH_ExactFractionPi::makeDataFromString(const string& str, const options_t& options)
    {
        (void)options;

        throw runtime_error("Unimplemented");

        if (str.empty() || !is_numeric(str))
        {
            throw invalid_argument("Invalid input string. Needs to be a valid Exact Real Pi Fraction");
        }
    }

    string STH_ExactFractionPi::makeStringFromData(const data_t& data, const options_t& options)
    {
        if (data.size() != 9)
        {
            throw invalid_argument("Invalid data array. Needs to contain 9 bytes");
        }

        return dec2frac(stod(STH_FP::makeStringFromData(data, options)), "π");
    }

}
