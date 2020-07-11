#include <iostream>
using namespace std;
int heap[100005];
int n = 0;


void up(int x) {
	while (heap[x]<heap[x/2] && x>1) {
		swap(heap[x], heap[x / 2]);
		x /= 2;
	}
}
void down(int x) {
	while ((heap[x] > heap[x * 2] && x * 2 <= n) || (heap[x] > heap[x * 2 + 1] && x * 2 + 1 <= n)) {
		if (heap[x * 2] <= heap[x * 2 + 1]) {
			swap(heap[x], heap[x * 2]);
			x *= 2;
		}
		else {
			swap(heap[x], heap[x * 2+1]);
			x = x * 2 + 1;
		}
	}
}
void insert(int val) {
	heap[++n] = val;
	up(n);
}
int pop() {
	int retValue = heap[1];
	heap[1] = heap[n];
	n--;
	down(1);
	return retValue;
}

// inline void swap(int& a, int& b) {
//     int c = a;
//     a = b;
//     b = c;
// }

// void up(int ind) {
//     while (ind > 1 && heap[ind] > heap[ind / 2]) {
//         swap(heap[ind], heap[ind / 2]);
//         ind /= 2;
//     }
// }

// void down(int ind) {
//     while ((ind * 2 <= height && heap[ind] > heap[ind * 2]) ||
//            (ind * 2 + 1 <= height && heap[ind] > heap[ind * 2 + 1])) {
//         if (heap[ind * 2] <= heap[ind * 2 + 1]) {
//             swap(heap[ind], heap[ind * 2]);
//             ind *= 1;
//         } else {
//             swap(heap[ind], heap[ind * 2 + 1]);
//             ind = ind * 2 + 1;
//         }
//     }
// }

// void insert(int value) {
//     heap[++height] = value;
//     up(height);
// }

// int pop() {
//     int tmp = heap[1];
//     heap[1] = heap[height];
//     height--;
//     down(1);
//     return tmp;
// }

int main() {
    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cmd,num;
        cin >> cmd;
        if(cmd==1){
            cin >> num;
            insert(num);
        }
        if(cmd==2)cout << heap[1]<<endl;
        if(cmd==3)pop();
    }
    system("pause");
    return 0;
}