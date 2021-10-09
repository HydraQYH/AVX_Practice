#include <stdio.h>
#include <immintrin.h>

int main()
{
    __m128 evens = {2.0, 4.0, 6.0, 8.0};
    __m128 odds = {1.0, 3.0, 5.0, 7.0};
    __m128 results = _mm_sub_ps(evens, odds);
    float* p = (float*)&results;
    printf("%f, %f, %f, %f\n", p[0], p[1], p[2], p[3]);
    return 0;
}
