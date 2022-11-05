#include<iostream>
#include"Int�ontainer.h"
//#include<string>
#include <exception>
using namespace std;

Int�ontainer::Int�ontainer(int length)
{
	
	try
	{
		CheckingTheInput(length);
	}
	
	catch (const exception& ex)
	{
		std::cout << "��������." << ex.what() << std::endl;
		std::cout << "������� �������� ������ �������" << std::endl;

		int i = 0;
		while (i >= 1) 
		{
			std::cin >> length;
			if (length <= 0)
			{
				std::cout << "������� ���������� ������ �������. -_- ��!" << std::endl;
			}
			else
			{
				i = 1;
			}
		};
		
	}
	catch (...)
	{
		std::cout << "��������. ��� �� ����� �� ��� 1"  << std::endl;
	}
	m_massiv = new int[length] {};
	m_dlinna = length;
}
Int�ontainer::~Int�ontainer()
{
	delete[] m_massiv;
}
void Int�ontainer :: DeleteCorrectly()
{
	delete[] m_massiv;
	m_massiv = nullptr;
	m_dlinna = 0;
}
int& Int�ontainer::operator[](int index)//�������� �������
{
	try
	{
		CheckingTheInput(m_dlinna, index);
	}
	catch (const exception& ex)
	{
		std::cout << "��������." << ex.what() << std::endl;
		std::cout << "������� ����� ��������" << std::endl;
		std::cin >> index;
	}
	catch (...)
	{
		std::cout << "��������. ��� �� ����� �� ��� 2" << std::endl;
	}
	return m_massiv[index];
}	
void Int�ontainer::ResizeAndClear(int newdlinna)// �������� ������ �������. ��� ������������ �������� ����� ����������
{
	DeleteCorrectly();
	if (newdlinna <= 0)
		return;
	m_massiv = new int[newdlinna];
	m_dlinna = newdlinna;
}
void Int�ontainer::ResizeAndSave(int newdlinna)//�������� ������ �������. ��� ������������ �������� ����� ���������.
{
	if (newdlinna == m_dlinna)
		return;
	if (newdlinna <= 0)
	{
		DeleteCorrectly();
		return;
	}
	int* data{ new int[newdlinna] };
	if (m_dlinna > 0)
	{
		int elementsToCopy{ (newdlinna > m_dlinna) ? m_dlinna : newdlinna };
		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_massiv[index];
	}
	delete[] m_massiv;
	m_massiv = data;
	m_dlinna = newdlinna;
}
void Int�ontainer::InsertBefore(int value, int index)
{ 
	try
	{
		CheckingTheInput(m_dlinna, index);
	}
	catch (const exception& ex)
	{
		std::cout << "��������." << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "��������. ��� �� ����� �� ��� 3" << std::endl;
	}
	int* data{ new int[m_dlinna + 1] };
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_massiv[before];
	data[index] = value;
	for (int after{ index }; after < m_dlinna; ++after)
		data[after + 1] = m_massiv[after];
	delete[] m_massiv;
	m_massiv = data;
	++m_dlinna;
}

void Int�ontainer::remove(int index)
{
	try
	{
		CheckingTheInput(m_dlinna,index);
	}
	catch(const char *ex)
	{
		std::cout<<"��������."<< ex <<std::endl;
		std::cout << "������� ����� ��������" << std::endl;
		std::cin>> index;
	}
	catch (...)
	{
		std::cout << "��������. ��� �� ����� �� ��� 4" << std::endl;
	}
	
	if (m_dlinna == 1)
	{
		DeleteCorrectly();
		return;
	}
	int* data{ new int[m_dlinna - 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_massiv[before];
	for (int after{ index + 1 }; after < m_dlinna; ++after)
		data[after - 1] = m_massiv[after];
	delete[] m_massiv;
	m_massiv = data;
	--m_dlinna;
}
void Int�ontainer::insertAtBeginning(int value)
{
	InsertBefore(value, 0);
}
void Int�ontainer::insertAtEnd(int value)
{
	InsertBefore(value, m_dlinna);
}
int Int�ontainer::getLength() const
{
	return m_dlinna;
}
void Int�ontainer::CheckingTheInput(int length)
{
	if (length <= 0)
		throw exception("��-��-��,\t(|)_0o_(|)\terror: ������ �� ����� ���� ������ ��� ����� 0");
}
void Int�ontainer::CheckingTheInput(int length, int index)
{
	CheckingTheInput(length);

	if (index > length )
		throw exception("�� ��� ��� ������!!! ��-��-��,\t(|)_0o_(|) \t error: ������ �� ����� ���� ������ ������ �������!");
}
void Int�ontainer::print()
{
	for (int i{ 0 }; i < getLength(); ++i)
		std::cout << m_massiv[i] << ' ';

	std::cout << '\n';
}
