#include <iostream>
#include <cstdlib>
#include <immintrin.h>

void printVector(float* p)
{
    for (size_t i = 0; i < 8; i++)
    {   
        float tmp = p[i];
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    float* p1 = (float*)malloc(8 * sizeof(float));
    float* p2 = (float*)malloc(8 * sizeof(float));
    for (int i = 0; i < 8; i++)
    {
        p1[i] = 0.1 * i;
        p2[i] = 0.1 * i + 0.8;
    }

    // Load data from memory
    __m256 vec1 = _mm256_loadu_ps(p1);
    __m256 vec2 = _mm256_loadu_ps(p2);
    
    __m256 res = _mm256_hadd_ps(vec1, vec2);
    printVector((float*)&res);
    __m256 res2 = _mm256_addsub_ps(vec2, vec1);
    printVector((float*)&res2);

    free(p2);
    free(p1);
    return 0;
}