
#include <stdlib.h>
#include <assert.h>
#include "qh_vector.h"


void test()
{
    qh::vector<int> num_vect; //初始化一个空的vector
    if (num_vect.size() != 0) {
        assert(false);
    }
    num_vect.push_back(0);//插入一个数字0
    num_vect.push_back(1);//插入一个数字1
    num_vect.push_back(2);//插入一个数字2
    num_vect.push_back(3);//插入一个数字3

    size_t num = num_vect.size();
    if (num != 4) {
        assert(false);
    }
    for (int i = 0; i < num; i++)//查看vector内的数据是否正确
    {
        assert(num_vect[i] == i);
    }

    num_vect.pop_back();//从末尾删除一个数字
    num = num_vect.size();
    if (num != 3) {
        assert(false);
    }
    for (int i = 0; i < num; i++)//查看删除后vector内的数据是否正确
    {
        assert(num_vect[i] == i);
    }

    num_vect.clear();//清空数据
    num = num_vect.size();
    if (num != 0) {
        assert(false);
    }

    if (!num_vect.empty()) {//判断vector是否为空
        assert(false);
    }

    num_vect.resize(3);//重置vector大小
    num = num_vect.size();
    if (num != 3) {
        assert(false);
    }
    for (int i = 0; i < num; i++)
    {
        assert(num_vect[i] == 0);
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


