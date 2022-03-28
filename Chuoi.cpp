//======== Lý Thuyết  =========
// 
// Câu 1 : Cơ chế của cin : yêu cầu nhập vào kiểu dự liệu mà đã yêu cầu 
// không quan tâm đã có bộ nhớ đệm chưa vẫn lưu thêm tiếp giá trị vào 
// 
//Cơ chế của gets : yêu cầu nhập vào kiểu dự liệu mà đã yêu cầu 
// nếu đã có bộ nhớ đếm chương trình sẽ không cho lưu tiếp dữ liệu từ bàn phím 
// nhập vào , tự động xuất dữ liệu phù hợp với dl yêu cầu từ trong bộ nhớ đệm 
// 
// Lưu ý : trong xâu nếu ta lưu một đoạn kí tự có cách dòng thì cin sẽ chỉ lưu đến đoạn 
// cách dòng và xuống dòng còn gets phải xuống dòng mới dừng ;
// 
// Câu 2: Phân tích lỗi trôi lệnh 
// 
// Ở đây nó chỉ xảy ra với một mình gets vì đối với cin nó sẽ tự động lưu không qtam bộ nhớ đệm
// Đối với gets khi đã có bộ nhớ đệm nó sẽ tự động bỏ qua cậu lệnh lưu giá trị từ bàn phím vào.
// Và khắc phục nó ta cần xóa bộ nhớ đệm cũ ;
// 
// //======== Bài tập  =========
//
#include <iostream>
using namespace std;
int strlen(char str[]);
char* strdup(char str2[]); // copy xâu
void strlwre(char str[]); // hàm trả về một hàm viết hoa
void struprr(char str[]); // hàm trả về một hàm thường
void strrevv(char str[]);
void bai3()
{
	cout << "======== NHẬP THÔNG TIN SINH VIÊN ========= " << endl;
	char hoten[30];
		cout << "\nNhap ho va ten thang sinh vien : ";
		gets_s(hoten);
	char masv [10];
		cout << "\nNhap ma sinh vien : ";
		gets_s(masv);
	int namsinh;
		cout << "Nhap nam sinh thang sinh vien : ";
		cin >> namsinh;
	while (getchar() != '\n');
	char diadiem[20];
		cout << "\nNhap noi o thang sinh vien : ";
		gets_s(diadiem);
		cout << "\nHo va Ten : " << hoten;
		cout << "\nMa sinh vien : " << masv;
		cout << "\n Nam sinh : " << namsinh;
		cout << " \n Noi o : " << diadiem;
}
int strlen(char str[]) // hàm đêm số lượng phần tử sử dựng trong xâu 
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
void strcpy(char strc1[], char strc2[], int n, int m)
{
	if (n >= m) 
	{
		for (int i = 0; i <= m; i++)
		{
			strc1[i] = strc2[i]; // nếu hay hơn thì bắt thêm \0
		}
		strc1[m] = '\0';
	}
	else
	{
		for (int i = 0; i <= n; i++)
		{
			strc1[i] = strc2[i]; // nếu hay hơn thì bắt thêm \0
		}
	}
}
char *strdup(char str2[]) // copy xâu
{
	char* str1 = new char[strlen(str2) + 1]; // khia báo độ dài thực bằng biesn strc2 bằng mảng động
	for (int i = 0; i <= strlen(str2); i++)
	{
		str1[i] = str2[i];
	}
	return str1;
}
void strlwre(char str[]) // hàm trả về một hàm viết hoa
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i + 32];
		}
	}
}
char struprre(char str[]) // hàm trả về một hàm thường
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i -32];
		}
	}
	return str[];
}
void sao_chep(char c1[], char c2[])
{
	//c2: hello\0
	//	  01234 5
	//c1: hello
	int nc2 = strlen(c2);//5

	for (int i = 0; i <= nc2; i++)//Xem \0 như là 1 kí tự
	{
		c1[i] = c2[i];
	}
}
char* sao_chep2(char c2[])
{
	//c2: hello \0
	//	  01234 5
	int nc2 = strlen(c2);//5

	char* c1 = new char[nc2 + 1];//+ 1 \0

	for (int i = 0; i <= nc2; i++)//Xem \0 như là 1 ký tự
	{
		c1[i] = c2[i];
	}
	return c1;
}
int ss_co_pb(char c1[], char c2[])// <0,	> 0,	== 0
{
	int nc1 = strlen(c1);
	int nc2 = strlen(c2);
	int min = (nc1 < nc2) ? nc1 : nc2;
	//c1: Thanh
	//	  01234
	//c2: Thanh
	for (int i = 0; i < min; i++)
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
	}
	return nc1 - nc2;
}
int ss_ko_pb(char c1[], char c2[])
{
	char* tam1 = sao_chep2(c1);
	char* tam2 = sao_chep2(c2);

	struprre(tam1);
	struprre(tam2);

	int kq = ss_co_pb(tam1, tam2);
	delete[] tam1;
	delete[] tam2;

	return kq;
}
void strrevv(char str[]) //đảo ngược xâu 
	{
		int n = strlen(str);
		int temp = n;
		for (int i = 0; i <= n; i++)
		{
			str[i] = str[n];
			n--;
		}
		cout << str << endl;
	}
void strcat(char str1[], char str2[]) // hàm ghép xâu phiên bản mảng 1 chiều 
{
	int n = strlen(str1);
	int m = strlen(str2);
	int temp = 0;
	for (int i = n ; i < n+m; i++)
	{
		str1[n] = str2[temp];
	}
}
void Them(char c[], int vitri, int giatri) // hàm thêm
{
	int n = strlen(c);
	for (int i = n ; i>vitri ; i++)
	{
		c[i] = c[i - 1];
	}
	c[vitri] = giatri;
}
void Xoa(char c[], int vitri) // hàm xóa
{
	int n = strlen(c);
	for (int i = vitri; i < n; i++)
	{
		c[i] = c[i + 1];
	}
}
int main(void)
{
	char test[31];
	cout << "Nhap gia tri thu ham : ";
	char avr2[31];
	gets_s(test);
	strlen(test); // hàm đếm số lượng 
	strcpy(avr2, test, 31, 31); // hàm chuyển từ test sang avr 
	cout << avr2 << endl;

	//char* c = strdup(test); // hàm copy dùng con trỏ
	cout << " hàm " << endl;
	//cout << c << endl;
	strrevv(test);
	//bai3();
	system("pause");
}