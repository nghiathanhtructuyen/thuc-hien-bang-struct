#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ChuyenDiCoBan
{
    string maChuyenDi;
    string tenKhachHang;
    string quocTich;
    int khoangCach;
    int soLuongHanhKhach;

    virtual ~ChuyenDiCoBan() = default;

    ChuyenDiCoBan(string maChuyenDi, string tenKhachHang, string quocTich, int khoangCach, int soLuongHanhKhach)
    {
        this->maChuyenDi = maChuyenDi;
        this->tenKhachHang = tenKhachHang;
        this->quocTich = quocTich;
        this->khoangCach = khoangCach;
        this->soLuongHanhKhach = soLuongHanhKhach;
    }
};

struct CuocPhiXeMay : public ChuyenDiCoBan
{
    double donGiaChoMotKm = 10000;
    double tongDonGia;

    CuocPhiXeMay(string maChuyenDi, string tenKhachHang, string quocTich, int khoangCach, int soLuongHanhKhach)
               : ChuyenDiCoBan(maChuyenDi, tenKhachHang, quocTich, khoangCach, soLuongHanhKhach)
    {
        if (soLuongHanhKhach >= 2) 
        {
            cout << "Loi: So luong hanh khach khong hop le cho xe may. Vui long nhap lai." << endl;
            return;
        }
        this->tongDonGia = donGiaChoMotKm * khoangCach;
    }
};

struct CuocPhiXeOto : public ChuyenDiCoBan
{
    double donGiaChoMotKm = 15000;
    int soLuongHanhKhach;
    double tongDonGia;

    CuocPhiXeOto(string maChuyenDi, string tenKhachHang, string quocTich, int khoangCach, int soLuongHanhKhach)
               : ChuyenDiCoBan(maChuyenDi, tenKhachHang, quocTich, khoangCach, soLuongHanhKhach)
    {
        this->soLuongHanhKhach = soLuongHanhKhach;
        if (soLuongHanhKhach <= 4)
        {
            this->tongDonGia = donGiaChoMotKm * khoangCach;
        }
        if (soLuongHanhKhach > 4)
        {
            this->tongDonGia = donGiaChoMotKm * 1.2 * khoangCach;
        }
    }
};

void hienThiThongTinChuyenDi(const ChuyenDiCoBan& chuyenDi)
{
    cout << "Ma chuyen di: " << chuyenDi.maChuyenDi << "\n";
    cout << "Ten khach hang: " << chuyenDi.tenKhachHang << "\n";
    cout << "Quoc tich: " << chuyenDi.quocTich << "\n";
    cout << "Khoang cach: " << chuyenDi.khoangCach << " km\n";
    cout << "So luong hanh khach: " << chuyenDi.soLuongHanhKhach << "\n";
    if (const CuocPhiXeMay* cuocPhiXeMay = dynamic_cast<const CuocPhiXeMay*>(&chuyenDi))
    {
        cout << "Tong cuoc phi: " << cuocPhiXeMay->donGiaChoMotKm * cuocPhiXeMay->khoangCach << "\n\n";
    }
    else if (const CuocPhiXeOto* cuocPhiXeOto = dynamic_cast<const CuocPhiXeOto*>(&chuyenDi))
    {
        cout << "Tong cuoc phi: " << cuocPhiXeOto->tongDonGia << "\n\n";
    }
}

int main()
{
    vector<ChuyenDiCoBan*> danhSachChuyenDi;

    danhSachChuyenDi.push_back(new CuocPhiXeMay("CD01", "Nguyen Van A", "Viet Nam", 10, 1));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD02", "Tran Thi B", "Viet Nam", 20, 5));
    danhSachChuyenDi.push_back(new CuocPhiXeMay("CD03", "Le Van C", "Viet Nam", 15, 1));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD04", "Pham Thi D", "Viet Nam", 30, 3));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD05", "Hoang Van E", "Viet Nam", 25, 6));
    danhSachChuyenDi.push_back(new CuocPhiXeMay("CD06", "Nguyen Thi F", "Viet Nam", 5, 1));
    danhSachChuyenDi.push_back(new CuocPhiXeOto("CD07", "Tran Van G", "Viet Nam", 12, 4));

    cout << "Danh sach chuyen di va cuoc phi tuong ung:" << endl;
    for (const auto& chuyenDi : danhSachChuyenDi)
    {
        hienThiThongTinChuyenDi(*chuyenDi);
    }

    return 0;
}