#include <iostream>
#include <list>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int n, k;
    cout << "Введите количество людей и шаг: ";
    cin >> n >> k;

    list<int> circle;
    for (int i = 1; i <= n; i++) {
        circle.push_back(i);
    }

    list<int>::iterator it = circle.begin();
    while (circle.size() > 1) {
        for (int i = 1; i < k; i++) {
            it++;
            if (it == circle.end()) {
                it = circle.begin();
            }
        }
        cout << "Удаляется человек №" << *it << endl;
        it = circle.erase(it);
        if (it == circle.end()) {
            it = circle.begin();
        }
    }

    cout << "Остался человек №" << *circle.begin() << endl;

    return 0;
}
