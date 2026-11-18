#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct TaiKhoanNganHang
{
    string soTaiKhoan;
    string tenChuTaiKhoan;
    long long soDuTaiKhoan;
};

struct TaiKhoanTietKiem
{
    TaiKhoanNganHang taiKhoanTK;
    double laiSuatHangNam;
};

struct TaiKhoanThanhToan
{
    TaiKhoanNganHang taiKhoanTT;
    long long hanMucThauChi;
};

long long tinhLaiSuatNam(const TaiKhoanTietKiem& taiKhoanTK)
{
    return taiKhoanTK.laiSuatHangNam * taiKhoanTK.taiKhoanTK.soDuTaiKhoan;
}

void inThongTinTaiKhoanTietKiem(const TaiKhoanTietKiem& taiKhoanTietKiem)
{
    cout << left << setw(10) << "| So tai khoan: " << taiKhoanTietKiem.taiKhoanTK.soTaiKhoan
         << "| Ten tai khoan: " << setw(15) << taiKhoanTietKiem.taiKhoanTK.tenChuTaiKhoan
         << "| So du tai khoan: " << setw(10) << taiKhoanTietKiem.taiKhoanTK.soDuTaiKhoan
         << "| Lai suat hang nam: " << setw(10) << taiKhoanTietKiem.laiSuatHangNam
         << "| Tien lai du kien: " << setw(10) << tinhLaiSuatNam(taiKhoanTietKiem) << " VND\n";
}

void inThongTinTaiKhoanThanhToan(const TaiKhoanThanhToan& taiKhoanThanhToan)
{
    cout << left << setw(10) << "| So tai khoan: " << taiKhoanThanhToan.taiKhoanTT.soTaiKhoan
         << "| Ten tai khoan: " << setw(15) << taiKhoanThanhToan.taiKhoanTT.tenChuTaiKhoan
         << "| So du tai khoan: " << setw(10) << taiKhoanThanhToan.taiKhoanTT.soDuTaiKhoan
         << "| Han muc thau chi: " << taiKhoanThanhToan.hanMucThauChi << " VND\n";
}

void rutTienTietKiem(TaiKhoanTietKiem& taiKhoanTietKiem, long long soTien)
{
    if (soTien > 0 && soTien <= taiKhoanTietKiem.taiKhoanTK.soDuTaiKhoan)
    {
        taiKhoanTietKiem.taiKhoanTK.soDuTaiKhoan -= soTien;
        cout << "Thanh cong rut " << soTien << " VND tu tai khoan tiet kiem.\n";
    }
    else
    {
        cout << "That bai vi so du khong du hoac so tien rut khong hop le!\n";
    }
}

void rutTienThanhToan(TaiKhoanThanhToan& taiKhoanThanhToan, long long soTien)
{
    if (soTien > 0 && soTien <= taiKhoanThanhToan.taiKhoanTT.soDuTaiKhoan)
    {
        taiKhoanThanhToan.taiKhoanTT.soDuTaiKhoan -= soTien;
        cout << "Thanh cong rut " << soTien << " VND tu tai khoan tiet kiem.\n";
    }
    else
    {
        cout << "That bai vi so du khong du hoac so tien rut khong hop le!\n";
    }
}

int main()
{
    vector<TaiKhoanTietKiem> danhSachTaiKhoanTK;
    vector<TaiKhoanThanhToan> danhSachTaiKhoanTT;

    TaiKhoanTietKiem taiKhoan1 = {{"TK01", "Nguyen Van A", 10000000}, 0.05};
    TaiKhoanThanhToan taiKhoan2 = {{"TK02", "Tran Thi B", 5000000}, 2000000};

    danhSachTaiKhoanTK.push_back(taiKhoan1);
    danhSachTaiKhoanTT.push_back(taiKhoan2);

    int soLuongTaiKhoanTK, soLuongTaiKhoanTT;
    cout << "Nhap lan luot so tai khoan tiet kiem va tai khoan thanh toan: ";
    cin >> soLuongTaiKhoanTK >> soLuongTaiKhoanTT;

    cin.ignore();

    for (int i = 0; i < soLuongTaiKhoanTK; i++)
    {
        TaiKhoanTietKiem taikhoanTietKiem;
        getline(cin, taikhoanTietKiem.taiKhoanTK.soTaiKhoan);
        getline(cin, taikhoanTietKiem.taiKhoanTK.tenChuTaiKhoan);
        cin >> taikhoanTietKiem.taiKhoanTK.soDuTaiKhoan;
        cin >> taikhoanTietKiem.laiSuatHangNam;

        danhSachTaiKhoanTK.push_back(taikhoanTietKiem);
    }

    cin.ignore();

    for (int i = 0; i < soLuongTaiKhoanTT; i++)
    {
        TaiKhoanThanhToan taikhoanThanhToan;
        getline(cin, taikhoanThanhToan.taiKhoanTT.soTaiKhoan);
        getline(cin, taikhoanThanhToan.taiKhoanTT.tenChuTaiKhoan);
        cin >> taikhoanThanhToan.taiKhoanTT.soDuTaiKhoan;
        cin >> taikhoanThanhToan.hanMucThauChi;

        danhSachTaiKhoanTT.push_back(taikhoanThanhToan);
    }

    cout << "---- Thong tin ban dau truoc giao dich ----\n";
    for (int i = 0; i < danhSachTaiKhoanTK.size(); i++)
    {
        inThongTinTaiKhoanTietKiem(danhSachTaiKhoanTK[i]);
    }

    for (int i = 0; i < danhSachTaiKhoanTT.size(); i++)
    {
        inThongTinTaiKhoanThanhToan(danhSachTaiKhoanTT[i]);
    }

    cout << "\n---- Giao dien rut tien ----\n";
    for (int i = 0; i < danhSachTaiKhoanTK.size(); i++)
    {
        rutTienTietKiem(danhSachTaiKhoanTK[i], 9000000);
    }

    for (int i = 0; i < danhSachTaiKhoanTT.size(); i++)
    {
        rutTienThanhToan(danhSachTaiKhoanTT[i], 4000000);
    }

    cout << "\n---- Thong tin tai khoan sau khi giao dich ----\n";
    for (int i = 0; i < danhSachTaiKhoanTK.size(); i++)
    {
        inThongTinTaiKhoanTietKiem(danhSachTaiKhoanTK[i]);
    }

    for (int i = 0; i < danhSachTaiKhoanTT.size(); i++)
    {
        inThongTinTaiKhoanThanhToan(danhSachTaiKhoanTT[i]);
    }

    return 0;
}