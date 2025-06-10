#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 函数声明
int get_base_choice(const char *prompt);
char* dec_to_base(double num, int target_base, int precision);
double base_to_dec(const char *num_str, int source_base);
void convert_number(void);
int is_valid_number(const char *num_str, int base);
int char_to_value(char c);
char value_to_char(int value);

int main() {
    int choice;
    
    do {
        printf("\n===== Base Conversing Tool =====\n");
        printf("1. To converse base\n");
        printf("2. Exit\n");
        printf("Please enter the number of choices: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input, please enter the number of choices\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }
        
        while (getchar() != '\n'); // 清除输入缓冲区
        
        switch (choice) {
            case 1:
                convert_number();
                break;
            case 2:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    } while (choice != 2);
    
    return 0;
}

// 获取用户选择的进制
int get_base_choice(const char *prompt) {
    int base;
    
    do {
        printf("%s (2=Binary, 8=Octal, 10=Decimal, 16=Hexadecimal): ", prompt);
        if (scanf("%d", &base) != 1) {
            printf("Invalid Input, please entering number.\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }
        
        while (getchar() != '\n'); // 清除输入缓冲区
        
        if (base != 2 && base != 8 && base != 10 && base != 16) {
            printf("The base for conversion is not supported, please input 2, 8, 10 or 16.\n");
        }
    } while (base != 2 && base != 8 && base != 10 && base != 16);
    
    return base;
}

// 将十进制数转换为目标进制的字符串
char* dec_to_base(double num, int target_base, int precision) {
    static char buffer[1024];
    int integer_part = (int)num;
    double fractional_part = num - integer_part;
    char *ptr = buffer;
    
    // 处理符号
    if (num < 0) {
        *ptr++ = '-';
        num = -num;
        integer_part = (int)num;
        fractional_part = num - integer_part;
    }
    
    // 处理整数部分
    if (integer_part == 0) {
        *ptr++ = '0';
    } else {
        char int_buffer[256];
        char *int_ptr = int_buffer + sizeof(int_buffer) - 1;
        *int_ptr = '\0';
        
        while (integer_part > 0) {
            int remainder = integer_part % target_base;
            *--int_ptr = value_to_char(remainder);
            integer_part /= target_base;
        }
        
        strcpy(ptr, int_ptr);
        ptr += strlen(int_ptr);
    }
    
    // 处理小数部分
    if (fractional_part > 0 && precision > 0) {
        *ptr++ = '.';
        
        for (int i = 0; i < precision; i++) {
            fractional_part *= target_base;
            int digit = (int)fractional_part;
            *ptr++ = value_to_char(digit);
            fractional_part -= digit;
        }
    }
    
    *ptr = '\0';
    return buffer;
}

// 将任意进制的字符串转换为十进制数
double base_to_dec(const char *num_str, int source_base) {
    double result = 0.0;
    int sign = 1;
    const char *ptr = num_str;
    int fractional = 0;
    double divisor = 1.0;
    
    // 处理符号
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    } else if (*ptr == '+') {
        ptr++;
    }
    
    // 处理整数和小数部分
    while (*ptr) {
        if (*ptr == '.') {
            if (fractional) break; // 多个小数点，非法
            fractional = 1;
            ptr++;
            continue;
        }
        
        int value = char_to_value(*ptr);
        if (value == -1 || value >= source_base) {
            printf("Error: '%c' is an invalid number of the base %d\n", *ptr, source_base);
            return 0.0;
        }
        
        if (fractional) {
            divisor *= source_base;
            result += value / divisor;
        } else {
            result = result * source_base + value;
        }
        
        ptr++;
    }
    
    return sign * result;
}

// 执行数值转换
void convert_number() {
    int source_base, target_base;
    char num_str[1024];
    double decimal_value;
    int precision = 10; // 默认小数精度
    
    source_base = get_base_choice("Please enter the current base:");
    target_base = get_base_choice("Please enter the target base:");
    
    printf("Please enter a number for conversion: ");
    if (fgets(num_str, sizeof(num_str), stdin) == NULL) {
        printf("Fail to read the number\n");
        return;
    }
    
    // 移除换行符
    num_str[strcspn(num_str, "\n")] = 0;
    
    // 验证输入
    if (!is_valid_number(num_str, source_base)) {
        printf("The number do not conform wiht its base.\n");
        return;
    }
    
    // 转换为十进制
    decimal_value = base_to_dec(num_str, source_base);
    
    // 从十进制转换为目标进制
    char *result = dec_to_base(decimal_value, target_base, precision);
    
    printf("\nResult: %s [base %d] to %s [base %d]\n", 
           num_str, source_base, result, target_base);
}

// 验证输入的数值是否符合指定进制
int is_valid_number(const char *num_str, int base) {
    const char *ptr = num_str;
    int has_digits = 0;
    int has_point = 0;
    
    // 处理符号
    if (*ptr == '+' || *ptr == '-') {
        ptr++;
    }
    
    // 检查每个字符
    while (*ptr) {
        if (*ptr == '.') {
            if (has_point) return 0; // 多个小数点
            has_point = 1;
            ptr++;
            continue;
        }
        
        int value = char_to_value(*ptr);
        if (value == -1 || value >= base) {
            return 0; // 非法字符
        }
        
        has_digits = 1;
        ptr++;
    }
    
    return has_digits;
}

// 将字符转换为对应的值
int char_to_value(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1; // 无效字符
}

// 将值转换为对应的字符
char value_to_char(int value) {
    if (value >= 0 && value <= 9) return '0' + value;
    if (value >= 10 && value <= 15) return 'A' + (value - 10);
    return '?'; // 无效值
}