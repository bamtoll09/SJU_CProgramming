#include <stdio.h>
#pragma warning(disable: 4996)

// decrypt�� encrypt �Լ� ���� ����
char decrypt(char ch, int M);
char encrypt(char ch, int M);

int main()
{
    // �Է¹��� ���ڸ� ������ �迭 arr �ʱ�ȭ
    // �Է¹��� ���ڿ� ũ�⸦ ����� ���� index �ʱ�ȭ
    char arr[100] = "";
    int index = 0;

    // ���ڸ� �Է¹��� ���� input �ʱ�ȭ
    // M1, M2 ���� �ʱ�ȭ
    char input = 0;
    int M1 = 0, M2 = 0;

    // ���� �ݺ�
    while (1)
    {
        // ���ڸ� �ϳ� �Է¹޴´�.
        scanf("%c", &input);

        // �Է¹��� ���ڰ� ������������ �Ǵ��Ѵ�.
        if (input == '*') break;
        
        // ���������� �ƴ϶�� ���ڸ� �迭�� �����Ѵ�.
        arr[index++] = input;
    }

    // M1�� M2�� ���� �Է¹޴´�.
    scanf("%d %d", &M1, &M2);

    // �迭�� ũ�⸸ŭ �ݺ��Ѵ�.
    for (int i=0; i<index; ++i)
    {
        // �迭�� i��° ���ڸ� ��ȣŰ M1���� ��ȣȭ�Ѵ�.
        // ��ȣȭ�� ���� �ٽ� �迭�� i��°�� �����ϰ� ����Ѵ�.
        arr[i] = decrypt(arr[i], M1);
        printf("%c", arr[i]);
    }
    printf("\n");

    // �迭�� ũ�⸸ŭ �ݺ��Ѵ�.
    for (int i=0; i<index; ++i)
    {
        // �迭�� i��° ���ڸ� ��ȣŰ M2�� ��ȣȭ�Ѵ�.
        // ��ȣȭ�� ���� �ٽ� �迭�� i��°�� �����ϰ� ����Ѵ�.
        arr[i] = encrypt(arr[i], M2);
        printf("%c", arr[i]);
    }
    printf("\n");
    
    return 0;
}

// ���� ch�� ��ȣŰ M���� ��ȣȭ �ϴ� �Լ� decrypt
char decrypt(char ch, int M)
{
    // ���� ch�� �ҹ������� �Ǵ��ϴ� ����
    int isLower = 0;

    // char�� ������ ������ int�� ������ �ø��� ���� ����
    int ch_i = ch;

    // ���� ch�� �ҹ��ڶ��
    if (ch_i >= 'a' && ch_i <= 'z')
    {
        // isLower�� 1�� �־� ���� ������� �ҹ��ڷ� ��µǰԲ� �Ѵ�.
        isLower = 1;

        // ���� ch�� �빮�ڷ� �ٲ��ش�.
        ch_i -= ('a' - 'A');
    }
    
    // ���ڰ� �ҹ��� �̰ų� �빮���� ��� (�������� ���)
    if (isLower || ch_i >= 'A' && ch_i <= 'Z')
    {
        // ��ȣȭ�ϱ� ���� M���� ���ش�.
        ch_i -= M;

        // ch���� �� A ���� ���� ���, ���̸� ����� Z�� ���̸� �� ������ ����Ѵ�.
        if (ch_i < 'A')
            ch_i = 'Z' - (('A' - ch_i - 1) % ('Z' - 'A' + 1));

        // ch�� �ҹ��ڿ��ٸ� �ٽ� �ҹ��ڷ� �ٲ��ش�.
        if (isLower)
            ch_i += ('a' - 'A');

        // ���� ch���� ��ȯ�Ѵ�.
        return ch_i;
    }

    // �����ڰ� �ƴ� ��� ch�� ��ȯ�Ѵ�.
    else
        return ch;
}

// ���� ch�� ��ȣŰ M���� ��ȣȭ �ϴ� �Լ� encrypt
char encrypt(char ch, int M)
{
    // ���� ch�� �ҹ������� �Ǵ��ϴ� ����
    int isLower = 0;

    // char�� ������ ������ int�� ������ �ø��� ���� ����
    int ch_i = ch;

    // ���� ch�� �ҹ��ڶ��
    if (ch_i >= 'a' && ch_i <= 'z')
    {
        // isLower�� 1�� �־� ���� ������� �ҹ��ڷ� ��µǰԲ� �Ѵ�.
        isLower = 1;

        // ���� ch�� �빮�ڷ� �ٲ��ش�.
        ch_i -= ('a' - 'A');
    }
    
    // ���ڰ� �ҹ��� �̰ų� �빮���� ��� (�������� ���)
    if (isLower || ch_i >= 'A' && ch_i <= 'Z')
    {
        // ��ȣȭ�ϱ� ���� M���� �����ش�.
        ch_i += M;

        // ch���� �� Z ���� ū ���, ���̸� ����� A�� ���̸� ���� ������ ����Ѵ�.
        if (ch_i > 'Z')
            ch_i = 'A' + ((ch_i - 'Z' - 1) % ('Z' - 'A' + 1));

        // ch�� �ҹ��ڿ��ٸ� �ٽ� �ҹ��ڷ� �ٲ��ش�.
        if (isLower)
            ch_i += ('a' - 'A');

        // ���� ch���� ��ȯ�Ѵ�.
        return ch_i;
    }

    // �����ڰ� �ƴ� ��� ch�� ��ȯ�Ѵ�.
    else
        return ch;

}