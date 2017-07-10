#include "ini_parser.h"

#include <string.h>
#include <assert.h>
#include <iostream>

void test1()
{
    const char* ini_text= "a=1\nb=2\n";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()//从ini文件读取并测试s
{
		qh::INIParser parser;
	    if (!parser.Parse("config.ini")) {
	        assert(false);
	    }
	    const std::string& a = parser.Get("a", NULL);
	    assert(a == "1");

	    std::string b = parser.Get("b", NULL);
	    assert(b == "2");

	    const std::string& c = parser.Get("c", NULL);
	    assert(c == "3");
}

void test5()//从默认section中查找某个key，并返回找到的value，找不到则返回空串
{
	 const char* ini_text= "a=1\nb=2\n";
	 qh::INIParser parser;
	 if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
		 assert(false);
	 }

	const string section = "a,b,c";
	const std::string& a = parser.Get(section, "a", NULL);
	assert(a == "1");

	std::string b = parser.Get(section, "b", NULL);
	assert(b == "2");

	const std::string& c = parser.Get(section, "c", NULL);
	assert(c == "");
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
