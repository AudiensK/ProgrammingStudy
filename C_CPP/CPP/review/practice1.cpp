#include <iostream>
#include <array>

void ret_nums();
void show_time();

class FormattedTime
{
    private:
        int hours, minutes, seconds;
    
    public:
        FormattedTime(int s = 0, int m = 0, int h = 0) : hours(h), minutes(m), seconds(s)
        {
            if (seconds < 0 || minutes < 0 || hours < 0) {
                throw std::invalid_argument("时间不能为负数。");
            }

            if (seconds >= 60) {
                minutes += seconds / 60;
                seconds %= 60;
            } 

            if (minutes >= 60) {
                hours += minutes / 60;
                minutes %= 60;
            } 
        }
    
        ~FormattedTime() {}

        void show_formatted_time() const
        {
            std::cout << "格式化后的时间为：\n\t" 
                << hours << "小时" << minutes << "分钟" << seconds << "秒" << std::endl;
        }
    
    protected:
};


int main()
{
    // 1：用户输入两个整数，程序显示这两个数的和、差、积以及余数。

    // 2：编写一个程序，让用户输入以秒为单位的时长，程序按照时分秒显示时长。

    // 3：用户输入两个整数，如果这两个整数都是偶数或者这两个整数都是奇数，\
    则显示这两个数的平均值；否则，显示这两个数中的较大值。


    std:: cout << "\t1：用户输入两个整数，程序显示这两个数的和、差、积以及余数。\n\n"
        "\t2：编写一个程序，让用户输入以秒为单位的时长，程序按照时分秒显示时长。\n\n"
        "\t3：用户输入两个整数，如果这两个整数都是偶数或者这两个整数都是奇数，\n\n"
        "\t则显示这两个数的平均值；否则，显示这两个数中的较大值。\n\n" 
        "\t0：退出程序。\n" << std::endl;

    int choice = 1;
    while (choice) {
        
        std::cout << "请输入选项编号：";
        std::cin >> choice;

        switch (choice) {
            case 0: 
                break;
            case 1: 
                ret_nums(); 
                choice = 0; 
                break;
            case 2: 
                show_time();
                choice = 0; 
                break;
            case 3: 
                choice = 0; 
                break;
            default: std::cout << "选项不存在，请重新输入；";
        }
    }
    

    return 0;
}


void ret_nums()
{
    int a, b;
    std::cout << "请输入两个整数" << std::endl;
    std::cin >> a >> b;

    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int remainder = a % b;

    std::array<int, 4> result = {sum, difference, product, remainder};

    std::cout << "这两个数的和、差、积以及余数分别是：";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << " " << result[i];
    }
    std::cout << std::endl;
}


void show_time()
{
    std::cout << "请输入时间（秒）：";
    int sec;
    std::cin >> sec;
    FormattedTime Time = FormattedTime(sec);
    Time.show_formatted_time();
}

