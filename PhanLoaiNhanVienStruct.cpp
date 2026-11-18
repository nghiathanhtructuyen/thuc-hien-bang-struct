#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct NhanVien
{
    string maNhanVien;
    string hoTen;
    double luongNhanVienCoBan;
};

struct NhanVienChinhThuc
{
    NhanVien nhanVienChinhThuc;
    double heSoLuong;
};

struct NhanVienPartTime
{
    NhanVien nhanVienPartTime;
    double soGioLamViec;
};

double tinhLuongChinhThuc(const NhanVienChinhThuc& nhanVienCT)
{
    return nhanVienCT.nhanVienChinhThuc.luongNhanVienCoBan * nhanVienCT.heSoLuong;
}

double tinhLuongPartTime(const NhanVienPartTime& nhanVienPT)
{
    return nhanVienPT.soGioLamViec * 50000;
}

void inThongTinNhanVienChinhThuc(const NhanVienChinhThuc& nhanVienCT)
{
    cout << left << setw(8) << nhanVienCT.nhanVienChinhThuc.maNhanVien
         << "| " << setw(20) << nhanVienCT.nhanVienChinhThuc.hoTen
         << "| Nhan vien Chinh thuc  "
         << "| Luong: " << fixed << setprecision(0) << tinhLuongChinhThuc(nhanVienCT) << " VND\n";
}

void inThongTinNhanVienPartTime(const NhanVienPartTime& nhanVienPT)
{
    cout << left << setw(8) << nhanVienPT.nhanVienPartTime.maNhanVien
         << "| " << setw(20) << nhanVienPT.nhanVienPartTime.hoTen
         << "| Nhan vien Part-Time   "
         << "| Luong: " << fixed << setprecision(0) << tinhLuongPartTime(nhanVienPT) << " VND\n";
}

int main()
{
    vector<NhanVienChinhThuc> danhSachChinhThuc;
    vector<NhanVienPartTime> danhSachPartTime;

    NhanVienChinhThuc nhanVien1;
    nhanVien1.nhanVienChinhThuc.maNhanVien = "NV01";
    nhanVien1.nhanVienChinhThuc.hoTen = "Nguyen Van A";
    nhanVien1.nhanVienChinhThuc.luongNhanVienCoBan = 5000000;
    nhanVien1.heSoLuong = 2.5;
    danhSachChinhThuc.push_back(nhanVien1);

    NhanVienPartTime nhanVien2;
    nhanVien2.nhanVienPartTime.maNhanVien = "NV02";
    nhanVien2.nhanVienPartTime.hoTen = "Tran Thi B";
    nhanVien2.nhanVienPartTime.luongNhanVienCoBan = 0;
    nhanVien2.soGioLamViec = 120;
    danhSachPartTime.push_back(nhanVien2);
    
    int soNhanVienChinhThuc, soNhanVienPartTime;
    cout << "Nhap lan luot so nhan vien chinh thuc va part-time: ";
    cin >> soNhanVienChinhThuc >> soNhanVienPartTime;

    cin.ignore();

    for (int i = 0; i < soNhanVienChinhThuc; i++)
    {
        NhanVienChinhThuc nhanVienCT;

        getline(cin, nhanVienCT.nhanVienChinhThuc.maNhanVien);
        getline(cin, nhanVienCT.nhanVienChinhThuc.hoTen);
        cin >> nhanVienCT.nhanVienChinhThuc.luongNhanVienCoBan;
        cin >> nhanVienCT.heSoLuong;

        cin.ignore();
        
        danhSachChinhThuc.push_back(nhanVienCT);
    }

    for (int i = 0; i < soNhanVienPartTime; i++)
    {
        NhanVienPartTime nhanVienPT;
        
        getline(cin, nhanVienPT.nhanVienPartTime.maNhanVien);
        getline(cin, nhanVienPT.nhanVienPartTime.hoTen);
        cin >> nhanVienPT.nhanVienPartTime.luongNhanVienCoBan;
        cin >> nhanVienPT.soGioLamViec;

        cin.ignore();
        
        danhSachPartTime.push_back(nhanVienPT);
    }

    for (int i = 0; i < danhSachChinhThuc.size(); i++)
    {
        inThongTinNhanVienChinhThuc(danhSachChinhThuc[i]);
    }

    for (int i = 0; i < danhSachPartTime.size(); i++)
    {
        inThongTinNhanVienPartTime(danhSachPartTime[i]);
    }

    return 0;
}