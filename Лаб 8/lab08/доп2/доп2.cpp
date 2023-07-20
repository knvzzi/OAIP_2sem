#include <iostream>
#include <queue>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int n;
    float num;
    queue<float> q;

    cout << "Введите количество элементов: ";
    cin >> n;
    int i = 0;
    cout << "Введите элементы очереди:\n";
    while (i < n) {
        cin >> num;
        q.push(num);
        i++;
    }

    float max_elem = q.front();
    queue<float> q_copy = q;
    while (!q_copy.empty()) {
        float curr_elem = q_copy.front();
        if (curr_elem > max_elem) {
            max_elem = curr_elem;
        }
        q_copy.pop();
    }

    while (q.front() != max_elem) {
        q.push(q.front());
        q.pop();
    }

    cout << "Элементы очереди после циклического сдвига:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
