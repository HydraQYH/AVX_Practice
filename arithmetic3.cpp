#include <iostream>
#include <cstdlib>
#include <immintrin.h>

void printVectorLong(long long* p)
{
    for (size_t i = 0; i < 4; i++)
    {   
        long long tmp = p[i];
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}

void printVector(int* p)
{
    for (size_t i = 0; i < 8; i++)
    {   
        int tmp = p[i];
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}


int main(void)
{
    int* p1 = (int*)malloc(8 * sizeof(int));
    int* p2 = (int*)malloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++)
    {
        p1[i] = i + 1;
        p2[i] = i + 1;
    }
    // Load data from memory
    __m256i vec1 = _mm256_loadu_si256((__m256i_u*)p1);
    printVector((int*)&vec1);
    __m256i vec2 = _mm256_loadu_si256((__m256i_u*)p2);
    printVector((int*)&vec2);
    __m256i res1 = _mm256_mul_epi32(vec1, vec2);
    printVectorLong((long long*)&res1);
    __m256i res2 = _mm256_mullo_epi32(vec1, vec2);
    printVector((int*)&res2);
    short* p3 = (short*)malloc(16 * sizeof(short));
    short* p4 = (short*)malloc(16 * sizeof(short));
    for (short i = 0; i < 16; i++)
    {
        p3[i] = i + 8192;
        p4[i] = i + 8192;
    }
    __m256i vec3 = _mm256_loadu_si256((__m256i_u*)p3);
    __m256i vec4 = _mm256_loadu_si256((__m256i_u*)p4);
    __m256i res3 = _mm256_mulhi_epi16(vec3, vec4);

    short* p5 = (short*)&res3;
    for (int i = 0; i < 16; i++)
    {   
        short tmp = p5[i];
        std::cout << tmp << " ";
    }
    std::cout << std::endl;

    free(p4);
    free(p3);
    free(p1);
    free(p2);
    return 0;
}
