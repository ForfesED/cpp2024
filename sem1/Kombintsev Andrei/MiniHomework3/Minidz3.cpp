#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Базовый класс для предметов
class ItemBase {
protected:
    std::string name;
    double price;
    double weight;
public:
    ItemBase( std::string& name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    double getPrice()  { return price; }
    double getWeight()  { return weight; }

    virtual void printInfo()  = 0;
};

// Классы-наследники для разных типов предметов
class FoodItem : public ItemBase {
public:
    FoodItem( std::string& name, double price, double weight)
        : ItemBase(name, price, weight) {}

    void printInfo()  override {
        std::cout << "Food Item: " << name << ", Price: " << price << ", Weight: " << weight << std::endl;
    }
};

class GameItem : public ItemBase {
public:
    GameItem( std::string& name, double price, double weight)
        : ItemBase(name, price, weight) {}

    void printInfo()  override {
        std::cout << "Game Item: " << name << ", Price: " << price << ", Weight: " << weight << std::endl;
    }
};

class TechItem : public ItemBase {
public:
    TechItem( std::string& name, double price, double weight)
        : ItemBase(name, price, weight) {}

    void printInfo()  override {
        std::cout << "Tech Item: " << name << ", Price: " << price << ", Weight: " << weight << std::endl;
    }
};

// Класс для магазина
class Store {
private:
    std::string storeName;
    std::vector<ItemBase*> items;
public:
    Store( std::string& name) : storeName(name) {}

    void addItem(ItemBase* item) {
        items.push_back(item);
    }

     std::string& getName()  {
        return storeName;
    }

    void calculateAverages()  {
        double totalWeight = 0;
        double totalPrice = 0;
       const int itemCount = items.size();

        for ( auto& item : items) {
            totalPrice += item->getPrice();
            totalWeight += item->getWeight();
        }

        std::cout << "Store: " << storeName << std::endl;
        if (itemCount > 0) {
            std::cout << "Average Price: " << totalPrice / itemCount << std::endl;
            std::cout << "Average Weight: " << totalWeight / itemCount << std::endl;
        } else {
            std::cout << "No items in store." << std::endl;
        }
    }

    ~Store() {
        for (auto item : items) {
            delete item;
        }
    }
};

// Функция для чтения данных из файла
void readDataFromFile( std::vector<Store>& stores) {
    std::ifstream file("list.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storeName, itemType, itemName;
        double price, weight;

        if (!(iss >> storeName >> itemType >> itemName >> price >> weight)) {
            continue; // Защита от дурака, если есть строки с ошибками.
        }

        Store* store = nullptr;
        for (auto& s : stores) {
            if (s.getName() == storeName) {
                store = &s;
                break;
            }
        }

        if (!store) {
            stores.emplace_back(storeName);
            store = &stores.back();
        }

        if (itemType == "Food") {
            store->addItem(new FoodItem(itemName, price, weight));
        } else if (itemType == "Game") {
            store->addItem(new GameItem(itemName, price, weight));
        } else if (itemType == "Tech") {
            store->addItem(new TechItem(itemName, price, weight));
        }
    }
}

// Основная функция
int main() {
    std::vector<Store> stores;
    readDataFromFile(stores);

    if (stores.empty()) {
        std::cout << "No stores were loaded from the file." << std::endl;
    }

    for (auto& store : stores) {
        store.calculateAverages();
    }

    return 0;
}