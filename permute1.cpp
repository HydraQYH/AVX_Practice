#include <iostream>
#include <immintrin.h>

void printVector(float* p, int count = 8)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}

void printVector(double* p, int count = 4)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}

int main(void)
{
    __m256 vec1 = _mm256_setr_ps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    __m256 res = _mm256_permute_ps(vec1, 0b00011011);
    printVector((float*)&res);
    __m256d vec2 = _mm256_setr_pd(3.1, 4.2, 5.3, 6.4);
    // 高4位无影响 低4位中低2位控制向量前两个值，高2位控制向量后两个值
    __m256d res2 = _mm256_permute_pd(vec2, 0b00000101);
    printVector((double*)&res2);
    // 控制位每2位控制输出向量中的一个元素
    __m256d res3 = _mm256_permute4x64_pd(vec2, 0b00011011);
    printVector((double*)&res3);
    __m256 vec3 = _mm256_setr_ps(9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
    // 控制位低4位控制输出向量前128bit的片 高4位控制输出向量后128bit的片
    // 控制位4位中 低2位用于在两个输入向量（4个片）中选择，最高一位若置1 则输出全部置0
    __m256 res4 = _mm256_permute2f128_ps(vec1, vec3, 0b00110011);
    printVector((float*)&res4);
    return 0;
}

