#pragma once


class Int�ontainer
{
public:
	Int�ontainer() = default;
	Int�ontainer(int length);
	~Int�ontainer();

	void DeleteCorrectly();// ������� m_data � nullptr 
	int& operator[](int index);//�������� �������
	void ResizeAndClear(int newLength);// �������� ������ �������. ��� ������������ �������� ����� ����������
	void ResizeAndSave(int newLength);//�������� ������ �������. ��� ������������ �������� ����� ���������.
	void InsertBefore(int value, int index);//�������� �������
	void remove(int index);//������� �������
	void insertAtBeginning(int value);//�������� � ������
	void insertAtEnd(int value);//�������� � �����
	int getLength() const;//������� ������
	void CheckingTheInput(int length);// �������� ������� ������ �� 0 ��� ������ 0
	void CheckingTheInput(int length, int index);// �������� ������� ������ �� 0 ��� ������ 0 � �� ����������� �������
	void print();

private:
	int m_dlinna;
	int* m_massiv;
};

