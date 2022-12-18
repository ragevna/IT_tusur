//#pragma warning(disable:4996)

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Объявление структуры Good, хранящей информацию о товарах
typedef struct good {
    char *name;       // название  товара
    double    price;      // цена товара
    int       count;      // количество товара
} good;

// Объявление структуры users, хранящей информацию о пользователях
typedef struct users {
    string  name;         // имя/логин
    string  password;     // пароль
    bool    isAdmin = false; // права администратора
} users;

// Задание максимального количества пользователей - 10
const int usersQuantity = 10;
// Создание массива структур users для хранения информации о пользователях
users user[usersQuantity];
// Переменная, которая хранит индекс пользователя, вошедшего в систему
int loggedUser = -1;

// Функция для добавления товаров в список
// Принимает в качестве аргументов - массив структур, текущий размер, максимальный разер
void addGood(good** goods, int* size, int* capacity) {

    // Ввод информации о товаре - имя, цена, количество

    // По какой-то причине, использование cin или scanf() в string напрямую, вызывает Segmentation Fault
    char tmpStr[100];
    cout << "Введите описание товара: ";
    scanf("%s", &tmpStr);
    // Выделяем память под имя, размером в длину введеной строки
    (*goods)[*size].name = (char*)malloc(strlen(tmpStr));
    strcpy((*goods)[*size].name, tmpStr);

    cout << "Введите цену товара: ";
    scanf("%lf", &(*goods)[*size].price);
    cout << "Введите количество товара: ";
    scanf("%d", &(*goods)[*size].count);

    cout << "\nЭлемент " << (*goods)[*size].name << " ценой " << (*goods)[*size].price << ", в количестве " << (*goods)[*size].count << " был успешно добавлен в массив.\n";

    // Увеличение текущего размера на 1, т.к. был добавлен новый элемент
    (*size)++;

    // Если текущий размер равен или больше чем максимальный размер массива, то
    if (*size >= *capacity) {
        // увеличиваем макс. размер в два раза
        *capacity *= 2;
        // реаллокейтим память
        // (тип памяти)realloc(объект, размер)
        *goods = (good*)realloc(*goods, *capacity * sizeof(good));
    }
    cout << "\nНажмите любую кнопку для продолжения...\n";
    system("pause");
    system("cls");
}

// Функция для отображения товаров в списке
// Принимает в качестве аргументов - массив структур, текущий размер
void printGoods(good* goods, int size) {

    // Если текущий размер равен нулю (т.е. в массиве нет элеметов)
    if (size == 0) {
        cout << "Ни один товар не добавлен.";

    } else {
        // построение "табличного" вывода информации о содержимом массива - шапка
        cout << setw(12) << "Товар " << setw(12) << "Цена " << setw(12) << "Количество\n";

        // цикличный перебор массива до size, чтобы не гонять пустые элементы
        for (int i = 0; i < size; i++)
            // продолжение "табличного" вывода - информация
            cout << setw(12) << goods[i].name << setw(12) <<  goods[i].price << setw(12) << goods[i].count << "\n";
    }

    cout << "\nНажмите любую кнопку для продолжения...\n";
    system("pause");
    system("cls");
}

// Функция для нахождения товара с самой высокой ценой
// Принимает в качестве аргументов - массив структур, текущий размер
void printHighest(good* goods, int size) {
    // max - цена товара, imax - индекс товара
    double max = goods[0].price;
    int imax = 0;

    // цикличный перебор массива до size, чтобы не гонять пустые элементы
    for (int i = 1; i < size; i++) { // тут с единицы, потому что по умолчанию в переменной хранится ноль
        // Если цена товара с индексом i больше чем цена в переменной max, то
        if (goods[i].count > max) {
            // обновляем максимальную цену и ее индекс
            max = goods[i].price;
            imax = i;
        }
    }

    cout << "Самая высокая цена - " << max << ", Товар - "<< goods[imax].name << "\n";
    cout << "\nНажмите любую кнопку для продолжения...\n";
    system("pause");
    system("cls");
}

// Функция аналогичная предыдущей, но искомая цена - минимальная
void printLowest(good* goods, int size) {
    double min = goods[0].price;
    int imin = 0;

    for (int i = 1; i < size; i++) {
        if (goods[i].count < min) {
            min = goods[i].price;
            imin = i;
        }
    }
    cout << "Самая низкая цена - " << min << ". Товар - "<< goods[imin].name << "\n";
    cout << "\nНажмите любую кнопку для продолжения...\n";
    system("pause");
    system("cls");
}

// Функция для вывода меню
void printMenu() {
    system("cls");  // очищаем экран
    cout << "Что вы бы хотели сделать?\n"
         << "1. Добавить товар в список\n"
         << "2. Показать все товары в списке\n"
         << "3. Показать товар с самой высокой ценой из списка\n"
         << "4. Показать товар с самой низкой ценой из списка\n"
         << "5. Показать список всех пользователей\n"
         << "6. Зарегистрировать нового пользователя\n"
         << "9. Выход из системы\n"
         << "0. Выход из программы\n"
         << ">> ";
}

