#include <stdio.h>
#include <limits.h>  // 包含基本整数类型的限制
#include <stdint.h>  // 包含固定宽度整数类型的限制
#include <inttypes.h>

int main() {
    // 基本整数类型范围
    printf("==== 基本整数类型范围 ====\n");
    printf("char 最小值: %d\n", CHAR_MIN);
    printf("char 最大值: %d\n", CHAR_MAX);
    printf("short 最小值: %d\n", SHRT_MIN);
    printf("short 最大值: %d\n", SHRT_MAX);
    printf("int 最小值: %d\n", INT_MIN);
    printf("int 最大值: %d\n", INT_MAX);
    // long的长度取决于平台，在64位win系统下，long为32位长度，而64位的Linux和macOS中long长度为64位
    // 避免依赖long的位数，跨平台编写代码时，优先使用 <stdint.h> 中的固定宽度类型（如int32_t、int64_t）。
    // 若需 “本地最大整数”，使用long long（在 64 位系统中通常为 64 位，且 C 标准保证其至少 64 位）。
    printf("long 最小值: %ld\n", LONG_MIN);
    printf("long 最大值: %ld\n", LONG_MAX);
    printf("long long 最小值: %lld\n", LLONG_MIN);
    printf("long long 最大值: %lld\n", LLONG_MAX);

    // 固定宽度整数类型范围
    printf("\n==== 固定宽度整数类型范围 ====\n");
    printf("int8_t 最小值: %" PRId8 "\n", INT8_MIN);
    printf("int8_t 最大值: %" PRId8 "\n", INT8_MAX);
    printf("uint8_t 最大值: %" PRIu8 "\n", UINT8_MAX);
    printf("int16_t 最小值: %" PRId16 "\n", INT16_MIN);
    printf("int16_t 最大值: %" PRId16 "\n", INT16_MAX);
    printf("int32_t 最小值: %" PRId32 "\n", INT32_MIN);
    printf("int32_t 最大值: %" PRId32 "\n", INT32_MAX);
    printf("int64_t 最小值: %" PRId64 "\n", INT64_MIN);
    printf("int64_t 最大值: %" PRId64 "\n", INT64_MAX);

    // 无符号整数类型范围
    printf("\n==== 无符号整数类型范围 ====\n");
    printf("unsigned char 最大值: %u\n", UCHAR_MAX);
    printf("unsigned short 最大值: %u\n", USHRT_MAX);
    printf("unsigned int 最大值: %u\n", UINT_MAX);
    printf("unsigned long 最大值: %lu\n", ULONG_MAX);
    printf("unsigned long long 最大值: %llu\n", ULLONG_MAX);

    return 0;
}