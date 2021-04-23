#include <iostream>
#include <string>
using namespace std;

//Proplar Yani Özellikler
struct Student
{
	string isim, harfnotu;
	int ogrencino;
	int* testnotlari;
	double ortalama;

};


//Harf notunu belirleme metodu (Dont Repeat Yourself)
void LetterGrade(int existStudent, Student students[])
{
	double avg = students[existStudent].ortalama;
	if (avg <= 100 && avg >= 85)
	{
		students[existStudent].harfnotu = " A";
	}


	else if (avg < 85 && avg >= 75)
	{
		students[existStudent].harfnotu = "B";
	}

	else if (avg < 75 && avg >= 65)
	{
		students[existStudent].harfnotu = " C";
	}

	else if (avg < 65 && avg >= 50)
	{
		students[existStudent].harfnotu = " D";
	}

	else if (avg < 50 && avg >= 0)
	{
		students[existStudent].harfnotu = " F";
	}

}

//Gerekli bilgileri alma metodu
void TakeInfo(int existStudent, int studentCount, Student students[], int examCount)
{
	std::cout << "Student Name:";
	std::cin >> students[existStudent].isim;

	std::cout << "Student Number:";
	std::cin >> students[existStudent].ogrencino;

	//O anki mevcut öðrencinin *testnotlarý new lenir.
	students[existStudent].testnotlari = new int[examCount];

	for (int i = 0; i < examCount; ++i)
	{
		std::cout << students[existStudent].isim << "'s" << i + 1 << " .Exam Note: ";
		std::cin >> students[existStudent].testnotlari[i];
	}
};


//Ortalama hrsaplama metodu
void AvgCalc(int exist_student, Student students[], int exam_count)
{
	double temp = 0;

	for (int i = 0; i < exam_count; ++i)
	{
		temp += students[exist_student].testnotlari[i];
	}
	students[exist_student].ortalama = temp / exam_count;


}

//Bilgileri gösterme metodu
void Show(int exist_student, Student student[], int exam_count)
{
	std::cout << exist_student + 1 << " .Student Name :" << student[exist_student].isim << endl;
	std::cout << exist_student + 1 << " .Student Number :" << student[exist_student].ogrencino << endl;

	for (int i = 0; i < exam_count; ++i)
	{
		std::cout << student[exist_student].isim << "'s " << i + 1 << " .Exam :" << student[exist_student].testnotlari[i] << endl;
	}
	std::cout << student[exist_student].isim << " .Student Avg :" << student[exist_student].ortalama << endl;
	std::cout << student[exist_student].isim << " .Student Letter Grade :" << student[exist_student].harfnotu << endl;
}

//Silme metodu
void Delete_new(int exist_student, Student student[])
{
	delete[] student;
	std::cout << "Deleted";

}

int main()
{
	int existStudent = 0;
	int studentCount, examCount;

	/* Öðrenci Sayýsýný alýyoruz*/
	std::cout << "Student Count: ";
	std::cin >> studentCount;
	/*Sýnav sayýsýný alýyoruz*/
	std::cout << "Exam Count";
	std::cin >> examCount;

	/*Öðrenci structýndan yeni öðrenciler tanýmlýyoruz*/
	Student* students;
	students = new Student[studentCount];


	for (int i = 0; i < studentCount; ++i)
	{
		//ExistStudent o anki var olan öðrenci için iþlemlerin yapýlmasýný saðlar.
		existStudent = i;
		TakeInfo(existStudent, studentCount, students, examCount);
		AvgCalc(existStudent, students, examCount);
		LetterGrade(existStudent, students);
		Show(existStudent, students, examCount);
	}

	//Bütün öðrencileri siler.
	for (int i = 0; i < studentCount; ++i)
	{
		Delete_new(existStudent, students);
	}

}