// Функция для регистрации пользователей
void userRegistration() {
    system("cls");

    string login, password;

    cout << "Начат процесс регистрации. \nВведите имя пользователя: ";
    cin >> login;
    cout << "Введите пароль пользователя: ";
    cin >> password;

    // Циклический перебор массива пользователей, для обнаружения пустого индекса и внесения туда данных нового пользователя
    for (int i = 0; i < usersQuantity; i++){
        // Если поле name в индексе не пустое, то
        if (!user[i].name.empty()) {
            continue;
        }
        else {
            // Присвоение данных. isAdmin всегда false, ибо не надо нам больше админов
            user[i].name = login;
            user[i].password = password;
            user[i].isAdmin = false;
            cout << "Пользователь" << login << "успешно добавлен";
            cout << "\nНажмите любую кнопку для продолжения...\n";
            system("pause");
            system("cls");
            return;
        }
    }
}

// Функция для отображения окна и выполнения процесса авторизации/регистрации
bool showLoginUI() {

    // Две флаговые переменные для отслеживания успешности процесса авторизации
    bool successFlag = false, userFoundFlag = false;
    string login, password;
    int choice;

    cout << "1. Авторизация\n2. Регистрация\n Введите цифру: ";
    cin >> choice;

    switch (choice) {
    case 1:
        // Бесконечный цикл, чтобы не было возможности выйти по желанию, до окончания процесса авторизации
        for (;;) {
            cout << "Имя пользователя:";
            cin >> login;
            cout << "Пароль:";
            cin >> password;

            // Циклический перебор массива пользователей
            for (int i = 0; i < usersQuantity; i++) {
                // Поиск совпадений в логинах
                if (user[i].name == login) {
                    // При обнаружении логина в массиве, ставим флаг о нахождении пользователя
                    userFoundFlag = true;

                    // Если поле пароля пользоавтеля совпадает с введенным паролем, то
                    if (user[i].password == password) {
                        // Также устанавливается флаг об успешности авторизации и в loggedUser присваивается индекс авторизованного пользователя
                        successFlag = true;
                        loggedUser = i;
                    }
                }
            }
            // Очищаем экран, подводим итоги
            system("cls");
            // Если пользователь не найден
            if (!userFoundFlag) {
                cout << "Пользователь " << login << " не найден. Попробуйте еще раз.\n\n";
            }
            // Если пользователь найден, но неверный пароль
            if (userFoundFlag && !successFlag) {
                cout << "Неправильный пароль! Попробуйте еще раз.\n\n";
            }
            // Если авторизация успешна
            if (successFlag) {
                return true;
            }
        }
    case 2:
        // В случае выбора регистрации нового пользователя:
        // обращаемся к функции регистрации
        userRegistration();
        showLoginUI();
    default:
        system("cls");
        cin.clear();
        cin.ignore(1,'\n');
        cout << "ошибка новичка.";
        showLoginUI();
    }
}

// Функция вывода информации о существующих в программе пользователях
void printUsers() {
    system("cls");

    cout << "Для просмотра учетных данных пользователей необходимо войти под учетной записью с правами администратора.\n\n";
    // Если у пользоавтеля есть админские права - выводим информацию, иначе - нет.
    if (user[loggedUser].isAdmin) {
        cout << setw(12) << "user" << setw(12) << "password\n"; // шапка таблицы пользователей
        // циклический перебор массива до обнаружения пустого индекса
        for (int i = 0; i < usersQuantity; i++) {
            if (user[i].name.empty()) {
                break;
            }
            cout << setw(12) << user[i].name << setw(12) << user[i].password << "\n"; // информация о пользователях
        }
    }
    else {
        cout << "Пользователь " << user[loggedUser].name << " не имеет прав администратора.\n";
    }
    cout << "\nНажмите любую кнопку для продолжения...\n";
    system("pause");
    system("cls");
}

int main() {

    setlocale(LC_ALL, "Russian");

    // DefaultUser0
    user[0].name = "ragevna";
    user[0].password = "P@ssw0rd";
    user[0].isAdmin = true;

    int variant;        // выбранный пункт меню
    int size = 0;       // количество элементов массива товаров
    int capacity = 1;   // ёмкость массива товаров

    // Переменная отвечающая за статус авторизации, по умолчанию равна статусу "не авторизован" (false)
    bool loggedIn = false;

    // выделение памяти под массив goods
    good* goods = (good*)malloc(capacity * sizeof(good));

    // Перенаправление на LoginUI, пока статус авторизации не будет "авторизован"(true)
    while (!loggedIn) {
        loggedIn = showLoginUI();
    }

    do {
        printMenu(); // выводим меню на экран

        cout << "Выберите номер: ";
        cin >> variant;

        switch (variant) {
        case 1:
            addGood(&goods, &size, &capacity);
            break;

        case 2:
            printGoods(goods, size);
            break;

        case 3:
            printHighest(goods, size);
            break;

        case 4:
            printLowest(goods, size);
            break;
        case 5:
            printUsers();
            break;
        case 6:
            userRegistration();
            break;
        case 9:
            loggedIn = false;
            system("cls");
            showLoginUI();
            break;
        case 0:
            return 0;
        default:
            system("cls");
            printMenu();
        }

    } while (variant != 0);

    return 0;
}
