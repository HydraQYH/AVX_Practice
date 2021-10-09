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
    __m256 vec1 = _mm256_setr_ps(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0);
    __m256 vec2 = _mm256_setr_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);
    __m256 res1 = _mm256_shuffle_ps(vec1, vec2, 0b01111001);
    printVector((float*)&res1);
    __m256d vec3 = _mm256_setr_pd(1.0, 2.0, 3.0, 4.0);
    __m256d vec4 = _mm256_setr_pd(5.0, 6.0, 7.0, 8.0);
    // 控制位仅仅低4位使用 第0位在第一个向量中前两个元素选择 第1位在第二个向量中前两个元素选择
    // 第3位在第一个向量中的后两个元素选择 第4位在第二个向量中的后两个元素中选择
    __m256d res2 = _mm256_shuffle_pd(vec3, vec4, 0b00001011);   // 2 6 3 8
    printVector((double*)&res2);
    return 0;
}

