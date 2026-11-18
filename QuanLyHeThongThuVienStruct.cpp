#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct TaiLieuCuaThuVien
{
    string maTaiLieu;
    int kieuTaiLieu;
    string tenKieuTaiLieu;
    string tenTaiLieu;
    string tenNhaXuatBan;
    int namXuatBan;
};

struct SachCuaThuVien : public TaiLieuCuaThuVien
{
    string tenTacGia;

    SachCuaThuVien(string maTaiLieu, string tenTaiLieu, string tenNhaXuatBan, int namXuatBan, string tenTacGia)
    {
        this->maTaiLieu = maTaiLieu;
        this->kieuTaiLieu = 1;
        this->tenKieuTaiLieu = "SACH";
        this->tenTaiLieu = tenTaiLieu;
        this->tenNhaXuatBan = tenNhaXuatBan;
        this->namXuatBan = namXuatBan;
        this->tenTacGia = tenTacGia;
    }
};

struct TapChiCuaThuVien : public TaiLieuCuaThuVien
{
    int soPhatHanh;

    TapChiCuaThuVien(string maTaiLieu, string tenTaiLieu, string tenNhaXuatBan, int namXuatBan, int soPhatHanh)
    {
        this->maTaiLieu = maTaiLieu;
        this->kieuTaiLieu = 2;
        this->tenKieuTaiLieu = "TAP CHI";
        this->tenTaiLieu = tenTaiLieu;
        this->tenNhaXuatBan = tenNhaXuatBan;
        this->namXuatBan = namXuatBan;
        this->soPhatHanh = soPhatHanh;
    }
};

void themTaiLieuMoi(vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, TaiLieuCuaThuVien* taiLieu)
{
    for (const auto& tl : danhSachTaiLieu)
    {
        if (tl->maTaiLieu == taiLieu->maTaiLieu)
        {
            cout << "Loi: Ma tai lieu da ton tai trong he thong. Khong the them." << endl;
            return;
        }
    }
    danhSachTaiLieu.push_back(taiLieu);
}

pair<int, int> thongKeSoLuongTaiLieu(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, int& soLuongSach, int& soLuongTapChi)
{
    soLuongSach = 0;
    soLuongTapChi = 0;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        if (taiLieu->kieuTaiLieu == 1)
        {
            soLuongSach++;
        }
        else if (taiLieu->kieuTaiLieu == 2)
        {
            soLuongTapChi++;
        }
    }
    return make_pair(soLuongSach, soLuongTapChi);
}

void hienThiDanhSachTaiLieu(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu)
{
    cout << setw(12) << left << "Loai" << " | "
         << setw(15) << left << "Ma tai lieu" << " | "
         << setw(30) << left << "Ten tai lieu" << " | "
         << setw(15) << left << "Nha xuat ban" << " | "
         << setw(12) << left << "Nam xuat ban" << " | "
         << setw(15) << left << "Thong tin khac"
         << endl;
    cout << string(113, '-') << endl;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        cout << setw(12) << left << taiLieu->kieuTaiLieu << " | "
             << setw(15) << left << taiLieu->maTaiLieu << " | "
             << setw(30) << left << taiLieu->tenTaiLieu << " | "
             << setw(15) << left << taiLieu->tenNhaXuatBan << " | "
             << setw(12) << left << taiLieu->namXuatBan << " | ";
        if (taiLieu->kieuTaiLieu == 1)
        {
            cout << setw(15) << left << static_cast<SachCuaThuVien*>(taiLieu)->tenTacGia;
        }
        else if (taiLieu->kieuTaiLieu == 2)
        {
            cout << setw(15) << left << static_cast<TapChiCuaThuVien*>(taiLieu)->soPhatHanh;
        }
        cout << endl;
    }
}

