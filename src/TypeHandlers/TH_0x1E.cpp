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

    data_t TH_0x1E::makeDataFromString(const string& str, const options_t& options)
    {
        (void)options;

        throw runtime_error("Unimplemented");

        if (str.empty() || !is_numeric(str))
        {
            throw invalid_argument("Invalid input string. Needs to be a valid Exact Complex Pi");
        }
    }

    string TH_0x1E::makeStringFromData(const data_t& data, const options_t& options)
    {
        (void)options;

        if (data.size() != dataByteCount)
        {
            throw invalid_argument("Empty data array. Needs to contain " + to_string(dataByteCount) + " bytes");
        }

        string coeffR = TH_0x00::makeStringFromData(data_t(data.begin(), data.begin() + TH_0x00::dataByteCount));
        string coeffI = TH_0x00::makeStringFromData(data_t(data.begin() + TH_0x00::dataByteCount, data.begin() + 2 * TH_0x00::dataByteCount));

        string str = ((coeffR != "0") ? (dec2frac(atof(coeffR.c_str())) + "+") : "")
                   + ((coeffI != "0") ? (coeffI + "*π*i") : "");

        // Improve final display
        str = regex_replace(str, regex("\\+1\\*"), "+");  str = regex_replace(str, regex("\\(1\\*"),  "(");
        str = regex_replace(str, regex("-1\\*"),   "-");  str = regex_replace(str, regex("\\(-1\\*"), "(-");
        str = regex_replace(str, regex("\\+-"),    "-");

        // Shouldn't happen - I don't believe the calc generate such files.
        if (str.empty())
        {
            str = "0";
        }

        return str;
    }

}