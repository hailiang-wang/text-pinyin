# text-pinyin
汉字转拼音

https://github.com/Samurais/text-spell-correction/issues/8

接口设计参考:
https://gist.github.com/erning/1338746


开源类库:
https://github.com/internet-dev/hz2py
https://github.com/ervinzhao/hanzipinyin

实现:
https://github.com/Samurais/text-pinyin

# 理解C++汉字的编码：区位码
http://www.cppblog.com/chenjt3533/archive/2013/05/31/200721.html

**在GBK编码时**
首先有必要说下机内码与区位：

 机内码高位字节=(区号)H+A0H
 机内码低位字节=(位号)H+A0H

 例子：
```
 string str = "陈"; // 机内码存储，占两个字节
 unsigned char ucHigh = (unsigned char)strText[0]; // 获取机内码高字节 ucHigh = 179
 unsigned char ucLow  = (unsigned char)strText[1]; // 获取机内码低字节 ucLow = 194
 unsigned int uCode = (ucHigh - 0xA0) * 100 + ucLow - 0xA0; // 区位码 uCode = (179 - 160) * 100 + 194 - 160 = 1934;
```

 接下来就是根据区位码 1934 找到对应的拼音，怎么找呢？看源码吧。



源码下载 http://pan.baidu.com/share/link?shareid=483963&uk=1812123514  

# VS中的char, string, wchar, wstring
http://blog.csdn.net/luoweifu/article/details/49382969

# C++ string类型占几个字节
http://blog.csdn.net/dlutbrucezhang/article/details/9822235

# C++ 判断一个字符串是不是utf8或者GBK格式
http://blog.csdn.net/thedarkfairytale/article/details/73457200

# char和编码类型
http://blog.csdn.net/martinue/article/details/75676129
http://blog.csdn.net/jcjc918/article/details/52200478


# 基于单词的拼音库
带有音标
https://github.com/Samurais/pinyin-1