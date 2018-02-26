/*
 * C++ implementation of HanZi to Pinyin
 *
 * Copyright (c) 2018 Hai Liang Wang
 * All rights reserved.
 */
#include <iostream>
#include <cstring>
#include "hz2pinyin.h"
#include <cstdlib>
#include <string.h>
#include "Common/Util/Encode/encodeUtil.h"
#include "Common/Base/flags.h"
#include "Common/Base/logging.h"

using namespace robot::query;
using namespace encode;

/*
	----------- 机内码与区位码 ----------------

	机内码高位字节=(区号)H+A0H
	机内码低位字节=(位号)H+A0H

	例子：
	string str = "陈"; // 机内码存储，占两个字节
	unsigned char ucHigh = (unsigned char)strText[0]; // 获取机内码高字节 ucHigh = 179
	unsigned char ucLow  = (unsigned char)strText[1]; // 获取机内码低字节 ucLow = 194
	unsigned int uCode = (ucHigh - 0xA0) * 100 + ucLow - 0xA0; // 区位码 uCode = (179 - 160) * 100 + 194 - 160 = 1934;
	接下来就是根据区位码 1934 找到对应的拼音
*/

/// 获取每个汉字的完整拼音
void TransToLetter(string strText)
{
	Hz2Py hz;
	std::cout << "TransToLetter:" << strText << "\n" << endl;
    string result;
    hz.pinyin(strText, result);
    std::cout << "result: " << result << endl;
}

/// 获取每个汉字的首字母
void TransToFirstLetter(string sChinese)
{
	Hz2Py hz;
    std::string result;
    hz.title(sChinese, result);
}


int main(int argc, char** argv)
{
    common::ParseCommandLineFlags(&argc, &argv, false);
    string chen = "中国人民"; // 在Linux中，为utf8
    TransToLetter(chen);
    TransToFirstLetter(chen);

    chen = "中国人民1123";
    TransToLetter(chen);
    TransToFirstLetter(chen);

    chen = "中国 人民 123";
    TransToLetter(chen);
    TransToFirstLetter(chen);


    chen = "中国 人民 de, 。";
    TransToLetter(chen);
    TransToFirstLetter(chen);

    // 关于编码的问题
    string gbk_chen;
    UTF82GBK(chen, gbk_chen);

    unsigned char ucHigh = (unsigned char)gbk_chen[0]; // 获取机内码高字节 ucHigh = 179
    unsigned char ucLow  = (unsigned char)gbk_chen[1]; // 获取机内码低字节 ucLow = 194
    std::cout << "陈: " << ucHigh << ", " << ucLow << endl;
    unsigned int uCode = (ucHigh - 0xA0) * 100 + ucLow - 0xA0; // 区位码 uCode = (179 - 160) * 100 + 194 - 160 = 1934;
    std::cout <<  "uCode: " << uCode << endl;

    string a("hha");  
    string b("hha好");
    string gbk_a, gbk_b;
    UTF82GBK(a, gbk_a);
    UTF82GBK(b, gbk_b);

    cout<<gbk_a.size()<<endl<<gbk_b.size()<<endl;  
    cout<<gbk_a.length()<<endl<<gbk_b.length()<<endl;  
    //可以发现string::size() 函数的作用是计算string有多少个字节  
    //一个char是一个字节（byte）=8bit ,一个汉字是两个char两个字节   
}
