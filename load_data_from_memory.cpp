#include <iostream>
#include <cstdlib>
#include <immintrin.h>

void printVector(float* p)
{
    for (size_t i = 0; i < 8; i++)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    float* p = (float*)std::malloc(8 * sizeof(float));
    for (size_t i = 0; i < 8; i++)
    {
        p[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }
    printVector(p);
    __m256 vec = _mm256_loadu_ps(p);
    float* p2 = (float*)(&vec);
    printVector(p2);
    __m256i mask = _mm256_setr_epi32(-1, -1, 0, -1, -1, 0, 0, 0);
    __m256 vec2 = _mm256_maskload_ps(p, mask);
    float* p3 = (float*)(&vec2);
    printVector(p3);
    std::free(p);
    return 0;
}

