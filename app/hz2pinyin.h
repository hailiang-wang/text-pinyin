/*
 * C++ implementation of HanZi to Pinyin
 *
 * Copyright (c) 2018 Hai Liang Wang
 * All rights reserved.
 */
#ifndef TEXY_HZ2PINYIN_H_
#define TEXY_HZ2PINYIN_H_

#include <cstdlib>
#include <string>
#include <string.h>
#include "Common/Util/Encode/encodeUtil.h"
using namespace std;

namespace robot { namespace query {

#define graduate(start, end, code, letter) if(code >= start && code <= end) return letter

class Hz2Py
{
 public: // constructor
	Hz2Py();
	~Hz2Py();

 public: // functions
	int pinyin(const string text, string& result); // 文本转换为拼音
	int title(string text, string& result); // 取文本拼音的首字母

 private: // functions
	string letter(int nCode); // 将区位码转为拼音
	char szm(int nCode); // 根据汉字区域码获取拼音声母
};

}} // namespace robot::query
#endif  // TEXY_HZ2PINYIN_H_