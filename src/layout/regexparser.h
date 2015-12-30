/*
 *  OpenBangla Keyboard
 *  Copyright (C) 2015 Muhammad Mominul Huque <nahidbinbaten1995@gmail.com>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

 /*
  *  Actually this parser is originated from the parser written by
  *  Rifat Nabi for iAvro under MPL 1.1. It was written in Objective C.
  *  I(Muhammad Mominul Huque) have re-written the parser in C++ for using with
  *  OpenBangla Keyboard.
  *  For showing respect to the Avro project and Rifat Nabi, I am
  *  releasing this code under MPL 2.0.
  *  So this is code now dual licensed under the MPL 2 and the GNU GPL 3.
  *  If you have any questions about this matter, please send e-mail to
  *  me at described above.
  *  http://www.gnu.org/licenses/license-list.en.html#MPL-2.0
  */
#ifndef REGEX_PARSER_H
#define REGEX_PARSER_H

#include <fstream>
#include <string>
#include <QString>
#include "json.hpp"

class RegexParser {
private:
  std::ifstream fin;
  nlohmann::json grammar;

  nlohmann::json patterns;
  std::string vowel;
  std::string cons;
  std::string ign;
  int maxPatternLength;

  char to_char(std::string a);
  std::string to_str(char a);

  char smallCap(char letter);
  bool isVowel(char c);
  bool isConsonant(char c);
  bool isPunctuation(char c);
  bool isExact(std::string needle, std::string heystack, int start, int end, bool strnot);
  bool isIgnore(char c);
  std::string cleanString(std::string input);

  QString makeRegexCompatible(std::string input);
public:
  RegexParser();
  ~RegexParser();
  QString parse(std::string input);
};

#endif /* end of include guard: REGEX_PARSER_H */