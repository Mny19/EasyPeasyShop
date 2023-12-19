#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Product {
public:
    string name;
    string category;
    double price;

    Product(string n, string c, double p) : name(n), category(c), price(p) {}

    void display() const {
        cout << name << " (" << category << ") - $" << fixed << setprecision(2) << price;
    }
};

class ShoppingCart {
public:
    vector<Product> items;

    void addProduct(const Product& product) {
        items.push_back(product);
    }

    void displayCart() const {
        cout << "Shopping Cart:\n";
        double total = 0.0;
        for (const auto& item : items) {
            item.display();
            cout << endl;
            total += item.price;
        }
        cout << "Total: $" << fixed << setprecision(2) << total << endl;
    }
};

class OnlineStore {
public:
    string storeName = "EasyPeasyShop";
    vector<Product> products;
    ShoppingCart cart;

    void displayMenu() const {
        cout << "1. Explore by Category\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
    }

      void displayWelcomeMessage() const {
        cout << "**********************************" << endl;
        cout << "* Welcome to " << storeName << " *" << endl;
        cout << "**********************************" << endl;
        cout << "Your Easy and Fun Online Shopping Destination!" << endl;
        cout << "Discover a wide range of products at unbeatable prices." << endl;
        cout << "Enjoy hassle-free shopping with just a few clicks!" << endl;
        cout << endl;
    }

    void exploreByCategory() const {
        cout << "Available Categories:\n";
        vector<string> categories;
        for (const auto& product : products) {
            if (find(categories.begin(), categories.end(), product.category) == categories.end()) {
                categories.push_back(product.category);
                cout << categories.size() << ". " << product.category << endl;
            }
        }

        int categoryChoice;
        cout << "Choose a category (1-" << categories.size() << "): ";
        cin >> categoryChoice;

        if (categoryChoice >= 1 && categoryChoice <= categories.size()) {
            string selectedCategory = categories[categoryChoice - 1];
            cout << "Products in the category '" << selectedCategory << "':\n";
            for (const auto& product : products) {
                if (product.category == selectedCategory) {
                    product.display();
                    cout << endl;
                }
            }
        } else {
            cout << "Invalid category choice.\n";
        }
    }

    void addToCart() {
        string productName;
        cout << "Enter product name to add to cart: ";
        cin.ignore();
        getline(cin, productName);

        auto it = find_if(products.begin(), products.end(),
                          [&](const Product& p) {
                              return toLowerCase(p.name) == toLowerCase(productName);
                          });

        if (it != products.end()) {
            cart.addProduct(*it);
            cout << productName << " added to the cart.\n";
        } else {
            cout << "Product not found.\n";
        }
    }

    void checkout() {
        cout << "Checkout completed. Thank you for shopping!\n";
        cart.displayCart();
        cart.items.clear();
    }

private:
    string toLowerCase(const string& s) const {
        string result(s);
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    string centerText(const string& text, int width) const {
        int padding = (width - text.length()) / 2;
        string paddedText = string(padding, ' ') + text + string(padding, ' ');
        if ((width - text.length()) % 2 != 0) {
            paddedText += ' ';
        }
        return paddedText;
    }
};

int main() {
    OnlineStore store;

    store.products.push_back(Product("Shirt", "Men's", 25.99));
    store.products.push_back(Product("Jeans", "Men's", 42.99));
    store.products.push_back(Product("V- Neck Sweater", "Men's", 55.99));
    store.products.push_back(Product("Trousers ", "Men's", 49.99));
    store.products.push_back(Product("T-shirt", "Men's", 22.99));
    store.products.push_back(Product("Hoodie 1", "Men's", 29.99));
    store.products.push_back(Product("Jacket ", "Men's", 65.99));
    store.products.push_back(Product("Shorts ", "Men's", 28.99));
    store.products.push_back(Product("Polo Shirt ", "Men's", 25.99));
    store.products.push_back(Product("Casual T-shirt", "Men's", 39.99));

    store.products.push_back(Product("Dress", "Women's", 39.99));
    store.products.push_back(Product("Handbag", "Women's", 49.99));
    store.products.push_back(Product("Jacket", "Women's", 59.99));
    store.products.push_back(Product("Skirt", "Women's", 29.99));
    store.products.push_back(Product("Gown", "Women's", 27.99));
    store.products.push_back(Product("Crop Top", "Women's", 68.99));
    store.products.push_back(Product("top", "Women's", 35.99));
    store.products.push_back(Product("Suit", "Women's", 38.99));
    store.products.push_back(Product("saree", "Women's", 59.99));
    store.products.push_back(Product("Pajama", "Women's", 34.99));

    store.products.push_back(Product("Toy", "Kids", 15.99));
    store.products.push_back(Product("Board Game", "Kids", 19.99));
    store.products.push_back(Product("Backpack ", "Kids", 24.99));
    store.products.push_back(Product("Pajamas ", "Kids", 18.99));
    store.products.push_back(Product("Globe ", "Kids", 29.99));
    store.products.push_back(Product("Action Figure ", "Kids", 12.99));
    store.products.push_back(Product("Bicycle ", "Kids", 69.99));
    store.products.push_back(Product("Bat", "Kids", 29.99));
    store.products.push_back(Product("Stationary Set", "Kids", 23.99));
    store.products.push_back(Product("Ball", "Kids", 34.99));
    store.products.push_back(Product("Pen Set", "Kids", 16.99));
    store.products.push_back(Product("Tricycle", "Kids", 79.99));

    store.products.push_back(Product("Unisex Watch", "Accessories", 49.99));
    store.products.push_back(Product("Sunglasses", "Accessories", 29.99));
    store.products.push_back(Product("Men's Watch", "Accessories", 69.99));
    store.products.push_back(Product("Women's Bracelet", "Accessories", 39.99));
    store.products.push_back(Product("Unisex Scarf ", "Accessories", 22.99));
    store.products.push_back(Product("Men's Belt ", "Accessories", 18.99));
    store.products.push_back(Product("Women's Hat", "Accessories", 24.99));
    store.products.push_back(Product("Men's Bracelet ", "Accessories", 79.99));
    store.products.push_back(Product("Women's Watch", "Accessories", 49.99));
    store.products.push_back(Product("Unisex Perfume", "Accessories", 29.99));
    store.products.push_back(Product("Men's Hat", "Accessories", 24.99));
    store.products.push_back(Product("Women's Perfume", "Accessories", 32.99));

    store.displayWelcomeMessage();

    int choice;
    do {
        store.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.exploreByCategory();
                break;
            case 2:
                store.addToCart();
                break;
            case 3:
                store.cart.displayCart();
                break;
            case 4:
                store.checkout();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
