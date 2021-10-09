#include <iostream>
#include <cstdlib>
#include <immintrin.h>

void printVector(float* p, int count = 8)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}

int main(void)
{
    __m256 vec1 = _mm256_setr_ps(10.0, 2.2, 3.2, 4.9, 5.1, 6.4, 7.6, 8.9);
    __m256 vec2 = _mm256_setr_ps(9.1, 8.3, 7.7, 6.6, 5.5, 4.2, 3.1, 2.2);
    __m256 vec3 = _mm256_setr_ps(1.0, 0.5, 1.5, 2.9, 2.5, 4.5, 3.5, 1.5);

    __m256 res1 = _mm256_fmadd_ps(vec1, vec2, vec3);
    printVector((float*)&res1);
    __m256 res2 = _mm256_fmsub_ps(vec1, vec2, vec3);
    printVector((float*)&res2);

    __m128 vec4 = _mm_setr_ps(4.0, 3.0, 2.0, 1.0);
    __m128 vec5 = _mm_setr_ps(9.0, 8.0, 7.0, 6.0);
    __m128 vec6 = _mm_setr_ps(2.0, 7.0, 8.0, 9.0);
    __m128 res3 = _mm_fmadd_ps(vec4, vec5, vec6);
    printVector((float*)&res3, 4);
    __m128 res4 = _mm_fmsub_ps(vec4, vec5, vec6);
    printVector((float*)&res4, 4);
    __m128 res5 = _mm_fmadd_ss(vec4, vec5, vec6);
    printVector((float*)&res5, 4);
    __m128 res6 = _mm_fmsub_ss(vec4, vec5, vec6);
    printVector((float*)&res6, 4);
    __m128 res7 = _mm_fnmadd_ps(vec4, vec5, vec6);
    printVector((float*)&res7, 4);
    __m128 res8 = _mm_fnmsub_ps(vec4, vec5, vec6);
    printVector((float*)&res8, 4);
    __m128 res9 = _mm_fnmadd_ss(vec4, vec5, vec6);
    printVector((float*)&res9, 4);
    __m128 res10 = _mm_fnmsub_ss(vec4, vec5, vec6);
    printVector((float*)&res10, 4);
    __m128 res11 = _mm_fmaddsub_ps(vec4, vec5, vec6);
    printVector((float*)&res11, 4);
    __m128 res12 = _mm_fmsubadd_ps(vec4, vec5, vec6);
    printVector((float*)&res12, 4);
    return 0;
}
