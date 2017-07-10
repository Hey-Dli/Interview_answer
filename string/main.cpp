#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>
#include <string.h>

void test()
{
    using namespace qh;
    string a = "abcde";//调用构造函数
    const char* testa[] = {"a", "b", "c", "d", "e"};
    if (strcmp(a.data(),"abcde") != 0) {
        assert(false);
    }
    for (int i = 0; i < a.size(); ++i) {
        if (strcmp(a[i],testa[i]) != 0) {
            assert(false);
        }
    }

    string b = a;//调用拷贝构造函数
    if (strcmp(b.data(),"abcde") != 0) {
        assert(false);
    }
    for (int i = 0; i < b.size(); ++i) {
        if (strcmp(b[i],testa[i]) != 0) {
            assert(false);
        }
    }

    string c;
    c = a;//调用operator=重载函数
    if (strcmp(c.data(),"abcde") != 0) {
        assert(false);
    }
    for (int i = 0; i < c.size(); ++i) {
        if (strcmp(c[i],testa[i]) != 0) {
            assert(false);
        }
    }

    string d("abcde", 3);//按字符串部分构造对象
    if (strcmp(d.data(),"abc") != 0) {
        assert(false);
    }

    string e;//调用默认构造函数
    if (strcmp(e.data(), "") != 0) {
        assert(false);
    }
}


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
    test();

#ifdef WIN32
    system("pause");
#endif

    return 0;
}
