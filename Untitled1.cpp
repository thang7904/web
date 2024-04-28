#include <iostream>
#include <string>

using namespace std;

struct ChuyenBay {
    string soHieu;
    int giaVe;
    int soGhe;
};

void hienThiChuyenBayTren700000(const ChuyenBay chuyenBay[], int n, int index, int nguong) {
    if (index >= n) {
        return;
    }
    if (chuyenBay[index].giaVe > nguong) {
        cout << "Chuyen bay " << chuyenBay[index].soHieu << " - Gia ve: " << chuyenBay[index].giaVe << endl;
    }
    hienThiChuyenBayTren700000(chuyenBay, n, index + 1, nguong);
}

ChuyenBay timChuyenBayGiaVeThapNhat(const ChuyenBay chuyenBay[], int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (chuyenBay[mid].giaVe < chuyenBay[right].giaVe) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return chuyenBay[left];
}
bool daDuocChon(const ChuyenBay chon[], int index, const ChuyenBay& chuyenBay) {
    for (int i = 0; i < index; ++i) {
        if (chon[i].soHieu == chuyenBay.soHieu) {
            return true;
        }
    }
    return false;
}

void lietKePhuongAn(const ChuyenBay chuyenBay[], int n, ChuyenBay chon[], int index) {
    if (index == 4) {
        for (int i = 0; i < 4; ++i) {
            cout << "Chuyen bay " << chon[i].soHieu << " - So ghe: " << chon[i].soGhe << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!daDuocChon(chon, index, chuyenBay[i])) {
            chon[index] = chuyenBay[i];
            lietKePhuongAn(chuyenBay, n, chon, index + 1);
        }
    }
}



int main() {
    const int n = 5; 
    ChuyenBay danhSachChuyenBay[n] = {
        {"VN001", 650000, 150},
        {"VN002", 720000, 120},
        {"VN003", 800000, 180},
        {"VN004", 680000, 200},
        {"VN005", 750000, 160}
    };

    cout << "Cac chuyen bay co gia ve tren 700000:" << endl;
    hienThiChuyenBayTren700000(danhSachChuyenBay, n, 0, 700000);
	ChuyenBay chuyenBayGiaVeThapNhat = timChuyenBayGiaVeThapNhat(danhSachChuyenBay, n);
    cout << "Chuyen bay co gia ve thap nhat: " << chuyenBayGiaVeThapNhat.soHieu << " - Gia ve: " << chuyenBayGiaVeThapNhat.giaVe << endl;
    ChuyenBay chon[4];
	lietKePhuongAn(danhSachChuyenBay, n, chon, 0);
	return 0;
}

