#include<string>
#include <vector>

class Rekenen {
    public:
    int getDateMenu();
    int ifBill(std::string dayBillRecord);
    int printBill(std::vector<std::vector<std::string>> daysWithRekening);
    std::string* getDateSpan();
};