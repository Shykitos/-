#include <iostream>
#include <string>
#include <cmath>

class Account {
private:
    std::string ownerName;
    std::string accountNumber;
    double interestRate;
    double balance;

    // Оголошуємо масиви рядків для пропису чисел та валюти як приватні статичні поля
    static const std::string units[];
    static const std::string teens[];
    static const std::string tens[];
    static const std::string hundreds[];
    static const std::string thousands[];
    static const std::string millions[];
    static const std::string billions[];

public:
    // Конструктор ініціалізації
    Account(std::string name, std::string number, double rate, double initialBalance)
        : ownerName(name), accountNumber(number), interestRate(rate), balance(initialBalance) {}

    // Конструктор без аргументів
    Account() : ownerName(""), accountNumber(""), interestRate(0.0), balance(0.0) {}

    // Конструктор копіювання
    Account(const Account& other)
        : ownerName(other.ownerName), accountNumber(other.accountNumber),
        interestRate(other.interestRate), balance(other.balance) {}

    // Деструктор (можна просто не вказувати, C++ автоматично згенерує за замовчуванням)

    // Метод виведення на екран
    void Display() {
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
        std::cout << "Balance: " << balance << " грн." << std::endl;
    }

    // Метод для зміни власника рахунку
    void ChangeOwner(std::string newName) {
        ownerName = newName;
    }

    // Метод для зняття грошей з рахунку
    void Withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Знято " << amount << " грн. Залишок: " << balance << " грн." << std::endl;
        }
        else {
            std::cout << "Недостатньо коштів на рахунку." << std::endl;
        }
    }

    // Метод для покладання грошей на рахунок
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Покладено " << amount << " грн. Залишок: " << balance << " грн." << std::endl;
        }
        else {
            std::cout << "Сума для внесення повинна бути більше нуля." << std::endl;
        }
    }

    // Метод для нарахування відсотків
    void AccrueInterest() {
        double interestAmount = balance * (interestRate / 100);
        balance += interestAmount;
        std::cout << "Нараховано відсотки: " << interestAmount << " грн. Залишок: " << balance << " грн." << std::endl;
    }

    // Метод для переведення суми в долари (припускаємо курс 1 долар = 38 грн)
    double ConvertToDollars() {
        return balance / 38.0;
    }

    // Метод для отримання суми прописом
    std::string AmountInWords() {
        // Округлюємо суму до двох знаків після коми
        double roundedBalance = round(balance * 100) / 100;

        // Розділяємо суму на гривні і копійки
        int hryvniaPart = static_cast<int>(roundedBalance);
        int kopiykaPart = static_cast<int>((roundedBalance - hryvniaPart) * 100);

        // Перетворюємо гривні в літерний рядок
        std::string hryvniaWords;
        int hryvnia = hryvniaPart;
        int hryvniaThousand = 0;

        while (hryvnia > 0) {
            int part = hryvnia % 1000;
            if (part > 0) {
                if (hryvniaThousand > 0) {
                    hryvniaWords = thousands[hryvniaThousand] + " " + hryvniaWords;
                }
                hryvniaWords = ConvertThreeDigitNumber(part) + " " + hryvniaWords;
            }
            hryvnia /= 1000;
            hryvniaThousand++;
        }

        // Перетворюємо копійки в літерний рядок
        std::string kopiykaWords;
        if (kopiykaPart > 0) {
            kopiykaWords = ConvertTwoDigitNumber(kopiykaPart);
        }

        // Формуємо результат
        std::string result = hryvniaWords + " грн.";
        if (!kopiykaWords.empty()) {
            result += " " + kopiykaWords + " коп.";
        }

        return result;
    }

private:
    // Приватний метод для перетворення трьохзначного числа в літерний рядок
    std::string ConvertThreeDigitNumber(int num) {
        int hundredsDigit = num / 100;
        int tensDigit = (num % 100) / 10;
        int unitsDigit = num % 10;

        std::string result = "";

        if (hundredsDigit > 0) {
            result += hundreds[hundredsDigit] + " ";
        }

        if (tensDigit == 1) {
            result += teens[unitsDigit] + " ";
        }
        else {
            if (tensDigit > 0) {
                result += tens[tensDigit] + " ";
            }

            if (unitsDigit > 0) {
                result += units[unitsDigit] + " ";
            }
        }

        return result;
    }

    // Приватний метод для перетворення двозначного числа в літерний рядок
    std::string ConvertTwoDigitNumber(int num) {
        int tensDigit = num / 10;
        int unitsDigit = num % 10;

        std::string result = "";

        if (tensDigit == 1) {
            result += teens[num] + " ";
        }
        else {
            if (tensDigit > 0) {
                result += tens[tensDigit] + " ";
            }

            if (unitsDigit > 0) {
                result += units[unitsDigit] + " ";
            }
        }

        return result;
    }
};

// Ініціалізація статичних полів для масивів рядків
const std::string Account::units[] = { "", "одна", "дві", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять" };
const std::string Account::teens[] = { "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять" };
const std::string Account::tens[] = { "", "", "двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто" };
const std::string Account::hundreds[] = { "", "сто", "двісті", "триста", "чотириста", "п'ятсот", "шістсот", "сімсот", "вісімсот", "дев'ятсот" };
const std::string Account::thousands[] = { "", "тисяча", "тисячі", "тисяч" };
const std::string Account::millions[] = { "", "мільйон", "мільйона", "мільйонів" };
const std::string Account::billions[] = { "", "мільярд", "мільярда", "мільярдів" };

int main() {
    // Приклад використання класу Account:
    Account myAccount("Шикітка Микола", "12345", 5.0, 1000.0);

    myAccount.Display();
    myAccount.ChangeOwner("Шикітка Петро");
    myAccount.Display();
    myAccount.Deposit(500);
    myAccount.Display();
    myAccount.Withdraw(200);
    myAccount.Display();
    myAccount.AccrueInterest();
    myAccount.Display();

    double dollars = myAccount.ConvertToDollars();
    std::cout << "Баланс у доларах: $" << dollars << std::endl;

    std::string amountInWords = myAccount.AmountInWords();
    std::cout << "Сума прописом: " << amountInWords << std::endl;

    return 0;
}
