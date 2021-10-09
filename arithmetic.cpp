#include <iostream>
#include <cstdlib>
#include <immintrin.h>

void _init_(char* p)
{
    for (size_t i = 0; i < 16; i++)
    {
        p[i] = rand() % 128;
    }
}

void printVector(char* p)
{
    for (size_t i = 0; i < 16; i++)
    {   
        int tmp = p[i];
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    // 创建两个vector，元素类型为char
    char* p1 = (char*)malloc(16 * sizeof(char));
    char* p2 = (char*)malloc(16 * sizeof(char));
    _init_(p1);
    _init_(p2);
    printVector(p1);
    printVector(p2);
    // 从内存中load向量
    __m128i vec1 = _mm_loadu_si128((__m128i_u*)p1);
    __m128i vec2 = _mm_loadu_si128((__m128i_u*)p2);
    printVector((char*)&vec1);
    printVector((char*)&vec2);

    __m128i vec3 = _mm_add_epi8(vec1, vec2);
    __m128i vec4 = _mm_adds_epi8(vec1, vec2);
    printVector((char*)&vec3);
    printVector((char*)&vec4);
    free(p2);
    free(p1);
    return 0;
}

