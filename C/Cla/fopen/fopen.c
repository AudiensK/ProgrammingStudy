// FILE* fopen(const char* restrict path, const char* restrict mode);
// FILE *fopen(const char *filename, const char *mode);
// int fclose(FILE *stream);
// fscanf(FILE*, ...)
// fprintf(FILE*, ...)
/* 打开文件的标准代码
FILE* fp = fopen("file", "r");  // 文件名， 模式
if (fp) {
    fscanf(fp, ...);
    fclose(fp);
} else {
    ...
}
*/
/* 模式
r 打开只读；r+ 打开读写，从文件头开始；
w 打开只写，如果不存在则新建，如果存在则清空；
w+ 打开读写，如果不存在则新建，如果存在则清空；
a 打开追加，如果不存在则新建，如果存在则从文件尾开始；
..x 在模式后面加上x后缀（比如ax） 只新建，如果文件已存在则不能打开
*/


#include <stdio.h>


int main()
{
    FILE *fp = fopen("12345.txt", "r");
    if (fp) {
        int num;
        fscanf(fp, "%d", &num);
        printf("%d\n", num);
        fclose(fp);
    } else {
        printf("无法打开该文件\n");
    }

    getchar();

    return 0;
}