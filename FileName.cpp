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

void addItem(string name, string type, int level) {
    if (itemCount < MAX_ITEMS) {
        inventory[itemCount].name = name;
        inventory[itemCount].type = type;
        inventory[itemCount].level = level;
        itemCount++;
        cout << "Добавлен: " << name << "\n";
    }
    else {
        cout << "Инвентарь полон!\n";
    }
}

void removeItem(string name) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].name == name) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            cout << "Удален: " << name << "\n";
            return;
        }
    }
    cout << "Не найден: " << name << "\n";
}

void printInventory() {
    cout << "\n--- ИНВЕНТАРЬ (" << itemCount << ") ---\n";
    for (int i = 0; i < itemCount; i++) {
        cout << inventory[i].name << " | "
            << inventory[i].type << " | "
            << inventory[i].level << "\n";
    }
}

void sortByLevel() {
    for (int i = 0; i < itemCount - 1; i++) {
        for (int j = 0; j < itemCount - i - 1; j++) {
            if (inventory[j].level > inventory[j + 1].level) {
                Item temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
    cout << "Отсортировано по уровню\n";
}

void filterByType(string type) {
    cout << "\n--- " << type << " ---\n";
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].type == type) {
            cout << inventory[i].name << " | " << inventory[i].level << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
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
