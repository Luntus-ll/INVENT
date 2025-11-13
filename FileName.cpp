#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    string type;
    int level;
};

const int MAX_ITEMS = 100;
Item inventory[MAX_ITEMS];
int itemCount = 0;

void printInventory() {
    cout << "\n--- Инвентарь (" << itemCount << ") ---\n";
    for (int i = 0; i < itemCount; i++) {
        cout << inventory[i].name << " | "
            << inventory[i].type << " | "
            << inventory[i].level << "\n";
    }
    cout << "-----------------------\n";
}
int main() {
    addItem("Меч", "оружие", 10);
    addItem("Щит", "броня", 5);
    addItem("Зелье", "зелье", 1);
    addItem("Лук", "оружие", 8);
    addItem("Шлем", "броня", 3);

    while (true) {
        cout << "\n1. Добавить 2. Удалить 3. Показать 4. Сортировать 5. Фильтр 0. Выход\n";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string name, type;
            int level;
            cout << "Название: "; cin >> name;
            cout << "Тип: "; cin >> type;
            cout << "Уровень: "; cin >> level;
            addItem(name, type, level);
        }
        else if (choice == 2) {
            string name;
            cout << "Название для удаления: "; cin >> name;
            removeItem(name);
        }
        else if (choice == 3) {
            printInventory();
        }
        else if (choice == 4) {
            sortByLevel();
            printInventory();
        }
        else if (choice == 5) {
            string type;
            cout << "Тип для фильтра: "; cin >> type;
            filterByType(type);
        }
    }
    return 0;
}