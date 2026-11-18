#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct TuDienAnhViet
{
    string tuVungTiengAnh;
    string nghiaTuTiengViet;
};

int timViTriTu(const vector<TuDienAnhViet>& tuDienAnhViet, const string& tuCanTim)
{
    for (int i = 0; i < tuDienAnhViet.size(); i++)
    {
        if (tuDienAnhViet[i].tuVungTiengAnh == tuCanTim)
        {
            return i;
        }
    }
    return -1;
}

void themTuVungMoi(vector<TuDienAnhViet>& tuDienAnhViet, const string& tuVungEng, const string& nghiaTuVie)
{
    if (timViTriTu(tuDienAnhViet, tuVungEng) != -1)
    {
        cout << "Tu " << tuVungEng << " da ton tai trong tu dien.\n";
        return;
    }
    TuDienAnhViet tuMoi;
    tuMoi.tuVungTiengAnh = tuVungEng;
    tuMoi.nghiaTuTiengViet = nghiaTuVie;
    
    tuDienAnhViet.push_back(tuMoi);
    cout << "Da them thanh cong " << tuVungEng << " vao tu dien.\n";
}

void suaTuDaCo(vector<TuDienAnhViet>& tuDienAnhViet, const string& tuEngCu, const string& nghiaVieMoi)
{
    if (timViTriTu(tuDienAnhViet, tuEngCu) != -1)
    {
        tuDienAnhViet[timViTriTu(tuDienAnhViet, tuEngCu)].nghiaTuTiengViet = nghiaVieMoi;
        cout << "Da cap nhat nghia cua tu " << tuEngCu << " thanh cong.\n";
    }
    else
    {
        cout << "Khong tim thay tu " << tuEngCu << " trong tu dien de sua.\n";
    }
}

void xoaTuVungCu(vector<TuDienAnhViet>& tuDienAnhViet, const string& tuEngCu)
{
    if (timViTriTu(tuDienAnhViet, tuEngCu) != -1)
    {
        tuDienAnhViet.erase(tuDienAnhViet.begin() + timViTriTu(tuDienAnhViet, tuEngCu));
        cout << "Da xoa tu " << tuEngCu << " khoi tu dien.\n";
    }
    else 
    {
        cout << "Khong tim thay tu " << tuEngCu << " de xoa.\n";
    }
}

void hienDanhSachTu(const vector<TuDienAnhViet>& tuDienAnhViet)
{
    if (tuDienAnhViet.empty())
    {
        cout << "Tu dien hien dang trong.\n";
        return;
    }
    cout << string(40, '-') << endl;
    cout << left << setw(20) << "Tieng Anh" << "| Tieng Viet\n";
    cout << string(40, '-') << endl;
    for (int i = 0; i < tuDienAnhViet.size(); i++)
    {
        cout << left << setw(20) << tuDienAnhViet[i].tuVungTiengAnh 
             << "| " << tuDienAnhViet[i].nghiaTuTiengViet << "\n";
    }
    cout << string(40, '-') << endl;
}

void traTuCanTim(const vector<TuDienAnhViet>& tuDienAnhViet, const string& tuEngCanTim)
{
    if (timViTriTu(tuDienAnhViet, tuEngCanTim) != -1)
    {
        cout << "Nghia cua tu " << tuEngCanTim << ": " 
             << tuDienAnhViet[timViTriTu(tuDienAnhViet, tuEngCanTim)].nghiaTuTiengViet << "\n"; 
    }
    else
    {
        cout << "Khong tim thay tu " << tuEngCanTim << " trong tu dien.\n";
    }
}

int main()
{
    vector<TuDienAnhViet> danhSachTuVung;

    themTuVungMoi(danhSachTuVung, "game", "tro choi dien tu");
    themTuVungMoi(danhSachTuVung, "travel", "chuyen du lich");
    themTuVungMoi(danhSachTuVung, "robot", "nguoi may tu dong");
    themTuVungMoi(danhSachTuVung, "application", "ung dung");
    themTuVungMoi(danhSachTuVung, "movie", "bo phim");
    themTuVungMoi(danhSachTuVung, "motherboard", "bo mach chu");

    int luaChon;
    do 
    {
        cout << string(30, '-') << endl;
        cout << "=== TU DIEN ANH - VIET ===" << endl;
        cout << string(30, '-') << endl;
        cout << "1. Xem danh sach tu" << endl;
        cout << "2. Tra tu" << endl;
        cout << "3. Them tu moi" << endl;
        cout << "4. Sua nghia cua tu" << endl;
        cout << "5. Xoa tu" << endl;
        cout << "0. Thoat" << endl;
        cout << string(30, '-') << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        string tuVungTiengAnh, nghiaTuTiengViet;
        switch (luaChon) 
        {
            case 1:
                hienDanhSachTu(danhSachTuVung);
                break;
            case 2:
                cout << "Nhap tu tieng Anh can tra: ";
                getline(cin, tuVungTiengAnh);
                traTuCanTim(danhSachTuVung, tuVungTiengAnh);
                break;
            case 3:
                cout << "Nhap tu tieng Anh: ";
                getline(cin, tuVungTiengAnh);
                cout << "Nhap nghia tieng Viet: ";
                getline(cin, nghiaTuTiengViet);
                themTuVungMoi(danhSachTuVung, tuVungTiengAnh, nghiaTuTiengViet);
                break;
            case 4:
                cout << "Nhap tu tieng Anh can sua: ";
                getline(cin, tuVungTiengAnh);
                cout << "Nhap nghia moi: ";
                getline(cin, nghiaTuTiengViet);
                suaTuDaCo(danhSachTuVung, tuVungTiengAnh, nghiaTuTiengViet);
                break;
            case 5:
                cout << "Nhap tu tieng Anh can xoa: ";
                getline(cin, tuVungTiengAnh);
                xoaTuVungCu(danhSachTuVung, tuVungTiengAnh);
                break;
            case 0:
                cout << "Dang thoat chuong trinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
        cout << endl;
    } 
    while (luaChon != 0);

    return 0;
}