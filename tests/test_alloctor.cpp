/**
 * @file test_alloctor.cpp
 * @author Kewin Li
 * @brief  测试配置器(Alloctor)
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <ext/pool_allocator.h>

#include "kit_STL/kit_allocator.h"

#define TIME_2_DIFF(t1, t2)     ((t2.tv_sec - t1.tv_sec)*1000 + (t2.tv_usec - t1.tv_usec)/1000)


/**
 * @brief 测试kit_STL库的分配器
 */
#include <vector>
void test_kit_alloctor()
{
    std::vector<int, kit_STL::kit_allocator<int> > m_v;

    for(int i = 0;i < 10;++i)
    {
        m_v.push_back(i + 1);
    }

    for(int i = 0;i < 10;++i)
    {
        m_v.front();
        m_v.pop_back();
    }
}


/**
 * @brief 测试内存池
 *
 */
void test_pool_allocator()
{
    struct timeval t1 = {0};
    struct timeval t2 = {0};

#if 0
    std::vector<int> m_v;

    gettimeofday(&t1, NULL);
    for(int i = 0;i < 10000000;++i)
    {
        m_v.push_back(i + 1);
    }
    gettimeofday(&t2, NULL);

    printf("cost time=%lld ms \n", TIME_2_DIFF(t1, t2));

#else
    std::vector<int, __gnu_cxx::__pool_alloc<int> > m_v;
    gettimeofday(&t1, NULL);
    for(int i = 0;i < 10000000;++i)
    {
        m_v.push_back(i + 1);
    }
    gettimeofday(&t2, NULL);

    printf("cost time=%lld ms \n", TIME_2_DIFF(t1, t2));

#endif
}


/**
 * @brief 测试STL标准库的分配器
 */
void test_stl_allocator()
{

    auto m_allocator = std::allocator<int>();
    struct timeval t1 = {0};
    struct timeval t2 = {0};

#if 1

    gettimeofday(&t1, NULL);
    for(int i = 0;i < 100000;++i)
    {
        auto p = m_allocator.allocate(10*1024*1024, (int *)0);
        m_allocator.deallocate(p, 10*1024*1024);
    }
    gettimeofday(&t2, NULL);

    printf("cost time=%lld ms \n", TIME_2_DIFF(t1, t2));

    return;

#else
    gettimeofday(&t1, NULL);
    for(int i = 0;i < 100000;++i)
    {
        auto p = new int[10*1024*1024];
        delete p;
    }
    gettimeofday(&t2, NULL);

    printf("cost time=%lld ms \n", TIME_2_DIFF(t1, t2));

    return;
#endif
}



int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        printf("input: xxx [num] \n");
        return 0;
    }


    switch(argv[1][0])
    {
        case '1':
        {
            test_stl_allocator();
            break;
        }

        case '2':
        {
            test_pool_allocator();
            break;
        }

        case '3':
        {
            test_kit_alloctor();
            break;
        }

        default:
            printf("type %c err! \n", argv[1][0]);
            return 0;

    }





    return 0;
}