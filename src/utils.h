/*
 * Part of tivars_lib_cpp
 * (C) 2015-2016 Adrien 'Adriweb' Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#ifndef TIVARSLIB_UTILS_H
#define TIVARSLIB_UTILS_H

#include "autoloader.h"
#include "TIModel.h"
#include "TIVarType.h"

bool is_in_vector_uchar(const std::vector<unsigned char>& v, unsigned char element);
bool is_in_vector_uint(const std::vector<unsigned int>& v, unsigned int element);
bool is_in_vector_string(const std::vector<std::string>& v, const std::string& element);
bool is_in_umap_string_uchar(const std::unordered_map<std::string, unsigned char>& m, const std::string& element);
bool is_in_umap_string_uint(const std::unordered_map<std::string, unsigned int>& m, const std::string& element);

bool is_in_umap_string_TIModel(const std::unordered_map<std::string, tivars::TIModel>& m, const std::string& element);
bool is_in_umap_string_TIVarType(const std::unordered_map<std::string, tivars::TIVarType>& m, const std::string& element);

bool has_option(const std::unordered_map<std::string, unsigned char>& m, const std::string& element);

unsigned char hexdec(const std::string& str);

std::string dechex(unsigned char i);

std::vector<std::string> explode(const std::string& str, const std::string& delim);
std::vector<std::string> explode(const std::string& str, char delim);

std::string ltrim(std::string s, const char* t = " \t\n\r\f\v");

std::string rtrim(std::string s, const char* t = " \t\n\r\f\v");

std::string trim(const std::string& s, const char* t = " \t\n\r\f\v");

std::string str_repeat(const std::string& str, unsigned int times);

void ParseCSV(const std::string& csvSource, std::vector<std::vector<std::string>>& lines);

bool is_numeric(const std::string& str);

std::string stripchars(std::string str, const std::string& chars);

bool file_exists(const std::string& filePath);

std::string str_pad(const std::string& str, unsigned long pad_length, std::string pad_string = " ");

#endif