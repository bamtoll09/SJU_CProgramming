#include <stdio.h>
#pragma warning(disable: 4996)

// decrypt와 encrypt 함수 원형 선언
char decrypt(char ch, int M);
char encrypt(char ch, int M);

int main()
{
    // 입력받은 문자를 저장할 배열 arr 초기화
    // 입력받은 문자열 크기를 계산할 변수 index 초기화
    char arr[100] = "";
    int index = 0;

    // 문자를 입력받을 변수 input 초기화
    // M1, M2 변수 초기화
    char input = 0;
    int M1 = 0, M2 = 0;

    // 무한 반복
    while (1)
    {
        // 문자를 하나 입력받는다.
        scanf("%c", &input);

        // 입력받은 문자가 종료조건인지 판단한다.
        if (input == '*') break;
        
        // 종료조건이 아니라면 문자를 배열에 저장한다.
        arr[index++] = input;
    }

    // M1과 M2의 값을 입력받는다.
    scanf("%d %d", &M1, &M2);

    // 배열의 크기만큼 반복한다.
    for (int i=0; i<index; ++i)
    {
        // 배열의 i번째 문자를 암호키 M1으로 복호화한다.
        // 복호화된 값은 다시 배열의 i번째에 저장하고 출력한다.
        arr[i] = decrypt(arr[i], M1);
        printf("%c", arr[i]);
    }
    printf("\n");

    // 배열의 크기만큼 반복한다.
    for (int i=0; i<index; ++i)
    {
        // 배열의 i번째 문자를 암호키 M2로 암호화한다.
        // 암호화된 값은 다시 배열의 i번째에 저장하고 출력한다.
        arr[i] = encrypt(arr[i], M2);
        printf("%c", arr[i]);
    }
    printf("\n");
    
    return 0;
}

// 문자 ch를 암호키 M으로 복호화 하는 함수 decrypt
char decrypt(char ch, int M)
{
    // 문자 ch가 소문자인지 판단하는 변수
    int isLower = 0;

    // char형 변수의 범위를 int형 범위로 늘리기 위한 변순
    int ch_i = ch;

    // 문자 ch가 소문자라면
    if (ch_i >= 'a' && ch_i <= 'z')
    {
        // isLower에 1을 넣어 추후 계산결과를 소문자로 출력되게끔 한다.
        isLower = 1;

        // 문자 ch를 대문자로 바꿔준다.
        ch_i -= ('a' - 'A');
    }
    
    // 문자가 소문자 이거나 대문자인 경우 (영문자인 경우)
    if (isLower || ch_i >= 'A' && ch_i <= 'Z')
    {
        // 복호화하기 위해 M값을 빼준다.
        ch_i -= M;

        // ch값이 값 A 보다 작은 경우, 차이를 계산해 Z와 차이를 뺀 값으로 계산한다.
        if (ch_i < 'A')
            ch_i = 'Z' - (('A' - ch_i - 1) % ('Z' - 'A' + 1));

        // ch가 소문자였다면 다시 소문자로 바꿔준다.
        if (isLower)
            ch_i += ('a' - 'A');

        // 계산된 ch값을 반환한다.
        return ch_i;
    }

    // 영문자가 아닌 경우 ch를 반환한다.
    else
        return ch;
}

// 문자 ch를 암호키 M으로 암호화 하는 함수 encrypt
char encrypt(char ch, int M)
{
    // 문자 ch가 소문자인지 판단하는 변수
    int isLower = 0;

    // char형 변수의 범위를 int형 범위로 늘리기 위한 변순
    int ch_i = ch;

    // 문자 ch가 소문자라면
    if (ch_i >= 'a' && ch_i <= 'z')
    {
        // isLower에 1을 넣어 추후 계산결과를 소문자로 출력되게끔 한다.
        isLower = 1;

        // 문자 ch를 대문자로 바꿔준다.
        ch_i -= ('a' - 'A');
    }
    
    // 문자가 소문자 이거나 대문자인 경우 (영문자인 경우)
    if (isLower || ch_i >= 'A' && ch_i <= 'Z')
    {
        // 암호화하기 위해 M값을 더해준다.
        ch_i += M;

        // ch값이 값 Z 보다 큰 경우, 차이를 계산해 A와 차이를 더한 값으로 계산한다.
        if (ch_i > 'Z')
            ch_i = 'A' + ((ch_i - 'Z' - 1) % ('Z' - 'A' + 1));

        // ch가 소문자였다면 다시 소문자로 바꿔준다.
        if (isLower)
            ch_i += ('a' - 'A');

        // 계산된 ch값을 반환한다.
        return ch_i;
    }

    // 영문자가 아닌 경우 ch를 반환한다.
    else
        return ch;

}