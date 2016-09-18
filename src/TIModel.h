/*
 * Part of tivars_lib_cpp
 * (C) 2015-2016 Adrien 'Adriweb' Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#ifndef TIMODEL_H
#define TIMODEL_H

#include "autoloader.h"
#include "TIVarType.h"

namespace tivars
{

    class TIModel
    {

    public:

        TIModel()
        {}

        TIModel(int orderId, std::string name, uint flags, std::string sig) : orderID(orderId), name(name), flags(flags), sig(sig)
        {}

        ~TIModel()
        {}

        /* Getters */
        const int& getOrderId() const { return this->orderID; }
        const std::string& getName() const { return this->name; }
        const uint& getFlags() const { return this->flags; }
        const std::string& getSig() const { return this->sig; }

        bool supportsType(const TIVarType& type);


        /*** "Constructors" ***/
        /**
         * @param   int     flags  The version compatibliity flags
         * @return  TIModel
         * @throws  \Exception
         */
        static TIModel createFromFlags(uint flags);

        /**
         * @param   string  name   The version name
         * @return  TIModel
         * @throws  \Exception
         */
        static TIModel createFromName(std::string name);

        /**
         * @param   string  sig    The signature (magic bytes)
         * @return  TIModel
         * @throws  \Exception
         */
        static TIModel createFromSignature(std::string sig);


    private:
        int orderID      = -1;
        std::string name = "Unknown";
        uint flags       = 0;
        std::string sig  = "";

    };

}

#endif