void timKiemTaiLieuTheoMa(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, const string& maTaiLieu)
{
    bool timThay = false;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        if (taiLieu->maTaiLieu == maTaiLieu)
        {
            cout << "Thong tin tai lieu:\n";
            cout << "Loai: " << taiLieu->kieuTaiLieu << endl;
            cout << "Ma tai lieu: " << taiLieu->maTaiLieu << endl;
            cout << "Ten tai lieu: " << taiLieu->tenTaiLieu << endl;
            cout << "Nha xuat ban: " << taiLieu->tenNhaXuatBan << endl;
            cout << "Nam xuat ban: " << taiLieu->namXuatBan << endl;
            if (taiLieu->kieuTaiLieu == 1)
            {
                cout << "Ten tac gia: " << static_cast<SachCuaThuVien*>(taiLieu)->tenTacGia << endl;
            }
            else if (taiLieu->kieuTaiLieu == 2)
            {
                cout << "So phat hanh: " << static_cast<TapChiCuaThuVien*>(taiLieu)->soPhatHanh << endl;
            }
            timThay = true;
            break;
        }
    }
    if (!timThay)
    {
        cout << "Khong tim thay tai lieu co ma: " << maTaiLieu << endl;
    }
}

void timKiemTaiLieuTheoTen(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, const string& tenTaiLieu)
{
    bool timThay = false;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        if (taiLieu->tenTaiLieu == tenTaiLieu)
        {
            cout << "Thong tin tai lieu:\n";
            cout << "Loai: " << taiLieu->kieuTaiLieu << endl;
            cout << "Ma tai lieu: " << taiLieu->maTaiLieu << endl;
            cout << "Ten tai lieu: " << taiLieu->tenTaiLieu << endl;
            cout << "Nha xuat ban: " << taiLieu->tenNhaXuatBan << endl;
            cout << "Nam xuat ban: " << taiLieu->namXuatBan << endl;
            if (taiLieu->kieuTaiLieu == 1)
            {
                cout << "Ten tac gia: " << static_cast<SachCuaThuVien*>(taiLieu)->tenTacGia << endl;
            }
            else if (taiLieu->kieuTaiLieu == 2)
            {
                cout << "So phat hanh: " << static_cast<TapChiCuaThuVien*>(taiLieu)->soPhatHanh << endl;
            }
            timThay = true;
            break;
        }
    }
    if (!timThay)
    {
        cout << "Khong tim thay tai lieu co ten: " << tenTaiLieu << endl;
    }
}

void timKiemTaiLieuTheoNhaXuatBan(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, const string& tenNhaXuatBan)
{
    bool timThay = false;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        if (taiLieu->tenNhaXuatBan == tenNhaXuatBan)
        {
            cout << "Thong tin tai lieu:\n";
            cout << "Loai: " << taiLieu->kieuTaiLieu << endl;
            cout << "Ma tai lieu: " << taiLieu->maTaiLieu << endl;
            cout << "Ten tai lieu: " << taiLieu->tenTaiLieu << endl;
            cout << "Nha xuat ban: " << taiLieu->tenNhaXuatBan << endl;
            cout << "Nam xuat ban: " << taiLieu->namXuatBan << endl;
            if (taiLieu->kieuTaiLieu == 1)
            {
                cout << "Ten tac gia: " << static_cast<SachCuaThuVien*>(taiLieu)->tenTacGia << endl;
            }
            else if (taiLieu->kieuTaiLieu == 2)
            {
                cout << "So phat hanh: " << static_cast<TapChiCuaThuVien*>(taiLieu)->soPhatHanh << endl;
            }
            timThay = true;
        }
    }
    if (!timThay)
    {
        cout << "Khong tim thay tai lieu cua nha xuat ban: " << tenNhaXuatBan << endl;
    }
}

