#pragma once

/// <summary>
/// ��������� ��� �������� ��������� ������
/// </summary>
struct l2_elem
{
	/// <summary>
	/// �������� �������� (�������������� ����)
	/// </summary>
	double x;

	/// <summary>
	/// ��������� �� ��������� ������� ������ (�������� ����)
	/// </summary>
	l2_elem* next = nullptr;

	/// <summary>
	/// ��������� �� ��������� ������� ������ (�������� ����)
	/// </summary>
	l2_elem* prev = nullptr;
};

/// <summary>
/// ��������� ��� ����������� ����������, ������������ ���������� ������
/// </summary>
struct list2
{
	/// <summary>
	/// ��������� �� ������ ������� ������
	/// </summary>
	l2_elem* first = nullptr;

	/// <summary>
	/// ��������� �� ��������� ������� ������
	/// </summary>
	l2_elem* last = nullptr;

	/// <summary>
	/// ���� ��� �������� ���������� ��������� ������
	/// </summary>
	int count = 0;
};

/// <summary>
/// ������� ��� ���������� �������� � ������
/// </summary>
/// <param name="list">������, � ������� ����� �������� ��������</param>
/// <param name="data">����������� � ������ ��������</param>
void add(list2& list, double data);

/// <summary>
/// ������� ��� �������� �������� �� ������
/// </summary>
/// <param name="list">������, ������ ��������� �������</param>
/// <param name="position">�������, � ������� ����� ������� ��������</param>
/// <returns></returns>
bool remove(list2& list, int position);

/// <summary>
/// ��������� �������� �������� ������
/// </summary>
/// <param name="list">������, ������ ���������� ��������</param>
/// <param name="position">�������, �� ������� ����� �������� ��������</param>
/// <returns>��������� �� �������� �������� ������ ��� nullptr, ���� �������� � ��������� ������� ���</returns>
const double* get(list2 list, int position);

/// <summary>
/// �������� ���� ��������� ������
/// </summary>
/// <param name="list">������, ������� ����� ������� �� ������</param>
void clear(list2& list);
