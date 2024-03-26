#include <iostream>
#include <algorithm>
using namespace std;

int n;

void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void XuatMangMerge(int a[], int left, int mid, int right) {
    for (int i = 0; i < left; i++) {
        cout << a[i] <<" ";
    }
    cout << "[ ";
    for (int i = left; i <= right; i++) {
        cout << a[i] << " ";
    }
    cout << "] ";
    for (int i = right + 1; i < n; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

void selectionSortReverse(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(a[i], a[maxIndex]);
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
        if (minIndex != i)
            XuatMang(a, n);
    }
}

void selectionSortString(string& a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void selectionSortString(string a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}
void selectionSortString(pair<string, int> a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].first < a[minIndex].first) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                XuatMang(a, n);
            }
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            XuatMang(a, n);
            j--;
        }
        a[j + 1] = key;
        XuatMang(a, n);
    }
}

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
        XuatMangMerge(a, left, mid, right);
    }
}

// search

void binarySearch(pair<string, int> a[], string x, int n){
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid].first == x) {
            cout << a[mid].second << endl;
            return;
        }
        if (a[mid].first < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }   
    }
    cout << "-1" << endl;
    return;
}

void binarySearch(int a[], int x, int n){
    int left = 0, right = n - 1, mid;
    while (left <= right) {
         mid = left + (right - left) / 2;
        if (a[mid] == x) {
            cout << mid << endl;
            return;
        }
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }   
    }
    cout << mid + 1 << endl;
    return;
}
void binarySearchRevese(int a[], int x, int n){
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            cout << 1 << endl;
            return;
        }
        if (a[mid] > x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }   
    }
    cout << "0" << endl;
    return;
}

void binarySearch(string a[], string x, int n){
    int left = 0, right = n - 1, mid;
    while (left <= right) {
         mid = left + (right - left) / 2;
        if (a[mid] == x) {
            cout << mid << endl;
            return;
        }
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }   
    }
    cout << mid << endl;
    return;
}
void binarySearchRevese(string a[], string x, int n){
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            cout << mid << endl;
            return;
        }
        if (a[mid] > x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }   
    }
    cout << "-1" << endl;
    return;
}
void selectionSortPair(pair<string, int> a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].first < a[minIndex].first) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}



int main() {
    
    int n;
    int a[1000] , x;
    pair<string, int> b[1000];
    string d[1000];
    string c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    selectionSortPair(b, n);
    selectionSortString(d, n);
    for (int i = 0; i < n; i++) {
        cout << d[i] << endl;
    }
}