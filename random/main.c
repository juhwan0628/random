#include <stdio.h>
#include <stdlib.h> // rand() �Լ� ���� ���̺귯��
#include <time.h> // time()�Լ� ���� ���̺귯��
#define CNT 15//�л��� �ִ� 15
#define YEAR 21//���Ի�:21�й�

int department(int department);
int subjectcon(int subject);
char gradecon(int grade);

int main() {
	int i,j;
	int cnt;
	int namelen[CNT];
	char name[CNT][10];//�̸� �ڸ���(3~5) ���ڸ����� a~z ���� ��ù�ڸ��� �빮��
	int student[CNT];//�й� 20���� 0~21���� �а�
	int subject[2][CNT];//����1�ڵ� ����2�ڵ� 
	char grade[2][CNT];//����1���� ����2����

	srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����

	cnt = rand() % CNT + 1; //cnt = 1 ~ 15
	printf("%d\n\n", cnt);

	//�й�
	for ( i = 0; i < cnt; i++)
	{
		student[i] = 2000000000 + (rand() % (YEAR+1))*1000000; //���г⵵
		student[i] = student[i] + department(rand() % 4) * 1000; //�а�
		student[i] = student[i] + rand() % 999 + 1;//��ȣ
	}
	//�̸�
	for ( i = 0; i < cnt; i++)
	{
		namelen[i] = rand() % 3 + 3; //namelen = 3~5
		name[i][0] = rand() % 25 + 65; // A~Z
		for ( j = 1; j < namelen[i]; j++)
		{
			name[i][j] = rand() % 25 + 97;
		}
	}

	//�����ڵ�
	for ( i = 0; i < cnt; i++)
	{
		subject[0][i] = subjectcon(rand() % 5);
		subject[1][i] = subjectcon(rand() % 5);
		if (subject[0][i]== subject[1][i])
		{
			i--;
		}
	}

	//����
	for ( i = 0; i < cnt; i++)
	{
		grade[0][i] = gradecon(rand() % 6);
		grade[1][i] = gradecon(rand() % 6);
	}

	//���
	for (i = 0; i < cnt; i++)
	{
		printf("%d ", student[i]);//�й����
		for (j = 0; j < namelen[i]; j++)
		{
			printf("%c", name[i][j]);//�̸����
		}
		printf(" %d ", subject[0][i]);//����1�ڵ�
		printf("%c", grade[0][i]);//����
		printf(" %d ", subject[1][i]);//����2�ڵ�
		printf("%c\n", grade[1][i]);//����
	}

	return 0;
}

int department(int department) {
	int ans = 0;
	switch (department)
	{
	case 0: ans = 7; break;
	case 1: ans = 12; break;
	case 2: ans = 81; break;
	case 3: ans = 91; break;
	default:
		break;
	}

	return ans;
}

int subjectcon(int subject) {
	int ans = 0;
	switch (subject)
	{
	case 0: ans = 101; break;
	case 1: ans = 102; break;
	case 2: ans = 103; break;
	case 3: ans = 105; break;
	case 4: ans = 201; break;
	default:
		break;
	}

	return ans;
}

char gradecon(int grade) {
	char ans=0;
	switch (grade)
	{
	case 0: ans = 'A'; break;
	case 1: ans = 'a'; break;
	case 2: ans = 'B'; break;
	case 3: ans = 'b'; break;
	case 4: ans = 'C'; break;
	case 5: ans = 'c'; break;
	default: break;
	}

	return ans;
}