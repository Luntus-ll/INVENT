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
    } else {
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
    cout << "\n--- Èíâåíòàðü (" << itemCount << ") ---\n";
    for (int i = 0; i < itemCount; i++) {
        cout << inventory[i].name << " | "
            << inventory[i].type << " | "
            << inventory[i].level << "\n";
    }
}
int main(){
    setlocale(LC_ALL ," ")
    addItem("Ìå÷", "îðóæèå", 10);
    addItem("Ùèò", "áðîíÿ", 5);
    addItem("Çåëüå", "çåëüå", 1);
    addItem("Ëóê", "îðóæèå", 8);
    addItem("Øëåì", "áðîíÿ", 3);

    while (true) {
        cout << "\n1. Äîáàâèòü 2. Óäàëèòü 3. Ïîêàçàòü 4. Ñîðòèðîâàòü 5. Ôèëüòð 0. Âûõîä\n";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string name, type;
            int level;
            cout << "Íàçâàíèå: "; cin >> name;
            cout << "Òèï: "; cin >> type;
            cout << "Óðîâåíü: "; cin >> level;
            addItem(name, type, level);
        }
        else if (choice == 2) {
            string name;
            cout << "Íàçâàíèå äëÿ óäàëåíèÿ: "; cin >> name;
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
            cout << "Òèï äëÿ ôèëüòðà: "; cin >> type;
            filterByType(type);
        }
    }
    return 0;

}
