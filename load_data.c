#include <stdio.h>
#include <immintrin.h>

int main()
{
    double a = 3.1415926;
    double* p = NULL;
    __m256d vec0 = _mm256_setzero_pd();
    p = (double*)&vec0;
    printf("%lf %lf %lf %lf\n", p[0], p[1], p[2], p[3]);
    __m256d vec1 = _mm256_set1_pd(a);
    p = (double*)&vec1;
    printf("%lf %lf %lf %lf\n", p[0], p[1], p[2], p[3]);
    // __m256 vec2 = _mm256_set_ps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    __m256 vec2 = _mm256_setr_ps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    float* p2 = NULL;
    p2 = (float*)&vec2;
    printf("%f %f %f %f %f %f %f %f\n", p2[0], p2[1], p2[2], p2[3], p2[4], p2[5], p2[6], p2[7]);
    return 0;
}
