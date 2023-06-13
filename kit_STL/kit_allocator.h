#ifndef __KIT_ALLOCTOR_H__
#define __KIT_ALLOCTOR_H__

#include <cstdlib>
#include <new>
#include <cstddef>


namespace kit_STL {


/**
 * @brief kit_STL分配器allocator的真实实现
 *
 * @tparam Tp 数据类型
 */
template<typename T>
class _kit_new_allocator
{
public:
    typedef T               value_type;        /*数据类型*/
    typedef T*              pointer;           /*数据类型-指针*/
    typedef const T*        const_pointer;     /*数据类型-常量指针*/
    typedef T&              reference;         /*数据类型-引用*/
    typedef const T&        const_reference;   /*数据类型-常引用*/
    typedef size_t          size_type;         /*数据长度*/
    typedef ptrdiff_t       difference_type;   /*等同long int*/

public:

    /**
     * @brief 构造函数
     */
    _kit_new_allocator() { }

    /**
     * @brief 拷贝构造函数
     */
    _kit_new_allocator(const _kit_new_allocator&) { }

    /**
     * @brief 析构函数
     */
    ~_kit_new_allocator() { }

    /**
     * @brief 分配内存
     * @param[in] _n 内存大小
     * @param[in] const void*
     * @return T* 指针类型
     */
    T* allocate(size_t _n, const void* = static_cast<const void*>(0))
    {
        if(_n <= 0 || _n >= this->max_size())
            return nullptr;

        printf("kit STL allocate!\n");
        return static_cast<T*>(::operator new(_n * sizeof(T)));
    }

    /**
     * @brief 释放内存
     * @param[in] _p 目标指针
     * @param[in] _n 内存大小(无用参数)
     */
    void deallocate(void *_p, size_t _n)
    {
        printf("kit STL deallocate!\n");
        ::operator delete(_p);
    }

private:
    /**
     * @brief 最大可分配空间
     * @return size_t
     */
    size_t max_size()
    {
#if __PTRDIFF_MAX__ < __SIZE_MAX__
	    return size_t(__PTRDIFF_MAX__) / sizeof(T);
#else
        return size_t(-1) / sizeof(T);
#endif
    }

};

/**
 * @brief 使用别名将_kit_new_allocator类隔离
 *
 * @tparam Tp 数据类型
 */
template<typename T>
using _kit_base_allocator = _kit_new_allocator<T>;


/**
 * @brief kit_STL分配器的调用子类
 *
 * @tparam Tp 数据类型
 */
template<typename T>
class kit_allocator: public _kit_base_allocator<T>
{
public:
    kit_allocator() { }

    kit_allocator(const kit_allocator&) { }

    ~kit_allocator() { }

};






}


#endif