void timKiemTaiLieuTheoNamXuatBan(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, int namXuatBan)
{
    bool timThay = false;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        if (taiLieu->namXuatBan == namXuatBan)
        {
            cout << "Thong tin tai lieu:\n";
            cout << "Loai: " << taiLieu->kieuTaiLieu << endl;
            cout << "Ma tai lieu: " << taiLieu->maTaiLieu << endl;
            cout << "Ten tai lieu: " << taiLieu->tenTaiLieu << endl;
            cout << "Nha xuat ban: " << taiLieu->tenNhaXuatBan << endl;
            cout << "Nam xuat ban: " << taiLieu->namXuatBan << endl;
            if (taiLieu->kieuTaiLieu == 1)
            {
                cout << "Ten tac gia: " << static_cast<SachCuaThuVien*>(taiLieu)->tenTacGia << endl;
            }
            else if (taiLieu->kieuTaiLieu == 2)
            {
                cout << "So phat hanh: " << static_cast<TapChiCuaThuVien*>(taiLieu)->soPhatHanh << endl;
            }
            timThay = true;
        }
    }
    if (!timThay)
    {
        cout << "Khong tim thay tai lieu cua nam xuat ban: " << namXuatBan << endl;
    }
}

void timKiemTaiLieuTheoTuKhoa(const vector<TaiLieuCuaThuVien*>& danhSachTaiLieu, const string& tuKhoa)
{
    bool timThay = false;
    for (const auto& taiLieu : danhSachTaiLieu)
    {
        if (taiLieu->tenTaiLieu.find(tuKhoa) != string::npos)
        {
            cout << "Thong tin tai lieu:\n";
            cout << "Loai: " << taiLieu->kieuTaiLieu << endl;
            cout << "Ma tai lieu: " << taiLieu->maTaiLieu << endl;
            cout << "Ten tai lieu: " << taiLieu->tenTaiLieu << endl;
            cout << "Nha xuat ban: " << taiLieu->tenNhaXuatBan << endl;
            cout << "Nam xuat ban: " << taiLieu->namXuatBan << endl;
            if (taiLieu->kieuTaiLieu == 1)
            {
                cout << "Ten tac gia: " << static_cast<SachCuaThuVien*>(taiLieu)->tenTacGia << endl;
            }
            else if (taiLieu->kieuTaiLieu == 2)
            {
                cout << "So phat hanh: " << static_cast<TapChiCuaThuVien*>(taiLieu)->soPhatHanh << endl;
            }
            timThay = true;
        }
    }
    if (!timThay)
    {
        cout << "Khong tim thay tai lieu co tu khoa: " << tuKhoa << endl;
    }
}

