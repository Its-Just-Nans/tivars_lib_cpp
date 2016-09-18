/*
 * Part of tivars_lib_cpp
 * (C) 2015-2016 Adrien 'Adriweb' Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#ifndef TIVARS_LIB_CPP_TIVARFILE_H
#define TIVARS_LIB_CPP_TIVARFILE_H

#include "autoloader.h"
#include "BinaryFile.h"
#include "TIVarType.h"
#include "TIModel.h"

namespace tivars
{

    class TIVarFile : public BinaryFile
    {

        struct var_header_t
        {
            uchar    signature[8]  = {0};
            uchar    sig_extra[3]  = {0};
            uchar    comment[42]   = {0};
            uint16_t entries_len   = 0;
        };

        struct var_entry_t
        {
            uchar    constBytes[2] = {0};
            uint16_t data_length   = {0};
            uchar    typeID        = 0;
            uchar    varname[8]    = {0};
            uchar    version       = 0;
            uchar    archivedFlag  = 0;
            uint16_t data_length2  = {0};
            data_t   data;
        };

    public:
        TIVarFile()
        {}

        TIVarFile(const std::string filePath);

        ~TIVarFile()
        { }

        const var_header_t& getHeader() const { return header; }
        const var_entry_t& getVarEntry() const { return varEntry; }
        const TIVarType& getType() const { return type; }
        const uint16_t& getInstanceChecksum() const { return computedChecksum; }

        static TIVarFile loadFromFile(const std::string filePath);

        static TIVarFile createNew(const TIVarType& type, const std::string name, const TIModel& model);
        static TIVarFile createNew(const TIVarType& type, const std::string name);
        static TIVarFile createNew(const TIVarType& type);

        void makeHeaderFromFile();

        void makeVarEntryFromFile();

        bool isValid();

        uint16_t getChecksumValueFromFile();

        void setContentFromData(const data_t data);

        void setContentFromString(const std::string str, const options_t options = {});

        void setCalcModel(const TIModel model);
        void setVarName(const std::string name);

        data_t getRawContent();

        std::string getReadableContent(const options_t options = {});

        void fixChecksumInFile();

        void saveVarToFile(std::string directory, std::string name);
        void saveVarToFile();

    private:
        void refreshMetadataFields();
        std::string fixVarName(const std::string& name);

        uint16_t computeChecksumFromInstanceData();
        uint16_t computeChecksumFromFileData();


        var_header_t header;
        var_entry_t  varEntry;
        TIVarType    type;
        TIModel      calcModel;
        uint16_t     computedChecksum = 0;
        uint16_t     inFileChecksum   = 0;
        bool         isFromFile       = false;

        data_t bindata_maker();

    };
}

#endif //TIVARS_LIB_CPP_BINARYFILE_H
