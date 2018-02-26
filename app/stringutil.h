/*
 * C++ implementation of HanZi to Pinyin
 *
 * Copyright (c) 2018 Hai Liang Wang
 * All rights reserved.
 * https://gist.github.com/wanjochan/d0aba83da88552f95edafb65124d41c3
 * http://blog.csdn.net/luoweifu/article/details/49382969
 */
#ifndef TEXY_HZ2PINYIN_STRING_UTIL_H_
#define TEXY_HZ2PINYIN_STRING_UTIL_H_

#include <cstdlib>
#include <string.h>
#include <string>

std::string WString2String(const std::wstring& ws);
std::wstring String2WString(const std::string& s);

#endif  // TEXY_HZ2PINYIN_STRING_UTIL_H_