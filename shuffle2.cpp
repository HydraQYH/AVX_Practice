#include <iostream>
#include <immintrin.h>

void printVector(short* p, int count = 16)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}

int main(void)
{
    __m256i vec1 = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    // elo 输出向量中第5-8 13-16个元素和输入向量相同
    // 控制位分成以两bit为一组分为4组 分别用于在输入向量的1-4 9-12中选择元素 放入输出向量中1-4 9-12位置
    __m256i res1 = _mm256_shufflelo_epi16(vec1, 0b00011011);
    printVector((short*)&res1);
    // elo 输出向量中第1-4 9-12个元素和输入向量相同
    // 控制位分成以两bit为一组分为4组 分别用于在输入向量的5-8 13-16中选择元素 放入输出向量中1-4 9-12位置
    __m256i res2 = _mm256_shufflehi_epi16(vec1, 0b01110010);
    printVector((short*)&res2);
    return 0;
}
