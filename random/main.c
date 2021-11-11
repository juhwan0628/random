#include <stdio.h>
#include <stdlib.h> // rand() 함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#define CNT 15//학생수 최대 15
#define YEAR 21//신입생:21학번

int department(int department);
int subjectcon(int subject);
char gradecon(int grade);

int main() {
	int i,j;
	int cnt;
	int namelen[CNT];
	char name[CNT][10];//이름 자리수(3~5) 각자리마다 a~z 랜덤 맨첫자리는 대문자
	int student[CNT];//학번 20ㅁㅁ 0~21까지 학과
	int subject[2][CNT];//과목1코드 과목2코드 
	char grade[2][CNT];//과목1학점 과목2학점

	srand(time(NULL)); // 매번 다른 시드값 생성

	cnt = rand() % CNT + 1; //cnt = 1 ~ 15
	printf("%d\n\n", cnt);

	//학번
	for ( i = 0; i < cnt; i++)
	{
		student[i] = 2000000000 + (rand() % (YEAR+1))*1000000; //입학년도
		student[i] = student[i] + department(rand() % 4) * 1000; //학과
		student[i] = student[i] + rand() % 999 + 1;//번호
	}
	//이름
	for ( i = 0; i < cnt; i++)
	{
		namelen[i] = rand() % 3 + 3; //namelen = 3~5
		name[i][0] = rand() % 25 + 65; // A~Z
		for ( j = 1; j < namelen[i]; j++)
		{
			name[i][j] = rand() % 25 + 97;
		}
	}

	//과목코드
	for ( i = 0; i < cnt; i++)
	{
		subject[0][i] = subjectcon(rand() % 5);
		subject[1][i] = subjectcon(rand() % 5);
		if (subject[0][i]== subject[1][i])
		{
			i--;
		}
	}

	//학점
	for ( i = 0; i < cnt; i++)
	{
		grade[0][i] = gradecon(rand() % 6);
		grade[1][i] = gradecon(rand() % 6);
	}

	//출력
	for (i = 0; i < cnt; i++)
	{
		printf("%d ", student[i]);//학번출력
		for (j = 0; j < namelen[i]; j++)
		{
			printf("%c", name[i][j]);//이름출력
		}
		printf(" %d ", subject[0][i]);//과목1코드
		printf("%c", grade[0][i]);//학점
		printf(" %d ", subject[1][i]);//과목2코드
		printf("%c\n", grade[1][i]);//학점
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