int main()
{
    vector<TaiLieuCuaThuVien*> danhSachTaiLieu;

    danhSachTaiLieu.push_back(new SachCuaThuVien{"S001", "Lap trinh C++", "NXB Tre", 2020, "Nguyen Van A"});
    danhSachTaiLieu.push_back(new TapChiCuaThuVien{"T001", "Tap chi CNTT", "NXB Khoa Hoc", 2021, 5});
    danhSachTaiLieu.push_back(new SachCuaThuVien{"S002", "Lap trinh Java", "NXB Tre", 2019, "Tran Thi B"});
    danhSachTaiLieu.push_back(new TapChiCuaThuVien{"T002", "Tap chi Toan hoc", "NXB Giao Duc", 2020, 8});
    danhSachTaiLieu.push_back(new SachCuaThuVien{"S003", "Lap trinh Python", "NXB GHI", 2021, "Le Van C"});
    danhSachTaiLieu.push_back(new TapChiCuaThuVien{"T003", "Tap chi Khoa hoc", "NXB UVW", 2022, 10});
    danhSachTaiLieu.push_back(new SachCuaThuVien{"S004", "Lap trinh C#", "NXB JKL", 2022, "Pham Thi D"});
    danhSachTaiLieu.push_back(new TapChiCuaThuVien{"T004", "Tap chi Van hoc", "NXB XYZ", 2021, 3});

    int luaChon;

    do
    {
        cout << "|==========================================================================|\n";
        cout << "|================== HE THONG QUAN LY THU VIEN TRUONG HOC ==================|\n";
        cout << "|==========================================================================|\n";
        cout << "Hay chon chuc nang ban muon su dung:\n";
        cout << "1. Hien thi danh sach tai lieu\n";
        cout << "2. Them tai lieu moi\n";
        cout << "3. Xoa tai lieu theo ma\n";
        cout << "4. Tim kiem tai lieu theo ten\n";
        cout << "5. Tim kiem tai lieu theo nha xuat ban\n";
        cout << "6. Tim kiem tai lieu theo nam xuat ban\n";
        cout << "7. Tim kiem tai lieu theo tu khoa\n";
        cout << "8. Thong ke so luong tai lieu\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "|==========================================================================|\n\n";
        cout << "Nhap lua chon cua ban: ";
        
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
            case 0:
                cout << "Cam on ban da su dung chuong trinh. Tam biet!" << endl;
                return 0;
            case 1:
                hienThiDanhSachTaiLieu(danhSachTaiLieu);
                break;
            case 2:
                {
                    int loaiTaiLieu;
                    cout << "Chon loai tai lieu (1: Sach, 2: Tap chi): ";
                    cin >> loaiTaiLieu;
                    cin.ignore();
                    if (loaiTaiLieu == 1)
                    {
                        string ma, ten, nhaXuatBan, tacGia;
                        int nam;
                        cout << "Nhap ma tai lieu: "; getline(cin, ma);
                        cout << "Nhap ten tai lieu: "; getline(cin, ten);
                        cout << "Nhap ten nha xuat ban: "; getline(cin, nhaXuatBan);
                        cout << "Nhap nam xuat ban: "; cin >> nam; cin.ignore();
                        cout << "Nhap ten tac gia: "; getline(cin, tacGia);
                        themTaiLieuMoi(danhSachTaiLieu, new SachCuaThuVien(ma, ten, nhaXuatBan, nam, tacGia));
                    }
                    else if (loaiTaiLieu == 2)
                    {
                        string ma, ten, nhaXuatBan;
                        int nam, soPhatHanh;
                        cout << "Nhap ma tai lieu: "; getline(cin, ma);
                        cout << "Nhap ten tai lieu: "; getline(cin, ten);
                        cout << "Nhap ten nha xuat ban: "; getline(cin, nhaXuatBan);
                        cout << "Nhap nam xuat ban: "; cin >> nam; cin.ignore();
                        cout << "Nhap so phat hanh: "; cin >> soPhatHanh; cin.ignore();
                        themTaiLieuMoi(danhSachTaiLieu, new TapChiCuaThuVien(ma, ten, nhaXuatBan, nam, soPhatHanh));
                    }
                    else
                    {
                        cout << "Lua chon khong hop le." << endl;
                    }
                }
                break;
            case 3:
                {
                    string ma;
                    cout << "Nhap ma tai lieu can xoa: ";
                    getline(cin, ma);
                    timKiemTaiLieuTheoMa(danhSachTaiLieu, ma);
                }
                break;
            case 4:
                {
                    string ten;
                    cout << "Nhap ten tai lieu can tim: ";
                    getline(cin, ten);
                    timKiemTaiLieuTheoTen(danhSachTaiLieu, ten);
                }
                break;
            case 5:
                {
                    string nhaXuatBan;
                    cout << "Nhap ten nha xuat ban can tim: ";
                    getline(cin, nhaXuatBan);
                    timKiemTaiLieuTheoNhaXuatBan(danhSachTaiLieu, nhaXuatBan);
                }
                break;
            case 6:
                {
                    int nam;
                    cout << "Nhap nam xuat ban can tim: ";
                    cin >> nam;
                    cin.ignore();
                    timKiemTaiLieuTheoNamXuatBan(danhSachTaiLieu, nam);
                }
                break;
            case 7:
                {
                    string tuKhoa;
                    cout << "Nhap tu khoa can tim: ";
                    getline(cin, tuKhoa);
                    timKiemTaiLieuTheoTuKhoa(danhSachTaiLieu, tuKhoa);
                }
                break;
            case 8:
                {
                    int soLuongSach, soLuongTapChi;
                    thongKeSoLuongTaiLieu(danhSachTaiLieu, soLuongSach, soLuongTapChi);
                    cout << "So luong sach: " << soLuongSach << endl;
                    cout << "So luong tap chi: " << soLuongTapChi << endl;
                }
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
    }
    while (luaChon != 0);
    return 0;
}